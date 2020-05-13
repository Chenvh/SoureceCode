#ifndef _HFM_TREE_H_2020
#define _HFM_TREE_H_2020



/*

  template<typename _InputIterator, typename _Function>
    _Function
    for_each(_InputIterator __first, _InputIterator __last, _Function __f)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_requires_valid_range(__first, __last);
      for (; __first != __last; ++__first)
	__f(*__first);
      return _GLIBCXX_MOVE(__f);
    }

Huffman�㷨
(1) �ɸ�����n��Ȩֵ{w0, w1, w2, ��, wn-1}������
����n�������������ɭ��F={T0, T1, T2, ��,Tn-1}��
����ÿ�����������Tiֻ��һ����Ȩ
ֵwi�ĸ���㣬������������Ϊ�ա�
(2) �ظ����²��裬ֱ��F�н�ʣ��һ����Ϊֹ��
�� ��F��ѡȡ���ø�����Ȩֵ��С���������
��, ��Ϊ������������һ���µĶ���������
�µĶ������ĸ�����ȨֵΪ������������
������Ȩֵ֮�͡�
�� ��F��ɾȥ�����ö�������
�� ���µĶ���������F
*/

#include "HfmTNode.h"

template <typename T>
void visit(HfmTNode<T> *  pnode){
	pnode->show();
}

template <typename T>
class HfmTree{
private:
	
typedef HfmTNode<T> HT;
//PS: �Ӷ�ո���⽫> >����Ϊ >> 
typedef vector< HfmTNode<T> > VHT;
	
	int m_leaf; //Ҷ�Ӹ���
	//vector����
	
	VHT mv_ht; //huffman tree
	
	vector<string> mv_code;//huffman code
	 
public:
	//�����鴴��Huffman Tree 
	void createHfmTeeFromArr(T a[], int n);
	
	//����Huffman Tree	
	void buildHfmTree(); 
	
	//������mv_ht������[0,end)ѡȡ��С��2����㲢���±걣����m1,m2
	void getDbMini(int&,int&, int);
	
	//����huffman code
	void codeFromLeaf(); 
	
	
	
	//��ʼ�� huffman tree 
	void initHfm( int n){
		m_leaf = n;
		
		//huffman tree ����2*n-1�����,��ʼʱΪ�ս�� 
		mv_ht.assign(2*n-1, HfmTNode<T>());
		
		//huffman code ����n��,��ʼʱΪ�մ� 
		mv_code.assign(m_leaf, ""); 
		
		//for_each(mv_ht.begin(), mv_ht.end(), visit<T> );
		
		//for_each(mv_ht.begin(), mv_ht.end(), mem_fun_ref(&HfmTNode<T> :: show ) );
	}	
	
	
	 
};




#endif
