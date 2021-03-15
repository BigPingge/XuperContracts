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