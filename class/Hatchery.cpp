/* 
* @Author: gicque_p
* @Date:   2015-02-13 10:18:09
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-17 19:47:42
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
	int8_t convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	return new Operand<int8_t>(convertedValue, INT8, LESS_ACCURATE);
}

IOperand *Hatchery::createInt16(const std::string &value) {
	int16_t convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	return new Operand<int16_t>(convertedValue, INT16, MINUS_ACCURATE);
}

IOperand *Hatchery::createInt32(const std::string &value) {
	int32_t convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	return new Operand<int32_t>(convertedValue, INT32, ACCURATE);
}

IOperand *Hatchery::createFloat(const std::string &value) {
	float convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	return new Operand<float>(convertedValue, FLOAT, PLUS_ACCURATE);
}

IOperand *Hatchery::createDouble(const std::string &value) {
	double convertedValue;
	std::istringstream buffer(value);

	buffer >> convertedValue;
	return new Operand<double>(convertedValue, DOUBLE, MORE_ACCURATE);
}
