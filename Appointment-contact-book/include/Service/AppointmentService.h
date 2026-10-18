#pragma once
/* AppointmentService.h
 * Date: 9-9-2026
 * Author: Michael Kik
 * Course ID: CS-320, CS-499
 * 
 * Appointment Service class - extends the Service Interface class
 * and is also a singleton. Fills out the Template arguments as well
*/

#include "Interface/ServiceInterface.h"
#include "Model/Appointment.h"
#include "Impl/LinerIdGenerator.h"

class AppointmentService: public ServiceInterface<Appointment, LinearIdGenerator>
{
public:
	static AppointmentService* GetInstance();
	std::optional<std::string> AddAppointment(const std::chrono::year_month_day& date, const std::string& description);

private:
	static AppointmentService* m_serviceInstance;
	AppointmentService() = default;
};
