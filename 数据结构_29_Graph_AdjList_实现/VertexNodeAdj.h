#ifndef VertexNodeAdj_HH_2020
#define VertexNodeAdj_HH_2020
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:VertexNodeAdj.h
 *	Descripton:�ڽӱ�Ķ�����(��ͼ�Ķ�����а�װ)
 *
 *******************************/



#include "ArcNodeAdj.h"
 
template <typename NameType, typename CostType>
class VertexNodeAdj {
public:
	VertexNode<NameType> m_head; //�ڽӱ��ͷ������ 
	
	 //�ö��������,���������ö������ڵ����б� 
	list< ArcNodeAdj<CostType> > m_adjList; 
} ;


#endif

