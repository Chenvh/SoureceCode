#ifndef _ArcNodeAdj_H_2020
#define _ArcNodeAdj_H_2020
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:ArcNodeAdj.h 
 *	Descripton:邻接表的弧结点类(将图的弧结点包装) 
 *
 *******************************/



//邻接表的弧结点类(将图的弧结点包装) 
template <typename CostType>
class ArcNodeAdj {
public:
	int m_dest;//边的另一顶点下标 
	ArcNode<CostType> m_arc; //边信息(权值,备注等) 
	
	int cmpCost(CostType cost){
		return m_arc.m_cost-cost;
	}
	
	bool lessThan(const ArcNodeAdj &obj){
		return this->m_arc.m_cost < obj.m_arc.m_cost;
	}
	
	void show(){
		cout << "(" << m_dest << ",";
		m_arc.show();
		cout << ")";
	}
	
	
	
} ;

#endif
