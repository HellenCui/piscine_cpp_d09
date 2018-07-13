#ifndef COMMUNICATION_HPP_
#define COMMUNICATION_HPP_

#include <string>
#include <vector>
#include <istream>
#include <ostream>

class CommunicationAPI
{
public:
	CommunicationAPI(std::istream &input, std::ostream &output);

	~CommunicationAPI();
	void startMission(std::string const &missionName);
	void addUser(std::string const &userName);
	void receiveMessage(std::string const &name, std::string &msg) const;
	void sendMessage(std::string const &userName,
		std::string const &message) const;
	bool hasUser(std::string const &name) const;
private:
	static const size_t MAX_USERS = 5;
	size_t _usersOffset;
	std::istream &_input;
	std::ostream &_output;
	std::string _missionName;
	std::string _users[MAX_USERS];

};

#endif 

