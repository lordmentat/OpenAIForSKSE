#pragma once

#include "Interface/WebFunctionsApi.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace WebFunctionsImpl {

    class WebFunctionsApiImpl: public WebFunctions::WebFunctionsApi {
    public:
        WebFunctionsApiImpl() = default;
        WebFunctionsApiImpl(const WebFunctionsApiImpl&) = delete;
        WebFunctionsApiImpl(WebFunctionsApiImpl&&) = delete;
        WebFunctionsApiImpl& operator=(const WebFunctionsApiImpl&) = delete;
        WebFunctionsApiImpl& operator=(WebFunctionsApiImpl&&) = delete;
        ~WebFunctionsApiImpl() = default;
        static WebFunctionsApiImpl* GetSingleton() noexcept {
            static WebFunctionsApiImpl INSTANCE;
            return std::addressof(INSTANCE);
        }
        virtual json RunWebRequest(const std::string& endpoint, const std::string& authToken, const json requestBody) override;
        virtual std::string CreateChatCompletion(const std::string& endPoint, const std::string& userPrompt,
                                         const std::string& systemPrompt = "", const std::string& apiKey = "",
                                         const std::string& model = "gpt-4o-mini") override;
    };

}