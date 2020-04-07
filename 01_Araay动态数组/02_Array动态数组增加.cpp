/*���Ա�֮˳���̬���� 
*/
#include "comm.h"
 
class ArrayD{
private :
	int * elements;//��ʼλ�� 
	int length;//����:Ԫ�صĸ��� 
	int size;//�ռ��С
	 
public: 
	//���캯��:������������ͬ,��ϵͳ�Զ�����,�޺������� 
	ArrayD(int n=3){
		if(n <= 0){
			cout << "error Size!\n";
			return;
		}
		getArray(n);
	}
	
	//Ϊ��������n ��Ԫ�ص��ڴ� 
	void getArray(int n){
		//elements = (int * )malloc(sizeof(int)* n);//�����ڴ�
		elements = new int[n];
		
		if(elements == NULL){
			cout << "error memory!" <<endl;
			return;
		}
		length = 0;//����0
		size = n;		
	} 
	
	//����traverse
	 void show(){
	 	cout << "length=" << length <<", size="<< size <<endl;
		// cout <<", BaseAddress=" << hex << elements << endl;
		
		//�����ʽ ���� [1,2,3] 
		cout << "[";
		for(int i=0; i<length; i++){
			cout << elements[i]  ;
			cout << ","; 
		}
		cout << "]";
		cout << endl;
	}	

	
	//��β������:���ж�,�ռ��С�Ƿ����� 
	void add(int e){
		if(isFull()){
			//cout << "Spaec is full!\n";
			//return;
			reSize(); //���ӿռ� 
		} 
		
		elements[length++] = e;
	}
	
	//��ָ��λ��pos����Ԫ��e
	void addByIndex(int pos, int e){
		//step0: �Ϸ�����֤ 
		
		if(pos < 0 || pos > length){
			cout << "error position!\n";
			return ;
		} 
		
		//step1: �������pos����Ԫ�غ���
		
		//step2: ����
		 
	} 
	
	//��ȡ���鳤��
	int getLength(){
		return length;
	} 
	
		
	//�ռ��С�Ƿ�����
	bool isFull(){
		return length>size-1;	
	}
	
	//�����ռ�: ��1���ٶ�����,��elements�ռ�Ϊ2*size 
	void reSize(){
		cout << "memory reapply!\n";
		int *pTmp ;
		//step1:�������� 
		pTmp = new int[2*size];//���·���2*size���ռ�
		if(pTmp == NULL){
			cout << "memory apply fail!" << endl;
			return;
		}
		
		//step2: ����
		for(int i = 0; i< length; i++){
			pTmp[i] = elements[i];
		} 
		
		//step3:update
		delete[]elements;//�ͷ�ԭ�����ڴ� 
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

