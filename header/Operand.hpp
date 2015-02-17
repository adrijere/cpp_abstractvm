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
		std::ostringstream buffer;

		buffer << this->_value;
		return (*new std::string(buffer.str()));
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

	IOperand *operator-(const IOperand &rhs) const {
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

	IOperand *operator*(const IOperand &rhs) const {
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

	IOperand *operator/(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		std::ostringstream stream;
		stream << atoi(this->toString().c_str()) / atoi(rhs.toString().c_str());
		if (atoi(this->toString().c_str()) / atoi(rhs.toString().c_str()) < 2) {
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

	IOperand *operator%(const IOperand &rhs) const {
		Hatchery hatchery;
		IOperand *operand;

		std::ostringstream stream;
		stream << atoi(this->toString().c_str()) % atoi(rhs.toString().c_str());
		if (atoi(this->toString().c_str()) % atoi(rhs.toString().c_str()) < 2) {
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

};

#endif /* OPERAND_HPP_ */
