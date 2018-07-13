#include "Errors.hpp"
NasaError::NasaError(std::string const &message,
	std::string const &component) :
	_message(message), _component(component)
{
}
std::string const &NasaError::getComponent() const
{
	return (this->_component);
}

const char *NasaError::what() const noexcept
{
	return (this->_message.c_str());
}
LifeCriticalError::LifeCriticalError(std::string const &message,
	std::string const &component) :
	NasaError(message, component)
{
}
MissionCriticalError::MissionCriticalError(std::string const &message,
	std::string const &component) :
	NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message) :
	NasaError(message, "CommunicationDevice")
{
}

UserError::UserError(std::string const &message,
	std::string const &component) :
	NasaError(message, component)
{
}

