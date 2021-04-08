#include"ProductTable.h"

string producttable::to_string(){
    string str ;
    str += "{" ;
    str += orgno() + ",";
    str += productbatchno() + ",";
    str += fileshash() + ",";
    str += filetype() + ",";
    str += address() + ",";
    str += lat() + ",";
    str += lng() + ",";
    str += createtime() + ",";
    str += updatetime() + ",";
    str += pinforecordid() + ",";
    str += paccount() + ",";
    str += puserid() + ",";
    str += prolename() + ",";
    str += premark() + ",";
    str += proleid() + ",";
    str += pusername();
    str += "}";
    return str;
}