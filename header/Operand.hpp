#ifndef OPERAND_HPP_
# define OPERAND_HPP_

# include "IOperand.hpp"

template <typename T>
class Operand : public IOperand {
	T _value;
	eOperandType _type;
	eOperandPrecision _precision;

 public:
	Operand(const T, eOperandType, eOperandPrecision);
	~Operand() {}

	std::string const &toString(void) const;

	int getPrecision(void) const;
	eOperandType getType(void) const;
	int8_t getValue(void) const;
	void setValue(int8_t);

	IOperand *operator+(const IOperand &rhs) const;
	IOperand *operator-(const IOperand &rhs) const;
	IOperand *operator*(const IOperand &rhs) const;
	IOperand *operator/(const IOperand &rhs) const;
	IOperand *operator%(const IOperand &rhs) const;
};

#endif /* OPERAND_HPP_ */
