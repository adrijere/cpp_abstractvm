/* 
* @Author: gicque_p
* @Date:   2015-02-12 09:59:22
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-21 11:06:20
*/

#include "Parsing.hpp"
#include "Core.hpp"
#include "Hatchery.hpp"
#include "Memory.hpp"
#include "Error.hpp"
#include <map>
#include <sstream>

int main() {
	Core core;

	std::string line;
	std::map<std::string, void (Core::*)(IOperand *)> map;

	map["push"] = &Core::push;
	map["pop"] = &Core::pop;
	map["dump"] = &Core::dump;
	map["assert"] = &Core::assert;
	map["add"] = &Core::add;
	map["sub"] = &Core::sub;
	map["mul"] = &Core::mul;
	map["div"] = &Core::div;
	map["mod"] = &Core::mod;
	map["print"] = &Core::print;

	Hatchery hatchery;
	// IOperand *operand = hatchery.createOperand(Int8, "42");

	// while (std::cin >> line) {
		// if (!word.empty()) {
		// 	if (map[word] and word != "") {
		// 		try {
		// 			(core.*map[word])(operand);
		// 		} catch (const CoreError &error) {
		// 			std::cerr << error.what() << std::endl;
		// 			return -1;
		// 		}
		// 	} else {
		// 		std::cout << "Instruction non reconnue" << std::endl;
		// 	}
		// }
	// }

    return 0;
}