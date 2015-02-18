/* 
* @Author: gicque_p
* @Date:   2015-02-12 09:59:22
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 09:34:18
*/

#include "Core.hpp"
#include "Hatchery.hpp"

int main() {
	Core core;
	Hatchery hatchery;

	IOperand *firstOperand = hatchery.createOperand(Int32, "2");
	IOperand *secondOperand = hatchery.createOperand(Int32, "3");

	core.push(firstOperand);
	core.push(secondOperand);
	core.add();

	IOperand *thirdOperand = hatchery.createOperand(Int32, "5");

	core.assert(thirdOperand);
	core.dump();
	
    return 0;
}