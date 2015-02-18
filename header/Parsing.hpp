/*
** Parser.hpp for Parser in /home/mathon_j/rendu/cpp_abstractvm/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Feb 17 22:39:20 2015 Jérémy MATHON
** Last update Wed Feb 18 16:13:55 2015 Jérémy MATHON
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
  std::list<std::string>	_value;
  char				*_sep;

public:
  Parsing() {};
  ~Parsing() {};
  
  std::list<std::string>	getInstruction(void) const;
  std::list<std::string>	getValue(void) const;
  char				*getSep(void) const;
  void				addInstruction(std::string);
  void				addValue(std::string);
  void				parsingGrammar();
  void				checkLine(std::string const &);
};

#endif /* !PARSING_HPP_ */
