/* 
* @Author: gicque_p
* @Date:   2015-02-13 10:18:09
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 16:39:37
*/

#include "Hatchery.hpp"

Hatchery::Hatchery() {
	this->arrayMethod[INT8] = &Hatchery::createInt8;
	this->arrayMethod[INT16] = &Hatchery::createInt16;
	this->arrayMethod[INT32] = &Hatchery::createInt32;
	this->arrayMethod[FLOAT] = &Hatchery::createFloat;
	this->arrayMethod[DOUBLE] = &Hatchery::createDouble;
}

IOperand *Hatchery::createOperand(eOperandType type, const std::string &value) {
	if (this->arrayMethod[type]) {
		return (this->*arrayMethod[type])(value);
	} else {
		throw Error("OperandType for array to member pointers undefined");
	}
}

IOperand *Hatchery::createInt8(const std::string &value) {
	return new Int8(value);
}

IOperand *Hatchery::createInt16(const std::string &value) {
	return new Int16(value);
}

IOperand *Hatchery::createInt32(const std::string &value) {
	return new Int32(value);
}

IOperand *Hatchery::createFloat(const std::string &value) {
	return new Float(value);
}

IOperand *Hatchery::createDouble(const std::string &value) {
	return new Double(value);
}
