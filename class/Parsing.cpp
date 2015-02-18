/* 
* @Author: gicque_p
* @Date:   2015-02-18 11:01:55
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 11:35:07
*/

#include "Parsing.hpp"

Parsing::Parsing() {
	this->_firstMap["pop"] = &Core::pop;
	this->_firstMap["dump"] = &Core::dump;
	this->_firstMap["add"] = &Core::add;
	this->_firstMap["sub"] = &Core::sub;
	this->_firstMap["mul"] = &Core::mul;
	this->_firstMap["div"] = &Core::div;
	this->_firstMap["mod"] = &Core::mod;
	this->_firstMap["print"] = &Core::print;
}

std::map<std::string, voidFunction> Parsing::getFirstMap(void) const {
	return this->_firstMap;
}

std::map<std::string, operandFunction> Parsing::getSecondMap(void) const {
	return this->_secondMap;
}
