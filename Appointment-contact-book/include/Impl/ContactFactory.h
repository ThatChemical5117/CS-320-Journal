#pragma once
/* ContactFactory.h
 * Author: Michael Kik
 * Date: 09-18-2026
 * Course ID: CS-499
 *
 * Contact Factory class produces Contact objects from JSON
*/

#include "Model/Contact.h"
#include "Interface/IdableFactoryInterface.h"
#include "nlohmann/json_fwd.hpp"

class ContactFactory: public IdableFactoryInterface<Contact, nlohmann::json>
{
public:
	static ContactFactory* GetInstance() noexcept;

	void FromSource(const nlohmann::json& document) override;
	nlohmann::json ToSource(const Contact* contact) override;

private:
	static ContactFactory* m_factoryInstance;
	ContactFactory() = default;

	
	nlohmann::json ContactToJson(const Contact& contact);

};
