#pragma once
/* Appointment.h
 * Author: Michael Kik
 * Date: 9-7-2026
 * Course ID: CS-320, CS-499
 *
 * Appointment class. Represents an appointment with a data and description
 * Ported from Java to C++
*/

#include <string>
#include <chrono>

// Use alias for the date field
using Date = std::chrono::year_month_day; // (C++20 feature)

class Appointment
{
public:
	// Constructor - marked to show the consumer that this constructor
	// can throw an exception
	Appointment(const std::string& id, const Date& date, const std::string& description) noexcept(false);

	// Setters - marked to make sure the consumer knows these can throw an exception
	void SetId(const std::string& id) noexcept(false);
	void SetDate(const Date& date) noexcept(false);
	void SetDescription(const std::string& description) noexcept(false);

	// Getters	
	const std::string_view GetId() const noexcept;
	const Date& GetDate() const noexcept;
	const std::string_view GetDescription() const noexcept;

private:
	std::string m_id;
	Date m_date;
	std::string m_description;
};
