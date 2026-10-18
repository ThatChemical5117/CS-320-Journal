#pragma once
/* TaskService.h
 * Date: 9-9-2026
 * Author: Michael Kik
 * Course Id: CS-320, CS-499
 *
 * Task Service class - extends the Service Interface to allow for adding new tasks
 * and editing them. This class is a singleton
*/

#include <string>
#include <optional>

#include "Model/Task.h"
#include "Interface/ServiceInterface.h"
#include "Impl/LinerIdGenerator.h"

class TaskService: public ServiceInterface<Task, LinearIdGenerator>
{
public:
	static TaskService* GetInstance();

	// Extended functionality
	std::optional<std::string> AddTask(const std::string& name, const std::string& description);
	void UpdateTask(const std::string& id, Task::Fields field, const std::string& data);
private:
	TaskService() = default;
	static TaskService* m_instance;
};
