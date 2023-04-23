#pragma once

class Profile;

class ProfileIterator {
public:
	virtual ~ProfileIterator() = default;
	virtual bool hasNext() = 0;
	virtual Profile getNext() = 0;
	virtual void reset() = 0;
};