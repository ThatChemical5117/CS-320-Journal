#include "Model/Appointment.h"
#include <stdexcept>

/* Appointment.cpp
 *
 * Appointment class implementation
 * Does extra handling for Dates
 */

// Constructor may throw an exception
Appointment::Appointment(const std::string& id, const Date& date, const std::string& description) noexcept(false)
{
	this->SetId(id);
	this->SetDate(date);
	this->SetDescription(description);
};

void Appointment::SetId(const std::string& id) noexcept(false)
{
	// Do a check on the item
	if (id.length() > 10)
		throw std::length_error("ID should be less than 10 characters in length");

	// Set the id
	m_id = id;
}

void Appointment::SetDate(const Date& date) noexcept(false)
{
	// TODO: Throw custom date exception
	if (!date.ok()) return;

	// TODO: Add check that the date is in the future for new Appointments
	m_date = date;
};

void Appointment::SetDescription(const std::string& description) noexcept(false)
{
	if (description.length() > 50)
		throw std::length_error("Description should be less than 50 characters long");

	m_description = description;
}

// Return string_views to prevent pointless copying
const std::string_view Appointment::GetId() const noexcept
{
	return m_id;
}

// Return a const reference to m_date
const Date& Appointment::GetDate() const noexcept
{
	return m_date;
}

const std::string_view Appointment::GetDescription() const noexcept
{
	return m_description;
};
