#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string &username, const std::string &password);
    std::string getUsername() const;
    bool checkPassword(const std::string &password) const;
    
private:
    std::string username;
    std::string password;
};

#endif // USER_H
