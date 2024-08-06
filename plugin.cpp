#include "Logger.h"
#include "PapyrusFunctions.h"
#include "Utility.h"
#include "WebFunctionsApiImpl.h"
#include "Interface/WebFunctionsApi.h"
#include "Interface/WebFunctionsExchangeMessage.h"


void SKSEMessageHandler(SKSE::MessagingInterface::Message* message) {
    switch (message->type) {
        case WebFunctions::WebFunctionsExchangeMessage::kMessage_ExchangeInterface: {
            WebFunctions::WebFunctionsExchangeMessage* exchangeMessage =
                (WebFunctions::WebFunctionsExchangeMessage*)message->data;
            exchangeMessage->api = WebFunctionsImpl::WebFunctionsApiImpl::GetSingleton();
        } break;
    }
}

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    SKSE::Init(skse);

    SetupLog();

    SKSE::GetPapyrusInterface()->Register(WebPapyrusFunctions::BindPapyrusFunctions);

    SKSE::GetMessagingInterface()->RegisterListener(nullptr, SKSEMessageHandler);

    //LoadDataFromINI();

    return true;
}
