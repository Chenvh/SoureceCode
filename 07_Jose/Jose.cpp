#include "Jose.h" 
#include "Cpp.h" 
/*Josephus类实现 声明
*/
Jose::Jose(int nums, int interval, int start):n(nums),m(interval), s(start),ring(n){
	if(nums<2 || interval<1 || start>=nums || start<1 || start>=nums){
		cerr<<"error value!" << endl;
		exit(1);
	}
	//n = nums; m = interval; s= start;
	
	//创建环 ,cur是指向最后一个 
	//ring = new BoyRing(n); //error,成员对象只能用初始化列表方法 
	
} 

//最后获胜者,假定为1个 
void Jose::getWinner(){
	//BoyRing ring(n);
	ring.showAll(); 
	
	//初始化,让cur指向第s-1个
	ring.countNum(s-1);
	
	//删除 n-1个结点
	for(int i=1; i< n; i++){
		//数m 个,让cur指向第m个 
		ring.countNum(m); 
		ring.delNode();//删除 
	} 
	 
	cout << ring.getCodeCur() << endl; 
	ring.showAll(); 
	
} 
