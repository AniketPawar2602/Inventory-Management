#include "Authentication.h"

Authentication::Authentication() {
    // Add a default admin user
    users.emplace_back("admin", "password");
}

bool Authentication::login(const std::string &username, const std::string &password) {
    User* user = findUser(username);
    if (user != nullptr && user->checkPassword(password)) {
        return true;
    }
    return false;
}

bool Authentication::signUp(const std::string &username, const std::string &password) {
    if (findUser(username) == nullptr) {
        users.emplace_back(username, password);
        return true;
    }
    return false;
}

User* Authentication::findUser(const std::string &username) {
    for (auto &user : users) {
        if (user.getUsername() == username) {
            return &user;
        }
    }
    return nullptr;
}
