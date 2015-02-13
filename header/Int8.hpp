#ifndef INT8_HPP_
# define INT8_HPP_

# include "IOperand.hpp"

class Int8 : public IOperand {
	std::string _value;

 public:
 	Int8(const std::string &);
	~Int8() {}

 	std::string const &toString(void) const;

	int getPrecision(void) const;
	eOperandType getType(void) const;

	IOperand *operator+(const IOperand &rhs) const;
	IOperand *operator-(const IOperand &rhs) const;
	IOperand *operator*(const IOperand &rhs) const;
	IOperand *operator/(const IOperand &rhs) const;
	IOperand *operator%(const IOperand &rhs) const;
};

#endif /* !INT8_HPP_ */
