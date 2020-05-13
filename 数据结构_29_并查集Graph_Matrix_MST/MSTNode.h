#pragma once

/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName: MSTNode��С�����������ģ�� 
 *	Descripton:
 *
 *******************************/


template <typename NameType, typename CostType>
class MSTNode{
//����������ʹ�� 
typedef VertexNode<NameType> vertNode;
typedef ArcNodeAdj<CostType> arcNode;
typedef MSTNode<NameType, CostType> MstNode; 

public:
	
	vertNode m_from;//һ������ 
	vertNode m_to;//һ������ 
	arcNode m_adjArc; //��2������ɵĻ�  
	
	//vertex index
	int i_from, i_to; //��������������±�
	
	void set(int from, int to, CostType cost, vertNode v1, vertNode v2){
		i_from = from; i_to = to;
		m_from = v1; m_to = v2;
		m_adjArc.m_arc.m_cost = cost;
	
		
	}
	 
	
	void show(){
		m_from.show(); cout << "--";
		m_to.show();cout << "-->";
		m_adjArc.show();
		cout<<" "<<i_from<<","<<i_to; 
	}
	
	//���ز�����>  ʵ��prior_queue�е�greater����
	friend bool operator>(const MstNode &node1, const MstNode &node2 )  {
		return node1.m_adjArc.m_arc.m_cost > node2.m_adjArc.m_arc.m_cost;
	}
};
