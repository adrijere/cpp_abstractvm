#ifndef INT8_HPP_
# define INT8_HPP_

# include "IOperand.hpp"

class Int8 : public IOperand {
	int8_t _value;
	std::string _stringValue;

 public:
	Int8(const std::string &);
	~Int8() {}

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

#endif /* !INT8_HPP_ */
