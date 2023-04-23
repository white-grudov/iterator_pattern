#include <string>
#include <iostream>

#include "SocialSpammer.h"

void SocialSpammer::sendSpamToFriends(const std::string& profileEmail, const std::string& message) {
    std::cout << "\nIterating over friends...\n";
    iterator_ = network_->createFriendsIterator(profileEmail);
    while (iterator_->hasNext()) {
        Profile profile = iterator_->getNext();
        sendMessage(profile.getEmail(), message);
    }
}
void SocialSpammer::sendSpamToCoworkers(const std::string& profileEmail, const std::string& message) {
    std::cout << "\nIterating over coworkers...\n";
    iterator_ = network_->createCoworkersIterator(profileEmail);
    while (iterator_->hasNext()) {
        Profile profile = iterator_->getNext();
        sendMessage(profile.getEmail(), message);
    }
}
void SocialSpammer::sendMessage(const std::string& email, const std::string& message) {
    std::cout << "Sent message to: '" << email << "'. Message body: '" << message << "'\n";
}