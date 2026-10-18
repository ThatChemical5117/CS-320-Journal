#include <iostream>

#include "Model/Appointment.h"
#include "Impl/AppointmentFactory.h"
#include "Service/AppointmentService.h"
#include "Impl/JsonReadWriter.h"



int main()
{
	JsonReadWriter<Appointment> appointmentReader { "appointments.json" , AppointmentFactory::GetInstance() };
	
	std::string id;
	std::optional<std::string> resut = AppointmentService::GetInstance()->AddAppointment(std::chrono::month(9)/30/2026, "Doctor's Visit");

	if (resut.has_value())
	{
		id = resut.value();



		const Appointment* app = AppointmentService::GetInstance()->GetItem(id);

		std::cout << app->GetId() << std::endl;
		std::cout << app->GetDate() << std::endl;
		std::cout << app->GetDescription() << std::endl;
	}

	appointmentReader.Write();
}
