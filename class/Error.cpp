/* 
* @Author: gicque_p
* @Date:   2015-02-13 11:06:21
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:31:54
*/

#include "Error.hpp"

Error::Error(std::string const &message) : _message(message) {}

const char *Error::what() const throw() {
	return this->_message.c_str();
}

HatcheryError::HatcheryError(std::string const &message) : _message(message) {}
const char *HatcheryError::what() const throw() {
	return this->_message.c_str();
}

CoreError::CoreError(std::string const &message) : _message(message) {}
const char *CoreError::what() const throw() {
	return this->_message.c_str();
}

OperandError::OperandError(std::string const &message) : _message(message) {}
const char *OperandError::what() const throw() {
	return this->_message.c_str();
}

ParsingError::ParsingError(std::string const &message) : _message(message) {}
const char *ParsingError::what() const throw() {
	return this->_message.c_str();
}
