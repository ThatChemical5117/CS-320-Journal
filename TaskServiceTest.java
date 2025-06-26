/* TaskServiceTest.java
 * Author: Michael Kik
 * Date: 6-11-25
 *
 * Test File for TaskService.java
 * Tests the functionality of the TaskService class against
 * the requirements set forth by the module 4 milestone assignment
 *
 * I added additional tests that I felt were necessary
 * to make sure that the class behaves in a secure and predictable way
 */

package org.snhu;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeAll;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertNotEquals;

class TaskServiceTest  {

	// To hold the instance for the duration of the test
	private static TaskService m_taskService;

	// We setup a new task service and preload a task into the service object
	// We then use this for testing
	@BeforeAll
	static void createTaskService() {
		m_taskService = TaskService.getInstance();

		m_taskService.addTask("Write unit tests", "Create good unit tests");
		m_taskService.listTasks();

	}

	// Tests the completeness of the get task function to make sure it can return tasks that
	// are in the internal data structure. And returns null if there is no task at the point.
	@Test 
	void testGetTask() {
		assertNotNull(m_taskService.getTask("1"));
		assertNull(m_taskService.getTask("22"));
	}

	// Test the add task function, makes sure that the task gets added
	// to the internal data structure
	@Test
	void testAddTask() {
		m_taskService.addTask("Do CourseWork", "Complete Coursework for CS320");

		assertNotNull(m_taskService.getTask("2"));
	}

	// Test the delete task to make sure that the function
	// removes the task
	@Test
	void testDeleteTask() {
		m_taskService.deleteTask("2");
		assertNull(m_taskService.getTask("2"));
	}

	@Test
	void testUpdateFields() {
		Task task = new Task(m_taskService.getTask("1"));

		m_taskService.updateTask("1", Task.Field.NAME, "Change unit Test");
		assertNotEquals(task, m_taskService.getTask("1"));
	}

	// Extra test to make sure that the internal tasks in the class
	// cannot be changed by outside code
	@Test
	void testTaskChangedFromOutside() {
		Task task = m_taskService.getTask("1");	
		task.setName("Changed from outside");

		assertNotEquals(m_taskService.getTask("1"), task);
	}
}
