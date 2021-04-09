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

xchain::json producttable::to_json() {
    xchain::json j = {
        {"orgNo", orgno()},
        {"productBatchNo", productbatchno()},
        {"filesHash", fileshash()},
        {"fileType", filetype()},
        {"address", address()},
        {"lat", lat()},
        {"lng", lng()},
        {"createTime", createtime()},
        {"updateTime", updatetime()},
        {"pinfoRecordId", pinforecordid()},
        {"pAccount", paccount()},
        {"pUserId", puserid()},
        {"pRoleName", prolename()},
        {"pRemark", premark()},
        {"pRoleId", proleid()},
        {"pUserName", pusername()},
    };

    return j;
}