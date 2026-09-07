#include "Model/Task.h"
#include <stdexcept>

Task::Task(const std::string& id, const std::string& name, const std::string& description) noexcept(false)
{}
	
	// Mutators
void Task::SetId(const std::string& id) noexcept(false)
{
	if (id.length() > 10)
		throw std::length_error("ID should be less than 10 characters long");
	m_id = id;
}

void Task::SetName(const std::string& name) noexcept(false)
{
	if (name.length() > 20)
		throw std::length_error("Name should be less than 20 characters long");

	m_name = name;
}

void Task::SetDescription(const std::string& description) noexcept(false)
{
	if (description.length() > 50)
		throw std::length_error("Description should be less than 50 characters long");

	m_description = description;
}

	// Getters
const std::string_view Task::GetId() const noexcept { return m_id; };
const std::string_view Task::GetName() const noexcept { return m_name; }
const std::string_view Task::GetDescription() const noexcept { return m_description; }
