#pragma once
#include <cstdint>

class IdGeneratorInterface
{
public:
	virtual std::uint64_t GenerateId() = 0;
	virtual ~IdGeneratorInterface() = default;
};
