
using VM = RE::BSScript::Internal::VirtualMachine;
using StackID = RE::VMStackID;

namespace WebPapyrusFunctions {
    bool BindPapyrusFunctions(RE::BSScript::IVirtualMachine* vm);
    RE::BSFixedString MakeWebRequest(RE::StaticFunctionTag*, RE::BSFixedString endPoint, RE::BSFixedString body);
    RE::BSFixedString MakeWebRequestWithAuth(RE::StaticFunctionTag*, RE::BSFixedString endPoint, RE::BSFixedString body,
                                             RE::BSFixedString apiToken);
    RE::BSFixedString GenerateChatCompletion(RE::StaticFunctionTag*, RE::BSFixedString endPoint,
                                             RE::BSFixedString prompt, RE::BSFixedString apiKey,
                                             RE::BSFixedString model);
}