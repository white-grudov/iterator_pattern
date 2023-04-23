#include "LinkedIn.h"

Profile LinkedIn::requestContactInfoFromLinkedInAPI(const std::string& profileEmail) {
    // Here would be a POST request to one of the LinkedIn API endpoints.
    // Instead, we emulate a long network connection, which you would expect
    // in real life...
    simulateNetworkLatency();
    std::cout << "LinkedIn: Loading profile '" << profileEmail << "' over the network...\n";
    // ...and return test data.
    return findContact(profileEmail);
}

std::vector<std::string> LinkedIn::requestRelatedContactsFromLinkedInAPI
            (const std::string& profileEmail, const std::string& contactType) {
    // Here would be a POST request to one of the LinkedIn API endpoints.
    // Instead, we emulate a long network connection, which you would expect
    // in real life.
    simulateNetworkLatency();
    std::cout << "LinkedIn: Loading '" << contactType << "' list of '" << profileEmail << "' over the network...\n";

    // ...and return test data.
    Profile profile = findContact(profileEmail);
    if (!profile.getEmail().empty()) {
        return profile.getContacts(contactType);
    }
    return {};
}

std::unique_ptr<ProfileIterator> LinkedIn::createFriendsIterator(const std::string& profileEmail) {
    return std::make_unique<LinkedInIterator>(this, "friends", profileEmail);
}

std::unique_ptr <ProfileIterator> LinkedIn::createCoworkersIterator(const std::string& profileEmail) {
    return std::make_unique<LinkedInIterator>(this, "coworkers", profileEmail);
}

Profile LinkedIn::findContact(const std::string& profileEmail) {
    for (const auto& profile : contacts_) {
        if (profile.getEmail() == profileEmail) {
            return profile;
        }
    }
    return {};
}

void LinkedIn::simulateNetworkLatency() {
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
}