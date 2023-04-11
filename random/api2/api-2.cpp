#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class MyApi {
public:
    void add_item(const std::string& item) {
        items_.push_back(item);
    }

    std::vector<std::string> get_items() const {
        return items_;
    }

    void clear_items() {
        items_.clear();
    }

    bool remove_item(const std::string& item) {
        auto it = std::find(items_.begin(), items_.end(), item);
        if (it != items_.end()) {
            items_.erase(it);
            return true;
        }
        return false;
    }

private:
    std::vector<std::string> items_;
};

int main() {
    MyApi api;
    api.add_item("ABC");
    api.add_item("DEF");
    api.add_item("GHI");

    std::vector<std::string> items = api.get_items();
    for (const auto& item : items) {
        std::cout << item << std::endl;
    }

    api.remove_item("banana");

    items = api.get_items();
    for (const auto& item : items) {
        std::cout << item << std::endl;
    }

    api.clear_items();

    items = api.get_items();
    for (const auto& item : items) {
        std::cout << item << std::endl;
    }

    return 0;
}
