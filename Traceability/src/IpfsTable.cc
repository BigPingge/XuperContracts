#include"IpfsTable.h"

string ipfstable::to_string(){
    string str ;
    str += "{" ;
    str += ipfshash() + ",";
    str += orgno() + ",";
    str += productbatchno() + ",";
    str += productcode() + ",";
    str += submittime();
    str += "}";
    return str;
}

string ipfstable::to_json(){
    string str;
    xchain::json j = {
        {"ipfshash", ipfshash()},
        {"orgNo", orgno()},
        {"productBatchNo", productbatchno()},
        {"productCode", productcode()},
        {"submitTime", submittime()},
    };
    return str;
}