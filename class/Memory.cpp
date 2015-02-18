/* 
* @Author: gicque_p
* @Date:   2015-02-18 16:07:36
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 17:15:48
*/

#include "Memory.hpp"

void Memory::pop(void) {
	this->_stack.pop();
}

void Memory::push(IOperand *operand) {
	this->_stack.push(operand);
}

void Memory::popInstruction(void) {
	this->_instructions.pop();
}

void Memory::pushInstruction(operandFunction function, IOperand *operand) {
	s_instructions structure;

	structure.function = function;
	structure.operand = operand;
	this->_instructions.push(structure);
}

std::stack<s_instructions> Memory::getInstructions(void) const {
	return this->_instructions;
}

std::stack<IOperand *> Memory::getStack(void) const {
	return this->_stack;
}
