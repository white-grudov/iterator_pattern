#pragma once

#include <memory>
#include <string>

class ProfileIterator;

class SocialNetwork {
public:
	virtual ~SocialNetwork() = default;
	virtual std::unique_ptr<ProfileIterator> createFriendsIterator(const std::string& profileEmail) = 0;
	virtual std::unique_ptr<ProfileIterator> createCoworkersIterator(const std::string& profileEmail) = 0;
};