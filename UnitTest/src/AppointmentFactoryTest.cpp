#include <gtest/gtest.h>

#include "nlohmann/json.hpp"
#include "Model/Appointment.h"
#include "Impl/AppointmentFactory.h"
#include "Service/AppointmentService.h"

class AppointmentFactoryTest: public testing::Test
{
protected:
	AppointmentFactoryTest()
	{
		m_original = nlohmann::json::object({
			{"date", "12/31/2027"},
			{"description", "Doctor's visit"}
		});
	}

	AppointmentFactory* m_factory = AppointmentFactory::GetInstance();
	AppointmentService* m_service = AppointmentService::GetInstance();
	nlohmann::json m_original;
};


TEST_F(AppointmentFactoryTest, CreateFromObject)
{
	// Manual appointment creation
	m_factory->FromSource(m_original);
	
	const std::string description = m_original.at("description");
	const Appointment* appointment = m_service->GetItem("1");

	ASSERT_EQ(appointment->GetDescription().compare(description), 0);
};

TEST_F(AppointmentFactoryTest, CreateJson)
{
	nlohmann::json object = m_factory->ToSource(m_service->GetItem("1"));
	ASSERT_EQ(object, m_original);
};
