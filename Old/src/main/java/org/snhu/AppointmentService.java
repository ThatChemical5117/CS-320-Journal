/* AppointmentService.java
 * Date: 10-12-2025
 * Author: Michael Kik
 * Coruse ID: CS-320
 *
 * AppointmentService class. Handles and controls individual appointment objects
 * by creating and deleting them.
 */
package org.snhu;

import java.util.Date;
import java.util.HashMap;

class AppointmentService {
	
	// private
	private static AppointmentService m_serviceInstance = null; // singleton instance
	private static int m_id = 1;// ID tracker

	private HashMap<String, Appointment> m_appointmentStore;// Appointment storage

	// get a new ID, increments the m_id variable
	private static int getNextId() {
		return m_id++;
	}

	// Private constructor
	private AppointmentService() {
		m_appointmentStore = new HashMap<String, Appointment>();
	}

	// return an instance of the service. call the constructor if it hasn't already
	public static AppointmentService getInstance() {
		if (m_serviceInstance == null) {
			m_serviceInstance = new AppointmentService();
		}

		return m_serviceInstance;
	}

	// Add a new appointment
	public void addAppointment(Date t_date, String t_description) {
		String id = String.valueOf(getNextId());
		m_appointmentStore.put(id, new Appointment(id, t_date, t_description));
	}

	// remove an appointment by id
	public void deleteAppointment(String t_id) {
		m_appointmentStore.remove(t_id);
	};


	// return an appointment by id.
	public Appointment getAppointment(String t_id) {
		// return null if there is no appointment
		if (m_appointmentStore.get(t_id) == null) return null;
		// otherwise create a copy of the appointment object
		return new Appointment(m_appointmentStore.get(t_id));
	}
};
