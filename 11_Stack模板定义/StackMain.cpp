#include "SqStack.h"

void testSqStack(){
	SqStack<int> iStack;
	iStack.traverse();
	cout<< boolalpha << iStack.isEmpty() << endl;
	for(int i=0;i<4; i++){
		iStack.push(11+i);	
	}
	
	iStack.traverse(); 
	int e ;
	for(int i=0;i<5; i++){
		iStack.pop(e);
		cout << e <<endl;
	}
	iStack.traverse();
}


int main(int argc, char** argv) {
	testSqStack();
	return 0;
}
