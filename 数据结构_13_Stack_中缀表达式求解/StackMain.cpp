#include "SqStack.h"
#include "InfixEvaluate.h"

/*
测试用例:
Stack Empty Error!
true
Memory reApply!
size=6:[11,12,13,14,]
14
14
13
12
11
Stack Empty Error!

--------------------------------
Process exited after 0.1906 seconds with return value 0
请按任意键继续. . .
 
*/
void testSqStack(){
	SqStack<int> iStack;
	iStack.traverse();
	cout<< boolalpha << iStack.isEmpty() << endl;
	for(int i=0;i<4; i++){
		iStack.push(11+i);	
	}
	
	iStack.traverse(); 
	int e ;
	iStack.getTop(e);
	cout << e << endl;
	
	for(int i=0;i<4; i++){
		iStack.pop(e);
		cout << e <<endl;
	}
	
	iStack.traverse();
}





int main(int argc, char** argv) {
	
	testInfixEvaluateDouble();
	
	//testSqStack();
	return 0;
}
