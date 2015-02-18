/* 
* @Author: gicque_p
* @Date:   2015-02-18 16:07:36
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 18:13:38
*/

#include "Memory.hpp"

void Memory::pop(void) {
	this->_stack.pop();
}

void Memory::push(IOperand *operand) {
	this->_stack.push(operand);
}

void Memory::popInstruction(void) {
	this->_queue.pop();
}

void Memory::pushInstruction(operandFunction function, IOperand *operand) {
	s_instructions structure;

	structure.function = function;
	structure.operand = operand;
	this->_queue.push(structure);
}

std::queue<s_instructions> Memory::getQueue(void) const {
	return this->_queue;
}

std::stack<IOperand *> Memory::getStack(void) const {
	return this->_stack;
}
