#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include <sstream>

std::vector<std::string> splitUrl(std::string url, const char delimiter='/') {
    std::stringstream ss(url);
    std::string token;
    std::vector<std::string> urlVector;
    while (getline(ss, token, delimiter)) {
        urlVector.push_back(token);
    }
    return urlVector;
}

/*
std::unordered_map<std::string, std::string> getURLParams(const std::string registeredUrl, 
        const std::string requestUrl, 
        std::vector<std::string> optionalParams={}) {
    std::unordered_map<std::string, std::string> paramsMap;
    //convert the url string into vector of string based on '/' as delimiter
    std::vector<std::string> requestUrlVector = splitUrl(requestUrl);
    std::vector<std::string> registeredUrlVector = splitUrl(registeredUrl);

    int i = 0;
    for (auto data: registeredUrlVector) {
        if (data.substr(0, 1).compare("{") == 0 && data.substr(data.length() - 1, 1).compare("}") == 0) {
            paramsMap[data] = requestUrlVector[i];
        }
        //if (data != "") {
        //    paramsMap[data] = requestUrlVector[i];
        // }
        i++;
    }

    // parsing optional parameter.
    std::unordered_map<std::string, std::string> optionalParamsMap;
    requestUrlVector = splitUrl(requestUrl, '?');
    if (requestUrlVector.size() > 1) {
        requestUrlVector = splitUrl(requestUrlVector[1], '&');
        for (auto data: requestUrlVector) {
            auto optionalParamVector =  splitUrl(data, '=');
            if (optionalParamVector.size() == 2) {
                optionalParamsMap[optionalParamVector[0]] = optionalParamVector[1];
            } else {
                std::cout << "OptionalParamVector Size exceeds 2.: " << optionalParamVector.size() << std::endl;
            }
        }
    }
    if (!optionalParams.empty()) {
        for (auto data: optionalParams) {
            if (optionalParamsMap.find(data) != optionalParamsMap.end()) {
                paramsMap[data] = optionalParamsMap[data];
            }
        }
    } 
    return paramsMap;
}
*/

std::unordered_map<std::string, std::string> getUrlParams(const std::string registeredUrl, 
                                                       const std::string requestUrl, 
                                                       std::vector<std::string> optionalParams={}) {
    // Dictionary of url parametrized part of URL and optional parameter and their value.
    std::unordered_map<std::string, std::string> paramsMap;
    //convert the url string into vector of string based on '/' as delimiter
    std::vector<std::string> requestUrlVector = splitUrl(requestUrl);
    std::vector<std::string> registeredUrlVector = splitUrl(registeredUrl);

    // Getting the parametrized part of url.
    int i = 0;
    for (auto data: registeredUrlVector) {
        if (data.substr(0, 1).compare("{") == 0 && data.substr(data.length() - 1, 1).compare("}") == 0) {
            paramsMap[data] = requestUrlVector[i];
        }
        i++;
    }

    // Getting the optional parameter.
    if (optionalParams.empty()) {
        return paramsMap;
    }

    // splitting url based on ?
    requestUrlVector = splitUrl(requestUrl, '?');
    if (requestUrlVector.size()  < 2) {
        // no optional parameter exist
        return paramsMap;
    }
    
    std::unordered_map<std::string, std::string> optionalParamsMap;
    requestUrlVector = splitUrl(requestUrlVector[1], '&');
    for (auto data: requestUrlVector) {
        // splitting each optionalParam to get optional param name and value
        auto optionalParamVector =  splitUrl(data, '=');
        if (optionalParamVector.size() == 2) {
            optionalParamsMap[optionalParamVector[0]] = optionalParamVector[1];
        }
    }

    for (auto data: optionalParams) {
            if (optionalParamsMap.find(data) != optionalParamsMap.end()) {
                paramsMap[data] = optionalParamsMap[data];
            }
    }
    return paramsMap;
}

int main() {
    const std::string CLOUD_DOMAIN_PARAM = "{cloud-domains}";
    std::string requestURL = "/cloud-domains/edbd94e2/software/esx?action=compliance-check&limit=10&org=vmcA";
    std::string registerdURL = "/cloud-domains/" + CLOUD_DOMAIN_PARAM + "/software/esx?action=compliance-check";

    std::vector<std::string> optionalParam = {"action"};

    auto paramMap = getUrlParams(registerdURL, requestURL, optionalParam);
    //auto paramMap = getURLParams(registerdURL, requestURL);
    std::cout << "Got URL Params and optional value" << std::endl;
    for (auto data:paramMap) {
        std::cout << data.first << "   " << data.second << std::endl;
    }
    return 0;
}
