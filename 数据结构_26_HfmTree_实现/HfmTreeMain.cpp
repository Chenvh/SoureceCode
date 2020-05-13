#include "TestFn.h"
int main(int argc, char** argv) {
	
	//函数指针数组,用于测试 
	void (*fn[])() = {testInit,createHfmTeeFromArr};
	
	fn[1](); 
	
	
	return 0;
}
