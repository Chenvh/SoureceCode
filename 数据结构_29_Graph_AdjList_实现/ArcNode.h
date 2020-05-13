#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:ArcNode.h �߻���ģ�� 
 *	Descripton:
 *
 *******************************/
 typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } AStatus;; 
 //��״̬(δ����,��,ʮ��,����ǰ,�����) 

 
 template <typename CostType>
 class ArcNode{
 public: 
	CostType m_cost; //Ȩֵ 
	
 	string info; //��ע 
 	AStatus status; //״̬ 
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

