#include "Utility.h"
#include "Logger.h"
/*#include <SimpleIni.h>

const std::string INI_FILE_PATH = "Data/OpenAIForSKSE.ini";
std::string openAiKey;
std::string openAiEndpoint;

void LoadDataFromINI() {
    CSimpleIniA ini;
    ini.SetUnicode();
    SI_Error rc = ini.LoadFile(INI_FILE_PATH.c_str());
    if (rc < 0) {
        logger::error("Failed to load INI file: {}", INI_FILE_PATH);
        return;
    }

    const char* openAiKeyValue = ini.GetValue("General", "sOpenAiKey", "0");
    const char* endpoint = ini.GetValue("General", "sOpenAiEndpoint", "0");
    openAiKey = openAiKeyValue;
    openAiEndpoint = endpoint;
}*/