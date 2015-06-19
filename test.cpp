#include "symcc.h"

int main()
{
    Symcc::unittest();
    Symcc::Expr expr("exp((x_AL*x_CU*(AL_ALCU0_0 + AL_ALCU0_1*T + AL_ALCU0_2*T*log(T)) + x_AL*x_SI*(AL_ALSI0_0 + AL_ALSI0_1*T + AL_ALSI0_2*T*log(T)) + x_AL*(AL_AL0_0 + AL_AL0_1*T + AL_AL0_2*T*log(T)) + x_CU*(AL_CU0_0 + AL_CU0_1*T + AL_CU0_2*T*log(T)) + x_SI*(AL_SI0_0 + AL_SI0_1*T + AL_SI0_2*T*log(T)))/(R*T))/(R*T)");
    expr["x_AL"] = 0.1;
    expr["x_CU"] = 0.2;
    expr["x_SI"] = 0.7;
    //
    expr["AL_AL0_0"] = 10.;
    expr["AL_AL0_1"] = 0.0;
    expr["AL_AL0_2"] = 0.0;
    expr["AL_CU0_0"] = 0.0;
    expr["AL_CU0_1"] = 0.0;
    expr["AL_CU0_2"] = 0.0;
    expr["AL_SI0_0"] = 0.0;
    expr["AL_SI0_1"] = 0.0;
    expr["AL_SI0_2"] = 0.0;
    expr["AL_ALCU0_0"] = 0.0;
    expr["AL_ALCU0_1"] = 0.0;
    expr["AL_ALCU0_2"] = 0.0;
    expr["AL_ALSI0_0"] = 0.0;
    expr["AL_ALSI0_1"] = 0.0;
    expr["AL_ALSI0_2"] = 0.0;    
    /*
    expr["CU_AL0_0"] = 0.0;
    expr["CU_AL0_1"] = 0.0;
    expr["CU_AL0_2"] = 0.0;
    expr["CU_CU0_0"] = 0.0;
    expr["CU_CU0_1"] = 0.0;
    expr["CU_CU0_2"] = 0.0;
    expr["CU_SI0_0"] = 0.0;
    expr["CU_SI0_1"] = 0.0;
    expr["CU_SI0_2"] = 0.0;
    expr["CU_ALCU0_0"] = 0.0;
    expr["CU_ALCU0_1"] = 0.0;
    expr["CU_ALCU0_2"] = 0.0;
    expr["CU_CUSI0_0"] = 0.0;
    expr["CU_CUSI0_1"] = 0.0;
    expr["CU_CUSI0_2"] = 0.0;
    
    expr["SI_AL0_0"] = 0.0;
    expr["SI_AL0_1"] = 0.0;
    expr["SI_AL0_2"] = 0.0;
    expr["SI_CU0_0"] = 0.0;
    expr["SI_CU0_1"] = 0.0;
    expr["SI_CU0_2"] = 0.0;
    expr["SI_SI0_0"] = 0.0;
    expr["SI_SI0_1"] = 0.0;
    expr["SI_SI0_2"] = 0.0;
    expr["SI_ALSI0_0"] = 0.0;
    expr["SI_ALSI0_1"] = 0.0;
    expr["SI_ALSI0_2"] = 0.0;
    expr["SI_CUSI0_0"] = 0.0;
    expr["SI_CUSI0_1"] = 0.0;
    expr["SI_CUSI0_2"] = 0.0;
    //expr.Evaluate();
    */
    /*
    std::cout<<expr.Evaluate()<<std::endl;
    for(auto item=expr.p.symbols_.begin(); item!=expr.p.symbols_.end(); ++item)
    {
        std::cout<<item->first<<std::endl;
    }
    */
    return 1;
}
