#include "xchain/xchain.h"
#include <string>

//第一张表，存了ipfs一些信息
const std::string IpfsTable = "IPFSTABLE"; 
//第二张表，存了商品详细信息
const std::string ProductTable = "PRODUCTTABLE";

class TracebilityBasic{
    // 初始化，基本不做任何工作
    virtual void initialize() = 0;

    //存ipfs表上链 
    virtual void storeIpfsInfo() = 0;

    //存product表上链
    virtual void storeProductTable() = 0;

    //通过key查询ipfs表内容
    virtual void queryIpfsInfo() = 0;

    //通过key查询Product表内容
    virtual void queryProductTable() = 0;
};

struct Tracebility : public TracebilityBasic, public xchain::Contract {

     void initialize(){
        xchain::Context* ctx = this->context();
        ctx->ok("initialize Tracebility contract success");
    }

    void storeIpfsInfo(){
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
       std::string IpfsKey = IpfsTable + "/" + orgNo  + productBatchNo  + productCode;
       std::string value = ipfshash + "\t" + orgNo + "\t" + productBatchNo + "\t" + productCode + "\t" + submitTime;

       std::string tempVal;
       if (ctx->get_object(IpfsKey, &tempVal)) {
            ctx->error("storeIpfsInfo failed, such hash has existed already");
            return;
        }

       if( ctx->put_object(IpfsKey, value) ){
           ctx->ok("storeIpfsInfo success");
            return;
       }
       ctx->error("storeIpfsInfo failed");
    }

    void storeProductTable(){
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

        std::string tablekey = ProductTable + "/" + receiveKey;
        std::string value = account + "\t" + address + "\t" + batchNo + "\t" + confirm + "\t" + createTime + "\t" + id + "\t" + key +
            "\t" + lat + "\t" + lng + "\t" + orgId + "\t" + picHash + "\t" + picture + "\t" + roleId + "\t" + roleName + "\t" + status + 
            "\t" + submitTime + "\t" + transactionId + "\t" + type + "\t" + updateTime + "\t" + uploadTimes + "\t" + userId + "\t" + userName + 
            "\t" + userUUID + "\t" + work + "\t" + receiveKey;

        
        std::string tempVal;
        if (ctx->get_object(tablekey, &tempVal)) {
            ctx->error("storeProductTable failed, such hash has existed already");
            return;
        }


        if( ctx->put_object(tablekey, value) ){
            ctx->ok("storeProductInfo success");
            return;
       }
       ctx->error("storeProductInfo failed");     
    }

    void queryIpfsInfo(){
        xchain::Context* ctx = this->context();
        const std::string key = IpfsTable + "/" + ctx->arg("key");

        if(ctx->arg("key").empty()){
             ctx->error("arg(key) cannot be empty");
            return;
        }
        strresult(key,ctx);
    }

    void queryProductTable(){
        xchain::Context* ctx = this->context();
        const std::string key = ProductTable + "/" + ctx->arg("key");

        if(ctx->arg("key").empty()){
             ctx->error("arg(key) cannot be empty");
            return;
        }
        strresult(key,ctx);
    }

public:
    void strresult(const std::string key , xchain::Context* ctx){
        std::unique_ptr<xchain::Iterator> iter = ctx->new_iterator(key, key + "～");
        std::string result;
        while (iter->next()) {
            std::pair<std::string, std::string> res;
            iter->get(&res);
            result += res.second + "\n";
        }
        ctx->ok(result);
    }
};

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