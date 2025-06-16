#pragma once
#include <google/protobuf/service.h>
#include <string>

class MprpcController : public google::protobuf::RpcController
{
public:
    MprpcController();

    // 重置Controller的状态，使其可以复用
    void Reset();

    // 检查RPC方法是否执行失败
    bool Failed() const;

    // 返回RPC方法失败时的错误信息
    std::string ErrorText() const;

    // 设置RPC方法执行失败的状态以及失败原因
    void SetFailed(const std::string& reason);

    // 以下方法目前未实现具体功能，仅提供接口声明

    // 请求取消RPC调用（暂未实现）
    void StartCancel();

    // 判断是否已经取消（暂未实现）
    bool IsCanceled() const;

    // 设置RPC调用被取消时的回调函数（暂未实现）
    void NotifyOnCancel(google::protobuf::Closure* callback);

private:
    bool m_failed;            // 表示RPC方法在执行过程中是否失败
    std::string m_errText;    // 存储RPC方法执行失败时的错误描述信息
};
