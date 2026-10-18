#pragma once
/* IdableFactoryInterface.h
 * Author: Michael Kik
 * Date: 09-10-2026
 * Course Id: CS-499
 *
 * Interface for a factory that builds type T objects from type S objects
*/

#include "Utilities/Idable.h"

template <typename T, typename S>
requires Idable<T>
class IdableFactoryInterface
{
public:
	virtual void FromSource(const S&) = 0;
	virtual S ToSource(const T* item) = 0;
protected:
	IdableFactoryInterface() = default;
	
};
