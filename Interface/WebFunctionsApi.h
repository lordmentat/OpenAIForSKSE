#pragma once
#include <nlohmann/json.hpp>
namespace WebFunctions {
    class WebFunctionsApi {
    public:
        virtual nlohmann::json RunWebRequest(const std::string& endpoint, const std::string& authToken,
                                             nlohmann::json requestBody) = 0;
        virtual std::string CreateChatCompletion(const std::string& endPoint, const std::string& userPrompt,
                                                 const std::string& systemPrompt = "", const std::string& apiKey = "",
                                                 const std::string& model = "gpt-4o-mini") = 0;
    };
}