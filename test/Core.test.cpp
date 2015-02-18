/* 
* @Author: gicque_p
* @Date:   2015-02-13 14:23:08
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-18 09:34:55
*/

#include "UnitTests.hpp"
#include "Core.hpp"
#include "Hatchery.hpp"

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
}

void testPush(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Double, "42.85");
	IOperand *thirdOperand = hatchery.createOperand(Int16, "42.52");

	try {
		core.push(firstOperand);
	} catch (const std::exception &error) {
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "8")) {
		printError("Push method is not inserting the right value");
	}

	try {
		core.push(secondOperand);
	} catch (const std::exception &error) {
		printError("Push method is catching an exception");
	}

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "42.85")) {
		printError("Push method is not inserting the right value");
	}

	try {
		core.push(thirdOperand);
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
	Hatchery hatchery;
	IOperand *operand = hatchery.createOperand(Int8, "42");
	bool status = false;

	firstCore.push(operand);
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
	Core core;
	Hatchery hatchery;

	std::stringstream buffer;
	std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

	IOperand *firstOperand = hatchery.createOperand(Int8, "42");
	IOperand *secondOperand = hatchery.createOperand(Int16, "42");
	IOperand *thirdOperand = hatchery.createOperand(Int32, "-42");
	IOperand *fourthOperand = hatchery.createOperand(Float, "42.50");
	IOperand *fifthOperand = hatchery.createOperand(Double, "42.50");

	core.push(firstOperand);
	core.push(secondOperand);
	core.push(thirdOperand);
	core.push(fourthOperand);
	core.push(fifthOperand);

	core.dump();
	std::string dump = buffer.str();
	std::cout.rdbuf(old);

	if (UnitTests::isNotEqual(dump, "42.5\n42.5\n-42\n42\n4\n")) {
		printError("Dump method is not dumping all right values");
	}
}

void testAssert(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "42");
	IOperand *secondOperand = hatchery.createOperand(Int16, "42");
	bool status = false;

	core.push(firstOperand);
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
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16,"16");
	IOperand *thirdOperand = hatchery.createOperand(Int32,"-24");
	bool status = false;

	try {
		core.add();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Add method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
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

	core.push(thirdOperand);
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
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16, "16");
	IOperand *thirdOperand = hatchery.createOperand(Int32, "8");
	bool status = false;

	try {
		core.sub();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Sub method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
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

	core.push(thirdOperand);
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
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16,"16");
	IOperand *thirdOperand = hatchery.createOperand(Int32,"-1");
	bool status = false;

	try {
		core.mul();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Mul method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
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

	core.push(thirdOperand);
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
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16,"16");
	IOperand *thirdOperand = hatchery.createOperand(Int32,"0");
	bool status = false;

	try {
		core.div();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Div method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
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

	core.push(thirdOperand);
	status = false;
	try {
		core.div();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Div method is not catching an exception as it ougth to be");		
	}

	core.push(thirdOperand);
	core.push(firstOperand);
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
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "8");
	IOperand *secondOperand = hatchery.createOperand(Int16, "15");
	bool status = false;

	try {
		core.mod();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Mod method is not catching an exception as it ougth to be");
	}

	core.push(firstOperand);
	core.push(secondOperand);
	status = false;
	try {
		core.mod();
	} catch (const Error &error) {
		printError("Mod method is catching an exception");
	}

	if (UnitTests::isNotEqual((int)core.getStack().size(), 1)) {
		printError("Mod method is not deleting elements in the stack after the operation");
	}

	if (UnitTests::isNotEqual(core.getStack().top()->toString(), "7")) {
		printError("Mod method is not moduling elements correctly");
	}

	core.push(firstOperand);
	core.push(firstOperand);
	try {
		core.mod();
	} catch (const Error &error) {
		status = true;
	}

	if (status == false) {
		printError("Mod method is not catching an exception as it ougth to be");
	}
}

void testPrint(void) {
	Core core;
	Hatchery hatchery;
	IOperand *firstOperand = hatchery.createOperand(Int8, "42");
	IOperand *secondOperand = hatchery.createOperand(Int16,"42");
	bool status = false;

	core.push(firstOperand);
	try {
		core.print();
	} catch (const Error &error) {
		printError("Print method is catching an exception");
	}
	
	core.push(secondOperand);
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
