#include <iostream>
#include <string>
#include <curl/curl.h>

class HttpWrapper {
public:
    HttpWrapper() {
        curl_global_init(CURL_GLOBAL_ALL);
        curl_handle_ = curl_easy_init();
    }

    ~HttpWrapper() {
        curl_easy_cleanup(curl_handle_);
        curl_global_cleanup();
    }

    std::string get(const std::string& url) {
        std::string result;
        if (curl_handle_) {
            curl_easy_setopt(curl_handle_, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl_handle_, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl_handle_, CURLOPT_WRITEDATA, &result);
            CURLcode res = curl_easy_perform(curl_handle_);
            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }
        }
        return result;
    }

private:
    CURL* curl_handle_;

    static size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
        std::string* str = reinterpret_cast<std::string*>(userdata);
        str->append(ptr, size * nmemb);
        return size * nmemb;
    }
};

int main() {
    HttpWrapper http;
    std::string response = http.get("https://www.example.com");
    std::cout << response << std::endl;
    return 0;
}
