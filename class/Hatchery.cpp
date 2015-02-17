/* 
* @Author: gicque_p
* @Date:   2015-02-13 10:18:09
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-17 18:51:50
*/

#include "Hatchery.hpp"

// template<> IOPerand *Operand<int8_t>::Operand(const int8_t, const int &second) {return first == second;}
// template<> bool Tester<float>::equal(const float &first, const float &second) {return first == second;}
// template<> bool Tester<double>::equal(const double &first, const double &second) {return first == second;}
// template<> bool Tester<std::string>::equal(const std::string &first, const std::string &second) {return first == second;}

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
	return new Operand<int8_t>((int8_t)0, INT8, LESS_ACCURATE);
}

IOperand *Hatchery::createInt16(const std::string &value) {
	return new Operand<int16_t>((int16_t)0, INT16, MINUS_ACCURATE);
}

IOperand *Hatchery::createInt32(const std::string &value) {
	return new Operand<int32_t>((int32_t)0, INT32, ACCURATE);
}

IOperand *Hatchery::createFloat(const std::string &value) {
	return new Operand<float>((float)0, FLOAT, PLUS_ACCURATE);
}

IOperand *Hatchery::createDouble(const std::string &value) {
	return new Operand<double>((double)0, DOUBLE, MORE_ACCURATE);
}
