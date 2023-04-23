#include "Profile.h"
#include "LinkedIn.h"
#include "SocialSpammer.h"

// I have found this code on the internet and thought it can be a good example to demonstrate
// the use of iterator pattern in a real-world case

using namespace std;

std::vector<Profile> createTestProfiles();

int main()
{
	std::vector<Profile> testData = createTestProfiles();
	LinkedIn linkedIn(testData);
	SocialSpammer spammer(&linkedIn);
	spammer.sendSpamToFriends("anna.smith@bing.com", "Hey! This is Anna's friend Josh. Can you do me a favor and like this post [link]?");
	spammer.sendSpamToCoworkers("anna.smith@bing.com", "Hey! This is Anna's boss Jason. Anna told me you would be interested in [link].");

	return 0;
}
std::vector<Profile> createTestProfiles() {
	std::vector<Profile> data = {
		Profile("anna.smith@bing.com", "Anna Smith", {"friends:mad_max@ya.com", "friends:catwoman@yahoo.com", "coworkers:sam@amazon.com"}),
		Profile("mad_max@ya.com", "Maximilian", {"friends:anna.smith@bing.com", "coworkers:sam@amazon.com"}),
		Profile("bill@microsoft.eu", "Billie", {"coworkers:avanger@ukr.net"}),
		Profile("avanger@ukr.net", "John Day", {"coworkers:bill@microsoft.eu"}),
		Profile("sam@amazon.com", "Sam Kitting", {"coworkers:anna.smith@bing.com", "coworkers:mad_max@ya.com", "friends:catwoman@yahoo.com"}),
		Profile("catwoman@yahoo.com", "Liza", {"friends:anna.smith@bing.com", "friends:sam@amazon.com"})
	};
	return data;
}
