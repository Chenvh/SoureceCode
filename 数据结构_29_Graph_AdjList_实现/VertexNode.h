#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:VertexNode.h ������ģ�� 
 *	Descripton:�������,����,˫�׽���±� 
 *
 *******************************/
 typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; 
 //����״̬(û�б���⵽,��⵽,���ʹ�) 

 
 template <typename NameType>
 class VertexNode{
 public: 
  	
   NameType m_name; //���� 
   
 	int in_degree,out_degree;//���,���� 
	int m_pa,m_left,m_right; //parent, left ,right 
 	VStatus status; //״̬ 
 	
	VertexNode(){
		reset();
	}
	VertexNode(NameType name):m_name(name){
		reset();
	}
	void reset(){
		in_degree=out_degree=0;
		m_pa = m_left = m_right = -1; 
		status=UNDISCOVERED;
	}
	
	void show(){
		cout << "[" <<m_name<<","<<m_pa<<",";
		cout << m_left << ","<<m_right<<"]"; 
	}
	
	bool equals(const VertexNode<NameType> ver){
		return this->m_name == ver.m_name;
	}
	

	//	���ز����� << >>
	//PS:template����Ԫ�������ز�������������ʵ��,��������޷�ͨ�� 
		
	friend  istream& operator>> (istream &in, VertexNode<NameType> &ver){
 		in >> ver.m_name;
 		return in;
	}
	friend  ostream& operator<< (ostream &out,const VertexNode<NameType> &ver){
		out << ver.m_name;
		return out;
	}	
	friend  bool operator == (const VertexNode<NameType> &v1,const VertexNode<NameType> &v2 ){
		return v1.m_name == v2.m_name;
	}
	
	 
 };
 

