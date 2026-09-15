#include "Service/AppointmentService.h"

#include <iostream>


// Static variable initialization
AppointmentService* AppointmentService::m_serviceInstance = nullptr;

AppointmentService* AppointmentService::GetInstance()
{
	if (m_serviceInstance == nullptr)
		m_serviceInstance = new AppointmentService;
	return m_serviceInstance;
}

// return an optional string to indicate that the appointment was added
std::optional<std::string> AppointmentService::AddAppointment(const std::chrono::year_month_day& date, const std::string& description)
{
	std::string ID = std::to_string(m_idGenerator.GenerateId());
	Appointment* appointment = nullptr;
	
	// Attempt to create a new appointment
	try
	{
		appointment = new Appointment { ID, date, description };		
	} catch (const std::exception& e){
		std::cout << "Could not create new appointment";
		std::cout << e.what();
		return {};
	}

	// New appointment
	m_itemStore.emplace(ID, appointment);
	return ID;
}

