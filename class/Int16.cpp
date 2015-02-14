/* 
* @Author: gicque_p
* @Date:   2015-02-12 11:44:09
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-14 19:14:02
*/

#include "Int16.hpp"
#include "Hatchery.hpp"

Int16::Int16(const std::string &value) {
	this->_value = atol(value.c_str());
	this->_stringValue = value;
}

std::string const &Int16::toString(void) const {
	return this->_stringValue;
}

int Int16::getPrecision(void) const {
	return MINUS_ACCURATE;
}

eOperandType Int16::getType(void) const {
	return INT16;
}

IOperand *Int16::operator+(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	std::ostringstream stream;
	stream << atoi(this->toString().c_str()) + atoi(rhs.toString().c_str());

	if (this->getType() <= rhs.getType()) {
		operand = hatchery.createOperand(rhs.getType(), stream.str());
	} else {
		operand = hatchery.createOperand(this->getType(), stream.str());
	}

	return operand;
}

IOperand *Int16::operator-(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	std::ostringstream stream;
	stream << atoi(this->toString().c_str()) - atoi(rhs.toString().c_str());

	if (this->getType() <= rhs.getType()) {
		operand = hatchery.createOperand(rhs.getType(), stream.str());
	} else {
		operand = hatchery.createOperand(this->getType(), stream.str());
	}

	return operand;
}

IOperand *Int16::operator*(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	std::ostringstream stream;
	stream << atoi(this->toString().c_str()) * atoi(rhs.toString().c_str());

	if (this->getType() <= rhs.getType()) {
		operand = hatchery.createOperand(rhs.getType(), stream.str());
	} else {
		operand = hatchery.createOperand(this->getType(), stream.str());
	}

	return operand;
}

IOperand *Int16::operator/(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int16::operator%(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}
