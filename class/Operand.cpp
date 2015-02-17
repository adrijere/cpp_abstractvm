/* 
* @Author: gicque_p
* @Date:   2015-02-17 17:00:20
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-17 18:50:02
*/

// #include "Operand.hpp"
#include "Hatchery.hpp"

template<typename T>
Operand<T>::Operand(const T value, eOperandType type, eOperandPrecision precision) : _value(value), _type(type), _precision(precision) {}

template<typename T>
std::string const &Operand<T>::toString(void) const {
	return this->_value;
}

template<typename T>
int Operand<T>::getPrecision(void) const {
	return this->_precision;
}

template<typename T>
eOperandType Operand<T>::getType(void) const {
	return this->_type;
}

template<typename T>
IOperand *Operand<T>::operator+(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	// std::ostringstream stream;
	// stream << atoi(this->toString().c_str()) + atoi(rhs.toString().c_str());
	// if (atoi(this->toString().c_str()) + atoi(rhs.toString().c_str()) < 2) {
	// 	throw Error("Trying to push a result lower than 2");
	// } else {
	// 	if (this->getType() <= rhs.getType()) {
	// 		operand<T> = hatchery.createOperand<T>(rhs.getType(), stream.str());
	// 	} else {
	// 		operand<T> = hatchery.createOperand<T>(this->getType(), stream.str());
	// 	}
	// }

	return operand;
}

template<typename T>
IOperand *Operand<T>::operator-(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	// std::ostringstream stream;
	// stream << atoi(this->toString().c_str()) - atoi(rhs.toString().c_str());
	// if (atoi(this->toString().c_str()) - atoi(rhs.toString().c_str()) < 2) {
	// 	throw Error("Trying to push a result lower than 2");
	// } else {
	// 	if (this->getType() <= rhs.getType()) {
	// 		operand<T> = hatchery.createOperand<T>(rhs.getType(), stream.str());
	// 	} else {
	// 		operand<T> = hatchery.createOperand<T>(this->getType(), stream.str());
	// 	}
	// }

	return operand;
}

template<typename T>
IOperand *Operand<T>::operator*(const IOperand &rhs) const {
	Hatchery hatchery;
	IOperand *operand;

	// std::ostringstream stream;
	// stream << atoi(this->toString().c_str()) * atoi(rhs.toString().c_str());
	// if (atoi(this->toString().c_str()) * atoi(rhs.toString().c_str()) < 2) {
	// 	throw Error("Trying to push a result lower than 2");
	// } else {
	// 	if (this->getType() <= rhs.getType()) {
	// 		operand<T> = hatchery.createOperand<T>(rhs.getType(), stream.str());
	// 	} else {
	// 		operand<T> = hatchery.createOperand<T>(this->getType(), stream.str());
	// 	}
	// }

	return operand;
}

template<typename T>
IOperand *Operand<T>::operator/(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}

template<typename T>
IOperand *Operand<T>::operator%(const IOperand &rhs) const {
	(void)rhs;
	return (IOperand *)this;
}
