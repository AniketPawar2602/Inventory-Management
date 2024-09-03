#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <vector>
#include "User.h"

class Authentication {
public:
    Authentication();
    bool login(const std::string &username, const std::string &password);
    bool signUp(const std::string &username, const std::string &password);

private:
    std::vector<User> users;
    User* findUser(const std::string &username);
};

#endif // AUTHENTICATION_H
