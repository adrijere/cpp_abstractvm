/*
** Parser.cpp for Parser in /home/mathon_j/rendu/cpp_abstractvm/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Feb 17 22:44:53 2015 Jérémy MATHON
** Last update Fri Feb 20 23:18:17 2015 Jérémy MATHON
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

void			Parsing::checkLine(std::string &ins)
{
  size_t		cpt;
  char			*tmp;
  int			i;

  cpt = 0;
  if (ins[0] != '|' or ins.empty())
    throw ParsingError("Wrong instruction.");
  ins.erase(0, 2);
  cpt = ins.find("VALEUR");
  if (cpt != std::string::npos)
    {
      i = ins.copy(tmp, cpt, 0);
      tmp[i] = '\0';
      ins.erase(0, cpt);
      addInstruction(tmp);
      addValue(ins);
      ins.clear();
    }
  else
    {
      addInstruction(ins);
      addValue("-1");
    }
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
	  while (ins.compare("\n") != 0)
	    {
	      std::getline(file, ins);
	      checkLine(ins);
	    }
	}
    }
}
