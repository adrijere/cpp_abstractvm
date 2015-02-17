#ifndef HATCHERY_HPP_
# define HATCHERY_HPP_

# include "Error.hpp"
# include "IOperand.hpp"

class Hatchery {

 private:
	IOperand *(Hatchery::*arrayMethod[5])(const std::string &);

	IOperand *createInt8(const std::string &);
	IOperand *createInt16(const std::string &);
	IOperand *createInt32(const std::string &);
	IOperand *createFloat(const std::string &);
	IOperand *createDouble(const std::string &);

 public:
	Hatchery();
	~Hatchery() {};

	IOperand *createOperand(eOperandType, const std::string &);
};

# include "Operand.hpp"

#endif /* !HATCHERY_HPP_ */
