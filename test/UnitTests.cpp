/* 
* @Author: gicque_p
* @Date:   2015-02-11 19:17:13
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-12 10:06:36
*/

#include <fstream>
#include "UnitTests.hpp"
using namespace std;

/*
* This is simple main test example
* Of course you can use any kind of tests in your files
* For example, you can implement try and catch tests and abort your programm when failed
*/

int main() {

	if (UnitTests::isTrue(true) == false) {
		printError("isTrue method is not working");
	}

	if (UnitTests::isFalse(false) == false) {
		printError("isFalse method is not working");
	}

	if (UnitTests::isEqual(42, 42) == false) {
		printError("isEqual method is not working");
	}

	if (UnitTests::isEqual("Kafei", "Kafei") == false) {
		printError("isEqual method is not working");
	}

	if (UnitTests::isNotEqual(42, 21) == false) {
		printError("isNotEqual method is not working");
	}

	if (UnitTests::isNotEqual("Kafei", "gicque_p") == false) {
		printError("isNotEqual method is not working");
	}

	if (UnitTests::isGreaterThan(42, 42) == true) {
		printError("isGreaterThan method is not working");
	}

	if (UnitTests::isGreaterThanOrEqual(42, 42) == false) {
		printError("isGreaterThanOrEqual method is not working");
	}

	if (UnitTests::isLowerThan(42, 42) == true) {
		printError("isLowerThan method is not working");
	}

	if (UnitTests::isLowerThanOrEqual(42, 42) == false) {
		printError("isLowerThanOrEqual method is not working");
	}

	if (UnitTests::isEmpty("") == false) {
		printError("isEmpty method is not working");
	}

	string arrayString[2] = { "Kafei", "gicque_p" };
	if (UnitTests::isContaining("Kafei", arrayString) == false) {
		printError("isContaining method is not working");
	}

	ifstream file("test/UnitTests.hpp");
	if (UnitTests::fileExists(file) == false) {
		printError("fileExists method is not working");
	}
	
	return 0;
}