#ifndef REF_PTR_HPP_
#define REF_PTR_HPP_

#include <iostream>
#include <fstream>
#include <cstddef>
#include "BaseComponent.hpp"

class RefPtr
{
public:
	RefPtr(BaseComponent *rawPtr);
	RefPtr() : RefPtr(nullptr) {}
	RefPtr(RefPtr const &other);
	~RefPtr();
	RefPtr &operator=(RefPtr const &other);

	BaseComponent *get() const;

private:
	BaseComponent *_rawPtr;
	int *_refCounter;
};
#endif

