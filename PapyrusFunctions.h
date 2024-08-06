
 using VM = RE::BSScript::Internal::VirtualMachine;
	using StackID = RE::VMStackID;

namespace WebPapyrusFunctions {
    bool BindPapyrusFunctions(RE::BSScript::IVirtualMachine* vm);
    RE::BSFixedString MakeWebRequest(RE::StaticFunctionTag*, RE::BSFixedString endPoint, RE::BSFixedString body);
}