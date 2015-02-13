/* 
* @Author: gicque_p
* @Date:   2015-02-12 11:44:09
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 13:17:41
*/

#include "Int16.hpp"

Int16::Int16(const std::string &value) : _value(value) {}

std::string const &Int16::toString(void) const {
	return *new std::string;
}

int Int16::getPrecision(void) const {
	return 0;
}

eOperandType Int16::getType(void) const {
	return INT16;
}

IOperand *Int16::operator+(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int16::operator-(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int16::operator*(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int16::operator/(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int16::operator%(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}
