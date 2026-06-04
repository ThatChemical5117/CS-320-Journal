/* TaskTest.java
 * Author: Michael Kik
 * Date: 6-11-25
 * Course ID: CS-250
 *
 * Test file for Task.java
 * Tests the functionality of the Task class against the requirements
 * set by the module 4 milestone
 *
 */
package org.snhu;

// imports
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertThrows;


class TaskTest
{
	// Test the general functionality of the class
	@Test
	void testTask() {
		Task task = new Task("1234512", "Task To Do", "Thing I must do");

		assertTrue(task.getId().equals("1234512"));
		assertTrue(task.getName().equals("Task To Do"));
		assertTrue(task.getDescription().equals("Thing I must do"));
	}

	// Test against inputs that are too long
	@Test
	void testFieldsToLong() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Task("12345678910", "Task To Do", "Thing I must do");
		});

		assertThrows(IllegalArgumentException.class, () -> { 
			new Task("12345", "Task That I need To Do right now", "Thing I must do");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			new Task("123", "Task To do", "Thing I must do right now, with no exceptions, I really need to do this task");
		});
	}

	// Test against null inputs
	@Test
	void testNotNull() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Task(null, "Task To Do", "Thing I must do");
		});

		assertThrows(IllegalArgumentException.class, () -> { 
			new Task("12345", null, "Thing I must do");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			new Task("123", "Task To do", null);
		});

	}

}
