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
 *	Descripton:�ڽӱ�Ļ������(��ͼ�Ļ�����װ) 
 *
 *******************************/



//�ڽӱ�Ļ������(��ͼ�Ļ�����װ) 
template <typename CostType>
class ArcNodeAdj {
public:
	int m_dest;//�ߵ���һ�����±� 
	ArcNode<CostType> m_arc; //����Ϣ(Ȩֵ,��ע��) 
	
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
