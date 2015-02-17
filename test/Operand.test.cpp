/* 
* @Author: gicque_p
* @Date:   2015-02-17 20:20:50
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-17 21:03:48
*/

#include "UnitTests.hpp"
#include "Operand.hpp"

void testOverloadAdd(void);
void testOverloadSub(void);
void testOverloadMul(void);
void testOverloadDiv(void);
void testOverloadMod(void);

void testsOperand(void) {
	testOverloadAdd();
	testOverloadSub();
	testOverloadMul();
	testOverloadDiv();
	testOverloadMod();
}

void testOverloadAdd(void) {
	Hatchery hatchery;

	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Float, "42.50");
	IOperand *thirdOperand = *firstOperand + *secondOperand;

	if (UnitTests::isNotEqual(thirdOperand->getType(), Float)) {
		printError("Add Overload is not returning the right type for IOperand");
	}

	if (UnitTests::isNotEqual(thirdOperand->toString(), "50.5")) {
		printError("Add Overload is not returning the right value for IOperand");
	}
}

void testOverloadSub(void) {
	Hatchery hatchery;

	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Float, "42.50");
	IOperand *thirdOperand = *secondOperand - *firstOperand;

	if (UnitTests::isNotEqual(thirdOperand->getType(), Float)) {
		printError("Add Overload is not returning the right type for IOperand");
	}

	if (UnitTests::isNotEqual(thirdOperand->toString(), "34.5")) {
		printError("Add Overload is not returning the right value for IOperand");
	}
}

void testOverloadMul(void) {
	Hatchery hatchery;

	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Float, "42.50");
	IOperand *thirdOperand = (*firstOperand) * (*secondOperand);

	if (UnitTests::isNotEqual(thirdOperand->getType(), Float)) {
		printError("Add Overload is not returning the right type for IOperand");
	}

	if (UnitTests::isNotEqual(thirdOperand->toString(), "340")) {
		printError("Add Overload is not returning the right value for IOperand");
	}
}

void testOverloadDiv(void) {
	Hatchery hatchery;

	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Float, "42.50");
	IOperand *thirdOperand = *secondOperand / *firstOperand;

	if (UnitTests::isNotEqual(thirdOperand->getType(), Float)) {
		printError("Add Overload is not returning the right type for IOperand");
	}

	if (UnitTests::isNotEqual(thirdOperand->toString(), "5.3125")) {
		printError("Add Overload is not returning the right value for IOperand");
	}
}

void testOverloadMod(void) {
	Hatchery hatchery;

	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Float, "42.50");
	IOperand *thirdOperand = *secondOperand % *firstOperand;

	if (UnitTests::isNotEqual(thirdOperand->getType(), Float)) {
		printError("Add Overload is not returning the right type for IOperand");
	}

	if (UnitTests::isNotEqual(thirdOperand->toString(), "2")) {
		printError("Add Overload is not returning the right value for IOperand");
	}
}
