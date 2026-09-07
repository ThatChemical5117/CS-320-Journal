/* ContactServiceTest.java
 * Author: Michael Kik
 * Date: 6-12-2025
 * Course ID: CS-320
 *
 * Test file for ContactService.java, tests the public functions
 * to make sure they meet the requirements set by the project 1 rubric
 *
 *
 */
package org.snhu;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeAll;

import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNotEquals;

class ContactServiceTest
{

	// Holds the singleton
	public static ContactService serviceInstance;

	@BeforeAll
	static void createContactService()
	{
		// get the service instance
		serviceInstance = ContactService.getInstance();		

		// add contacts for testing
		serviceInstance.addContact("John", "Doe", "2393334444", "123 Elm st");
		serviceInstance.addContact("Jane", "Doe", "2484442222", "125 Elm st");
		serviceInstance.addContact("Jordan", "James", "4232328893", "452 Elm st");
		serviceInstance.addContact("Michael", "Jorden", "3434442533", "3222 Oak Ave");
	}

	@Test
	void testGetContact() {
		assertNotNull(serviceInstance.getContact("2"));
		assertNull(serviceInstance.getContact("44"));
	}

	@Test
	void testAddContact()
	{
		
		// add a new contact
		serviceInstance.addContact("Michael", "Jackson", "3334442233", "3422 Elm Ave");
		// test if all contacts are present
		assertNotNull(serviceInstance.getContact("2"));
		assertNotNull(serviceInstance.getContact("3"));
		assertNotNull(serviceInstance.getContact("4"));

	}

	@Test
	void testDeleteContact() {
		assertNotNull(serviceInstance.getContact("1"));

		// delete and assert the contact is not there
		serviceInstance.deleteContact("1");
		assertNull(serviceInstance.getContact("1"));
	}

	@Test
	void testUpdateContact() {
		// Update the different fields
		Contact contactCopy = serviceInstance.getContact("2");
		Contact contactCopy_2 = serviceInstance.getContact("3");
		Contact contactCopy_3 = serviceInstance.getContact("4");

		serviceInstance.updateContact("2", Contact.Field.LASTNAME, "Smith");
		assertNotEquals(contactCopy, serviceInstance.getContact("2"));

		serviceInstance.updateContact("3", Contact.Field.FIRSTNAME, "Janet");
		assertNotEquals(contactCopy_2, serviceInstance.getContact("3"));

		serviceInstance.updateContact("4", Contact.Field.ADDRESS, "124322 Oak ln");
		assertNotEquals(contactCopy_3, serviceInstance.getContact("4"));
	}

}
