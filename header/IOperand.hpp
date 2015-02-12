#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

# include <iostream>

class IOperand {

	enum eOperandType {
		Int8,
		Int16,
		Int32,
		Float,
		Double
	};

 public:
	virtual std::string const &toString(void) const = 0;

	virtual int getPrecision(void) const = 0;
	virtual eOperandType getType(void) const = 0;

	virtual IOperand *operator+(const IOperand &rhs) const = 0;
	virtual IOperand *operator-(const IOperand &rhs) const = 0;
	virtual IOperand *operator*(const IOperand &rhs) const = 0;
	virtual IOperand *operator/(const IOperand &rhs) const = 0;
	virtual IOperand *operator%(const IOperand &rhs) const = 0;

	virtual ~IOperand() {}
};

#endif /* !IOPERAND_HPP_ */
