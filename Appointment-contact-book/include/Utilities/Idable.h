#pragma once
/* Idable.h
 * Author: Michael Kik
 * Date: 9-10-2026
 * Course Id: CS-499
 *
 * C++20 concept: Idable
 * Requires the template item to have both an GetId and SetId function
*/

#include <concepts>
#include <string>

template <typename T>
concept Idable = requires (T item)
{
	{ item.GetId() } -> std::same_as<const std::string_view>;
	item.SetId(std::string {});
};
