/*
** Parser.hpp for Parser in /home/mathon_j/rendu/cpp_abstractvm/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Feb 17 22:39:20 2015 Jérémy MATHON
** Last update Fri Feb 20 22:48:27 2015 Jérémy MATHON
*/

#ifndef PARSING_HPP_
# define PARSING_HPP_

# include <iostream>
# include <sstream>
# include <fstream>
# include <algorithm>
# include <list>

# include	"Error.hpp"

class	Parsing {
	std::list<std::pair<std::string, bool> >	_instructions;
	std::list<std::string>	_values;
	unsigned int _line;
	unsigned int _elements;
	bool  _exit;

public:
	Parsing();
	~Parsing() {};

	void getCommands(std::istream &);
	void commandLine(const std::string &);
	void checkElements(const std::string &);
	void isNumber(const std::string &);

	std::list<std::pair<std::string, bool> >	getInstructions(void) const;
	std::list<std::string>	getValues(void) const;
	std::string getErrorLine(const char * = "") const;

	// void getGrammar(const char *);
};

#endif /* !PARSING_HPP_ */
