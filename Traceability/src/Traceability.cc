#include <inttypes.h>
#include "xchain/json/json.h"
#include "xchain/xchain.h"
#include "xchain/account.h"
#include "xchain/contract.pb.h"
#include "xchain/syscall.h"
#include "Traceability.pb.h"
#include "Traceability.h"

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

bool Tracebility::is_product_exit(const string& productkey, producttable & table){
    if(!get_product_table().find({{"productkey", productkey}}, &table))
        return false;
    return true;
}

void Tracebility::initialize(){
    xchain::Context* ctx = this->context();
    ctx->ok("initialize Tracebility contract success");
}

void Tracebility::storeIpfsInfo(){
    xchain::Context* ctx = this->context(); 

    std::string ipfshash = ctx->arg("ipfshash");
    std::string orgNo = ctx->arg("orgNo");
    std::string productBatchNo = ctx->arg("productBatchNo");
    std::string productCode = ctx->arg("productCode");
    std::string submitTime = ctx->arg("submitTime");

    if (ipfshash.empty() || orgNo.empty() || productBatchNo.empty() || productCode.empty() || submitTime.empty()) {
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
    table.set_ipfshash(ipfshash);
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

    std::string account = ctx->arg("account");
    std::string address = ctx->arg("address");
    std::string batchNo = ctx->arg("batchNo");
    std::string confirm = ctx->arg("confirm");
    std::string createTime = ctx->arg("createTime");
    std::string id = ctx->arg("id");
    std::string key = ctx->arg("key");
    std::string lat = ctx->arg("lat");
    std::string lng = ctx->arg("lng");
    std::string orgId = ctx->arg("orgId");
    std::string picHash = ctx->arg("picHash");
    std::string picture = ctx->arg("picture");
    std::string roleId = ctx->arg("roleId");
    std::string roleName = ctx->arg("roleName");
    std::string status = ctx->arg("status");
    std::string submitTime = ctx->arg("submitTime");
    std::string transactionId = ctx->arg("transactionId");
    std::string type = ctx->arg("type");
    std::string updateTime = ctx->arg("updateTime");
    std::string uploadTimes = ctx->arg("uploadTimes");
    std::string userId = ctx->arg("userId");
    std::string userName = ctx->arg("userName");
    std::string userUUID = ctx->arg("userUUID");
    std::string work = ctx->arg("work");
    //这个key从客户端传
    std::string receiveKey = ctx->arg("receiveKey");

    

    if(account.empty() || address.empty() || batchNo.empty() || confirm.empty() || createTime.empty() || id.empty() || key.empty()
        || lat.empty() || lng.empty() || orgId.empty() || picHash.empty() || picture.empty() || roleId.empty() || roleName.empty()
        || status.empty() || submitTime.empty() || transactionId.empty() || type.empty() || updateTime.empty() || uploadTimes.empty()
        || userId.empty() || userName.empty() || userUUID.empty() || work.empty() || receiveKey.empty()
        ) {

        ctx->error("some args are missing");
        return;
    }

    producttable table;
    if (is_product_exit(receiveKey, table)){
        ctx->error("storeProductTable failed, such hash has existed already");
        return;
    }
    table.set_productkey(receiveKey);
    table.set_account(account);
    table.set_address(address);
    table.set_batchno(batchNo);
    table.set_confirm(confirm);
    table.set_createtime(createTime);
    table.set_id(id);
    table.set_key(key);
    table.set_lat(lat);
    table.set_lng(lng);
    table.set_orgid(orgId);
    table.set_pichash(picHash);
    table.set_picture(picture);
    table.set_roleid(roleId);
    table.set_rolename(roleName);
    table.set_status(status);
    table.set_submittime(submitTime);
    table.set_transactionid(transactionId);
    table.set_type(type);
    table.set_updatetime(updateTime);
    table.set_uploadtimes(uploadTimes);
    table.set_userid(userId);
    table.set_username(userName);
    table.set_useruuid(userUUID);
    table.set_work(work);

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
        ctx->error("null");
        return;
    }

    ctx->ok(table.to_string());
}

void Tracebility::queryProductTable(){
    xchain::Context* ctx = this->context();
    const std::string key =  ctx->arg("key");

    if(ctx->arg("key").empty()){
            ctx->error("arg(key) cannot be empty");
        return;
    }

    producttable table;
    if (!is_product_exit(key, table)){
        ctx->error("null");
        return;
    }
    
    ctx->ok(table.to_string());
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