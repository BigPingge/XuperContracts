#ifndef _PRODUCTTABLE_H_
#define _PRODUCTTABLE_H_

#include "xchain/table/types.h"
#include "Traceability.pb.h"

#include <string>
using namespace std;

class producttable : public Traceability :: ProductTable {
    DEFINE_ROWKEY(orgno,productbatchno,pinforecordid);  //联合主键
    DEFINE_INDEX_BEGIN(17)
        DEFINE_INDEX_ADD(0, orgno,productbatchno)
        DEFINE_INDEX_ADD(1, productbatchno,pinforecordid)
        DEFINE_INDEX_ADD(2, fileshash)
        DEFINE_INDEX_ADD(3, filetype)
        DEFINE_INDEX_ADD(4, address)
        DEFINE_INDEX_ADD(5, lat)
        DEFINE_INDEX_ADD(6, lng)
        DEFINE_INDEX_ADD(7, createtime)
        DEFINE_INDEX_ADD(8, updatetime)
        DEFINE_INDEX_ADD(9, pinforecordid)
        DEFINE_INDEX_ADD(10, paccount)
        DEFINE_INDEX_ADD(11, puserid)
        DEFINE_INDEX_ADD(12, prolename)
        DEFINE_INDEX_ADD(13, premark)
        DEFINE_INDEX_ADD(14, proleid)
        DEFINE_INDEX_ADD(15, pusername)
        DEFINE_INDEX_ADD(16, orgno,pinforecordid)
    DEFINE_INDEX_END();


    string to_string();
};

#endif //_PRODUCTTABLE_H_