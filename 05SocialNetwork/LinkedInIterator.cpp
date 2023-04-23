#include <iostream>
#include <memory>
#include <map>

#include "LinkedIn.h"
#include "LinkedInIterator.h"

LinkedInIterator::LinkedInIterator(LinkedIn* linkedIn, const std::string& type, const std::string& email)
    : linkedIn_(linkedIn), type_(type), email_(email), currentPosition_(0) {}

bool LinkedInIterator::hasNext() {
    lazyLoad();
    return currentPosition_ < emails_.size();
}

Profile LinkedInIterator::getNext() {
    if (!hasNext()) {
        return Profile(); // Empty Profile
    }

    std::string friendEmail = emails_[currentPosition_];
    Profile friendContact = contacts_[currentPosition_];
    if (friendContact.getEmail().empty()) {
        friendContact = linkedIn_->requestContactInfoFromLinkedInAPI(friendEmail);
        contacts_[currentPosition_] = friendContact;
    }
    currentPosition_++;
    return friendContact;
}

void LinkedInIterator::reset() {
    currentPosition_ = 0;
}

void LinkedInIterator::lazyLoad() {
    if (emails_.empty()) {
        std::vector<std::string> profiles = linkedIn_->requestRelatedContactsFromLinkedInAPI(email_, type_);
        for (const std::string& profile : profiles) {
            emails_.push_back(profile);
            contacts_.emplace_back(); // Add an empty Profile
        }
    }
}
