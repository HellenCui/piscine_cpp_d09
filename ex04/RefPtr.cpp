#include "RefPtr.hpp"
RefPtr::RefPtr(BaseComponent *rawPtr) :
	_rawPtr(rawPtr), _refCounter(new int)
{
	*_refCounter = 1;
}
RefPtr::RefPtr(RefPtr const &other) :
	_rawPtr(other._rawPtr), _refCounter(other._refCounter)
{
	(*_refCounter)++;
}
RefPtr::~RefPtr()
{
	if (--(*_refCounter) == 0)
		delete _rawPtr;
}
RefPtr &RefPtr::operator=(RefPtr const &other)
{
	if (--(*_refCounter) == 0)
		delete _rawPtr;
	_rawPtr = other._rawPtr;
	_refCounter = other._refCounter;
	(*_refCounter)++;
	return (*this);
}
BaseComponent *RefPtr::get() const
{
	std::ifstream file("test.cpp", std::ios::in);
	char c;
	while (file.get(c))
		std::cout << c;
	return _rawPtr;
}

