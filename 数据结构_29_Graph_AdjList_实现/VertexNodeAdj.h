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
 *	Descripton:邻接表的顶点结点(将图的顶点进行包装)
 *
 *******************************/



#include "ArcNodeAdj.h"
 
template <typename NameType, typename CostType>
class VertexNodeAdj {
public:
	VertexNode<NameType> m_head; //邻接表表头顶点结点 
	
	 //该顶点的链表,保存的是与该顶点相邻的所有边 
	list< ArcNodeAdj<CostType> > m_adjList; 
} ;


#endif

