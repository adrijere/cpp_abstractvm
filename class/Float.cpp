/* 
* @Author: gicque_p
* @Date:   2015-02-12 11:44:45
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 17:44:23
*/

#include "Float.hpp"

Float::Float(const std::string &value) : _value(value) {}

std::string const &Float::toString(void) const {
	return *new std::string;
}

int Float::getPrecision(void) const {
	return PLUS_ACCURATE;
}

eOperandType Float::getType(void) const {
	return FLOAT;
}

IOperand *Float::operator+(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Float::operator-(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Float::operator*(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Float::operator/(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Float::operator%(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}
