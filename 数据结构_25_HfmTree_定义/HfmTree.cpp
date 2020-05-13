/*Huffman Tree��ģ��HfmTree.h��ʵ��Դ�ļ�
FileName: HfmTree.cpp 
*/

#include "HfmTree.h"
#define MAXVALUE 9999
 
//�����鴴��Huffman Tree 
template<typename T> 
void HfmTree<T>::createHfmTeeFromArr(T a[], int n){
	initHfm(n);
	
	//����Ȩֵ
	int i ;
	for(i=0; i<n; i++){
		mv_ht[i].m_weight = a[i];
	}
	
	//����Huffman Tree
	buildHfmTree(); 
}

/*����Huffman Tree
�� ��F��ѡȡ���ø�����Ȩֵ��С���������
��, ��Ϊ������������һ���µĶ���������
�µĶ������ĸ�����ȨֵΪ������������
������Ȩֵ֮�͡�
�� ��F��ɾȥ�����ö�������
�� ���µĶ���������F
*/
template<typename T> 
void HfmTree<T>::buildHfmTree(){
	int mini1, mini2; //��С���������±�
	
	//������[m_leaf, 2*m_leaf-1]���ɽ��
	int end;
	for(end = m_leaf; end < 2*m_leaf-1; end++){
		
		//ѡȡ��С��������㲢���±걣����mini1,mini2
		getDbMini(mini1, mini2, end); 
	} 
}

//������mv_ht������[0,end)ѡȡ��С��2����㲢���±걣����m1,m2
template<typename T> 
void HfmTree<T>::getDbMini(int &m1, int &m2, int end){
	int i;
	
	//����(2��)
	T least = MAXVALUE; //��С�� 
	T less = MAXVALUE;  //��С��
	 
	//traverseһ��,��ȡ��С��2������±�, [0,end)
	for(i=0; i< end; i++){
		
		//������<��С�� 
		if(mv_ht[i].m_weight < least){
			//����С�߱�������С�� 
			less = least; m2 = m1;
			
			//������С�� 
			least = mv_ht[i].m_weight;
			m1 = i;
		}
		
		//������<��С�ߵ�>��С�� 
		else if(mv_ht[i].m_weight < less){
			
			//���´�С�� 
			less = mv_ht[i].m_weight;
			m2 = i;
		}
		
	}
	
}
