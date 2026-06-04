/* AppointmentTest.java
 * Author: Michael Kik
 *
 * Test file for Appointment.java
 * Test the functionality of the appointment class
 *
 */
package org.snhu;

import java.util.Date;

// junit imports
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertThrows;

class AppointmentTest {

	@Test  // Test basic functionality of the appointment class
	void testAppointmentClass() {
		Appointment appointment = new Appointment("12", new Date(10000000000000L), "Appointment");

		assertTrue(appointment.getID().equals("12"));
		assertTrue(appointment.getDate().equals(new Date(10000000000000L)));
		assertTrue(appointment.getDescription().equals("Appointment"));
	}

	@Test  // test how the class handles invalid length arguments
	void testFieldLength() {
		assertThrows(IllegalArgumentException.class, () -> { 
			new Appointment("12345678912345", new Date(10000000000000L), "Appointment"); 
		});

		assertThrows(IllegalArgumentException.class, () -> {
			new Appointment("12", new Date(10000000000000L), "Appointment description is wayy too long. Surley this is long enough to trigger the error message"); 
		});
	}

	@Test // test how the class handles null inputs
	void testNullFeilds() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Appointment(null, new Date(10000000000000L), "Appointment");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			new Appointment("23", null, "Appointment");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			new Appointment("2", new Date(10000000000000L), null);
		});
	}

	@Test // test how the class handles invalid dates
	void testDateInPast() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Appointment("1", new Date(100L), "Desc");
		});
	}
}
