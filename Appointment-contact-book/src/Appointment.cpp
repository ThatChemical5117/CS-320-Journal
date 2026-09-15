#include "Model/Appointment.h"
#include <stdexcept>

/* Appointment.cpp
 *
 * Appointment class implementation
 * Does extra handling for Dates
 */

// Constructor may throw an exception
Appointment::Appointment(const std::string& id, const std::chrono::year_month_day& date, const std::string& description) noexcept(false)
{
	this->SetId(id);
	this->SetDate(date);
	this->SetDescription(description);
};

void Appointment::SetId(const std::string& id) noexcept(false)
{
	// Do a check on the item
	if (id.length() == 0)
		throw std::invalid_argument("ID should not be empty");
	if (id.length() > 10)
		throw std::length_error("ID should be less than 10 characters in length");

	// Set the id
	m_id = id;
}

void Appointment::SetDate(const std::chrono::year_month_day& date) noexcept(false)
{
	if (!date.ok())
		throw std::invalid_argument("Invalid Date");
	if (date <= std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()))
		throw std::invalid_argument("Date is in the past");

	m_date = date;
};

void Appointment::SetDescription(const std::string& description) noexcept(false)
{
	if (description.length() == 0)
		throw std::invalid_argument("Description should not be empty");
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
const std::chrono::year_month_day& Appointment::GetDate() const noexcept
{
	return m_date;
}

const std::string_view Appointment::GetDescription() const noexcept
{
	return m_description;
};
