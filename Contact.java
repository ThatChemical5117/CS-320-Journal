/* Contact.java
 * Author: Michael Kik
 * Date: 6-10-2025
 * Course ID: CS-320
 * 
 * Contact class represents a contact with a unique ID. The contact can hold a first name, last name, phonenumber, and address.
 * Class throws errors when bad inputs are given
 */

package org.snhu;


public class Contact
{
	// private members
	private String m_id;
	private String m_firstName;
	private String m_lastName;
	private String m_phoneNumber;
	private String m_address;

	// private functions
	// Set id internal use only
	private void setId(String t_id) {
		if (t_id == null) {
			throw new IllegalArgumentException("Invalid Input ID: Null");
		} else if (t_id.length() > 10) {
			throw new IllegalArgumentException("Invalid Input ID");
		} 

		m_id = t_id;
	}

	// Public functions
	
	// Public enum to show available fields
	public enum Field {
		FIRSTNAME,
		LASTNAME,
		PHONENUMBER,
		ADDRESS
	}

	public Contact(String t_id, String t_firstName, String t_lastName, String t_phoneNumber, String t_address){

		// Set all private fields with the setters
		setId(t_id);
		setFirstName(t_firstName);
		setLastName(t_lastName);
		setPhoneNumber(t_phoneNumber);
		setAddress(t_address);
	}

	// For deep copy
	public Contact(Contact t_contact)
	{
		// copy the strings from another object into this new object
		setId(t_contact.getId());
		setFirstName(t_contact.getFirstName());
		setLastName(t_contact.getLastName());
		setPhoneNumber(t_contact.getPhoneNumber());
		setAddress(t_contact.getAddress());
	};

	// Getters - return the strings
	public String getId(){ return m_id; };
	public String getFirstName() { return m_firstName; };
	public String getLastName() { return m_lastName; };
	public String getPhoneNumber() { return m_phoneNumber; };
	public String getAddress() { return m_address; };

	
	// setters
	public void setFirstName(String t_firstName) {
		if (t_firstName == null) {
			throw new IllegalArgumentException("Invalid Input: Null");
		} else if (t_firstName.length() > 10) {
			throw new IllegalArgumentException("Invalid Input");
		}

		m_firstName = t_firstName;
	}
	
	public void setLastName(String t_lastName) {
		if (t_lastName == null) {
			throw new IllegalArgumentException("Invalid Input: Null");
		} else if (t_lastName.length() > 10) {
			throw new IllegalArgumentException("Invalid Input");
		}

		m_lastName = t_lastName;
	}

	
	public void setPhoneNumber(String t_phoneNumber) {
		if (t_phoneNumber == null) {
			throw new IllegalArgumentException("Invalid Input: Null");
		} else if (t_phoneNumber.length() != 10 ) {
			throw new IllegalArgumentException("Invalid Input");
		}

		m_phoneNumber = t_phoneNumber;
		
	}
	public void setAddress(String t_address) {
		if (t_address == null) {
			throw new IllegalArgumentException("Invalid Input: Null");
		} else if ( t_address.length() > 50) {
			throw new IllegalArgumentException("Invalid Input");
		}

		m_address = t_address;
	}

}
