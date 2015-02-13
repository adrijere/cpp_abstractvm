/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 17:53:24
*/

#include "Core.hpp"
#include "Int8.hpp"

std::list<IOperand *> Core::getList(void) const {
	return this->_list;
}

void Core::push(IOperand *operand) {
	this->_list.push_back(operand);
}

void Core::pop(void) {
	if (this->_list.empty()) {
		throw Error("Pop instruction on an empty list");
	} else {
		this->_list.pop_back();
	}
}

void Core::dump(void) {
	for (std::list<IOperand *>::iterator iterator = this->_list.begin(), end = this->_list.end(); iterator != end; ++iterator) {
		std::cout << *iterator << std::endl;
	}
}

void Core::assert(const IOperand &operand) {
	if (this->_list.empty() or this->_list.back()->getType() != operand.getType()) {
		throw Error("Assert with a wrong operand type on the last element");
	}
}

void Core::add(void) {
	if (this->_list.size() < 2) {
		throw Error("Add instruction is not possible unless two elements are present in the stack");
	} else {
		// IOperand *firstOperand = this->_list.back();
		// this->_list.pop_back();
		// IOperand *secondOperand = this->_list.back();
		// this->_list.pop_back();

		// this->_list.push_back(firstOperand + secondOperand);
	}
}

void Core::sub(void) {

}

void Core::mul(void) {

}

void Core::div(void) {

}

void Core::mod(void) {

}

void Core::print(void) {
	this->assert(*new Int8(""));
}

void Core::exit(void) {

}
