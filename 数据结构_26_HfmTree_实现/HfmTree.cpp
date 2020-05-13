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
	
	//show
	for_each(mv_ht.begin(), mv_ht.end(), mem_fun_ref(&HfmTNode<T> :: show ) );
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
		
		//���� ���� mv_ht
		
		//update node end
		mv_ht[end].m_weight = mv_ht[mini1].m_weight + mv_ht[mini2].m_weight;
		mv_ht[end].m_left = mini1;
		mv_ht[end].m_right = mini2;
		
		//update node mini1,mini2
		mv_ht[mini1].m_pa = end;
		mv_ht[mini2].m_pa = end;
		
	} //loop end
}

/*===������mv_ht������[0,end)ѡȡ��С��2����㲢���±걣����m1,m2
@param m1: int&,��������,������С�����±� 
@param m2: int&,��������,�����С�����±� 
@param end: int,������������� 
*/
template<typename T> 
void HfmTree<T>::getDbMini(int & m1, int &m2, int end){
	int i;
	
	//����(2��):��ʼ�� 
	T least = MAXVALUE; //��С�� 
	T less = MAXVALUE;  //��С��
	 
	//traverseһ��,��ȡ��С��2������±�, [0,end)
	for(i=0; i< end; i++){
		//����ý���Ѿ���ѡȡ,���� 
		if(mv_ht[i].m_pa != -1){
			continue; //���� 
		} 
		
		//������<��С�� 
		if(mv_ht[i].m_weight < least){
			//����С�߱�������С�� 
			less = least; m2 = m1;
			
			//������С�� 
			least = mv_ht[i].m_weight;
			m1 = i;
		}
		
		//������ <��С�� �� >��С�� 
		else if(mv_ht[i].m_weight < less){
			
			//���´�С�� 
			less = mv_ht[i].m_weight;
			m2 = i;
		}
		
	}//m1Ϊ��С�����±�,m2Ϊ��С�����±� 
	
}//--- getDbMini() END


	//����huffman code
template<typename T> 
void HfmTree<T>:: codeFromLeaf(){
	//��ʼ��
	string* p_code;
	int leaf; 
	int cur, pa;//�±�:��ǰ,˫�� 
	
	mv_code.clear();
	for(leaf = 0; leaf<m_leaf; leaf ++){
		p_code = new string;
		for(cur=leaf,pa=mv_ht[leaf].m_pa ; pa != -1; pa = mv_ht[pa].m_pa){
			if(cur == mv_ht[pa].m_left) {
				p_code->insert(0,"0");
			}
			else{
				p_code->insert(0,"1");
			}
		}//loop END,p_code ������� leaf ���� 
		
		mv_code.push_back(*p_code); 
	}//loop END, mv_code �����������leaf���ı��� 
	
	//show code
	for(int i=0;i<mv_code.size(); i++){
		cout << mv_code[i] << endl;
	} 
	
	
}
