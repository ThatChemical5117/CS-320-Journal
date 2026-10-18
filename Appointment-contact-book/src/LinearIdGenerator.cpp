#include "Impl/LinerIdGenerator.h"

std::uint64_t LinearIdGenerator::GenerateId()
{
	return m_nextId++;
}
