/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:23:08
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-14 19:15:04
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
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(core.getList().back()->toString(), "42")) {
		printError("Push method is not inserting the right value");
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

	if (UnitTests::isNotEqual((int)secondCore.getList().size(), 0)) {
		printError("Pop method is not deleting elements in the stack");
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
	Int8 firstOperand("8");
	Int16 secondOperand("16");
	bool status = false;

	try {
		core.add();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Add method is not catching an exception as it ougth to be");
	}

	core.push(&firstOperand);
	core.push(&secondOperand);
	try {
		core.add();
	} catch (const Error &error) {
		printError("Add method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getList().size(), 1)) {
		printError("Add method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getList().back()->toString(), "24")) {
		printError("Add method is not adding elements correctly");
	}
}

void testSub(void) {
	Core core;
	Int8 firstOperand("8");
	Int16 secondOperand("16");
	bool status = false;

	try {
		core.sub();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Sub method is not catching an exception as it ougth to be");
	}

	core.push(&firstOperand);
	core.push(&secondOperand);
	try {
		core.sub();
	} catch (const Error &error) {
		printError("Sub method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getList().size(), 1)) {
		printError("Sub method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getList().back()->toString(), "8")) {
		printError("Sub method is not substribing elements correctly");
	}
}

void testMul(void) {
	Core core;
	Int8 firstOperand("8");
	Int16 secondOperand("16");
	bool status = false;

	try {
		core.mul();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Mul method is not catching an exception as it ougth to be");
	}

	core.push(&firstOperand);
	core.push(&secondOperand);
	try {
		core.mul();
	} catch (const Error &error) {
		printError("Mul method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getList().size(), 1)) {
		printError("Mul method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getList().back()->toString(), "128")) {
		printError("Mul method is not multiplying elements correctly");
	}
}

void testDiv(void) {

}

void testMod(void) {

}

void testPrint(void) {
	Core core;
	Int8 firstOperand("42");
	Int16 secondOperand("42");
	bool status = false;

	core.push(&firstOperand);
	try {
		core.print();
	} catch (const Error &error) {
		printError("Print method is catching an exception");
	}
	
	core.push(&secondOperand);
	try {
		core.print();
	} catch (const Error &error) {
		status = true;	
	}

	if (status == false) {
		printError("Print method is not catching an exception as it ought to be");
	}
}

void testExit(void) {

}
