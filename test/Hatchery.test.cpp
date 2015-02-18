/* 
* @Author: gicque_p
* @Date:   2015-02-13 12:21:51
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 10:35:12
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
		hatchery.createOperand(Int8, "42");
	} catch (const HatcheryError &error) {
		printError("createOperand method is catching an exception");
	}

	try {
		hatchery.createOperand(Int32, "42");
	} catch (const HatcheryError &error) {
		printError("createOperand method is catching an exception");
	}
}