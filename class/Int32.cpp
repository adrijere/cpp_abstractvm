/* 
* @Author: gicque_p
* @Date:   2015-02-12 11:44:31
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 17:44:15
*/

#include "Int32.hpp"

Int32::Int32(const std::string &value) : _value(value) {}

std::string const &Int32::toString(void) const {
	return *new std::string;
}

int Int32::getPrecision(void) const {
	return ACCURATE;
}

eOperandType Int32::getType(void) const {
	return INT32;
}

IOperand *Int32::operator+(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int32::operator-(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int32::operator*(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int32::operator/(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int32::operator%(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}
