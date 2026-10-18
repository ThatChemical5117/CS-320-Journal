#pragma once
/* ServiceInterface.h
 * Author: Michael Kik
 * Date: 09-13-2026
 * Course Id: CS-499
 *
 * Interface for service classes that manipulate a std::unordered_map
 * Also provides ways to Get, Delete, and Loop over items in the map.
 *
 * Requires a  Generator strategy to provide a source for ID generation
*/
#include <string>
#include <unordered_map>
#include <functional>

// Custom concepts (see respective files)
#include "Utilities/Idable.h"
#include "Utilities/IsGenerator.h"

// Makes sure that the Item can have an ID and that the ID generator is derived from the GeneratorInterface
template <typename Item, typename GeneratorStrategy> requires Idable<Item> && IsGenerator<GeneratorStrategy>
class ServiceInterface
{
public:
	virtual void DeleteItem(const std::string& id);
	virtual const Item*  GetItem(const std::string& id) const;

	void ForEach(std::function<void (const Item&)> functionStrategy);

	virtual ~ServiceInterface();
protected:
	ServiceInterface() = default;
	bool HasItem(const std::string& id) const;
	std::unordered_map<std::string, Item*> m_itemStore;

	GeneratorStrategy m_idGenerator;
};

// Implementation ==============================================================

// Check that the unordered map has the id
template <typename Item, typename GeneratorStrategy> requires Idable<Item> && IsGenerator<GeneratorStrategy>
bool ServiceInterface<Item, GeneratorStrategy>::HasItem(const std::string& id) const
{
	return m_itemStore.contains(id);
};

// Deletes and item from the hash map
template<typename Item, typename GeneratorStrategy> requires Idable<Item> && IsGenerator<GeneratorStrategy>
void ServiceInterface<Item, GeneratorStrategy>::DeleteItem(const std::string& id)
{
	if (this->HasItem(id))
	{
		// free the memory
		delete m_itemStore.at(id);

		// remove it from the map
		m_itemStore.erase(id);
	}
};


// Get the item at the specified id return nullptr if not there
template<typename Item, typename GeneratorStrategy> requires Idable<Item> && IsGenerator<GeneratorStrategy>
const Item* ServiceInterface<Item, GeneratorStrategy>::GetItem(const std::string& id) const
{
	if (this->HasItem(id))
		return m_itemStore.at(id);

	return nullptr;
}

template<typename Item, typename GeneratorStrategy> requires Idable<Item> && IsGenerator<GeneratorStrategy>
void ServiceInterface<Item, GeneratorStrategy>::ForEach(std::function<void (const Item&)> functionStrategy)
{
	// Loop over each item and call the provided function
	for (const auto& [key, item]: m_itemStore)
	{
		functionStrategy(*item);
	}
}

// Destroy and free all memory from the pointers
template<typename Item, typename GeneratorStrategy> requires Idable<Item> && IsGenerator<GeneratorStrategy>
ServiceInterface<Item, GeneratorStrategy>::~ServiceInterface()
{
	// For each item
	for (const auto& [key, item] : m_itemStore)
	{
		// Delete the item in memory
		delete item;	
	}
}

