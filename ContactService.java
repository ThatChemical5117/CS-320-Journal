/* ContactService.java Author: Michael Kik
 * Date: 10-11-2025
 * Course ID: CS-320
 *
 * Contact service class. Creates, edits, and deletes internally stored contacts
 * This class is a Singleton
 */
package org.snhu;

import java.util.HashMap;

// Singleton design pattern
class ContactService
{
	// private
	private static ContactService m_instance = null;
	private static int m_id = 1;
	
	private HashMap<String, Contact> m_contactStore = null;
	private ContactService(){ // Private constructor
		m_contactStore = new HashMap<String, Contact>();
	};

	//  gets the next id
	private static String getNextId() {
		return String.valueOf(m_id++);
	}


	// Singleton design pattern
	public static ContactService getInstance() { 
		if ( m_instance == null ) {
			m_instance = new ContactService();
		}

		return m_instance;
	}

	public void addContact(String t_firstName, String t_lastName, String t_phoneNumber, String t_address) {
		String id = getNextId();
		m_contactStore.put(id,new Contact(id, t_firstName, t_lastName, t_phoneNumber, t_address)); // the contact to the hashmap
	}

	public void deleteContact(String t_id) {
		m_contactStore.remove(t_id); // remove contact
	}

	public void updateContact(String t_id, Contact.Field t_field, String t_data)
	{
		// Holds a reference to the contact
		Contact toUpdate = m_contactStore.get(t_id);

		// Uses the enum to determine which field gets updated
		switch (t_field)
		{
			case FIRSTNAME:
				toUpdate.setFirstName(t_data);
				break;
			case LASTNAME:
				toUpdate.setLastName(t_data);
				break;
			case PHONENUMBER: 
				toUpdate.setPhoneNumber(t_data);
				break;
			case ADDRESS:
				toUpdate.setAddress(t_data);
				break;
		}
	}

	// returns a contact
	public Contact getContact(String t_id)
	{
		// return null if there is no contact
		if (m_contactStore.get(t_id) == null ) return null;
		// otherwise create a copy of the contact object
		return new Contact(m_contactStore.get(t_id));
	}

}
