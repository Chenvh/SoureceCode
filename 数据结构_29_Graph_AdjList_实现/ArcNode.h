#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:ArcNode.h 边弧类模板 
 *	Descripton:
 *
 *******************************/
 typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } AStatus;; 
 //边状态(未定的,树,十字,向右前,向左后) 

 
 template <typename CostType>
 class ArcNode{
 public: 
	CostType m_cost; //权值 
	
 	string info; //备注 
 	AStatus status; //状态 
	ArcNode():m_cost((CostType)0){
		reset();
	}
	ArcNode(CostType cost):m_cost(cost){
		reset();
	}
	void reset(){
		info = "null";
		status=UNDETERMINED;
	}
	
	void show(){
		cout << "[" <<m_cost<<","<<info<<"]" ; 
	}
	 
 };

