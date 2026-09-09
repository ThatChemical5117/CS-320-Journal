#include <iostream>
#include "Model/Task.h"

int main()
{
	Task task { "001", "Assignment", "CS-499 Assignment" };

	std::cout << task.GetId() << std::endl;
	std::cout << task.GetId().compare("001") << std::endl;
}
