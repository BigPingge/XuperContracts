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
        DEFINE_INDEX_ADD(1, orgno)
        DEFINE_INDEX_ADD(2, productbatchno)
        DEFINE_INDEX_ADD(3, submittime)
    DEFINE_INDEX_END();

    string to_string();
};

#endif //_IPFSTABLE_H_


