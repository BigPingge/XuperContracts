#ifndef _IPFSTABLE_H_
#define _IPFSTABLE_H_

#include "xchain/table/types.h"
#include "Traceability.pb.h"

#include <string>
using namespace std;

class ipfstable : public Traceability :: IpfsTable {
    DEFINE_ROWKEY(ipfskey);          //主键
    DEFINE_INDEX_BEGIN(5)
        DEFINE_INDEX_ADD(0, ipfskey) //主键只能find
        DEFINE_INDEX_ADD(1, ipfshash)
        DEFINE_INDEX_ADD(2, orgno)
        DEFINE_INDEX_ADD(3, productbatchno)
        DEFINE_INDEX_ADD(4, submittime)
    DEFINE_INDEX_END();

    string to_string(); //转string
    string to_json();  //转json

};

#endif //_IPFSTABLE_H_


