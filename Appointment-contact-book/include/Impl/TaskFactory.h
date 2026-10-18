#pragma once
/* TaskFactory.h
 * Author: Michael Kik
 * Date: 9-16-2026
 * Course Id: CS-499
 *
 * Task factory class produces a task from nlohmann::json objects
*/

#include "Model/Task.h"
#include "Interface/IdableFactoryInterface.h"
#include "nlohmann/json_fwd.hpp"


class TaskFactory: IdableFactoryInterface<Task, nlohmann::json>
{
public:
	static TaskFactory* GetInstance() noexcept;

	void FromSource(const nlohmann::json& document) override;
	nlohmann::json ToSource(const Task* task) override;

private:
	static TaskFactory* m_factoryInstance;
	TaskFactory() = default;

	nlohmann::json TaskToJson(const Task& task);
};
