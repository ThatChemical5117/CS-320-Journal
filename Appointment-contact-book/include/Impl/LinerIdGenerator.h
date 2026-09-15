#pragma once

#include "Interface/IdGeneratorInterface.h"

class LinerIdGenerator: public IdGeneratorInterface
{
public:
	std::uint64_t GenerateId() override final;
private:
	std::uint64_t m_nextId {1}; // make sure that there is a valid value in this member variable
};
