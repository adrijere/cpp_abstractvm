/* 
* @Author: gicque_p
* @Date:   2015-02-13 12:21:51
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 12:45:11
*/

#include "UnitTests.hpp"
#include "Hatchery.hpp"

static void testCreateOperand(void);

void testsHatchery(void) {
	testCreateOperand();
}

void testCreateOperand(void) {
	Hatchery hatchery;

	bool status = false;
	try {
		hatchery.createOperand(INT8, "Kafei");
	} catch (const Error &error) {
		status = true;
	}

	if (status == true) {
		printError("createOperand method with Int8 is catched");
	}

	// status = false;
	// try {
	// 	hatchery.createOperand(INT32, "Kafei");
	// } catch (const Error &error) {
	// 	status = true;
	// }

	// if (status == true) {
	// 	printError("createOperand method with Int32 is catched");
	// }
}