#include"IpfsTable.h"

string ipfstable::to_string(){
    string str ;
    str += "{" ;
    str += orgno() + ",";
    str += productbatchno() + ",";
    str += productcode() + ",";
    str += submittime();
    str += "}";
    return str;
}

xchain::json ipfstable::to_json() {
    xchain::json j = {
        {"orgNo", orgno()},
        {"productBatchNo", productbatchno()},
        {"productCode", productcode()},
        {"submitTime", submittime()},
    };

    return j;
}