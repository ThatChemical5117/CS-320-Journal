#pragma once
/* Contact.h
 * Author: Michael Kik
 * Date: 9-7-2026
 * Course ID: CS-320, CS-499
 *
 * Contact class represents a contact with a unique ID. The contact can hold a first name, last name, phonenumber, and address.
 */

#include <string>

class Contact
{
public:
	Contact(const std::string& id, const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::string& address) noexcept(false);

	// Setters
	void SetId(const std::string& id) noexcept(false);
	void SetFirstName(const std::string& firstName) noexcept(false);
	void SetLastName(const std::string& lastName) noexcept(false);
	void SetPhoneNumber(const std::string& phoneNumber) noexcept(false);
	void SetAddress(const std::string& address) noexcept(false);

	// Getters
	const std::string_view GetId() const noexcept;
	const std::string_view GetFirstName() const noexcept;
	const std::string_view GetLastName() const noexcept;
	const std::string_view GetPhoneNumber() const noexcept;
	const std::string_view GetAddress() const noexcept;

private:
	std::string m_id;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_phoneNumber;
	std::string m_address;
};
