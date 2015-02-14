#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

# include <iostream>
# include <sstream>
# include <cstdlib>
# include "Error.hpp"

enum eOperandType {
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
};

enum eOperandPrecision {
	LESS_ACCURATE = 0,
	MINUS_ACCURATE = 1,
	ACCURATE = 2,
	PLUS_ACCURATE = 3,
	MORE_ACCURATE = 4
};

class IOperand {
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
