/* 
* @Author: gicque_p
* @Date:   2015-02-12 09:59:22
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 11:35:25
*/

#include "Parsing.hpp"
#include "Core.hpp"
#include "Hatchery.hpp"

int main() {
	Parsing parsing;

	Core core;
	Hatchery hatchery;

	IOperand *firstOperand = hatchery.createOperand(Int32, "2");
	IOperand *secondOperand = hatchery.createOperand(Int32, "3");

	std::map<std::string, voidFunction> map = parsing.getFirstMap();

	core.push(firstOperand);
	core.push(secondOperand);
	core.add();

	IOperand *thirdOperand = hatchery.createOperand(Int32, "5");

	core.assert(thirdOperand);
	(core.*map["dump"])();
	// core.dump();
	
    return 0;
}