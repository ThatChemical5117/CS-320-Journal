#pragma once
/* JsonReadWriter.h
 * Author: Michael Kik
 * Date: 09-17-2026
 * Course ID: CS-499
 *
 * JsonReadWriter is an implementation of the  Read-Write Interface
 * This class defined a generic way to read from a json file into objects
 * that fufill the Idable concept requirements. 
 *
 * This class requires a factory that is derived from the IdableFactoryInterface as this provides
 * the class the knowledge to actually produce and store the read objects
 */


#include <string>
#include <fstream>

#include "Utilities/Idable.h"
#include "Interface/IdableFactoryInterface.h"
#include "Interface/ReadWriterInterface.h"

#include "nlohmann/json.hpp"

// For Task
template <typename T>
requires Idable<T>
class JsonReadWriter: ReadWriteInterface<T, nlohmann::json>
{
public:
	JsonReadWriter(const std::string& filename, IdableFactoryInterface<T, nlohmann::json>* factory);

	void Read() override;
	void Write() override;
};


template <typename T> requires Idable<T>
JsonReadWriter<T>::JsonReadWriter(const std::string& filename, IdableFactoryInterface<T, nlohmann::json>* factory)
	: ReadWriteInterface<T, nlohmann::json> {filename, ".json", factory}
{};

template <typename T> requires Idable<T>
void JsonReadWriter<T>::Read()
{
	this->m_file.Read([this](std::ifstream& stream) -> void	{
		nlohmann::json document = nlohmann::json::parse(stream);	

		for (const auto& object: document)
		{
			// This constructs a new task object into the TaskService object
			this->m_factory->FromSource(object);	
		};
	});
};

// Write should require taking in a source to write from
template <typename T> requires Idable<T>
void JsonReadWriter<T>::Write()
{
	// One shots the document creation process
	nlohmann::json document = this->m_factory->ToSource(nullptr);

	this->m_file.Write([this, &document](std::ofstream& stream) -> void {
		stream << std::setw(4) << document;	
	});
};

