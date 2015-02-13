#ifndef DOUBLE_HPP_
# define DOUBLE_HPP_

# include "IOperand.hpp"

class Double : public IOperand {
	std::string _value;

 public:
	Double(const std::string &);
	~Double() {}

	std::string const &toString(void) const;

	int getPrecision(void) const;
	eOperandType getType(void) const;

	IOperand *operator+(const IOperand &rhs) const;
	IOperand *operator-(const IOperand &rhs) const;
	IOperand *operator*(const IOperand &rhs) const;
	IOperand *operator/(const IOperand &rhs) const;
	IOperand *operator%(const IOperand &rhs) const;
};

#endif /* !DOUBLE_HPP_ */
