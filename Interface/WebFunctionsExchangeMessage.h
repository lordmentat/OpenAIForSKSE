#pragma once

#include "WebFunctionsApi.h"

namespace WebFunctions {

    struct WebFunctionsExchangeMessage {
        enum : uint32_t { kMessage_ExchangeInterface = 'WEBF' };

        WebFunctionsApi* api = NULL;
    };
}