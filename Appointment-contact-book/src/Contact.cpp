#include "Model/Contact.h"
#include <stdexcept>


Contact::Contact(const std::string& id, const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::string& address) noexcept(false)
{
	this->SetId(id);
	this->SetFirstName(firstName);
	this->SetLastName(lastName);
	this->SetPhoneNumber(phoneNumber);
	this->SetAddress(address);
};

// Setters
void Contact::SetId(const std::string& id) noexcept(false)
{
	if (id.length() > 10)
		throw std::length_error("ID should be less than 10 characters long");

	m_id = id;
};

void Contact::SetFirstName(const std::string& firstName) noexcept(false)
{
	if (firstName.length() > 15)
		throw std::length_error("First Name should be less than 15 characters long");

	m_firstName = firstName;
};

void Contact::SetLastName(const std::string& lastName) noexcept(false)
{
	if (lastName.length() > 15)
		throw std::length_error("Last Name should be less than 15 characters long");

	m_lastName = lastName;
};

void Contact::SetPhoneNumber(const std::string& phoneNumber) noexcept(false)
{
	if (phoneNumber.length() != 10)
		throw std::length_error("Phone number should be exactly 10 characters long");

	m_phoneNumber = phoneNumber;
};

void Contact::SetAddress(const std::string& address) noexcept(false)
{
	if (address.length() > 50)
		throw std::length_error("Address should be less than 50 characters long");
};

// Getters
const std::string_view Contact::GetId() const noexcept
{
	return m_id;
}

const std::string_view Contact::GetFirstName() const noexcept
{
	return m_firstName;
}

const std::string_view Contact::GetLastName() const noexcept
{
	return m_lastName;
}

const std::string_view Contact::GetPhoneNumber() const noexcept
{
	return m_phoneNumber;
}

const std::string_view Contact::GetAddress() const noexcept
{
	return m_address;
}
