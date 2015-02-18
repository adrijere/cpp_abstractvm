/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:22:30
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:38:43
*/

#ifndef PARSING_HPP_
# define PARSING_HPP_

# include <iostream>
# include <map>

# include "Core.hpp"
# include "Error.hpp"

typedef void (Core::*voidFunction)(void);
typedef void (Core::*operandFunction)(IOperand *);

class Parsing {
	std::map<std::string, voidFunction> _firstMap;
	std::map<std::string, operandFunction> _secondMap;

 public:
	Parsing();
	~Parsing() {};

	std::map<std::string, voidFunction> getFirstMap(void) const;
	std::map<std::string, operandFunction> getSecondMap(void) const;
};

#endif /* !PARSING_HPP_ */
