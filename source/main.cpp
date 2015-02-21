/* 
* @Author: gicque_p
* @Date:   2015-02-12 09:59:22
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-21 17:29:49
*/

#include "Parsing.hpp"
#include "Core.hpp"

int main(int argc, char **argv) {
	Parsing parsing;
	Core core;

	try {
		if (argc > 1) {
			std::ifstream file(argv[1]);
			parsing.getCommands(file);
		} else {
			parsing.getCommands(std::cin);
		}		
	} catch (const ParsingError &error) {
		std::cerr << error.what() << std::endl;
	}

    return 0;
}