#include <gtest/gtest.h>

#include "nlohmann/json.hpp"

#include "Model/Contact.h"
#include "Impl/ContactFactory.h"
#include "Service/ContactService.h"

class ContactFactoryTest: public testing::Test
{
protected:

	ContactFactoryTest()
	{
		// Default contact (This will become object 1)
		m_original = nlohmann::json::object({
			{"firstname", "John"},
			{"lastname", "Doe"},
			{"phonenumber", "2488885029"},
			{"address", "456 NW 33rd st"}
		});

	};

	ContactService* m_service = ContactService::GetInstance();
	ContactFactory* m_factory = ContactFactory::GetInstance();

	nlohmann::json m_original;
};


TEST_F(ContactFactoryTest, CreateFromJson)
{
	m_factory->FromSource(m_original);

	// convert the values in the json object to strings for easier use
	std::string firstname = m_original.at("firstname");
	std::string lastname = m_original.at("lastname");
	std::string phonenumber = m_original.at("phonenumber");
	std::string address = m_original.at("address");

	// Get the contact ahead of time
	const Contact* contact = m_service->GetItem("1");

	// Assert that the objects match
	ASSERT_EQ(contact->GetFirstName().compare(firstname), 0);
	ASSERT_EQ(contact->GetLastName().compare(lastname), 0);
	ASSERT_EQ(contact->GetPhoneNumber().compare(phonenumber), 0);
	ASSERT_EQ(contact->GetAddress().compare(address), 0);
};


TEST_F(ContactFactoryTest, CreateToJson)
{
	nlohmann::json object = m_factory->ToSource(m_service->GetItem("1"));

	ASSERT_EQ(object, m_original);
};
