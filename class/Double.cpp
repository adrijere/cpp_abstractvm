/* 
* @Author: gicque_p
* @Date:   2015-02-12 11:45:02
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 17:44:29
*/

#include "Double.hpp"

Double::Double(const std::string &value) : _value(value) {}

std::string const &Double::toString(void) const {
	return *new std::string;
}

int Double::getPrecision(void) const {
	return MORE_ACCURATE;
}

eOperandType Double::getType(void) const {
	return DOUBLE;
}

IOperand *Double::operator+(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Double::operator-(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Double::operator*(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Double::operator/(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Double::operator%(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}
