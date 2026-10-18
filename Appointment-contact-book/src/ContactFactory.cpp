#include "Impl/ContactFactory.h"

#include "Service/ContactService.h"
#include "nlohmann/json.hpp"

ContactFactory* ContactFactory::m_factoryInstance = nullptr;
ContactFactory* ContactFactory::GetInstance() noexcept
{
	if (m_factoryInstance == nullptr)
		m_factoryInstance = new ContactFactory;
	return m_factoryInstance;
};

void ContactFactory::FromSource(const nlohmann::json& object)
{
	ContactService::GetInstance()->AddContact(object.at("firstname"), object.at("lastname"), object.at("phonenumber"), object.at("address"));
};

nlohmann::json ContactFactory::ToSource(const Contact* contact)
{
	// Return if the object is not nullptr
	if (contact != nullptr)
		return ContactToJson(*contact);

	nlohmann::json document = nlohmann::json::array();

	ContactService::GetInstance()->ForEach([this, &document](const Contact& contact) -> void {
		document.push_back(ContactToJson(contact));
	});

	return document;
}

nlohmann::json ContactFactory::ContactToJson(const Contact& contact)
{
	nlohmann::json object = nlohmann::json::object();

	object["firstname"] = static_cast<std::string>(contact.GetFirstName());
	object["lastname"] = static_cast<std::string>(contact.GetLastName());
	object["phonenumber"] = static_cast<std::string>(contact.GetPhoneNumber());
	object["address"] = static_cast<std::string>(contact.GetAddress());

	return nlohmann::json::object(
	{
		{"firstname", static_cast<std::string>(contact.GetFirstName())},
		{"lastname", static_cast<std::string>(contact.GetLastName())},
		{"phonenumber", static_cast<std::string>(contact.GetPhoneNumber()) },
		{"address", static_cast<std::string>(contact.GetAddress())}
	});
};

