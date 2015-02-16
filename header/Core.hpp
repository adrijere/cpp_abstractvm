#ifndef CORE_HPP_
# define CORE_HPP_

# include <iostream>
# include <stack>

# include "Error.hpp"
# include "IOperand.hpp"

class Core {
	std::stack<IOperand *> _stack;

 public:
	Core() {};
	~Core() {};

	std::stack<IOperand *> getStack(void) const;

	void push(IOperand *);
	void pop(void);
	void dump(void);
	void assert(const IOperand &);
	void add(void);
	void sub(void);
	void mul(void);
	void div(void);
	void mod(void);
	void print(void);
	void exit(void);
};

#endif /* !CORE_HPP_ */
