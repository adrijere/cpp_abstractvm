/* 
* @Author: gicque_p
* @Date:   2015-02-21 18:05:45
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-21 18:06:11
*/


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

// void testGetGrammar(void) {
// 	Parsing firstParsing;
// 	Parsing secondParsing;
// 	Parsing thirdParsing;
// 	Parsing fourthParsing;
// 	Parsing fifthParsing;

// 	bool status = false;

// 	try { 
// 		firstParsing.getGrammar("foo.txt");
// 	} catch (const ParsingError &error) {
// 		status = true;
// 	}

// 	if (UnitTests::isFalse(status)) {
// 		printError("GetGrammar method is not catching an exception as it ougth to be");
// 	}

// 	status = false;
// 	try { 
// 		firstParsing.getGrammar("test/data/wrongGrammar1.txt");
// 	} catch (const ParsingError &error) {
// 		status = true;
// 	}

// 	if (UnitTests::isFalse(status)) {
// 		printError("GetGrammar method is not catching an exception as it ougth to be");
// 	}

// 	status = false;
// 	try { 
// 		secondParsing.getGrammar("test/data/wrongGrammar2.txt");
// 	} catch (const ParsingError &error) {
// 		status = true;
// 	}

// 	if (UnitTests::isFalse(status)) {
// 		printError("GetGrammar method is not catching an exception as it ougth to be");
// 	}

// 	status = false;
// 	try { 
// 		thirdParsing.getGrammar("test/data/wrongGrammar3.txt");
// 	} catch (const ParsingError &error) {
// 		status = true;
// 	}

// 	if (UnitTests::isFalse(status)) {
// 		printError("GetGrammar method is not catching an exception as it ougth to be");
// 	}

// 	status = false;
// 	try { 
// 		fourthParsing.getGrammar("test/data/wrongGrammar4.txt");
// 	} catch (const ParsingError &error) {
// 		status = true;
// 	}

// 	if (UnitTests::isFalse(status)) {
// 		printError("GetGrammar method is not catching an exception as it ougth to be");
// 	}

// 	try {
// 		fifthParsing.getGrammar("test/data/goodGrammar.txt");
// 	} catch (const ParsingError &error) {
// 		printError("GetGrammar method is catching an exception");		
// 	}
// }
