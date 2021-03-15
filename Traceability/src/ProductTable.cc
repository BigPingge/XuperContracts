#include"ProductTable.h"

string producttable::to_string(){
    string str ;
    str += "{" ;
    str += account() + ",";
    str += address() + ",";
    str += batchno() + ",";
    str += confirm() + ",";
    str += createtime() + ",";
    str += id() + ",";
    str += key() + ",";
    str += lat() + ",";
    str += lng() + ",";
    str += orgid() + ",";
    str += pichash() + ",";
    str += picture() + ",";
    str += roleid() + ",";
    str += rolename() + ",";
    str += status() + ",";
    str += submittime() + ",";
    str += transactionid() + ",";
    str += type() + ",";
    str += updatetime() + ",";
    str += uploadtimes() + ",";
    str += userid() + ",";
    str += username() + ",";
    str += useruuid() + ",";
    str += work() ;
    str += "}";
    return str;
}