/* 
* @Author: gicque_p
* @Date:   2015-02-12 11:43:48
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-16 09:53:12
*/

#include "Int8.hpp"
#include "Hatchery.hpp"

Int8::Int8(const std::string &value) {
	this->_value = atoi(value.c_str());
	this->_stringValue = value;
}

std::string const &Int8::toString(void) const {
	return this->_stringValue;
}

int Int8::getPrecision(void) const {
	return LESS_ACCURATE;
}

eOperandType Int8::getType(void) const {
	return INT8;
}

IOperand *Int8::operator+(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	std::ostringstream stream;
	stream << atoi(this->toString().c_str()) + atoi(rhs.toString().c_str());
	if (atoi(this->toString().c_str()) + atoi(rhs.toString().c_str()) < 2) {
		throw Error("Trying to push a result lower than 2");
	} else {
		if (this->getType() <= rhs.getType()) {
			operand = hatchery.createOperand(rhs.getType(), stream.str());
		} else {
			operand = hatchery.createOperand(this->getType(), stream.str());
		}
	}

	return operand;
}

IOperand *Int8::operator-(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	std::ostringstream stream;
	stream << atoi(this->toString().c_str()) - atoi(rhs.toString().c_str());
	if (atoi(this->toString().c_str()) - atoi(rhs.toString().c_str()) < 2) {
		throw Error("Trying to push a result lower than 2");
	} else {
		if (this->getType() <= rhs.getType()) {
			operand = hatchery.createOperand(rhs.getType(), stream.str());
		} else {
			operand = hatchery.createOperand(this->getType(), stream.str());
		}
	}

	return operand;
}

IOperand *Int8::operator*(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	std::ostringstream stream;
	stream << atoi(this->toString().c_str()) * atoi(rhs.toString().c_str());
	if (atoi(this->toString().c_str()) * atoi(rhs.toString().c_str()) < 2) {
		throw Error("Trying to push a result lower than 2");
	} else {
		if (this->getType() <= rhs.getType()) {
			operand = hatchery.createOperand(rhs.getType(), stream.str());
		} else {
			operand = hatchery.createOperand(this->getType(), stream.str());
		}
	}

	return operand;
}

IOperand *Int8::operator/(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

IOperand *Int8::operator%(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}
