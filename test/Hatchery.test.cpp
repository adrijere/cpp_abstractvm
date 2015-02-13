/* 
* @Author: gicque_p
* @Date:   2015-02-13 12:21:51
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 16:50:12
*/

#include "UnitTests.hpp"
#include "Hatchery.hpp"

static void testCreateOperand(void);

void testsHatchery(void) {
	testCreateOperand();
}

void testCreateOperand(void) {
	Hatchery hatchery;

	try {
		hatchery.createOperand(INT8, "Kafei");
	} catch (const Error &error) {
		printError("createOperand method is catching an exception");
	}

	try {
		hatchery.createOperand(INT32, "Kafei");
	} catch (const Error &error) {
		printError("createOperand method is catching an exception");
	}
}