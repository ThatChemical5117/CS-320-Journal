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

class Appointment
{
public:
	// Constructor - marked to show the consumer that this constructor
	// can throw an exception
	Appointment(const std::string& id, const std::chrono::year_month_day& date, const std::string& description) noexcept(false);

	// Setters - marked to make sure the consumer knows these can throw an exception
	void SetId(const std::string& id) noexcept(false);
	void SetDate(const std::chrono::year_month_day& date) noexcept(false);
	void SetDescription(const std::string& description) noexcept(false);

	// Getters	
	const std::string_view GetId() const noexcept;
	const std::chrono::year_month_day& GetDate() const noexcept;
	const std::string_view GetDescription() const noexcept;

private:
	std::string m_id;
	std::chrono::year_month_day m_date;
	std::string m_description;
};
