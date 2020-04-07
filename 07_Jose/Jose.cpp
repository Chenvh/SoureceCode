#include "Jose.h" 
#include "Cpp.h" 
/*Josephus��ʵ�� ����
*/
Jose::Jose(int nums, int interval, int start):n(nums),m(interval), s(start),ring(n){
	if(nums<2 || interval<1 || start>=nums || start<1 || start>=nums){
		cerr<<"error value!" << endl;
		exit(1);
	}
	//n = nums; m = interval; s= start;
	
	//������ ,cur��ָ�����һ�� 
	//ring = new BoyRing(n); //error,��Ա����ֻ���ó�ʼ���б��� 
	
} 

//����ʤ��,�ٶ�Ϊ1�� 
void Jose::getWinner(){
	//BoyRing ring(n);
	ring.showAll(); 
	
	//��ʼ��,��curָ���s-1��
	ring.countNum(s-1);
	
	//ɾ�� n-1�����
	for(int i=1; i< n; i++){
		//��m ��,��curָ���m�� 
		ring.countNum(m); 
		ring.delNode();//ɾ�� 
	} 
	 
	cout << ring.getCodeCur() << endl; 
	ring.showAll(); 
	
} 
