#include "TestFn.h"
int main(int argc, char** argv) {
	
	//����ָ������,���ڲ��� 
	void (*fn[])() = {testInit,createHfmTeeFromArr};
	
	fn[1](); 
	
	
	return 0;
}
