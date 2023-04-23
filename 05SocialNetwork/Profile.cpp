#include "Profile.h"

Profile::Profile(std::string email, std::string name, std::vector<std::string> contacts)
    : email_(std::move(email)), name_(std::move(name)) {
    for (const auto& contact : contacts) {
        auto colon_pos = contact.find(':');
        std::string contactType = "friend";
        std::string contactEmail;
        if (colon_pos != std::string::npos) {
            contactType = contact.substr(0, colon_pos);
            contactEmail = contact.substr(colon_pos + 1);
        }
        else {
            contactEmail = contact;
        }
        contacts_[contactType].push_back(contactEmail);
    }
}

std::string Profile::getEmail() const {
    return email_;
}

std::string Profile::getName() const {
    return name_;
}

std::vector<std::string> Profile::getContacts(const std::string& contactType) {
    if (contacts_.find(contactType) == contacts_.end()) {
        contacts_[contactType] = std::vector<std::string>{};
    }
    return contacts_[contactType];
}