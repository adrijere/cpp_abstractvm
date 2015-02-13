/* 
* @Author: gicque_p
* @Date:   2015-02-12 09:59:22
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 16:17:35
*/

#include "Core.hpp"
#include "Int8.hpp"

int main() {
	Core core;

	Int8 inteuh("coucou");

	core.push(&inteuh);

	try {
		core.print();	
	} catch (const Error *error) {
		std::cerr << error->what() << std::endl;
	}

    return 0;
}