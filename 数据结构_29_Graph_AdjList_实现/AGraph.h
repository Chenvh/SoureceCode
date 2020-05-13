#ifndef _ADT_GRAPH_H_2020
#define _ADT_GRAPH_H_2020
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName: AGraph.h 图抽象基类模板 
 *	Descripton: 定义图基本数据:顶点集,顶点个数
 边个数, 是否有向,是否带权等 
 *
 *******************************/

#include "comm.h"
#include "VertexNode.h"
#include "ArcNode.h"

#define LIMITED 9999


//图类型：有向图，无向图，有向网，无向网

typedef enum {UDG, UDN, DG, DN } GraphKind ;
//char GraphType[][5] = {"DG","DN","UDG","UDN"};
const string graph_type[4] = {"无向图","无向网","有向图","有向网"};

template<typename NameType>
void Visit(VertexNode<NameType> vtx){
	vtx.show();
}

template <typename NameType, typename CostType>
class AGraph {
//重命名,便于使用 
typedef vector<VertexNode<NameType> > VV;
typedef vector<ArcNode<CostType> > VA;
typedef vector< VA > VVA;

protected:
		VV verts; //顶点集,用向量存储
		
		CostType threshold;//权值为空的阀值 
		
		int vtx_num, arc_num;//顶点个数,边个数
				
		bool Directed; //标记是否有方向 ,false无向
		bool Weight; //标记是否带权 ,false无权 
		GraphKind g_kind;  

	public:
		AGraph():threshold(0), vtx_num(0), arc_num(0){
		}
		
		void init(ifstream& fin){
			//assert file open correct
			if(!fin.is_open()) {
				cout << "file read error!\n";
				exit(1);
			}

			fin>>boolalpha >> this->Directed; //方向
			fin>>boolalpha >> this->Weight; //权值
			//cout<< boolalpha << Directed <<","<< Weight << endl;
	

			//输入顶点信息
			fin>> this->vtx_num; // 顶点个数
			//cout << vtx_num << endl;		
				
			//设置空边值,即2点间没有边	
			this->threshold = (this->Weight?LIMITED:0);
			
		}

	//===createFromFile由文件创建图 
	virtual void createFromFile(string FileName) =0; 
	
	//===DFSTraverse深度优先遍历 
	virtual void DFSTraverse(void(*visit)(VertexNode<NameType>))=0;
	
	//===BFSTraverse广度优先遍历
	virtual void BFSTraverse(void(*visit)(VertexNode<NameType>))=0;

		
	//===show 输出图的顶点集 
	void showVertexSet() {
	
		//设置空边的权值	
		threshold = (this->Weight?LIMITED:0);
		
		int id= 2*Directed+Weight;
		//g_kind = GraphKind[id];
			
		cout << "该图是包含" << verts.size() <<"个顶点及" ; 
		cout<< arc_num<<"条弧组成的" << graph_type[id] << "!!!\n";
		cout <<"各顶点名依次是:\n";	
		
		/*
		vector<VertexNode<NameType> >::iterator it;//迭代器指针 
		for(it=verts.begin(); it != verts.end(); it++){
			Visit(*it);
			it != verts.end()-1 ? cout << ", " : cout<<endl;
		}
	   */
		for(int i=0; i<verts.size(); i++){
			Visit(verts[i]);
			(i+1) !=verts.size()?cout << ", " : cout<<endl;
			
		}
		
		cout<<endl;
		
	}//--- showVertexSet() END

	//===inputVertexFromIS从输入流中输入一顶点结点 
	void inputVertexFromIS(ifstream &ifs, VertexNode<CostType> &ver) {
		//PS:已在VertexNode中重载操作符>> ,可直接输入 
		ifs >> ver;
		
		//cout << ver.name << endl;
	}//---inputVertexFromIS从文件中输入一顶点 ENDING

	//===inputArcFromIS从输入流中输入弧结点 
	void inputArcFromIS(ifstream &ifs, ArcNode<CostType> &arc) {
		ifs.ignore(1, ' ');//忽略空格(上一次输入剩下的) 
		getline(ifs, arc.message);
	}//---inputArcFromIS() ENDING


	//===locateVex根据顶点获取其序号
	int locateVex(VertexNode<NameType> vtx)const {
		//visit(u);
		for(int i=0; i<verts.size(); i++) {

			if( vtx.equals(verts[i]) ) {
				return i;
			}
		}

		return -1;
	}//---locateVex根据顶点获取其序号 END

	//===getVexNumOrArcNum获取顶点数或边数
	int getVexNumOrArcNum(bool f)const {
		if(f) {

			return verts.size();
		} else {

			return arc_num;
		}
	}//---getVexNumOrArcNum获取顶点数或边数 END

	//===getDirectedOrWeight获取方向或权
	bool getDirectedOrWeight(bool f)const {
		if(f) {
			return Directed;
		}

		else {
			return Weight;
		}

	}//---getDirectedOrWeight获取方向或权


	//===getVex根据序号获取顶点信息
	VertexNode<NameType> getVex(int i)const {
		if(i>=verts.size() || i<0) {
			exit(1);
		}

		return verts[i];
	}//---getVex根据序号获取顶点信息

	//===equals判断2个VertexNode是否相等
	bool equals(VertexNode<NameType> v1, VertexNode<NameType> v2) const {
		return (v1.m_name == v2.m_name );
	} //---equals判断2个verT是否相等 END


	//===visit访问顶点
	void visit(VertexNode<NameType> ver)const {
		//cout<<'('<<ver.name <<")"; //<<", "<<ver.size<<")";
		cout << ver.name; 
	}//---visit访问顶点 ENDING
	
		
	

	//===inputArc从键盘输入弧arc(方向,权值,弧头,弧尾).用于测试 
	void inputArc( ArcNode<CostType> &arc) {
		/*	string s="—";
			if(direct)
				s="→";
			if(weight) {
				cout<<"请输入"<<ver1.name<<s<<ver2.name<<"的权值：";
				cin>>arc.m_cost;
			}*/
		cout<<"请输入此弧的备注信息：";
		cin.ignore(1, ' ');
		getline(cin, arc.message);
	}//---inputArc输入弧arc(方向,权值,弧头,弧尾) ENDING



	//===outputArc输出弧(方向,起点,终点,边信息) 
	void outputArc(bool direct,  VertexNode<NameType> ver1,
						 VertexNode<NameType> ver2, 
						 ArcNode<CostType> arc)const {
			string s="—";
		if(direct){				
			s="→";
		}
		cout << ver1 << s <<ver2 <<"：" ; 
		arc.show();
		cout <<endl;

	}//---outputArc输出弧 ENDING

	
		

};




#endif




