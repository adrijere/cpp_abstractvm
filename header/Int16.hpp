#ifndef INT16_HPP_
# define INT16_HPP_

# include "IOperand.hpp"

class Int16 : public IOperand {
	std::string _value;

 public:
	Int16(const std::string &);
	~Int16() {}

	std::string const &toString(void) const;

	int getPrecision(void) const;
	eOperandType getType(void) const;

	IOperand *operator+(const IOperand &rhs) const;
	IOperand *operator-(const IOperand &rhs) const;
	IOperand *operator*(const IOperand &rhs) const;
	IOperand *operator/(const IOperand &rhs) const;
	IOperand *operator%(const IOperand &rhs) const;
};

#endif /* !INT16_HPP_ */
