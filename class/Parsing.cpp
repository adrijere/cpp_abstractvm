/*
** Parser.cpp for Parser in /home/mathon_j/rendu/cpp_abstractvm/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Feb 17 22:44:53 2015 Jérémy MATHON
** Last update Fri Feb 20 23:18:17 2015 Pierrick Gicquelais
*/

#include	"Parsing.hpp"

Parsing::Parsing() {
	this->_instructions.push_back(std::make_pair("push", true));
	this->_instructions.push_back(std::make_pair("pop", false));
	this->_instructions.push_back(std::make_pair("dump", false));
	this->_instructions.push_back(std::make_pair("assert", true));
	this->_instructions.push_back(std::make_pair("add", false));
	this->_instructions.push_back(std::make_pair("sub", false));
	this->_instructions.push_back(std::make_pair("mul", false));
	this->_instructions.push_back(std::make_pair("div", false));
	this->_instructions.push_back(std::make_pair("mod", false));
	this->_instructions.push_back(std::make_pair("print", false));

	this->_values.push_back("int8");
	this->_values.push_back("int16");
	this->_values.push_back("int32");
	this->_values.push_back("float");
	this->_values.push_back("double");

	this->_line = 1;
	this->_exit = false;
}

void Parsing::getCommands(const char *filename) {
	std::ifstream file;
	std::string line;

	file.open(filename, std::ifstream::in);
	if (file) {
		while (getline(file, line)) {
			if (line.size() != 0 and line.at(0) != ';') {
				if (line.find_first_of(';') != line.npos) {
					line.erase(line.find_first_of(';'), line.npos);
				}

				if (line == "exit") {
					this->_exit = true;
					break;
				} else {
					this->commandLine(line);
				}
			}
			this->_line++;
		}

		if (this->_exit == false) {
			throw ParsingError("You must finish your commands file with exit instruction");
		}
	} else {
		throw ParsingError("Commands file does not exists");
	}
}

void Parsing::commandLine(const std::string &line) {
	std::istringstream word(line);
	std::string instruction;
	std::string type;
	std::string value;
	bool status = false;

	word >> instruction;
	word >> type;

	if (!type.empty()) {
		if (type.find('(') != type.npos and type.find(')') != type.npos) {
			value = type.substr(type.find_first_of('(') + 1);
			value = value.substr(0, value.find_last_of(')'));
			type.erase(type.find_first_of('('), type.npos);
			status = true;
		} else {
			throw ParsingError(this->getErrorLine());
		}
	}

	if (std::find(this->_instructions.begin(), this->_instructions.end(), std::make_pair(instruction, status)) == this->_instructions.end()) {
		throw ParsingError(this->getErrorLine());
	} else {
		std::cout << "instr: " << instruction << "\t| type: " << type << "\t| value: " << value << std::endl;
	}
}

std::string Parsing::getErrorLine(void) const {
	std::stringstream stream;
	stream << "Line ";
	stream << this->_line;
	stream << ": Parsing Error";

	return stream.str();
}

std::list<std::pair<std::string, bool> > Parsing::getInstructions(void) const {
	return this->_instructions;
}

std::list<std::string>	Parsing::getValues(void) const {
	return this->_values;
}

// void Parsing::getGrammar(const char *filename = "grammar.txt") {
// 	std::ifstream file;
// 	std::string line;

// 	file.open(filename, std::ifstream::in);
// 	if (file) {
// 		while (getline(file, line)) {
// 			if (line == "INSTR :=") {
// 				while (getline(file, line) and line.size() != 0 and line.at(0) == '|') {
// 					line.erase(0, 2);
// 					if (line.find(" VALUE") != line.npos) {
// 						// PUT A BOOLEAN TO TRUE ?!!
// 					} else {
// 						// PUT A BOOLEAN TO FALSE ?!!
// 					}

// 					if (line.find_first_of(' ') != line.npos) {
// 						line.erase(line.find_first_of(' '), line.npos);
// 					}

// 					try {
// 						this->addInstruction(line);
// 					} catch (const std::exception &error) {
// 						throw ParsingError(error.what());
// 					}
// 				}
// 			}

// 			if (line == "VALUE :=") {
// 				while (getline(file, line) and line.size() != 0 and line.at(0) == '|') {
// 					line.erase(0, 2);
// 					try {
// 						this->addValue(line);
// 					} catch (const std::exception &error) {
// 						throw ParsingError(error.what());
// 					}
// 				}
// 			}

// 			if (line.find("SEP := ") != line.npos) {
// 				line.erase(0, 7);
// 				if (line.find_first_of('"') != line.npos and line.find_last_of('"') != line.npos) {
// 					line.erase(0, line.find_first_of('"') + 1);
// 					line.erase(line.find_last_of('"'), line.npos);

// 					if (line == "\\n") {
// 						this->_separator = "\n";
// 					} else {
// 						this->_separator = line;
// 					}
// 				}
// 			}
// 		}
// 	} else {
// 		throw ParsingError("Grammar file does not exists");
// 	}

// 	if (this->_instructions.empty()) {
// 		throw ParsingError("Instructions list is empty");
// 	}

// 	if (this->_values.empty()) {
// 		throw ParsingError("Values list is empty");
// 	}

// 	if (this->_separator.empty()) {
// 		throw ParsingError("Separator character is set to Null");
// 	}
// }
