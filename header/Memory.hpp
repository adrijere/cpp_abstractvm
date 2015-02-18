/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:38:43
*/

#ifndef MEMORY_HPP_
# define MEMORY_HPP_

# include <iostream>
# include <stack>
# include <queue>

# include "IOperand.hpp"

class Core;
typedef void (Core::*operandFunction)(IOperand *);

struct s_instructions {
	operandFunction function;
	IOperand *operand;
};

class Memory {
	std::queue<s_instructions> _queue;
	std::stack<IOperand *> _stack;

 public:
	Memory() {};
	~Memory() {};

	void pop();
	void push(IOperand *);

	void popInstruction();
	void pushInstruction(operandFunction, IOperand *);

	std::queue<s_instructions> getQueue(void) const;
	std::stack<IOperand *> getStack(void) const;
};

#endif /* !MEMORY_HPP_ */
