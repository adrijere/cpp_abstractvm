/* 
* @Author: gicque_p
* @Date:   2015-02-18 11:02:02
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-21 12:21:29
*/

#include "UnitTests.hpp"
#include "Parsing.hpp"

static void	testParsingGrammar(void);
static void testGetGrammar(void);

void	testsParsing(void) {
	testParsingGrammar();

	testGetGrammar();
}

void testGetGrammar(void) {
	Parsing firstParsing;
	Parsing secondParsing;
	Parsing thirdParsing;
	Parsing fourthParsing;
	Parsing fifthParsing;

	bool status = false;

	try { 
		firstParsing.getGrammar("foo.txt");
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("GetGrammar method is not catching an exception as it ougth to be");
	}

	status = false;
	try { 
		firstParsing.getGrammar("test/data/wrongGrammar1.txt");
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("GetGrammar method is not catching an exception as it ougth to be");
	}

	status = false;
	try { 
		secondParsing.getGrammar("test/data/wrongGrammar2.txt");
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("GetGrammar method is not catching an exception as it ougth to be");
	}

	status = false;
	try { 
		thirdParsing.getGrammar("test/data/wrongGrammar3.txt");
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("GetGrammar method is not catching an exception as it ougth to be");
	}

	status = false;
	try { 
		fourthParsing.getGrammar("test/data/wrongGrammar4.txt");
	} catch (const ParsingError &error) {
		status = true;
	}

	if (UnitTests::isFalse(status)) {
		printError("GetGrammar method is not catching an exception as it ougth to be");
	}

	try {
		fifthParsing.getGrammar("grammar.txt");
	} catch (const ParsingError &error) {
		printError("GetGrammar method is catching an exception");		
	}
}

void	testParsingGrammar(void)
{
  Parsing	parser;

  // parser.parsingGrammar();
}
