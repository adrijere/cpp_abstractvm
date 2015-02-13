#ifndef INT32_HPP_
# define INT32_HPP_

# include "IOperand.hpp"

class Int32 : public IOperand {
	std::string _value;

 public:
	Int32(const std::string &);
	~Int32() {}

	std::string const &toString(void) const;

	int getPrecision(void) const;
	eOperandType getType(void) const;

	IOperand *operator+(const IOperand &rhs) const;
	IOperand *operator-(const IOperand &rhs) const;
	IOperand *operator*(const IOperand &rhs) const;
	IOperand *operator/(const IOperand &rhs) const;
	IOperand *operator%(const IOperand &rhs) const;
};

#endif /* !INT32_HPP_ */
