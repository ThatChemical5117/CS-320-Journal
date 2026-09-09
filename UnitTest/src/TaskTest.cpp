#include <stdexcept>
#include "Model/Task.h"

#include <gtest/gtest.h>

/* TaskTest.cpp
 * Author: Michael Kik
 * Date: 9-8-2026
 * Course ID: CS-250
 *
 * Test file for Test.h
 * Tests the functionality of the task class along with various edge cases
 */


class TaskTest : public testing::Test
{
protected:
	TaskTest()
		: m_task { "001", "Task", "Assignment" }
	{};


	Task m_task;
};

TEST_F(TaskTest, generalfunctionality)
{
	EXPECT_TRUE(m_task.GetId().compare("001") == 0);
	EXPECT_TRUE(m_task.GetName().compare("Task") == 0);
	EXPECT_TRUE(m_task.GetDescription().compare("Assignment") == 0);
};

// Test against fields that are too long
TEST_F(TaskTest, FieldsToLong) {
	ASSERT_THROW(m_task.SetId("123123123411"), std::length_error);
	ASSERT_THROW(m_task.SetName("Task that I need to Do right now"), std::length_error);
	ASSERT_THROW(m_task.SetDescription("Thing I must do right now, with no exceptions, I really need to do this task"), std::length_error);
}

// Test against empty strings
TEST_F(TaskTest, EmptyStrings) {
	ASSERT_THROW(m_task.SetId(""), std::invalid_argument);
	ASSERT_THROW(m_task.SetName(""), std::invalid_argument);
	ASSERT_THROW(m_task.SetDescription(""), std::invalid_argument);
}
