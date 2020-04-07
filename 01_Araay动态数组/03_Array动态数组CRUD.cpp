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
	
	//��ȡ���鳤��
	int getLength(){
		return length;
	} 
	
		
	//�ռ��С�Ƿ�����
	bool isFull(){
		return length>size-1;	
	}
	
	//�Ƿ�Ϊ�ձ�
	bool isEmpty(){
		return  0 == length;
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
			if( i != length-1){
				cout << ","; 	
			}
		
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
	
	/* ����,д���� 
	��ָ��λ��pos����Ԫ��e, PS:�����0�±����λ��0 
	*/
	void addByIndex(int pos, int e){
	
		//step0: �Ϸ�����֤ 
		if(isFull()){
			//cout << "Spaec is full!\n";
			//return;
			reSize(); //���ӿռ� 
		} 		
		if(pos < 0 || pos > length){
			cout << "error position!\n";
			return ;
		} 
		
		//step1: �������pos����Ԫ�غ���
		for(int i=length-1; i>=pos; i--){
			elements[i+1] = elements[i];//���� 
		}//for ending, i��ֵΪpos-1 
				
		//step2: ����
		elements[pos] = e;
		
		//step3:update
		length ++; //���ȸ��� 
		 
	} 
	
	/*ɾ��:д���� 
	�ڱ��posλ��ɾ��Ԫ�أ� �ò���������ɾ����Ԫ��e
	@param pos:int, ���е�λ��
	@param e:int &(int����),��ɾ����Ԫ�� 
	@return void 
	*/
	void delByIndex(int pos, int& e){
		//step0: �Ϸ�����֤ 
		if(isEmpty()){
			cout << "empty List error" << endl;
			return;
		}
				
		if(pos < 0 || pos > length-1){
			cout << "error position!\n";
			return ;
		} 
		
		//step1:������ɾ����Ԫ��
		e = elements[pos]; 
		
		//step2: ����pos+1�����һ��λ������Ԫ��ǰ��
		for(int i=pos+1; i <= length-1; i++){
			elements[i-1] = elements[i];//ǰ�� 
		}
		
		//step3:update
		length --; //���ȸ���
		return;
	}
	
	/*�޸�:д���� 
	�����posλ��Ԫ�ص�ֵ�޸ĳ�ֵe 
	@param pos:int, ���е�λ��
	@param e:int ,Ԫ�ص���ֵ 
	*/
	void modifyByIndex(int pos, int e){
		//step0: �Ϸ�����֤ 
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
	
	/*����:������
	��ȡ���Ա�L�е�pos��λ�õ�����Ԫ�ز��ò������� 
 	@param pos:int, ���е�λ��
	@param e:int &(int����),�����ҵ�Ԫ�� 
	@return void 
	*/
	void getDataByIndex(int pos, int & e){
		//step0: �Ϸ�����֤ 		
		if(pos < 0 || pos > length-1){
			cout << "error position!\n";
			return ;
		}
		
		//step1:��ȡԪ��
		e = elements[pos];//����
		
		return; 
	} 
	
	/*����:������
	��ȡ���Ա���ֵΪe��Ԫ�ص�1�γ��ֵ�λ�÷��� 
 	@param pos:int, ���е�λ��
	@param e:int &(int����),�����ҵ�Ԫ�� 
	@return int:����������ֵ, -1��ʾ������ 
	*/
	int getIndexByValue(int e){
		int id = -1;
		
		//���� 
		for(int i=0; i<length; i++){
			if(elements[i] == e){
				id = i;break;
			}
		}
		return id;
	}
	
		/*����:������
	��ȡ���Ա���ֵΪe��Ԫ�ص�����λ�÷��� 
 	@param pos:int, ���е�λ��
	@param e:int &(int����),�����ҵ�Ԫ�� 
	@return int:����������ֵ, -1��ʾ������ 
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

