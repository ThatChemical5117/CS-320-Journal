#include "Service/TaskService.h"

#include <iostream>

TaskService* TaskService::m_instance = nullptr;
TaskService* TaskService::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new TaskService;

	return m_instance;
}

std::optional<std::string> TaskService::AddTask(const std::string& name, const std::string& description)
{
	try
	{
		std::string id = std::to_string(m_idGenerator.GenerateId());
		Task* newTask = new Task { id, name, description };

		m_itemStore.emplace(id, newTask);

		return id;
	} catch (const std::exception& e) {
		std::cout << "Could not create new task\n\t";
		std::cout << e.what() << std::endl;
		return {};
	}
};

void TaskService::UpdateTask(const std::string& id, const Task::Fields field, const std::string& data)
{
	if (!HasItem(id))
		return;
	
	Task* taskToUpdate = m_itemStore.at(id);

	try
	{
		switch(field)
		{
			case Task::Fields::NAME:
				taskToUpdate->SetName(data);
				break;
			case Task::Fields::DESCRIPTION:
				taskToUpdate->SetDescription(data);
				break;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Could not update task\n\t";
		std::cout << e.what() << std::endl;
		return;
	};
};
