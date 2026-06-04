/* Appointment.java
 * Author: Michael Kik
 * Date: 6-10-2025
 * Course ID: CS-320
 *
 * Appointment class. Represents an appointment with a date and description
 *
 */
package org.snhu;

import java.util.Date;

class Appointment {
	// Private
	private String m_id;	
	private Date m_date;
	private String m_description;

	// Set the ID. Throws an error if the string does not match required criteria
	private void setID(String t_id) {
		if (t_id == null) {
			throw new IllegalArgumentException("Invalid ID: Null");
		} else if (t_id.length() > 10) {
			throw new IllegalArgumentException("Invalid ID");
		}

		m_id = t_id;
	};

	// Set the date. Throws an error if null or the date is in the past
	private void setDate(Date t_date) {
		if (t_date == null) {
			throw new IllegalArgumentException("Invalid Date: Null");
		}
		else if ( t_date.before(new Date())) {
			throw new IllegalArgumentException("Invalid Date");
		}

		m_date = t_date;
	}

	// Set the description. Throws an error if null or too long
	private void setDescription(String t_description) {
		if ( t_description == null ) {
			throw new IllegalArgumentException("Invalid Description: Null");
		} else if (t_description.length() > 50) {
			throw new IllegalArgumentException("Invalid Description");
		}

		m_description = t_description;
	}

	// Constructor to create a new Appointment
	public Appointment(String t_id, Date t_date, String t_description) {
		setID(t_id);
		setDate(t_date);
		setDescription(t_description);
	}

	// Copy constructor
	public Appointment(Appointment t_appointment) {
		setID(t_appointment.getID());
		setDate(t_appointment.getDate());
		setDescription(t_appointment.getDescription());
	}

	// return the ID
	public String getID() {
		return m_id;
	}

	// return the date
	public Date getDate() {
		return m_date;
	}

	// return the description
	public String getDescription() { 
		return m_description;
	}
};
