#include "Impl/TaskFactory.h"
#include "Service/TaskService.h"
#include "nlohmann/json.hpp"

TaskFactory* TaskFactory::m_factoryInstance = nullptr;

TaskFactory* TaskFactory::GetInstance() noexcept
{
	if (m_factoryInstance == nullptr)
		m_factoryInstance = new TaskFactory;
	return m_factoryInstance;
};

void TaskFactory::FromSource(const nlohmann::json& object)
{
	TaskService::GetInstance()->AddTask(object.at("name"), object.at("description"));
};

nlohmann::json TaskFactory::ToSource(const Task* task)
{
	if (task != nullptr) return TaskToJson(*task);
	nlohmann::json document = nlohmann::json::array();
	
	TaskService::GetInstance()->ForEach([this, &document](const Task& task) ->void{
		document.push_back(TaskToJson(task));
	});

	return document;
}

nlohmann::json TaskFactory::TaskToJson(const Task& task)
{
	return nlohmann::json::object({
		{"name", static_cast<std::string>(task.GetName()) },
		{ "description", static_cast<std::string>(task.GetDescription()) }
	});
};
