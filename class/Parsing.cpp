/*
** Parser.cpp for Parser in /home/mathon_j/rendu/cpp_abstractvm/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Feb 17 22:44:53 2015 Jérémy MATHON
** Last update Wed Feb 18 16:31:23 2015 Jérémy MATHON
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

void			Parsing::checkLine(std::string const &ins)
{
  std::cout << ins << std::endl;
}

void			Parsing::parsingGrammar()
{
  std::ifstream		file;
  std::string		ins;

  file.open("grammar.txt", std::ifstream::in);
  if (file.fail())
    throw ParsingError("Can't open grammar file");
  while (std::getline(file, ins))
    {
      if (ins == "INSTR :=")
	{
	  while (ins.compare(" ") != 0)
	    {
	      std::getline(file, ins);
	      checkLine(ins);
	    }
	}
    }
}
