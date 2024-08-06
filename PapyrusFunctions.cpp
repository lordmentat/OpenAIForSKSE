
#include "PapyrusFunctions.h"

#include <future>
#include <thread>

#include "WebFunctionsApiImpl.h"

namespace WebPapyrusFunctions {

    bool BindPapyrusFunctions(RE::BSScript::IVirtualMachine* vm) {
        vm->RegisterFunction("MakeWebRequest", "OpenAIForSKSE", MakeWebRequest);
        vm->RegisterFunction("MakeWebRequestWithAuth", "OpenAIForSKSE", MakeWebRequestWithAuth);
        vm->RegisterFunction("GenerateChatCompletion", "OpenAIForSKSE", GenerateChatCompletion);
        return true;
    }

    RE::BSFixedString MakeWebRequest(RE::StaticFunctionTag*, RE::BSFixedString endPoint, RE::BSFixedString body) {
        json requestBody = json::parse(body.c_str());

        json data =
            WebFunctionsImpl::WebFunctionsApiImpl::GetSingleton()->RunWebRequest(endPoint.c_str(), "", requestBody);
        return data.dump();
    };

    RE::BSFixedString MakeWebRequestWithAuth(RE::StaticFunctionTag*, RE::BSFixedString endPoint, RE::BSFixedString body,
                                             RE::BSFixedString apiToken) {
        json requestBody = json::parse(body.c_str());

        json data = WebFunctionsImpl::WebFunctionsApiImpl::GetSingleton()->RunWebRequest(endPoint.c_str(),
                                                                                         apiToken.c_str(), requestBody);
        return data.dump();
    };

    RE::BSFixedString GenerateChatCompletion(RE::StaticFunctionTag*, RE::BSFixedString endPoint,
                                             RE::BSFixedString prompt, RE::BSFixedString apiKey,
                                             RE::BSFixedString model) {
        json data = WebFunctionsImpl::WebFunctionsApiImpl::GetSingleton()->CreateChatCompletion(
            endPoint.c_str(), prompt.c_str(), "", apiKey.c_str(), model.c_str());

        return data.dump();
    };
}