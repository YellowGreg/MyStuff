#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class RandomNumberAPI {
public:
    RandomNumberAPI() {
        listener_ = http_listener("http://localhost:8080/api/random");
        listener_.support(methods::GET, std::bind(&RandomNumberAPI::handle_get, this, std::placeholders::_1));
    }

    void start() {
        listener_.open().wait();
        std::cout << "Listening on port 8080..." << std::endl;
    }

    void stop() {
        listener_.close().wait();
    }

private:
    http_listener listener_;

    void handle_get(http_request request) {
        srand(time(NULL));
        int random_number = rand() % 10 + 1;

        json::value response;
        response["random_number"] = json::value::number(random_number);

        request.reply(status_codes::OK, response);
    }
};

int main() {
    RandomNumberAPI api;
    api.start();

    std::string input;
    std::getline(std::cin, input);

    api.stop();
    return 0;
}
