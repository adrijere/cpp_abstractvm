#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

# include <iostream>

class IOperand {
 private:
	// IOperand *(IOperand::*funct)(const std::string &)[5]; // Tableau qui servira de map pour pointeur sur membres.

	IOperand *createInt8(const std::string &);
	IOperand *createInt16(const std::string &);
	IOperand *createInt32(const std::string &);
	IOperand *createFloat(const std::string &);
	IOperand *createDouble(const std::string &);

 public:
	enum eOperandType {
		Int8,
		Int16,
		Int32,
		Float,
		Double
	};

	IOperand *createOperand(eOperandType, const std::string &);

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
