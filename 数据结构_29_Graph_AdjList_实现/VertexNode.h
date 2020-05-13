#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:VertexNode.h 顶点类模板 
 *	Descripton:包括入度,出度,双亲结点下标 
 *
 *******************************/
 typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; 
 //顶点状态(没有被检测到,检测到,访问过) 

 
 template <typename NameType>
 class VertexNode{
 public: 
  	
   NameType m_name; //名字 
   
 	int in_degree,out_degree;//入度,出度 
	int m_pa,m_left,m_right; //parent, left ,right 
 	VStatus status; //状态 
 	
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
	

	//	重载操作符 << >>
	//PS:template的友元函数重载操作符不能在外实现,否则编译无法通过 
		
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
 

