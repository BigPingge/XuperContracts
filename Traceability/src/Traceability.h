#ifndef _TRACEABILITY_H_
#define _TRACEABILITY_H_

// #include "xchain/xchain.h"
// #include "xchain/contract.pb.h"
#include <inttypes.h>
#include "xchain/xchain.h"
#include "xchain/table/types.h"
#include "xchain/table/table.tpl.h"

#include "IpfsTable.h"
#include "ProductTable.h"

#include <string>
using namespace std;
class Tracebility : public xchain::Contract {
public:
    Tracebility();
private:
    //两张表
    xchain::cdt::Table<ipfstable>            _ipfs_table;
    xchain::cdt::Table<producttable>         _product_table;

    xchain::Context* ctx;
public:
    decltype(_ipfs_table)& get_ipfs_table(){
        return _ipfs_table;
    }
    decltype(_product_table)& get_product_table(){
        return _product_table;
    }
public:
    // 初始化，基本不做任何工作
    void initialize();

    //存ipfs表上链 
    void storeIpfsInfo();

    //存product表上链
    void storeProductTable();

    //通过key查询ipfs表内容
    void queryIpfsInfo();

    //通过key查询Product表内容
    void queryProductTable();
private:
    //其他函数，仅供内部调用
    bool is_ipfs_exit(const string &, ipfstable &);
    bool is_product_exit(const string &,const string &,const string &,producttable &);
    void find_ProductTable(const string &,const string &,const string &,const string &);
};

#endif //_TRACEABILITY_H_