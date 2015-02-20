/* 
* @Author: gicque_p
* @Date:   2015-02-11 19:17:13
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-20 15:31:06
*/

void testsHatchery(void);
void testsOperand(void);
void testsMemory(void);
void testsCore(void);
void testsParsing(void);

int main() {
	testsHatchery();
	testsOperand();
	testsMemory();
	testsCore();
	testsParsing();

	return 0;
}