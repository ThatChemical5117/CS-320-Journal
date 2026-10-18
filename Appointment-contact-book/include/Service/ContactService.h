#pragma once
/* ContactService.h
 * Author: Michael Kik
 * Date: 9-9-2026
 * Course Id: CS-320, CS-499
 *
 * Contact service class - extends the Service Interfacce class
 * and is also a singleton. Uses a LinearIdGenerator
*/

#include <string>
#include <optional>

#include "Interface/ServiceInterface.h"
#include "Model/Contact.h"
#include "Impl/LinerIdGenerator.h"

class ContactService: public ServiceInterface<Contact, LinearIdGenerator>
{
public:
	// return a singleton instance
	static ContactService* GetInstance();
	std::optional<std::string> AddContact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, const std::string& address);
	void UpdateContact(const std::string& id, const Contact::FIELDS field, const std::string& data);

private: // Make into singleton
	static ContactService* m_instance;
	ContactService() = default;
};
