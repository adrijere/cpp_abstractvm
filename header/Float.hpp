#ifndef FLOAT_HPP_
# define FLOAT_HPP_
 
# include "IOperand.hpp"

class Float : public IOperand {
	std::string _value;

 public:
	Float(const std::string &);
	~Float() {}

	std::string const &toString(void) const;

	int getPrecision(void) const;
	eOperandType getType(void) const;

	IOperand *operator+(const IOperand &rhs) const;
	IOperand *operator-(const IOperand &rhs) const;
	IOperand *operator*(const IOperand &rhs) const;
	IOperand *operator/(const IOperand &rhs) const;
	IOperand *operator%(const IOperand &rhs) const;
};

#endif /* !FLOAT_HPP_ */
