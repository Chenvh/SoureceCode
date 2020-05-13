#include "AdjListGraph.cpp"

void testGraph(){
	
	int i, j, k, n;
	string s="udgData.txt";
	AdjListGraph<string,int> g;
	VertexNode<string> v1, v2;

	g.createFromFile(s);
	g.show();

	cout<<"AdjListGraph�����������������ͼ�Ľ����" << endl;
	g.DFSTraverse(Visit);
	cout<<"AdjListGraph����������������ͼ�Ľ����" << endl;
	g.BFSTraverse(Visit);

}

/*
udgData.txt

false
false
3
a1 a2 a3
3
a2 a1
a2 a3
a1 a3



��ͼ�ǰ���3�����㼰3������ɵ�����ͼ!!!
��������������:
[a1,-1,-1,-1],[a2,-1,-1,-1],[a3,-1,-1,-1]

�����㼰�ڽӱ���:
vexId(m_cost)->
[a1,-1,-1,-1]->2)->1)->null
[a2,-1,-1,-1]->2)->0)->null
[a3,-1,-1,-1]->0)->1)->null

3������
a1��a3��[0,null]
a1��a2��[0,null]

a2��a3��[0,null]


AdjListGraph�����������������ͼ�Ľ����
[a1,-1,-1,-1][a3,-1,-1,-1][a2,-1,-1,-1]
AdjListGraph����������������ͼ�Ľ����
[a1,-1,-1,-1][a3,-1,-1,-1][a2,-1,-1,-1]

--------------------------------
Process exited after 0.5077 seconds with return value 0
�밴���������. . .

*/
