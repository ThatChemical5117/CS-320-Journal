#include <gtest/gtest.h>

#include "Service/AppointmentService.h"

class AppointmentServiceTest: public testing::Test
{
protected:
	AppointmentServiceTest()
	{
		AppointmentService* service { AppointmentService::GetInstance() };

		// pre add some services
		Item1 = service->AddAppointment(std::chrono::day(10)/12/2050, "Meeting").value(); 
		Item2 = service->AddAppointment(std::chrono::day(11)/12/2050, "Doctor's visit").value();
	}

	std::string Item1, Item2;
};

TEST_F(AppointmentServiceTest, GetFunctionality)
{
	ASSERT_NE(AppointmentService::GetInstance()->GetItem(Item1), nullptr);
	ASSERT_NE(AppointmentService::GetInstance()->GetItem(Item2), nullptr);
};

TEST_F(AppointmentServiceTest, DeleteFunctionality)
{
	AppointmentService::GetInstance()->DeleteItem(Item2);
	ASSERT_EQ(AppointmentService::GetInstance()->GetItem(Item2), nullptr);
}
