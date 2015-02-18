/*
** Parser.cpp for Parser in /home/mathon_j/rendu/cpp_abstractvm/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Feb 17 22:44:53 2015 Jérémy MATHON
** Last update Wed Feb 18 15:19:36 2015 Jérémy MATHON
*/

#include	"Parsing.hpp"

std::list<std::string>	Parsing::getInstruction(void) const
{
  return (this->_instructions);
}

std::list<std::string>	Parsing::getValue(void) const 
{
  return (this->_value);
}

char			*Parsing::getSep(void) const
{
  return (this->_sep);
}

void			Parsing::addInstruction(std::string ins)
{
  this->_instructions.push_back(ins);
}

void			Parsing::addValue(std::string value)
{
  this->_value.push_back(value);
}
