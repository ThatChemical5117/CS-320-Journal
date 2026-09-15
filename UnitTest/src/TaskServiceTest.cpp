#include <gtest/gtest.h>

#include "Model/Task.h"
#include "Service/TaskService.h"


class TaskServiceTest: public testing::Test
{
protected:
	TaskServiceTest()
	{
		m_serviceInstance = TaskService::GetInstance();

		Item1 = m_serviceInstance->AddTask("CS-499", "Port Java code to C++").value();
		Item2 = m_serviceInstance->AddTask("Write Test", "Write C++ unit tests using gtest").value();
		Item3 = m_serviceInstance->AddTask("Read book", "Read book about C++ template meta-programming").value();
	}

	std::string Item1, Item2, Item3;
	TaskService* m_serviceInstance;
};


TEST_F(TaskServiceTest, GetFunctionality)
{
	ASSERT_NE(m_serviceInstance->GetItem(Item1), nullptr);
	ASSERT_NE(m_serviceInstance->GetItem(Item2), nullptr);
}

TEST_F(TaskServiceTest, AddFunctionality)
{
	ASSERT_TRUE(m_serviceInstance->AddTask("Complete essay", "Finish essay for other course").has_value());
}

TEST_F(TaskServiceTest, UpdateFunctionality)
{
	Task taskCopy = *m_serviceInstance->GetItem(Item1);	

	m_serviceInstance->UpdateTask(Item1, Task::Fields::NAME, "Complete work");
	ASSERT_FALSE(taskCopy.GetName().compare(m_serviceInstance->GetItem(Item1)->GetName()) == 0);

	m_serviceInstance->UpdateTask(Item1, Task::Fields::DESCRIPTION, "Do course work for CS499");
	ASSERT_FALSE(taskCopy.GetDescription().compare(m_serviceInstance->GetItem(Item1)->GetDescription()) == 0);
}

TEST_F(TaskServiceTest, DeleteFunctionality)
{
	m_serviceInstance->DeleteItem(Item2);
	ASSERT_EQ(m_serviceInstance->GetItem(Item2), nullptr);
}
