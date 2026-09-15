#include <gtest/gtest.h>

#include "Service/ContactService.h"

class ContactServiceTest: public testing::Test
{
protected:
	ContactServiceTest()
	{
		// Set the instance
		m_serviceInstance = { ContactService::GetInstance() };

		Item1 = m_serviceInstance->AddContact("John", "Doe", "2392340129", "123 Dr. Blvd").value();
		Item2 = m_serviceInstance->AddContact("Jane", "Doe", "2392371132", "129 Dr. Blvd Rd").value();
		Item3 = m_serviceInstance->AddContact("Jim", "Deleted", "2342394356", "454 SW 85th st").value();
	}

	std::string Item1, Item2, Item3;
	ContactService* m_serviceInstance;
};

TEST_F(ContactServiceTest, GetFunctionality)
{
	ASSERT_NE(m_serviceInstance->GetItem(Item1), nullptr);
	ASSERT_NE(m_serviceInstance->GetItem(Item2), nullptr);
}

TEST_F(ContactServiceTest, AddFunctionality)
{
	// Assert that the value was created (represented by the std::optional return value)
	ASSERT_TRUE(m_serviceInstance->AddContact("Michael", "Jorden", "2344321234", "921 Dr. Blvd Rd").has_value());
}

TEST_F(ContactServiceTest, UpdateFunctionality)
{
	std::string copyOfFirstName = static_cast<std::string>(m_serviceInstance->GetItem(Item1)->GetFirstName());
	std::string copyOfAddress = static_cast<std::string>(m_serviceInstance->GetItem(Item2)->GetAddress());
	
	m_serviceInstance->UpdateContact(Item1, Contact::FIELDS::FIRSTNAME, "Jimmy");
	m_serviceInstance->UpdateContact(Item2, Contact::FIELDS::ADDRESS, "853 33rd St");

	ASSERT_FALSE(copyOfFirstName.compare(m_serviceInstance->GetItem(Item1)->GetFirstName()) == 0);
	ASSERT_FALSE(copyOfAddress.compare(m_serviceInstance->GetItem(Item2)->GetAddress()) == 0);

	// Copy checks
};

TEST_F(ContactServiceTest, DeleteFunctionality)
{
	m_serviceInstance->DeleteItem(Item3);
	ASSERT_EQ(m_serviceInstance->GetItem(Item3), nullptr);
}
