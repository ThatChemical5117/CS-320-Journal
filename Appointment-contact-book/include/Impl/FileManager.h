#pragma once
/* FileManager.h
 * Author: Michael Kik
 * Date: 09-17-2026
 * Course ID: CS-499
 *
 * FileManager class managers the fstream class by openeing and closing them as appropriate
 * and providing functions to be able to both read and write from the same file
 */

#include <string>
#include <fstream>
#include <functional>

class FileManager
{
public:
	FileManager(const std::string fileName, const std::string extension = ".txt", bool createMode = false);

	void Read(std::function<void (std::ifstream&)> parser);
	void Write(std::function<void (std::ofstream&)> parser, const std::ofstream::openmode mode = std::ofstream::trunc);
	
	~FileManager() = default;


private:
	std::string m_filename;
	bool m_isValid;
	bool m_createIfNotExsist;

	std::ifstream m_inStream;
	std::ofstream m_outStream;

	bool checkIfValid(std::string extension) const noexcept;
};
