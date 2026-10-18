#pragma once
/* AppointmentFactory.h
 * Author: Michael Kik
 * Date: 09-18-0226
 * Course ID: CS-499
 * 
 * Appointment factory class produces Appointment object from a JSON object
 * This class uses nlohmann::json object to achieve this. This class has no knowledge of
 * any file or file system
 */


#include "Model/Appointment.h"
#include "Interface/IdableFactoryInterface.h"
#include "nlohmann/json_fwd.hpp"


class AppointmentFactory: public IdableFactoryInterface<Appointment, nlohmann::json>
{
public:
	static AppointmentFactory* GetInstance();

	void FromSource(const nlohmann::json& object) override;
	nlohmann::json ToSource(const Appointment* appointmnet) override;

private:
	static AppointmentFactory* m_instance;
	AppointmentFactory() = default;

	nlohmann::json AppointmentToJson(const Appointment& appointment);

	std::chrono::year_month_day StringToDate(const std::string& date) const;
	std::string DateToString(const std::chrono::year_month_day& date) const;
};
