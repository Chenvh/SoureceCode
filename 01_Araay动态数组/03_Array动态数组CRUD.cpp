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
	
	//获取数组长度
	int getLength(){
		return length;
	} 
	
		
	//空间大小是否已满
	bool isFull(){
		return length>size-1;	
	}
	
	//是否为空表
	bool isEmpty(){
		return  0 == length;
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
			if( i != length-1){
				cout << ","; 	
			}
		
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
	
	/* 插入,写操作 
	在指定位置pos插入元素e, PS:数组的0下标代表位置0 
	*/
	void addByIndex(int pos, int e){
	
		//step0: 合法性验证 
		if(isFull()){
			//cout << "Spaec is full!\n";
			//return;
			reSize(); //增加空间 
		} 		
		if(pos < 0 || pos > length){
			cout << "error position!\n";
			return ;
		} 
		
		//step1: 从最后至pos所有元素后移
		for(int i=length-1; i>=pos; i--){
			elements[i+1] = elements[i];//后移 
		}//for ending, i的值为pos-1 
				
		//step2: 插入
		elements[pos] = e;
		
		//step3:update
		length ++; //长度更新 
		 
	} 
	
	/*删除:写操作 
	在表的pos位置删除元素， 用参数返回所删除的元素e
	@param pos:int, 表中的位置
	@param e:int &(int引用),被删除的元素 
	@return void 
	*/
	void delByIndex(int pos, int& e){
		//step0: 合法性验证 
		if(isEmpty()){
			cout << "empty List error" << endl;
			return;
		}
				
		if(pos < 0 || pos > length-1){
			cout << "error position!\n";
			return ;
		} 
		
		//step1:保存所删除的元素
		e = elements[pos]; 
		
		//step2: 从至pos+1至最后一个位置所有元素前移
		for(int i=pos+1; i <= length-1; i++){
			elements[i-1] = elements[i];//前移 
		}
		
		//step3:update
		length --; //长度更新
		return;
	}
	
	/*修改:写操作 
	将表的pos位置元素的值修改成值e 
	@param pos:int, 表中的位置
	@param e:int ,元素的新值 
	*/
	void modifyByIndex(int pos, int e){
		//step0: 合法性验证 
		if(isEmpty()){
			cout << "empty List error" << endl;
			return;
		}
				
		if(pos < 0 || pos > length-1){
			cout << "error position!\n";
			return ;
		}
		//step1: modify
		elements[pos] = e; 
		
		return;
	}
	
	/*查找:读操作
	获取线性表L中第pos个位置的数据元素并用参数返回 
 	@param pos:int, 表中的位置
	@param e:int &(int引用),所查找的元素 
	@return void 
	*/
	void getDataByIndex(int pos, int & e){
		//step0: 合法性验证 		
		if(pos < 0 || pos > length-1){
			cout << "error position!\n";
			return ;
		}
		
		//step1:获取元素
		e = elements[pos];//保存
		
		return; 
	} 
	
	/*查找:读操作
	获取线性表中值为e的元素第1次出现的位置返回 
 	@param pos:int, 表中的位置
	@param e:int &(int引用),所查找的元素 
	@return int:返回其索引值, -1表示不存在 
	*/
	int getIndexByValue(int e){
		int id = -1;
		
		//遍历 
		for(int i=0; i<length; i++){
			if(elements[i] == e){
				id = i;break;
			}
		}
		return id;
	}
	
		/*查找:读操作
	获取线性表中值为e的元素的所有位置返回 
 	@param pos:int, 表中的位置
	@param e:int &(int引用),所查找的元素 
	@return int:返回其索引值, -1表示不存在 
	*/	
	
}; 

//test
int main(){
	ArrayD arr(20);
	//arr.getArray(10);
	
	arr.show();
	
	for(int i=0;i<7; i++){
	 arr.add(i+20);	
	}
//	
//	arr.show();
//	
	arr.addByIndex(0, 2020); arr.show();
	
	//arr.addByIndex(4, 2020);
	int e=-999;
	arr.delByIndex(0,e);	cout << e <<endl;
	arr.show();
	
	arr.modifyByIndex(0,2020); arr.show();
	
	arr.getDataByIndex(0,e);	cout << e <<endl;
	
	cout << arr.getIndexByValue(23) << endl;
} 

