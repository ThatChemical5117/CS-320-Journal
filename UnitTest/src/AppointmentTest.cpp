#include <stdexcept>
#include <chrono>

#include <gtest/gtest.h>
#include <Model/Appointment.h>

class AppointmentTest : public testing::Test
{
protected:
	AppointmentTest()
		: m_appointment{ "001", std::chrono::month(9)/8/3129, "Visit"}
	{};

	Appointment m_appointment;
};

TEST_F(AppointmentTest, ValidAppointment) {
	ASSERT_TRUE(m_appointment.GetId().compare("001") == 0);
	ASSERT_TRUE(m_appointment.GetDate() == std::chrono::month(9)/8/3129);
	ASSERT_TRUE(m_appointment.GetDescription().compare("Visit") == 0);
}

TEST_F(AppointmentTest, FieldTooLong) {
	ASSERT_THROW(m_appointment.SetId("12312312345"), std::length_error);
	ASSERT_THROW(m_appointment.SetDescription("Very long description that is very long and wordy. Running out of things to say in this message before the description error is triggered"), std::length_error);
}

TEST_F(AppointmentTest, OnEmptyField) {
	ASSERT_THROW(m_appointment.SetId(""), std::invalid_argument);
	ASSERT_THROW(m_appointment.SetDescription(""), std::invalid_argument);
}

TEST_F (AppointmentTest, DateNotInPass) {
	ASSERT_NO_THROW(m_appointment.SetDate(std::chrono::day(31)/12/3020));
}

TEST_F(AppointmentTest, ErrorOnPastDate) {
	ASSERT_THROW(m_appointment.SetDate(std::chrono::day(1)/1/1999), std::invalid_argument);
}
