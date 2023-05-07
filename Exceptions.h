//------------------------------------------------------------------------------
// Exceptions.h : base class declaration and definition
//------------------------------------------------------------------------------
#pragma once
#include <stdexcept>

// Gives error and closes app when user inputs an invalid file
class FileOpenException : public std::exception {
private:
	std::string message;
public:
	FileOpenException() : message("Could not open inventory file! Exiting application.\n") {}
	const char* what() const throw() {
		return message.c_str();
	}
};

// Gives user an error when a line doesn't begin with 1 or 2 and tells which line it is then continues
class FileFormatException : public std::exception {
private:
	std::string m_message;
public:
	FileFormatException(int lineNum)
	{
		std::stringstream message;
		message << "Could not read inventory item at line " << lineNum << ". Continuing application.\n";
		m_message = message.str();
	}
	const char* what() const noexcept
	{
		return m_message.c_str();
	}
};