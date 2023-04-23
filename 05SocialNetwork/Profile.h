#pragma once

#include <string>
#include <vector>
#include <map>

class Profile {
public:
    Profile(std::string email, std::string name, std::vector<std::string> contacts);
    Profile() {}

    std::string getEmail() const;

    std::string getName() const;

    std::vector<std::string> getContacts(const std::string& contactType);

private:
    std::string email_;
    std::string name_;
    std::map<std::string, std::vector<std::string>> contacts_;
};