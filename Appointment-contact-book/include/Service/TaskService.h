#pragma once

#include <string>
#include <optional>

#include "Model/Task.h"
#include "Interface/ServiceInterface.h"
#include "Impl/LinerIdGenerator.h"

class TaskService: public ServiceInterface<Task, LinerIdGenerator>
{
public:
	static TaskService* GetInstance();

	std::optional<std::string> AddTask(const std::string& name, const std::string& description);
	void UpdateTask(const std::string& id, Task::Fields field, const std::string& data);
private:
	TaskService() = default;
	static TaskService* m_instance;
};
