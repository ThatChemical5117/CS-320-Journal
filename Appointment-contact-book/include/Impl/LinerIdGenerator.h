#pragma once
/* LinearIdGenerator.h
 * Author: Michael Kik
 * Date: 09-16-2026
 * Course Id: CS-499
 *
 * An id generator that simply counts up from the previous id
 * uses the IdGeneratorInterface to enforce the use of the GenerateId function
*/

#include "Interface/IdGeneratorInterface.h"

class LinearIdGenerator: public IdGeneratorInterface
{
public:
	std::uint64_t GenerateId() override final;
private:
	std::uint64_t m_nextId {1}; // make sure that there is a valid value in this member variable
};
