package org.snhu;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertThrows;

class ContactTest
{
	@Test
	void testContact()
	{
		Contact contact = new Contact("1", "John", "Doe", "5555555555", "123 Elm St");


		assertTrue(contact.getId().equals("1"));
		assertTrue(contact.getFirstName().equals("John"));
		assertTrue(contact.getLastName().equals("Doe"));
		assertTrue(contact.getPhoneNumber().equals("5555555555"));
		assertTrue(contact.getAddress().equals("123 Elm St"));
		
	}

	@Test
	void testIncorrectLength(){
		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("11111111111", "John", "Doe", "5555555555", "123 Elm St");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("1", "John Doe Henry Smith", "Doe ", "5555555555", "123 Elm St");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("1", "John", "Doe Smith goldberg Doe", "5555555555", "123 Elm St");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("1", "John", "Doe", "555555555", "123 Elm St");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("1", "John", "Doe", "5555555555", "123 Elm St, Cape Coral FL, 33293 United States of America");
		});

	}

	@Test
	void testNullInputs(){
		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact(null, "John", "Doe", "5555555555", "123 Elm St");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("1", null, "Doe", "5555555555", "123 Elm St");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("1", "John", null, "5555555555", "123 Elm St");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("1", "John", "Doe", null, "123 Elm St");
		});

		assertThrows(IllegalArgumentException.class, () -> {
			Contact contact = new Contact("1", "John", "Doe", "5555555555", null);
		});

	}
}
