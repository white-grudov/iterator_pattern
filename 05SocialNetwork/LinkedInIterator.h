#pragma once

#include <string>
#include <vector>

#include "ProfileIterator.h"

class Profile;
class LinkedIn;

class LinkedInIterator : public ProfileIterator {
public:
	LinkedInIterator(LinkedIn* linkedIn, const std::string& type, const std::string& email);
	bool hasNext() override;
	Profile getNext() override;
	void reset() override;
private:
	void lazyLoad();
	LinkedIn* linkedIn_;
	std::string type_;
	std::string email_;
	int currentPosition_ = 0;
	std::vector<std::string> emails_;
	std::vector<Profile> contacts_;
};