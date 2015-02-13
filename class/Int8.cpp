/* 
* @Author: gicque_p
* @Date:   2015-02-12 11:43:48
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 12:18:10
*/

#include "Int8.hpp"

Int8::Int8(const std::string &value) : _value(value) {}

std::string const &Int8::toString(void) const {
	return *new std::string;
}

int Int8::getPrecision(void) const {
	return 0;
}

eOperandType Int8::getType(void) const {
	return INT8;
}

IOperand *Int8::operator+(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int8::operator-(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int8::operator*(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int8::operator/(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int8::operator%(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}
