#pragma once
/* Task.h
 * Author: Michael Kik
 * Date: 9-7-2026
 * Course ID: CS-320, CS-499
 *
 * Task class definition. Represents a task
 * Each task has a name and description
 *
 * Ported from Java to C++
 */

#include <string>

class Task
{
public:
	Task(const std::string& id, const std::string& name, const std::string& description) noexcept(false);
	
	// Mutators
	void SetId(const std::string& id) noexcept(false);
	void SetName(const std::string& name) noexcept(false);
	void SetDescription(const std::string& description) noexcept(false);

	// Getters
	const std::string_view GetId() const noexcept;
	const std::string_view GetName() const noexcept;
	const std::string_view GetDescription() const noexcept;

private:
	std::string m_id;
	std::string m_name;
	std::string m_description;
};
