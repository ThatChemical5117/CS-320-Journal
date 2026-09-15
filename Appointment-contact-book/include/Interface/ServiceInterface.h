#pragma once
#include <string>
#include <unordered_map>

#include <Interface/IdGeneratorInterface.h>

// Has ID concept 
template <typename T>
concept Idable = requires(T item) { { item.GetId() } -> std::same_as<const std::string_view>; item.SetId(std::string{}); };

// Derived from IdGeneratorInterface concept
template <typename T>
concept IdGenerator = std::derived_from<T, IdGeneratorInterface>;

// Makes sure that the Item can have an ID and that the ID generator is derived from the 
template <typename Item, typename GeneratorStrategy> requires Idable<Item> && IdGenerator<GeneratorStrategy>
class ServiceInterface
{
public:
	virtual void DeleteItem(const std::string& id);
	virtual const Item*  GetItem(const std::string& id) const;

	virtual ~ServiceInterface();
protected:
	ServiceInterface() = default;
	bool HasItem(const std::string& id) const;
	std::unordered_map<std::string, Item*> m_itemStore;

	GeneratorStrategy m_idGenerator;
};

// Implementation ==============================================================

// Check that the unordered map has the id
template <typename Item, typename GeneratorStrategy> requires Idable<Item> && IdGenerator<GeneratorStrategy>
bool ServiceInterface<Item, GeneratorStrategy>::HasItem(const std::string& id) const
{
	return m_itemStore.contains(id);
};

// Deletes and item from the hash map
template<typename Item, typename GeneratorStrategy> requires Idable<Item> && IdGenerator<GeneratorStrategy>
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
template<typename Item, typename GeneratorStrategy> requires Idable<Item> && IdGenerator<GeneratorStrategy>
const Item* ServiceInterface<Item, GeneratorStrategy>::GetItem(const std::string& id) const
{
	if (this->HasItem(id))
		return m_itemStore.at(id);

	return nullptr;
}

// Destroy and free all memory from the pointers
template<typename Item, typename GeneratorStrategy> requires Idable<Item> && IdGenerator<GeneratorStrategy>
ServiceInterface<Item, GeneratorStrategy>::~ServiceInterface()
{
	// For each item
	for (const auto& [key, item] : m_itemStore)
	{
		// Delete the item in memory
		delete item;	
	}
}

