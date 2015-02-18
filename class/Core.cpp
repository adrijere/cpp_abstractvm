/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 18:41:36
*/

#include "Core.hpp"
#include "Hatchery.hpp"

Memory Core::getMemory(void) const {
	return this->_memory;
}

void Core::push(IOperand *operand) {
	try {
		this->_memory.push(operand);
	} catch (const std::exception &error) {
		throw CoreError("Push instruction is catching an exception");
	}
}

void Core::pop(IOperand *operand) {
	(void)operand;
	if (this->_memory.getStack().empty()) {
		throw CoreError("Pop instruction on an empty stack");
	} else {
		try {
			this->_memory.pop();		
		} catch (const std::exception &error) {
			throw CoreError("Pop instruction is catching an exception");
		}
	}
}

void Core::dump(IOperand *operand) {
	std::stack<IOperand *>stack = this->_memory.getStack();

	(void)operand;
	while (stack.size() > 0) {
		std::cout << stack.top()->toString() << std::endl;
		stack.pop();
	}
}

void Core::assert(IOperand *operand) {
	if (this->_memory.getStack().empty() or _memory.getStack().top()->getType() != operand->getType()) {
		throw CoreError("Assert with a wrong operand type on the last element");
	}
}

void Core::add(IOperand *operand) {
	(void)operand;
	if (this->_memory.getStack().size() < 2) {
		throw CoreError("Add instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_memory.getStack().top();
		this->pop();
		IOperand *secondOperand = this->_memory.getStack().top();
		this->pop();

		try {
			this->push(*firstOperand + *secondOperand);
		} catch (const OperandError &error) {
			this->pop();
			throw CoreError("Add result is lower than 2");
		}
	}
}

void Core::sub(IOperand *operand) {
	(void)operand;
	if (this->_memory.getStack().size() < 2) {
		throw CoreError("Sub instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_memory.getStack().top();
		this->pop();
		IOperand *secondOperand = this->_memory.getStack().top();
		this->pop();

		try {
			this->push(*firstOperand - *secondOperand);
		} catch (const OperandError &error) {
			this->pop();
			throw CoreError("Sub result is lower than 2");
		}
	}
}

void Core::mul(IOperand *operand) {
	(void)operand;
	if (this->_memory.getStack().size() < 2) {
		throw CoreError("Mul instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_memory.getStack().top();
		this->pop();
		IOperand *secondOperand = this->_memory.getStack().top();
		this->pop();

		try {
			this->push(*firstOperand * (*secondOperand));
		} catch (const OperandError &error) {
			this->pop();
			throw CoreError("Mul result is lower than 2");
		}
	}
}

void Core::div(IOperand *operand) {
	(void)operand;
	if (this->_memory.getStack().size() < 2) {
		throw CoreError("Div instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_memory.getStack().top();
		this->pop();
		IOperand *secondOperand = this->_memory.getStack().top();
		this->pop();

		if (secondOperand->toString() == "0") {
			throw CoreError("Div instruction is trying to divide by zero");
		} else {
			try {
				this->push(*firstOperand / *secondOperand);
			} catch (const OperandError &error) {
				this->pop();
				throw CoreError("Div result is lower than 2");
			}
		}
	}
}

void Core::mod(IOperand *operand) {
	(void)operand;
	if (this->_memory.getStack().size() < 2) {
		throw CoreError("Mod instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_memory.getStack().top();
		this->pop();
		IOperand *secondOperand = this->_memory.getStack().top();
		this->pop();

		if (secondOperand->toString() == "0") {
			throw CoreError("Mod instruction is trying to divide by zero");
		} else {
			try {
				this->push(*firstOperand % *secondOperand);
			} catch (const OperandError &error) {
				this->pop();
				throw CoreError("Mod result is lower than 2");
			}
		}
	}
}

void Core::print(IOperand *operand) {
	Hatchery hatchery;
	IOperand *newOperand = hatchery.createOperand(Int8, "Kafei"); 

	(void)operand;
	try {
		this->assert(newOperand);	
	} catch (const OperandError &error) {
		throw CoreError("The last element on the stack is not an Int8");
	}

	std::istringstream buffer(this->_memory.getStack().top()->toString());
	int value;

	buffer >> value;
	char ascii = static_cast<char>(value);
	std::cout << ascii << std::endl;
}
