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

string producttable::to_json(){
    string str;
     xchain::json j = {
        {"account", account()},
        {"address", address()},
        {"batchNo", batchno()},
        {"confirm", confirm()},
        {"createTime", createtime()},
        {"id", id()},
        {"key", key()},
        {"lat", lat()},
        {"lng", lng()},
        {"orgId", orgid()},
        {"picHash", pichash()},
        {"picture", picture()},
        {"roleId", roleid()},
        {"roleName", rolename()},
        {"status", status()},
        {"submitTime", submittime()},
        {"transactionId", transactionid()},
        {"type", type()},
        {"updateTime", updatetime()},
        {"uploadTimes", uploadtimes()},
        {"userId", userid()},
        {"userName", username()},
        {"userUUID", useruuid()},
        {"work", work()},
    };
}