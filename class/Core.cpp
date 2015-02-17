/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-17 20:14:24
*/

#include "Core.hpp"
#include "Hatchery.hpp"

std::stack<IOperand *> Core::getStack(void) const {
	return this->_stack;
}

void Core::push(IOperand *operand) {
	this->_stack.push(operand);
}

void Core::pop(void) {
	if (this->_stack.empty()) {
		throw Error("Pop instruction on an empty stack");
	} else {
		this->_stack.pop();
	}
}

void Core::dump(void) {
	std::stack<IOperand *>stack = this->_stack;

	while (stack.size() > 0) {
		std::cout << stack.top()->toString() << std::endl;
		stack.pop();
	}
}

void Core::assert(const IOperand &operand) {
	if (this->_stack.empty() or this->_stack.top()->getType() != operand.getType()) {
		throw Error("Assert with a wrong operand type on the last element");
	}
}

void Core::add(void) {
	if (this->_stack.size() < 2) {
		throw Error("Add instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_stack.top();
		this->_stack.pop();
		IOperand *secondOperand = this->_stack.top();
		this->_stack.pop();

		try {
			this->push(*firstOperand + *secondOperand);
		} catch (const Error &error) {
			this->pop();
			throw Error("Add result is lower than 2");
		}
	}
}

void Core::sub(void) {
	if (this->_stack.size() < 2) {
		throw Error("Sub instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_stack.top();
		this->_stack.pop();
		IOperand *secondOperand = this->_stack.top();
		this->_stack.pop();

		try {
			this->push(*firstOperand - *secondOperand);
		} catch (const Error &error) {
			this->pop();
			throw Error("Sub result is lower than 2");
		}
	}
}

void Core::mul(void) {
	if (this->_stack.size() < 2) {
		throw Error("Mul instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_stack.top();
		this->_stack.pop();
		IOperand *secondOperand = this->_stack.top();
		this->_stack.pop();

		try {
			this->push(*firstOperand * (*secondOperand));
		} catch (const Error &error) {
			this->pop();
			throw Error("Mul result is lower than 2");
		}
	}
}

void Core::div(void) {
	if (this->_stack.size() < 2) {
		throw Error("Div instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_stack.top();
		this->_stack.pop();
		IOperand *secondOperand = this->_stack.top();
		this->_stack.pop();

		if (secondOperand->toString() == "0") {
			throw Error("Div instruction is trying to divide by zero");
		} else {
			try {
				this->push(*firstOperand / *secondOperand);
			} catch (const Error &error) {
				this->pop();
				throw Error("Div result is lower than 2");
			}
		}
	}
}

void Core::mod(void) {
	if (this->_stack.size() < 2) {
		throw Error("Mod instruction is not possible unless two elements are present in the stack");
	} else {
		IOperand *firstOperand = this->_stack.top();
		this->_stack.pop();
		IOperand *secondOperand = this->_stack.top();
		this->_stack.pop();

		if (secondOperand->toString() == "0") {
			throw Error("Mod instruction is trying to divide by zero");
		} else {
			try {
				this->push(*firstOperand % *secondOperand);
			} catch (const Error &error) {
				this->pop();
				throw Error("Mod result is lower than 2");
			}
		}
	}
}

void Core::print(void) {
	Hatchery hatchery;
	IOperand *operand = hatchery.createOperand(INT8, ""); 

	this->assert(*operand);
}

void Core::exit(void) {

}
