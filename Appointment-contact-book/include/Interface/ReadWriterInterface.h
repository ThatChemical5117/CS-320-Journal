#pragma once
/* ReadWriteInterface.h
 * Author: Michael Kik
 * Date: 9-12-2026
 * Course Id: CS-499
 *
 * This interface provides two Functions, Read and Write, for a derived class to define. 
 * This interface also provides a FileManager class along with storage for an IdableFactoryInterface (must be defined by the client)
 *
 * This allows for a variable number of derived classes to both output different objects and pull from different source files (json, csv)
*/

#include "Utilities/Idable.h"
#include "Impl/FileManager.h"

#include "Interface/IdableFactoryInterface.h"

template <typename T, typename S>
requires Idable<T>
class ReadWriteInterface
{
public:

	// Read
	virtual void Read() = 0;

	// Write
	virtual void Write() = 0;

	virtual ~ReadWriteInterface() = default;
protected:
	FileManager m_file;
	IdableFactoryInterface<T, S>* m_factory;
	
	// Constructor
	ReadWriteInterface(const std::string filename, const std::string extension, IdableFactoryInterface<T, S>* factory);
};

// Basic constructor
template <typename T, typename S> requires Idable<T>
ReadWriteInterface<T, S>::ReadWriteInterface(const std::string filename, const std::string extension, IdableFactoryInterface<T, S>* factory)
	: m_file { filename, extension }, m_factory { factory }
{};
