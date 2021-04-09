#include <inttypes.h>
#include "xchain/json/json.h"
#include "xchain/xchain.h"
#include "xchain/account.h"
#include "xchain/contract.pb.h"
#include "xchain/syscall.h"
#include "Traceability.pb.h"
#include "Traceability.h"
#include "xchain/json/json.h"
#include <iostream>
using namespace std;


//构造函数
Tracebility::Tracebility() :
    _ipfs_table(         context(), "ipfs"                ),
    _product_table(          context(), "product"                 ),

    ctx(context())
{
}

bool Tracebility::is_ipfs_exit(const string & ipfskey, ipfstable & table){
    if(!get_ipfs_table().find({{"ipfskey", ipfskey}}, &table))
        return false;
    return true;
}

bool Tracebility::is_product_exit(const string& orgNo,const string& productBatchNo,const string& pinfoRecordId, producttable & table){
    if(!get_product_table().find({{"orgno", orgNo},{"productbatchno",productBatchNo},{"pinforecordid",pinfoRecordId}}, &table))
        return false;
    return true;
}

void Tracebility::find_ProductTable(const string & v1,const string & v2,const string & k1,const string & k2){
    if(v1.empty() || v2.empty()){
        ctx->error("some args are missing");
        return;
    }

    auto it = get_product_table().scan({{k1,v1},{k2,v2}});
    string ret;
    producttable ent;
    xchain::json spec_json ;
    while(it->next()) {
        if (!it->get(&ent)) {
            ctx->error("product table get failure : ");
            return;
        }
        //ret += ent.to_string();
        spec_json.push_back(ent.to_json());
    }
    ctx->ok(spec_json.dump());
}

void Tracebility::initialize(){
    xchain::Context* ctx = this->context();
    ctx->ok("initialize Tracebility contract success");
}

void Tracebility::storeIpfsInfo(){
    xchain::Context* ctx = this->context(); 

    std::string orgNo = ctx->arg("orgNo");
    std::string productBatchNo = ctx->arg("productBatchNo");
    std::string productCode = ctx->arg("productCode");
    std::string submitTime = ctx->arg("submitTime");

    if (orgNo.empty() || productBatchNo.empty() || productCode.empty() || submitTime.empty()) {
        ctx->error("some args are missing");
        return;
    }

    /*
    * 拼接key值
    * key值 = IpfsTable + orgNo + productBatchNo + productCode
    */
    ipfstable table;
    std::string IpfsKey = orgNo  + productBatchNo  + productCode;
    if (is_ipfs_exit(IpfsKey, table)){
        ctx->error("storeIpfsInfo failed, such hash has existed already");
        return;
    }
    table.set_ipfskey(IpfsKey);
    table.set_orgno(orgNo);
    table.set_productbatchno(productBatchNo);
    table.set_productcode(productCode);
    table.set_submittime(submitTime);

    if(!get_ipfs_table().put(table)){
        ctx->error("storeIpfsInfo failed");
        return;
    }
    ctx->ok("storeIpfsInfo success");
}

void Tracebility::storeProductTable(){
    xchain::Context* ctx = this->context(); 

    std::string orgNo = ctx->arg("orgNo");
    std::string productBatchNo = ctx->arg("productBatchNo");
    std::string filesHash = ctx->arg("filesHash");
    std::string fileType = ctx->arg("fileType");
    std::string address = ctx->arg("address");
    std::string lat = ctx->arg("lat");
    std::string lng = ctx->arg("lng");
    std::string createTime = ctx->arg("createTime");
    std::string updateTime = ctx->arg("updateTime");
    std::string pinfoRecordId = ctx->arg("pInfoRecordId");
    std::string paccount = ctx->arg("pAccount");
    std::string puserId = ctx->arg("pUserId");
    std::string proleName = ctx->arg("pRoleName");
    std::string premark = ctx->arg("pRemark");
    std::string proleId = ctx->arg("pRoleId");
    std::string puserName = ctx->arg("pUserName");
   
    if(orgNo.empty() || productBatchNo.empty() || filesHash.empty() || fileType.empty() || address.empty() || lat.empty() || lng.empty()
        || createTime.empty() || updateTime.empty() || pinfoRecordId.empty() || paccount.empty() || puserId.empty() || proleName.empty() || premark.empty()
        || proleId.empty() || puserName.empty() 
        ) {

        ctx->error("some args are missing");
        return;
    }

    producttable table;
    if (is_product_exit(orgNo , productBatchNo, pinfoRecordId,table)){
        ctx->error("storeProductTable failed, such hash has existed already");
        return;
    }
    table.set_orgno(orgNo);
    table.set_productbatchno(productBatchNo);
    table.set_fileshash(filesHash);
    table.set_filetype(fileType);
    table.set_address(address);
    table.set_lat(lat);
    table.set_lng(lng);
    table.set_createtime(createTime);
    table.set_updatetime(updateTime);
    table.set_pinforecordid(pinfoRecordId);
    table.set_paccount(paccount);
    table.set_puserid(puserId);
    table.set_prolename(proleName);
    table.set_premark(premark);
    table.set_proleid(proleId);
    table.set_pusername(puserName);

    if(!get_product_table().put(table)){
         ctx->error("storeProductTable failed");
         return;
    }
    ctx->ok("storeProductInfo success");
    
}

void Tracebility::queryIpfsInfo(){
    xchain::Context* ctx = this->context();
    const std::string key =  ctx->arg("key");

    if(ctx->arg("key").empty()){
            ctx->error("arg(key) cannot be empty");
        return;
    }

    ipfstable table;

    if (!is_ipfs_exit(key, table)){
        ctx->ok("null");
        return;
    }

    ctx->ok(table.to_json().dump());
}

void Tracebility::queryProductTable(){
    xchain::Context* ctx = this->context();
    const std::string orgNo =  ctx->arg("orgNo");
    const std::string productBatchNo =  ctx->arg("productBatchNo");
    const std::string pinfoRecordId =  ctx->arg("pInfoRecordId");
    const std::string mode = ctx->arg("mode");

    bool flag = mode.empty() ? true : false;  //true：单一查找，false：多字段查找
    if(flag){
        if (orgNo.empty() || productBatchNo.empty() || pinfoRecordId.empty()){
                ctx->error("arg cannot be empty");
            return;
        }

        producttable table;
        if (!is_product_exit(orgNo , productBatchNo, pinfoRecordId,table)){
            ctx->ok("null");
            return;
        }
        
        ctx->ok(table.to_json().dump());
    }else{

        if (!orgNo.empty() && !productBatchNo.empty() && !pinfoRecordId.empty()){
                ctx->error("Please set mode value");
            return;
        }

        int status = atoi(mode.c_str());
        switch (status)
        {
        case 0:
            find_ProductTable(orgNo,productBatchNo,"orgno","productbatchno");
            break;
        case 1:
            find_ProductTable(orgNo,pinfoRecordId,"orgno","pinforecordid");
            break;
        case 2:
            find_ProductTable(productBatchNo,pinfoRecordId,"productbatchno","pinforecordid");
            break;
        default:
            ctx->error("The mode value must be 0, 1, 2");
            break;
        }

    
    }
}

DEFINE_METHOD(Tracebility,initialize){
    self.initialize();
}

DEFINE_METHOD(Tracebility,storeIpfsInfo){
    self.storeIpfsInfo();
}

DEFINE_METHOD(Tracebility,storeProductTable){
    self.storeProductTable();
}

DEFINE_METHOD(Tracebility,queryProductTable){
    self.queryProductTable();
}

DEFINE_METHOD(Tracebility,queryIpfsInfo){
    self.queryIpfsInfo();
}