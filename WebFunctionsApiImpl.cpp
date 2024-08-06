#include "WebFunctionsApiImpl.h"

#include <cpr/cpr.h>

#include <nlohmann/json.hpp>

#include "Logger.h"
#include "Utility.h"

using json = nlohmann::json;
namespace WebFunctionsImpl {

    json WebFunctionsApiImpl::RunWebRequest(const std::string& endpoint, const std::string& authToken,
                                            const json requestBody) {
        // Convert the JSON object into a character string
        std::string requestBodyStr = requestBody.dump();

        try {
            // Send the request to the API endpoint
            cpr::Response response =
                cpr::Post(cpr::Url{endpoint},
                          cpr::Header{{"Authorization", "Bearer " + authToken}, {"Content-Type", "application/json"}},
                          cpr::Body{requestBodyStr});

            if (response.status_code == 200) {
                auto jsonResponse = json::parse(response.text);
                return jsonResponse;
            } else {
                return json::parse("{}");
            }
        } catch (int e) {
            return json::parse("{}");
        }
    }

    std::string WebFunctionsApiImpl::CreateChatCompletion(const std::string& endPoint, const std::string& userPrompt,
                                                          const std::string& systemPrompt, const std::string& apiKey,
                                                          const std::string& model) {
        logger::debug("got a request for {}", endPoint);

        // Create the JSON object for the request
        json requestBody = {{"model", model},
                            {"messages", json::array({{{"role", "system"}, {"content", systemPrompt}},
                                                      {{"role", "user"}, {"content", userPrompt}}})}};

        // Convert the JSON object into a character string
        std::string requestBodyStr = requestBody.dump();

        // Send the request to the API endpoint
        cpr::Response response =
            cpr::Post(cpr::Url{endPoint},
                      cpr::Header{{"Authorization", "Bearer " + apiKey}, {"Content-Type", "application/json"}},
                      cpr::Body{requestBodyStr});

        if (response.status_code == 200) {
            // Analyse the JSON response and return the first choice
            auto jsonResponse = json::parse(response.text);
            if (jsonResponse.contains("choices") && jsonResponse["choices"].is_array()) {
                return jsonResponse["choices"][0]["message"]["content"];
            } else {
                return "Error: No valid response received.";
            }
        } else {
            return "Error: HTTP " + std::to_string(response.status_code);
        }
    }
}