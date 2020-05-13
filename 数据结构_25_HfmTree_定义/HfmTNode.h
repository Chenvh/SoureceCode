#ifndef _HFM_TREE_NODE_H_2020
#define _HFM_TREE_NODE_H_2020


/*
Huffman Tree Node template
�����ģ�� 
*/
#include "comm.h"
template <typename T>
class HfmTNode{
public:
	T m_weight;//Ȩֵ 
	int m_pa, m_left, m_right;//�±�:˫��,����,����
	
	HfmTNode():m_pa(-1), m_left(-1), m_right(-1){
		
	}
	HfmTNode(T w):m_weight(w), m_pa(-1), m_left(-1), m_right(-1){
		
	} 
	
	void show(){
		cout << "[" << m_pa<<","<<m_left<<","<<m_right<<"]";
	}
};

#endif
