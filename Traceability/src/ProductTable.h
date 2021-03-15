#ifndef _PRODUCTTABLE_H_
#define _PRODUCTTABLE_H_

#include "xchain/table/types.h"
#include "Traceability.pb.h"

#include <string>
using namespace std;

class producttable : public Traceability :: ProductTable {
    DEFINE_ROWKEY(productkey);  //主键
    DEFINE_INDEX_BEGIN(25)
        DEFINE_INDEX_ADD(0, productkey)  //主键只能find
        DEFINE_INDEX_ADD(1, account)
        DEFINE_INDEX_ADD(2, address)
        DEFINE_INDEX_ADD(3, batchno)
        DEFINE_INDEX_ADD(4, confirm)
        DEFINE_INDEX_ADD(5, createtime)
        DEFINE_INDEX_ADD(6, id)
        DEFINE_INDEX_ADD(7, key)
        DEFINE_INDEX_ADD(8, lat)
        DEFINE_INDEX_ADD(9, lng)
        DEFINE_INDEX_ADD(10, orgid)
        DEFINE_INDEX_ADD(11, pichash)
        DEFINE_INDEX_ADD(12, picture)
        DEFINE_INDEX_ADD(13, roleid)
        DEFINE_INDEX_ADD(14, rolename)
        DEFINE_INDEX_ADD(15, status)
        DEFINE_INDEX_ADD(16, submittime)
        DEFINE_INDEX_ADD(17, transactionid)
        DEFINE_INDEX_ADD(18, type)
        DEFINE_INDEX_ADD(19, updatetime)
        DEFINE_INDEX_ADD(20, uploadtimes)
        DEFINE_INDEX_ADD(21, userid)
        DEFINE_INDEX_ADD(22, username)
        DEFINE_INDEX_ADD(23, useruuid)
        DEFINE_INDEX_ADD(24, work)
    DEFINE_INDEX_END();


    string to_string();
};

#endif //_PRODUCTTABLE_H_