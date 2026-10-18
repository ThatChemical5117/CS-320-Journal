#include <chrono>
#include <sstream>
#include <vector>

#include "Impl/AppointmentFactory.h"
#include "Service/AppointmentService.h"
#include "nlohmann/json.hpp"

// Utility function
std::vector<std::string> splitWithDelimiter(const std::string& string,  const char delimiter)
{
	std::vector<std::string> splitLine;
	std::stringstream stream(string);
	std::string substr;

	while(getline(stream, substr, delimiter))
	{
		if (substr.find_first_not_of(" \t\n\v\f\r") != std::string::npos && !substr.empty())
		{
			if (substr.find('\r') != std::string::npos)
				substr.erase(substr.find('\r'));
			splitLine.push_back(substr);
		};
	};

	return splitLine;
};



AppointmentFactory* AppointmentFactory::m_instance = nullptr;

AppointmentFactory* AppointmentFactory::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new AppointmentFactory;
	return m_instance;
};

void AppointmentFactory::FromSource(const nlohmann::json& object)
{
	// Create a new appointment into the service
	AppointmentService::GetInstance()->AddAppointment(StringToDate(object.at("date")), object.at("description"));	
};

// Converts all appointments into one large json document or a single Appointment into one object
nlohmann::json AppointmentFactory::ToSource(const Appointment* appointment)
{
	// If there is an object to convert
	if (appointment != nullptr)
	{
		// convert the appointment to json
		return AppointmentToJson(*appointment);
	};

	// Otherwise loop through the internal structure of the service and convert the whole thing into one document
	nlohmann::json document = nlohmann::json::array();
	AppointmentService::GetInstance()->ForEach([this, &document](const Appointment& appointment) -> void{
		// Do the actual conversion
		document.push_back(AppointmentToJson(appointment));
	});

	return document;
};

nlohmann::json AppointmentFactory::AppointmentToJson(const Appointment& appointment)
{
	return nlohmann::json::object({
		{ "date",DateToString(appointment.GetDate())},
		{ "description", static_cast<std::string>(appointment.GetDescription()) }
	});

};


std::string AppointmentFactory::DateToString(const std::chrono::year_month_day& date) const
{
	std::stringstream ss;
	ss << static_cast<unsigned int>(date.month()) << "/" << date.day() << "/" << date.year();

	return ss.str();
};

std::chrono::year_month_day AppointmentFactory::StringToDate(const std::string& date) const
{
	int month, day, year;

	auto splitline = splitWithDelimiter(date, '/');
	month = std::stoi(splitline.at(0));
	day = std::stoi(splitline.at(1));
	year = std::stoi(splitline.at(2));

	return std::chrono::month(month)/day/year;
};
