#pragma once
/* IdGeneratorInterface.h
 * Author: Michael Kik
 * Date: 9-10-2026
 * Course Id: CS-499
 *
 * Interface for classes that generate IDs. Used to specify that the client
 * of another class that requires this interface needs to provide a proper implementation of it.
 *
 * Also useful for restricting the valid template type arguments through concepts
*/


#include <cstdint>

class IdGeneratorInterface
{
public:
	virtual std::uint64_t GenerateId() = 0;
	virtual ~IdGeneratorInterface() = default;
protected:
	IdGeneratorInterface() = default;
};
