#include <iostream>
#include <assert.h>
#include <vector>

#ifndef PARSER_H
#include "parser.h"
#endif

#ifndef SYMCC_H
#define SYMCC_H
namespace Symcc
{

std::string number_to_string(int num)
{
    return std::to_string(num);
}

std::string number_to_string(double num)
{
    return std::to_string(num);
}

class Expr
{
private:
    bool is_create;
    bool is_set;
public:
    Parser p;
    std::map<std::string, double> _symbols;
    std::string _program;
    void Initialize(std::string program)
    {
        is_create = 1;
        is_set = 1;
        _program = program;
        p.Set(_program);
        p.Evaluate();
        _symbols.clear();
        _symbols["pi"] = 3.1415926535897932385;
        _symbols["e"]  = 2.7182818284590452354;
        _symbols["R"] = 8.314;
        _symbols["T"] = 1.0;
    }
    Expr(std::string program)
    {
        Initialize(program);
    }
    Expr() {is_create=0;}
    
    Expr(const Expr& expr)
    {
        Initialize(expr._program);
    }
    
    bool CheckAssign()
    {
        std::vector<std::string> unassigned;
        for(auto item=p.symbols_.begin(); item!=p.symbols_.end(); ++item)
        {
            bool flag = 0;
            for(auto jtem=_symbols.begin(); jtem!=_symbols.end(); ++jtem)
            {
                if(item->first==jtem->first)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                unassigned.push_back(item->first);
            }
        }
        if(unassigned.size() != 0)
        {
            for(auto each=unassigned.begin(); each!=unassigned.end(); ++each)
            {
                std::cout<<*each<<std::endl;
            }
            return 0;
        }
        else
        {
            return 1;
        }
    }
    
    void SyncSymbols()
    {
        for(auto item=_symbols.begin(); item!=_symbols.end(); ++item)
        {
            p.symbols_[item->first] = item->second;
        }
    }
    
    const double Evaluate()
    {
        if(!is_create)
        {
            throw std::runtime_error ("Empty Expr is not allowed to be Evaluated!");
        }
        if(!is_set) p.Set(_program);
        if(!CheckAssign())
        {
            throw std::runtime_error ("Variables have not been assigned!");
        }
        SyncSymbols();
        return p.Evaluate();
    }
    
    double & operator[] (const std::string & key) { return _symbols[key]; }
    
    void operator+=(const Expr& expr)
    {
        this->_program = this->_program + " + " + expr._program;
    }
    
    void operator-=(const Expr& expr)
    {
        this->_program = this->_program + " - " + expr._program;
    }
    
    void operator*=(const Expr& expr)
    {
        this->_program = "(" + this->_program + ") * (" + expr._program + ")";
    }
    
    void operator/=(const Expr& expr)
    {
        this->_program = "(" + this->_program + ") / (" + expr._program + ")";
    }
    
    Expr operator+(const Expr& expr)
    {
        return  Expr(this->_program + " + " + expr._program);
    }
    
    Expr operator-(const Expr& expr)
    {
        return  Expr(this->_program + " - " + expr._program);
    }
    
    Expr operator*(const Expr& expr)
    {
        return  Expr("(" + this->_program + ") * (" + expr._program + ")");
    }
    
    Expr operator/(const Expr& expr)
    {
        return  Expr("(" + this->_program + ") / (" + expr._program + ")");
    }
    
    //Integer 
    void operator+=(int num)
    {
        this->_program = this->_program + " + " + number_to_string(num);
    }
    
    void operator-=(int num)
    {
        this->_program = this->_program + " - " + number_to_string(num);
    }
    
    void operator*=(int num)
    {
        this->_program = "(" + this->_program + ") * (" + number_to_string(num) + ")";
    }
    
    void operator/=(int num)
    {
        this->_program = "(" + this->_program + ") / (" + number_to_string(num) + ")";
    }
    
    Expr operator+(int num)
    {
        return  Expr(this->_program + " + " + number_to_string(num));
    }
    
    Expr operator-(int num)
    {
        return  Expr(this->_program + " - " + number_to_string(num));
    }
    
    Expr operator*(int num)
    {
        return  Expr("(" + this->_program + ") * (" + number_to_string(num) + ")");
    }
    
    Expr operator/(int num)
    {
        return  Expr("(" + this->_program + ") / (" + number_to_string(num) + ")");
    }
    
    //Double
    void operator+=(double num)
    {
        this->_program = this->_program + " + " + number_to_string(num);
    }
    
    void operator-=(double num)
    {
        this->_program = this->_program + " - " + number_to_string(num);
    }
    
    void operator*=(double num)
    {
        this->_program = "(" + this->_program + ") * (" + number_to_string(num) + ")";
    }
    
    void operator/=(double num)
    {
        this->_program = "(" + this->_program + ") / (" + number_to_string(num) + ")";
    }
    
    Expr operator+(double num)
    {
        return  Expr(this->_program + " + " + number_to_string(num));
    }
    
    Expr operator-(double num)
    {
        return  Expr(this->_program + " - " + number_to_string(num));
    }
    
    Expr operator*(double num)
    {
        return  Expr("(" + this->_program + ") * (" + number_to_string(num) + ")");
    }
    
    Expr operator/(double num)
    {
        return  Expr("(" + this->_program + ") / (" + number_to_string(num) + ")");
    }
};

Expr operator+(int num, const Expr& expr)
{
    return Expr(number_to_string(num) + " + " + expr._program);
}

Expr operator-(int num, const Expr& expr)
{
    return Expr(number_to_string(num) + " - " + expr._program);
}

Expr operator*(int num, const Expr& expr)
{
    return  Expr("(" + number_to_string(num) + ") * (" + expr._program + ")");
}

Expr operator/(int num, const Expr& expr)
{
    return  Expr("(" + number_to_string(num) + ") / (" + expr._program + ")");
}

Expr operator+(double num, const Expr& expr)
{
    return Expr(number_to_string(num) + " + " + expr._program);
}

Expr operator-(double num, const Expr& expr)
{
    return Expr(number_to_string(num) + " - " + expr._program);
}

Expr operator*(double num, const Expr& expr)
{
    return  Expr("(" + number_to_string(num) + ") * (" + expr._program + ")");
}

Expr operator/(double num, const Expr& expr)
{
    return  Expr("(" + number_to_string(num) + ") / (" + expr._program + ")");
}

Expr symexp(const Expr expr)
{
    return Expr(std::string("exp( ") + expr._program + std::string(")"));
}

Expr symlog(const Expr expr)
{
    return Expr(std::string("log( ") + expr._program + std::string(")"));
}

void unittest()
{
    Expr exp1(std::string("123"));
    Expr exp2(std::string("232"));
    
    Expr exp3 = exp1 + exp2;
    assert(exp3._program == std::string("123 + 232"));
    exp3 = exp1 - exp2;
    assert(exp3._program == std::string("123 - 232"));
    exp3 = exp1 * exp2;
    assert(exp3._program == std::string("(123) * (232)"));
    exp3 = exp1 / exp2;
    assert(exp3._program == std::string("(123) / (232)"));
    exp3 = 100 + exp1;
    assert(exp3._program == std::string("100 + 123"));
    exp3 = 100 - exp1;
    assert(exp3._program == std::string("100 - 123"));
    exp3 = 100 * exp2;
    assert(exp3._program == std::string("(100) * (232)"));
    exp3 = 100 / exp2;
    assert(exp3._program == std::string("(100) / (232)"));
    
}
}
#endif
