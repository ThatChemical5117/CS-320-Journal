#include "Service/ContactService.h"

#include <iostream>

ContactService* ContactService::m_instance = nullptr;
ContactService* ContactService::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new ContactService;
	return m_instance;
};


std::optional<std::string> ContactService::AddContact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::string& address)
{
	try
	{
		std::string id = std::to_string(m_idGenerator.GenerateId());
		Contact* contact = new Contact { id, firstName, lastName, phoneNumber, address };
		m_itemStore.emplace(id, contact);
		return id;
	}
	catch (const std::exception& e)
	{
		std::cout << "Could not create contact\n\t";
		std::cout << e.what() << std::endl;
		return {};
	};
};


void ContactService::UpdateContact(const std::string& id, const Contact::FIELDS field, const std::string& data)
{
	if (!HasItem(id))
		return;
	
	Contact* contactToUpdate = m_itemStore.at(id);

	try {

		switch (field)
		{
			case Contact::FIELDS::FIRSTNAME:
				contactToUpdate->SetFirstName(data);
				break;
			case Contact::FIELDS::LASTNAME:
				contactToUpdate->SetLastName(data);
				break;
			case Contact::FIELDS::PHONENUMBER:
				contactToUpdate->SetPhoneNumber(data);
				break;
			case Contact::FIELDS::ADDRESS:
				contactToUpdate->SetAddress(data);
				break;
		}
	} catch (const std::exception& e)
	{
		std::cout << "Failed to update contact\n\t";
		std::cout << e.what() << std::endl;
	}
}

