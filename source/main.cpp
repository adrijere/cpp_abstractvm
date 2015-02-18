/* 
* @Author: gicque_p
* @Date:   2015-02-12 09:59:22
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 18:58:04
*/

#include "Parsing.hpp"
#include "Core.hpp"
#include "Hatchery.hpp"
#include "Memory.hpp"
#include "Error.hpp"
#include <map>

int main() {
	Core core;

	std::string cmd;
	std::map<std::string, void (Core::*)(IOperand *)> map;

	map["push"] = &Core::push;
	map["dump"] = &Core::dump;
	map["print"] = &Core::print;
	map["add"] = &Core::add;
	map["pop"] = &Core::pop;

	Hatchery hatchery;
	IOperand *operand = hatchery.createOperand(Int8, "42");

	while (std::cin >> cmd) {
		if (map[cmd]) {
			try {
				(core.*map[cmd])(operand);			
			} catch (const CoreError &error) {
				std::cerr << error.what() << std::endl;
				return -1;
			}
		} else {
			std::cout << "Instruction non reconnue" << std::endl;
		}
	}

    return 0;
}