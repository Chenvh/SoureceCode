#pragma once

/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName: MSTNode最小生成树结点类模板 
 *	Descripton:
 *
 *******************************/


template <typename NameType, typename CostType>
class MSTNode{
//重命名方便使用 
typedef VertexNode<NameType> vertNode;
typedef ArcNodeAdj<CostType> arcNode;
typedef MSTNode<NameType, CostType> MstNode; 

public:
	
	vertNode m_from;//一个顶点 
	vertNode m_to;//一个顶点 
	arcNode m_adjArc; //由2顶点组成的弧  
	
	//vertex index
	int i_from, i_to; //弧的两个顶点的下标
	
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
	
	//重载操作符>  实现prior_queue中的greater函数
	friend bool operator>(const MstNode &node1, const MstNode &node2 )  {
		return node1.m_adjArc.m_arc.m_cost > node2.m_adjArc.m_arc.m_cost;
	}
};
