/* AppointmentServiceTest.java
 * Author: Michael Kik
 *
 * Test file for AppointmentService.java
 * Test the functionality of the AppointmentService class
 */
package org.snhu;

import java.util.Date;

// junit imports
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeAll;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

class AppointmentServiceTest {

	// private - holds the singlton instance for all tests
	static AppointmentService service;
	
	@BeforeAll // initialize the service 
	static void initService() {
		service = AppointmentService.getInstance();
		service.addAppointment(new Date(100000000000000L), "Appointment!!");
	};

	@Test
	void testGetAppointment() { // test the get appointment function
		assertNotNull(service.getAppointment("1"));
		assertNull(service.getAppointment("33"));
	}

	@Test // test add appointment function
	void testAddAppointment() {
		service.addAppointment(new Date(100000000000000L), "Appointment?");
		assertNotNull(service.getAppointment("2"));
	}

	@Test // test delete appointment function
	void deleteAppointment() {
		service.deleteAppointment("2");
		assertNull(service.getAppointment("2"));
	}
}
