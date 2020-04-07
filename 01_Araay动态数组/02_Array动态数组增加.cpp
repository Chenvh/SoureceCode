/*线性表之顺序表动态数组 
*/
#include "comm.h"
 
class ArrayD{
private :
	int * elements;//起始位置 
	int length;//长度:元素的个数 
	int size;//空间大小
	 
public: 
	//构造函数:名字与类名相同,由系统自动调用,无函数类型 
	ArrayD(int n=3){
		if(n <= 0){
			cout << "error Size!\n";
			return;
		}
		getArray(n);
	}
	
	//为数组申请n 个元素的内存 
	void getArray(int n){
		//elements = (int * )malloc(sizeof(int)* n);//申请内存
		elements = new int[n];
		
		if(elements == NULL){
			cout << "error memory!" <<endl;
			return;
		}
		length = 0;//长度0
		size = n;		
	} 
	
	//遍历traverse
	 void show(){
	 	cout << "length=" << length <<", size="<< size <<endl;
		// cout <<", BaseAddress=" << hex << elements << endl;
		
		//输出格式 形如 [1,2,3] 
		cout << "[";
		for(int i=0; i<length; i++){
			cout << elements[i]  ;
			cout << ","; 
		}
		cout << "]";
		cout << endl;
	}	

	
	//在尾部增加:加判断,空间大小是否已满 
	void add(int e){
		if(isFull()){
			//cout << "Spaec is full!\n";
			//return;
			reSize(); //增加空间 
		} 
		
		elements[length++] = e;
	}
	
	//在指定位置pos插入元素e
	void addByIndex(int pos, int e){
		//step0: 合法性验证 
		
		if(pos < 0 || pos > length){
			cout << "error position!\n";
			return ;
		} 
		
		//step1: 从最后至pos所有元素后移
		
		//step2: 插入
		 
	} 
	
	//获取数组长度
	int getLength(){
		return length;
	} 
	
		
	//空间大小是否已满
	bool isFull(){
		return length>size-1;	
	}
	
	//增长空间: 按1倍速度增加,让elements空间为2*size 
	void reSize(){
		cout << "memory reapply!\n";
		int *pTmp ;
		//step1:重新申请 
		pTmp = new int[2*size];//重新分配2*size个空间
		if(pTmp == NULL){
			cout << "memory apply fail!" << endl;
			return;
		}
		
		//step2: 拷贝
		for(int i = 0; i< length; i++){
			pTmp[i] = elements[i];
		} 
		
		//step3:update
		delete[]elements;//释放原来的内存 
		elements = pTmp;
		size *= 2;		
	}
			
}; 

//test
int main(){
	ArrayD arr(20);
	//arr.getArray(10);
	
	arr.show();
	
	for(int i=0;i<13; i++){
	 arr.add(i+20);	
	}
	
	arr.show();
	
	//arr.addByIndex(4, 2020);
	
	arr.show();
} 

