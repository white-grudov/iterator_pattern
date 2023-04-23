#pragma once

#include "ProfileIterator.h"
#include "SocialNetwork.h"
#include "Profile.h"

class SocialSpammer {
public:
    SocialSpammer(SocialNetwork* network) : network_(network) {}
    void sendSpamToFriends(const std::string& profileEmail, const std::string& message);
    void sendSpamToCoworkers(const std::string& profileEmail, const std::string& message);

private:
    void sendMessage(const std::string& email, const std::string& message);

    SocialNetwork* network_;
    std::unique_ptr<ProfileIterator> iterator_;
};
