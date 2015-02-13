/* 
* @Author: gicque_p
* @Date:   2015-02-13 11:06:21
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 11:07:27
*/

#include "Error.hpp"

Error::Error(std::string const &message) : _message(message) {}

const char *Error::what() const throw() {
	return this->_message.c_str();
}
