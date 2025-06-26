/* Task.java
 * Author: Michael Kik
 * Date: 6-11-2025
 * Course ID: CS-320
 * 
 * Implementation for an class that represents a task
 * Each task has a name and description
 * 
 * Note that member variables start with m_ prefix. Function parameters start with t_ prefix
 *
 */

package org.snhu;

public class Task
{
	// private
	private String m_id;
	private String m_name;
	private String m_description;

	private void setId(String t_id) {
		if (t_id == null ) {
			throw new IllegalArgumentException("Invalid Input: Null");
		} else if (t_id.length() > 10) {
			throw new IllegalArgumentException("Invalid Input");
		}

		m_id = t_id;
	}

	//public
	public static enum Field {  // Enum to help with the Task Service
		ID,
		NAME,
		DESCRIPTION
	}

	// Constructor takes in all necessary information at creation
	public Task(String t_id, String t_name, String t_description) {
		// Use the setters to set member variables
		setId(t_id);
		setName(t_name);
		setDescription(t_description);
	}

	// Copy constructor
	public Task(Task t_taskToCopy) {
		setId(t_taskToCopy.getId());
		setName(t_taskToCopy.getName());
		setDescription(t_taskToCopy.getDescription());
	}

	// Getters
	public String getId() { return m_id; }
	public String getName() { return m_name; }
	public String getDescription() { return m_description; }

	// Setters
	public void setName(String t_name) {
		if (t_name == null ) {
			throw new IllegalArgumentException("Invalid Input: Null");
		} else if (t_name.length() > 20) {
			throw new IllegalArgumentException("Invalid Input");
		};

		m_name = t_name;
	}

	public void setDescription(String t_description) {
		if (t_description == null ) {
			throw new IllegalArgumentException("Invalid Input: Null");
		} else if (t_description.length() > 50) {
			throw new IllegalArgumentException("Invalid Input");
		};

		m_description = t_description;
	}
}
