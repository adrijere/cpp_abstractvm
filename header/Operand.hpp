#ifndef OPERAND_HPP_
# define OPERAND_HPP_

# include "IOperand.hpp"
# include "Error.hpp"
# include "Hatchery.hpp"

template <typename T>
class Operand : public IOperand {
	T _value;
	eOperandType _type;
	eOperandPrecision _precision;

 public:
	Operand(const T value, eOperandType type, eOperandPrecision precision) : _value(value), _type(type), _precision(precision) {}
	~Operand() {}

	std::string const &toString(void) const {
		return *(new std::string("coucou"));
		// return this->_value;
	}

	int getPrecision(void) const {
		return this->_precision;
	}

	eOperandType getType(void) const {
		return this->_type;
	}

	IOperand *operator+(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		(void)rhs;
		operand = NULL;
		return operand;
	}

	IOperand *operator-(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		operand = NULL;
		(void)rhs;
		return operand;
	}

	IOperand *operator*(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		operand = NULL;
		(void)rhs;
		return operand;
	}

	IOperand *operator/(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		operand = NULL;
		(void)rhs;
		return operand;
	}

	IOperand *operator%(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		operand = NULL;
		(void)rhs;
		return operand;
	}

};

#endif /* OPERAND_HPP_ */
