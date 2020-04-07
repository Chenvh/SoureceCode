/*线性表之顺序表动态数组 
*/
#include "Comm.h"
 
class ArrayD{
private :
	int * elements;//起始位置 
	int length;//长度:元素的个数 
public: 	
	//初始化 
	void init(int n){
		//elements = (int * )malloc(sizeof(int)* n);//申请内存
		elements = new int[n];
		
		if(elements == NULL){
			cout << "error memory!" <<endl;
			return;
		}
		length = 0;//长度0		
	} 
	
	//遍历traverse
	 void show(){
	 	cout << "length=" << length <<",BaseAddress=" 
		 << hex << elements << endl;
		for(int i=0; i<length; i++){
			cout << elements[i] ;
			
		}
	}			
}; 

//test
int main(){
	ArrayD arr;
	arr.init(10);
	arr.show();
} 

