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

std::list<std::string>	Parsing::getInstructions(void) const
{
  return (this->_instructions);
}

std::list<std::string>	Parsing::getValues(void) const 
{
  return (this->_values);
}

std::string Parsing::getSeparator(void) const
{
  return (this->_separator);
}

void			Parsing::addInstruction(std::string ins)
{
  this->_instructions.push_back(ins);
}

void			Parsing::addValue(std::string value)
{
  this->_values.push_back(value);
}

void			Parsing::checkLine(std::string &ins)
{
  size_t		cpt;
  char			*tmp;
  int			i;

  cpt = 0;
  tmp = NULL;
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

void Parsing::getGrammar(const char *filename) {
	std::ifstream file;
	std::string line;

	file.open(filename, std::ifstream::in);
	if (file) {
		while (getline(file, line)) {
			if (line == "INSTR :=") {
				while (getline(file, line) and line.size() != 0 and line.at(0) == '|') {
					line.erase(0, 2);
					if (line.find(" VALUE") != line.npos) {
						// PUT A BOOLEAN TO TRUE ?!!
					} else {
						// PUT A BOOLEAN TO FALSE ?!!
					}

					if (line.find_first_of(' ') != line.npos) {
						line.erase(line.find_first_of(' '), line.npos);					
					}

					try {
						this->addInstruction(line);					
					} catch (const std::exception &error) {
						throw ParsingError(error.what());
					}
				}
			}

			if (line == "VALUE :=") {
				while (getline(file, line) and line.size() != 0 and line.at(0) == '|') {
					line.erase(0, 2);
					try {
						this->addValue(line);					
					} catch (const std::exception &error) {
						throw ParsingError(error.what());
					}
				}
			}

			if (line.find("SEP := ") != line.npos) {
				line.erase(0, 7);
				if (line.find_first_of('"') != line.npos and line.find_last_of('"') != line.npos) {
					line.erase(0, line.find_first_of('"') + 1);
					line.erase(line.find_last_of('"'), line.npos);

					if (line == "\\n") {
						this->_separator = "\n";
					} else {
						this->_separator = line;
					}
				}
			}
		}
	} else {
		throw ParsingError("Grammar file does not exists");
	}

	if (this->_instructions.empty()) {
		throw ParsingError("Instructions list is empty");
	}

	if (this->_values.empty()) {
		throw ParsingError("Values list is empty");
	}

	if (this->_separator.empty()) {
		throw ParsingError("Separator character is set to Null");
	}
}

void			Parsing::parsingGrammar()
{
  std::ifstream		file;
  std::string		ins;

  file.open("grammar.txt", std::ifstream::in);
  if (file.fail())
	throw ParsingError("Can't open grammar file");
  while (getline(file, ins))
	{
	  if (ins == "INSTR :=")
		{
		  while (ins.compare("\n") != 0)
			{
			  std::getline(file, ins);
			try {
			  checkLine(ins);            
			} catch (const ParsingError &error) {
			  throw ParsingError(error.what());
			}
			}
		 }
	}
}
