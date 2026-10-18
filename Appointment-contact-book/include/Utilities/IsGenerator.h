#pragma once
/* IsGenerator.h
 * Author: Michael Kik
 * Date: 9-10-2026
 * Course Id: CS-499
 *
 * C++20 Concept
 * Ensures that the template argument T is derived from IdGeneratorInterface
*/
#include <concepts>

#include "Interface/IdGeneratorInterface.h"

template <typename T>
concept IsGenerator = std::derived_from<T, IdGeneratorInterface>;
