#include <gtest/gtest.h>

#include "nlohmann/json.hpp"
#include "Model/Task.h"
#include "Impl/TaskFactory.h"
#include "Service/TaskService.h"

class TaskFactoryTest: public testing::Test
{
protected:
	TaskFactoryTest()
	{
		m_original = nlohmann::json::object(
		{
			{"name", "Todo" },
			{"description", "Task To Do" }
		});
	}

	TaskFactory* m_factory = TaskFactory::GetInstance();
	TaskService* m_service = TaskService::GetInstance();
	nlohmann::json m_original;

};

TEST_F(TaskFactoryTest, FromJson)
{
	m_factory->FromSource(m_original);

	const std::string name = m_original.at("name");
	const std::string description = m_original.at("description");

	const Task* task = m_service->GetItem("1");

	ASSERT_EQ(task->GetName().compare(name), 0);
	ASSERT_EQ(task->GetDescription().compare(description), 0);
};

TEST_F(TaskFactoryTest, ToJson)
{
	nlohmann::json task = m_factory->ToSource(m_service->GetItem("1"));

	ASSERT_EQ(task, m_original);
};

