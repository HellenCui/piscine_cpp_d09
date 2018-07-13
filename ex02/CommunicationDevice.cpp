#include <cstring>
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(
	std::istream &input, std::ostream &output)
try : _api(input, output)
{
} catch (std::exception const &ex) {
	throw CommunicationError(std::string("Error: ") + ex.what());
}
CommunicationDevice::~CommunicationDevice()
{
}
void CommunicationDevice::startMission(
	std::string const &missionName, std::string *users, size_t nbUsers)
{
	try {
		for (size_t i = 0; i < nbUsers; ++i)
			_api.addUser(users[i]);
		_api.startMission(missionName);
	} catch (std::logic_error const &ex) {
		throw (std::string("LogicError: ") + ex.what());
	} catch (std::runtime_error const &ex) {
		throw (std::string("RuntimeError: ") + ex.what());
	} catch (std::exception const &ex) {
		throw (std::string("Error: ") + ex.what());
	}
}
void CommunicationDevice::send(
	std::string const &user, std::string const &message) const
{
	try {
		_api.sendMessage(user, message);
	} catch (std::exception const &ex) {
		std::cerr << ex.what() << std::endl;
	}
}
void CommunicationDevice::receive(
	std::string const &user, std::string &message) const
{
	try {
		_api.receiveMessage(user, message);
	} catch (std::exception const &ex) {
		if (std::strcmp(ex.what(), "INVALID MESSAGE") == 0)
			std::cerr << "INVALID MESSAGE" << std::endl;
	}
}

