/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:23:08
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-16 10:30:07
*/

#include "UnitTests.hpp"
#include "Core.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

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

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "42")) {
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

	status = false;
	try {
		secondCore.pop();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Pop method is not catching an exception as it ought to be");
	}

	if (UnitTests::isNotEqual((int)secondCore.getStack().size(), 0)) {
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

	status = false;
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
	Int8 thirdOperand("-24");
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
	status = false;
	try {
		core.add();
	} catch (const Error &error) {
		printError("Add method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getStack().size(), 1)) {
		printError("Add method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "24")) {
		printError("Add method is not adding elements correctly");
	}

	core.push(&thirdOperand);
	status = false;
	try {
		core.add();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Add method is not catching an exception as it ougth to be");
	}
}

void testSub(void) {
	Core core;
	Int8 firstOperand("8");
	Int16 secondOperand("16");
	Int8 thirdOperand("8");
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
	status = false;
	try {
		core.sub();
	} catch (const Error &error) {
		printError("Sub method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getStack().size(), 1)) {
		printError("Sub method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "8")) {
		printError("Sub method is not substribing elements correctly");
	}

	core.push(&thirdOperand);
	status = false;
	try {
		core.sub();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Sub method is not catching an exception as it ougth to be");
	}
}

void testMul(void) {
	Core core;
	Int8 firstOperand("8");
	Int16 secondOperand("16");
	Int8 thirdOperand("-1");
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
	status = false;
	try {
		core.mul();
	} catch (const Error &error) {
		printError("Mul method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getStack().size(), 1)) {
		printError("Mul method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "128")) {
		printError("Mul method is not multiplying elements correctly");
	}

	core.push(&thirdOperand);
	status = false;
	try {
		core.mul();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Mul method is not catching an exception as is ougth to be");
	}
}

void testDiv(void) {
	Core core;
	Int8 firstOperand("8");
	Int16 secondOperand("16");
	Int32 thirdOperand("0");
	Int8 fourthOperand("2");
	bool status = false;

	try {
		core.div();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Div method is not catching an exception as it ougth to be");
	}

	core.push(&firstOperand);
	core.push(&secondOperand);
	status = false;
	try {
		core.div();
	} catch (const Error &error) {
		printError("Div method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getStack().size(), 1)) {
		printError("Div method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "2")) {
		printError("Div method is not multiplying elements correctly");
	}

	core.push(&thirdOperand);
	status = false;
	try {
		core.div();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Div method is not catching an exception as it ougth to be");		
	}

	core.push(&fourthOperand);
	core.push(&firstOperand);
	status = false;
	try {
		core.div();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Div method is not catching an exception as it ougth to be");
	}
}

void testMod(void) {
	Core core;
	Int8 firstOperand("8");
	Int16 secondOperand("16");
	bool status = false;

	try {
		core.mod();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Mod method is not catching an exception as it ougth to be");
	}

	core.push(&firstOperand);
	core.push(&secondOperand);
	status = false;
	try {
		core.mod();
	} catch (const Error &error) {
		printError("Mod method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getStack().size(), 1)) {
		printError("Mod method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "0")) {
		printError("Mod method is not multiplying elements correctly");
	}
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
	status = false;
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
