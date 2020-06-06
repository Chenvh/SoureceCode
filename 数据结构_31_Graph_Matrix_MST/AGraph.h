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
 *	fileName: AGraph.h ͼ�������ģ�� 
 *	Descripton: ����ͼ��������:���㼯,�������
 �߸���, �Ƿ�����,�Ƿ��Ȩ�� 
 *
 *******************************/

#include "comm.h"
#include "VertexNode.h"
#include "ArcNode.h"

#define LIMITED 9999


//ͼ���ͣ�����ͼ������ͼ����������������

typedef enum {UDG, UDN, DG, DN } GraphKind ;
//char GraphType[][5] = {"DG","DN","UDG","UDN"};
const string graph_type[4] = {"����ͼ","������","����ͼ","������"};

template<typename NameType>
void Visit(VertexNode<NameType> vtx){
	vtx.show();
}

template <typename NameType, typename CostType>
class AGraph {
//������,����ʹ�� 
typedef vector<VertexNode<NameType> > VV;
typedef vector<ArcNode<CostType> > VA;
typedef vector< VA > VVA;

protected:
		VV verts; //���㼯,�������洢
		
		CostType threshold;//ȨֵΪ�յķ�ֵ 
		
		int vtx_num, arc_num;//�������,�߸���
				
		bool Directed; //����Ƿ��з��� ,false����
		bool Weight; //����Ƿ��Ȩ ,false��Ȩ 
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

			fin>>boolalpha >> this->Directed; //����
			fin>>boolalpha >> this->Weight; //Ȩֵ
			//cout<< boolalpha << Directed <<","<< Weight << endl;
	

			//���붥����Ϣ
			fin>> this->vtx_num; // �������
			//cout << vtx_num << endl;		
				
			//���ÿձ�ֵ,��2���û�б�	
			this->threshold = (this->Weight?LIMITED:0);
			
		}

	//===createFromFile���ļ�����ͼ 
	virtual void createFromFile(string FileName) =0; 
	
	//===DFSTraverse������ȱ��� 
	virtual void DFSTraverse(void(*visit)(VertexNode<NameType>))=0;
	
	//===BFSTraverse������ȱ���
	virtual void BFSTraverse(void(*visit)(VertexNode<NameType>))=0;

		
	//===show ���ͼ�Ķ��㼯 
	void showVertexSet() {
	
		//���ÿձߵ�Ȩֵ	
		threshold = (this->Weight?LIMITED:0);
		
		int id= 2*Directed+Weight;
		//g_kind = GraphKind[id];
			
		cout << "��ͼ�ǰ���" << verts.size() <<"�����㼰" ; 
		cout<< arc_num<<"������ɵ�" << graph_type[id] << "!!!\n";
		cout <<"��������������:\n";	
		
		/*
		vector<VertexNode<NameType> >::iterator it;//������ָ�� 
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

	//===inputVertexFromIS��������������һ������ 
	void inputVertexFromIS(ifstream &ifs, VertexNode<CostType> &ver) {
		//PS:����VertexNode�����ز�����>> ,��ֱ������ 
		ifs >> ver;
		
		//cout << ver.name << endl;
	}//---inputVertexFromIS���ļ�������һ���� ENDING

	//===inputArcFromIS�������������뻡��� 
	void inputArcFromIS(ifstream &ifs, ArcNode<CostType> &arc) {
		ifs.ignore(1, ' ');//���Կո�(��һ������ʣ�µ�) 
		getline(ifs, arc.message);
	}//---inputArcFromIS() ENDING


	//===locateVex���ݶ����ȡ�����
	int locateVex(VertexNode<NameType> vtx)const {
		//visit(u);
		for(int i=0; i<verts.size(); i++) {

			if( vtx.equals(verts[i]) ) {
				return i;
			}
		}

		return -1;
	}//---locateVex���ݶ����ȡ����� END

	//===getVexNumOrArcNum��ȡ�����������
	int getVexNumOrArcNum(bool f)const {
		if(f) {

			return verts.size();
		} else {

			return arc_num;
		}
	}//---getVexNumOrArcNum��ȡ����������� END

	//===getDirectedOrWeight��ȡ�����Ȩ
	bool getDirectedOrWeight(bool f)const {
		if(f) {
			return Directed;
		}

		else {
			return Weight;
		}

	}//---getDirectedOrWeight��ȡ�����Ȩ


	//===getVex������Ż�ȡ������Ϣ
	VertexNode<NameType> getVex(int i)const {
		if(i>=verts.size() || i<0) {
			exit(1);
		}

		return verts[i];
	}//---getVex������Ż�ȡ������Ϣ

	//===equals�ж�2��VertexNode�Ƿ����
	bool equals(VertexNode<NameType> v1, VertexNode<NameType> v2) const {
		return (v1.m_name == v2.m_name );
	} //---equals�ж�2��verT�Ƿ���� END


	//===visit���ʶ���
	void visit(VertexNode<NameType> ver)const {
		//cout<<'('<<ver.name <<")"; //<<", "<<ver.size<<")";
		cout << ver.name; 
	}//---visit���ʶ��� ENDING
	
		
	

	//===inputArc�Ӽ������뻡arc(����,Ȩֵ,��ͷ,��β).���ڲ��� 
	void inputArc( ArcNode<CostType> &arc) {
		/*	string s="��";
			if(direct)
				s="��";
			if(weight) {
				cout<<"������"<<ver1.name<<s<<ver2.name<<"��Ȩֵ��";
				cin>>arc.m_cost;
			}*/
		cout<<"������˻��ı�ע��Ϣ��";
		cin.ignore(1, ' ');
		getline(cin, arc.message);
	}//---inputArc���뻡arc(����,Ȩֵ,��ͷ,��β) ENDING



	//===outputArc�����(����,���,�յ�,����Ϣ) 
	void outputArc(bool direct,  VertexNode<NameType> ver1,
						 VertexNode<NameType> ver2, 
						 ArcNode<CostType> arc)const {
			string s="��";
		if(direct){				
			s="��";
		}
		cout << ver1 << s <<ver2 <<"��" ; 
		arc.show();
		cout <<endl;

	}//---outputArc����� ENDING

	
		

};




#endif




