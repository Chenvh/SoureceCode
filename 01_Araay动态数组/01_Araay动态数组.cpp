/*���Ա�֮˳���
	��̬����
*/
#include"com.h"

class ArrayD {
	private :
		int *elements;//��ʼλ��
		int length;//����:Ԫ�صĸ��� 
		int size;//�ռ��С 
	public : 
		//��ʼ��   
	void getArray (int n) {
	//	elements = (int*)malloc(sizeof(int)*n);	//�����ڴ�ռ�
		elements = new int[n];
		if (elements == NULL) {
			cout << "error memory!" <<endl;
			return;
		}
		length = 0;
		
	}
	
	//���� traverse
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










