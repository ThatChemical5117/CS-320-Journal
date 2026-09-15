#pragma once
/* AppointmentService.h
 * Date: 9-9-2026
 * Author: Michael Kik
 * Course ID: CS-320, CS-499
 *
*/

#include "Interface/ServiceInterface.h"
#include "Model/Appointment.h"
#include "Impl/LinerIdGenerator.h"

class AppointmentService: public ServiceInterface<Appointment, LinerIdGenerator>
{
public:
	static AppointmentService* GetInstance();
	std::optional<std::string> AddAppointment(const std::chrono::year_month_day& date, const std::string& description);

private:
	static AppointmentService* m_serviceInstance;
	AppointmentService() = default;
};
