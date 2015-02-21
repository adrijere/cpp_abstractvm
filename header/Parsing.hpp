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

# include	<iostream>
# include	<list>
# include	<string>
# include	<fstream>

# include	"Error.hpp"

class	Parsing
{
  std::list<std::string>	_instructions;
  std::list<std::string>	_values;
  std::string _separator;

public:
  Parsing() {};
  ~Parsing() {};
  
  std::list<std::string>	getInstructions(void) const;
  std::list<std::string>	getValues(void) const;
  std::string getSeparator(void) const;

  void				addInstruction(std::string);
  void				addValue(std::string);
  void				parsingGrammar();
  void				checkLine(std::string &);

  void getGrammar(const char *);
};

#endif /* !PARSING_HPP_ */
