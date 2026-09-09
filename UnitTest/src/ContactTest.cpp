#include <string>

#include <gtest/gtest.h>
#include "Model/Contact.h"

// Contact test fixture
class ContactTest: public testing::Test
{
protected:
	ContactTest()
		: m_contact { "001", "John", "Doe", "2842740158", "Address unknown" }
	{}

	Contact m_contact;
};

TEST_F(ContactTest, ContactIsValid) {
	ASSERT_TRUE(m_contact.GetId().compare("001") == 0);
	ASSERT_TRUE(m_contact.GetFirstName().compare("John") == 0);
	ASSERT_TRUE(m_contact.GetLastName().compare("Doe") == 0);
	ASSERT_TRUE(m_contact.GetPhoneNumber().compare("2842740158") == 0);
	ASSERT_TRUE(m_contact.GetAddress().compare("Address unknown") == 0);
}

TEST_F(ContactTest, InvalidLengths)
{
	ASSERT_THROW(m_contact.SetId("1234567890111"), std::length_error);
	ASSERT_THROW(m_contact.SetFirstName("John Doe Henry Smith Brown Jimmithy Timmothy"), std::length_error);
	ASSERT_THROW(m_contact.SetLastName("John Doe Henry Smith Brown Jimmithy Timmothy"), std::length_error);
	// Phone number tests (length not = to 10)
	ASSERT_THROW(m_contact.SetPhoneNumber("3333"), std::length_error);
	ASSERT_THROW(m_contact.SetPhoneNumber("1231231234555"), std::length_error);

	ASSERT_THROW(m_contact.SetAddress("12343333 John riversville blvd, St. Augustine FL, 44332 United States of America"), std::length_error);

}

TEST_F(ContactTest, EmptyStrings)
{
	ASSERT_THROW(m_contact.SetId(""), std::invalid_argument);
	ASSERT_THROW(m_contact.SetFirstName(""), std::invalid_argument);
	ASSERT_THROW(m_contact.SetLastName(""), std::invalid_argument);
	ASSERT_THROW(m_contact.SetPhoneNumber(""), std::length_error);
	ASSERT_THROW(m_contact.SetAddress(""), std::invalid_argument);
}
