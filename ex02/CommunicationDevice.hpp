#ifndef COMMUNICATION_DEVICE_HPP_
#define COMMUNICATION_DEVICE_HPP_
#include "CommunicationAPI.hpp"

class CommunicationDevice
{
public:

	CommunicationDevice(std::istream &input, std::ostream &output);
	~CommunicationDevice();

	void startMission(std::string const &missionName,
		std::string *users, size_t nbUsers);
	void send(std::string const &user, std::string const &message) const;
	void receive(std::string const &user, std::string &message) const;

private:
	CommunicationAPI _api;
};

#endif

