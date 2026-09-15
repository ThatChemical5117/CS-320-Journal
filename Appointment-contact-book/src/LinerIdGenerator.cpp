#include "Impl/LinerIdGenerator.h"

std::uint64_t LinerIdGenerator::GenerateId()
{
	return m_nextId++;
}
