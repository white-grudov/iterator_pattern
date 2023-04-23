#pragma once

#include <vector>
#include <thread>
#include <iostream>

#include "SocialNetwork.h"
#include "Profile.h"
#include "LinkedInIterator.h"

class LinkedIn : public SocialNetwork {
public:
    LinkedIn(std::vector<Profile> cache) : contacts_(std::move(cache)) {}

    Profile requestContactInfoFromLinkedInAPI(const std::string& profileEmail);
    std::vector<std::string> requestRelatedContactsFromLinkedInAPI
            (const std::string& profileEmail, const std::string& contactType);

    std::unique_ptr<ProfileIterator> createFriendsIterator(const std::string& profileEmail) override;
    std::unique_ptr <ProfileIterator> createCoworkersIterator(const std::string& profileEmail) override;

private:
    Profile findContact(const std::string& profileEmail);
    void simulateNetworkLatency();

    std::vector<Profile> contacts_;
};
