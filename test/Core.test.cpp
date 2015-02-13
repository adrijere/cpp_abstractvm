/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:23:08
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-13 16:50:21
*/

#include "UnitTests.hpp"
#include "Core.hpp"
#include "Int8.hpp"
#include "Int16.hpp"

void testPush(void);
void testPop(void);
void testDump(void);
void testAssert(void);
void testAdd(void);
void testSub(void);
void testMul(void);
void testDiv(void);
void testMod(void);
void testPrint(void);
void testExit(void);

void testsCore(void) {
	testPush();
	testPop();
	testDump();
	testAssert();
	testAdd();
	testSub();
	testMul();
	testDiv();
	testMod();
	testPrint();
	testExit();
}

void testPush(void) {
	Core core;
	Int8 operand("42");

	try {
		core.push(&operand);
	} catch (const std::exception &error) {
		printError("PushMethod is catching an exception");
	}
}

void testPop(void) {
	Core firstCore;
	Core secondCore;
	Int8 operand("42");
	bool status = false;

	firstCore.push(&operand);
	try {
		firstCore.pop();
	} catch (const Error &error) {
		printError("Pop method is catching an exception");
	}

	try {
		secondCore.pop();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Pop method is not catching an exception as it ought to be");
	}
}

void testDump(void) {
}

void testAssert(void) {
	Core core;
	Int8 firstOperand("42");
	Int16 secondOperand("42");
	bool status = false;

	core.push(&firstOperand);
	try {
		core.assert(firstOperand);
	} catch (const Error &error) {
		printError("Assert method is catching an exception");
	}

	try {
		core.assert(secondOperand);
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Assert method is not catching an exception as it ought to be");
	}
}

void testAdd(void) {
	Core core;

	try {
		core.add();
	} catch (const Error &error) {
		printError("Add method is catching an exception");
	}
}

void testSub(void) {

}

void testMul(void) {

}

void testDiv(void) {

}

void testMod(void) {

}

void testPrint(void) {

}

void testExit(void) {

}
