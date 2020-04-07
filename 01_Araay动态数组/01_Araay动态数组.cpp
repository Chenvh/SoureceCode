/*线性表之顺序表
	动态数组
*/
#include"com.h"

class ArrayD {
	private :
		int *elements;//起始位置
		int length;//长度:元素的个数 
		int size;//空间大小 
	public : 
		//初始化   
	void getArray (int n) {
	//	elements = (int*)malloc(sizeof(int)*n);	//申请内存空间
		elements = new int[n];
		if (elements == NULL) {
			cout << "error memory!" <<endl;
			return;
		}
		length = 0;
		
	}
	
	//遍历 traverse
	void show () {
		cout << "length" << length << ", BaseAddress=" << hex <<elements << endl;
		for (int i=0; i<length; i++) {
			cout << elements[i];
			
		}
	}
	
	
}; 
		//test
int main(){
	ArrayD arr(20);
	//arr.getArray(10);
	arr.show();
	
	for (int i=0; i<13; i++) {
		arr.add(i+20);
	}
	arr.show();
//	arr.addByIndex(-1, 2020);
	arr.show();
} 










