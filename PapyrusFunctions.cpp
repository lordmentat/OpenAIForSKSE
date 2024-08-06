
#include "PapyrusFunctions.h"

#include <future>
#include <thread>

#include "WebFunctionsApiImpl.h"

namespace WebPapyrusFunctions {

    bool BindPapyrusFunctions(RE::BSScript::IVirtualMachine* vm) {
        vm->RegisterFunction("MakeWebRequest", "OpenAIForSKSE", MakeWebRequest);
        return true;
    }

    RE::BSFixedString MakeWebRequest(RE::StaticFunctionTag*, RE::BSFixedString endPoint, RE::BSFixedString body) {
        json requestBody = json::parse(body.c_str());

        /*
        auto future = std::async(WebFunctions::RunWebRequest, endPoint.c_str(), "", requestBody);
        json data = future.get();
        return data.dump();
        */
        /* std::thread requestThread(WebFunctions::RunWebRequest, endPoint, "", requestBody);
         if (requestThread.joinable()) {
             requestThread.join();
         }
         */
        json data = WebFunctionsImpl::WebFunctionsApiImpl::GetSingleton()->RunWebRequest(endPoint.c_str(), "", requestBody);
        return data.dump();
    };
}