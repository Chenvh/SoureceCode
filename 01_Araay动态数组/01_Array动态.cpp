/*���Ա�֮˳���̬���� 
*/
#include "Comm.h"
 
class ArrayD{
private :
	int * elements;//��ʼλ�� 
	int length;//����:Ԫ�صĸ��� 
public: 	
	//��ʼ�� 
	void init(int n){
		//elements = (int * )malloc(sizeof(int)* n);//�����ڴ�
		elements = new int[n];
		
		if(elements == NULL){
			cout << "error memory!" <<endl;
			return;
		}
		length = 0;//����0		
	} 
	
	//����traverse
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

