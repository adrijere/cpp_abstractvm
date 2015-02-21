/* 
* @Author: gicque_p
* @Date:   2015-02-18 11:02:02
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-21 11:10:32
*/

#include "UnitTests.hpp"
#include "Parsing.hpp"

static void	testParsingGrammar(void);

void	testsParsing(void) {
	testParsingGrammar();
}

void	testParsingGrammar(void)
{
  Parsing	parser;

  parser.getGrammar();
  // parser.parsingGrammar();
}
