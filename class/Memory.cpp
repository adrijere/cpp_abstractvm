/* 
* @Author: gicque_p
* @Date:   2015-02-18 16:07:36
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 16:44:18
*/

#include "Memory.hpp"

void Memory::pop(void) {
	this->_stack.pop();
}

void Memory::push(IOperand *operand) {
	this->_stack.push(operand);
}

void Memory::popInstructions(void) {
	this->_instructions.pop();
}

void Memory::pushInstructions(operandFunction function, IOperand *operand) {
	s_instructions structure;

	structure.function = function;
	structure.operand = operand;
	this->_instructions.push(structure);
}