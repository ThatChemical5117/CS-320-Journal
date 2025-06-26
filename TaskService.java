/* TaskService.java
 * Author: Michael Kik
 * Date: 6-11-2025
 * Course ID: CS-320
 *
 * Task service class implementation. Uses singleton design pattern to prevent multiple "services" to be active at once.
 * Task service controls how new tasks are created, updated, and deleted
 *
 */
package org.snhu;

import java.util.HashMap;

public class TaskService {
	// Private
	private static TaskService m_serviceInstance = null;
	private static int m_id = 1;

	private HashMap<String, Task> m_taskStore = null;

	// Get a new ID
	private static int getNextId() {
		return m_id++;
	}

	// Constructor is private to prevent new instances being created without the
	// getInstance function controlling it. 
	private TaskService() {
		m_taskStore = new HashMap<String, Task>();
	}

	// Public	
	// Get instance return a new TaskService if there is not one already created
	// otherwise it returns a reference to one that was already created
	public static TaskService getInstance() {
		if (m_serviceInstance == null ) {
			m_serviceInstance = new TaskService();
		}

		return m_serviceInstance;
	}

	// Getter We want to return a copy of the task
	public Task getTask(String t_id) { 
		// return null if there is no task
		if (m_taskStore.get(t_id) == null) return null;
		//otherwise return a copy of the task object
		return new Task(m_taskStore.get(t_id));
	}

	// Add a new task with a unique key
	public void addTask(String t_name, String t_description) {
		int key = getNextId();
		m_taskStore.put(String.valueOf(key), new Task(String.valueOf(key), t_name, t_description));
	};

	// Remove a task using a key
	public void deleteTask(String t_id) {
		m_taskStore.remove(t_id);
	};

	// update a task
	public void updateTask(String t_id, Task.Field t_field, String t_data) {
		Task task = m_taskStore.get(t_id);

		switch (t_field) {
			case NAME:
				task.setName(t_data);
				break;
			case DESCRIPTION:
				task.setDescription(t_data);
				break;
			default:
				break;
		}

	}

	// print out a list of the tasks
	public void listTasks() {
		for (Task task : m_taskStore.values()) {
			System.out.println("ID: " + task.getId());
			System.out.println("\tName: " + task.getName());
			System.out.println("\tDescription " + task.getDescription());
		}
	};

};
