#include "Impl/FileManager.h"

#include <filesystem>
#include <iostream>


FileManager::FileManager(const std::string fileName, const std::string extension, bool createMode)
	: m_filename { fileName }, m_createIfNotExsist { createMode }
{
	m_isValid = checkIfValid(extension);
};


void FileManager::Read(std::function<void (std::ifstream&)> parser)
{
	m_inStream.open(m_filename);

	if (!m_inStream.is_open())
	{
		std::cout << "Can not open file: " << m_filename << "\n";
		return;
	}

	if (!m_isValid)
		return;
	
	// Call user defined parser
	parser(m_inStream);

	m_inStream.close();
}

void FileManager::Write(std::function<void (std::ofstream&)> parser, const std::ofstream::openmode mode)
{
	m_outStream.open(m_filename, mode);

	if (!m_outStream.is_open())
	{
		std::cout << "Can not open file: " << m_filename << std::endl;
		return;
	}

	if (!m_isValid)
		return;

	parser(m_outStream);

	// Close file - object lives outside of this function scope
	m_outStream.close();
};


bool FileManager::checkIfValid(std::string extension) const noexcept
{
	using namespace std;

	filesystem::path path = filesystem::current_path();
	path.append(m_filename);

	if (!filesystem::exists(path) && !m_createIfNotExsist){
		std::cout << "Can not open: " << m_filename << "\nNo file found" << std::endl;
		return false;
	}

	if (filesystem::is_directory(path))
	{
		std::cout << "Can not open: " << m_filename << "\nI not a file" << std::endl;
		return false;
	}

	if (path.extension() != extension)
	{
		std::cout << "Invalid file format: " << path.extension() << std::endl;
		std::cout << "Expected " << extension << std::endl;

		return false;
	}

	return true;
};
