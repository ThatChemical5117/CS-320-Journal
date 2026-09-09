#include "Model/Task.h"
#include <stdexcept>

Task::Task(const std::string& id, const std::string& name, const std::string& description) noexcept(false)
{
	SetId(id);
	SetName(name);
	SetDescription(description);
}
	
	// Mutators
void Task::SetId(const std::string& id) noexcept(false)
{
	if (id.length() > 10)
		throw std::length_error("ID should be less than 10 characters long");
	if (id.length() == 0)
		throw std::invalid_argument("ID shouldn't be empty");

	m_id = id;
}

void Task::SetName(const std::string& name) noexcept(false)
{
	if (name.length() > 20)
		throw std::length_error("Name should be less than 20 characters long");
	if (name.length() == 0)
		throw std::invalid_argument("Name shouldn't be empty");

	m_name = name;
}

void Task::SetDescription(const std::string& description) noexcept(false)
{
	if (description.length() > 50)
		throw std::length_error("Description should be less than 50 characters long");
	if (description.length() == 0)
		throw std::invalid_argument("Description shouldn't be empty");

	m_description = description;
}

	// Getters
const std::string_view Task::GetId() const noexcept { return m_id; };
const std::string_view Task::GetName() const noexcept { return m_name; }
const std::string_view Task::GetDescription() const noexcept { return m_description; }
