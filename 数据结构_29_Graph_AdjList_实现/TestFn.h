#include "AdjListGraph.cpp"

void testGraph(){
	
	int i, j, k, n;
	string s="udgData.txt";
	AdjListGraph<string,int> g;
	VertexNode<string> v1, v2;

	g.createFromFile(s);
	g.show();

	cout<<"AdjListGraph类深度优先搜索遍历图的结果：" << endl;
	g.DFSTraverse(Visit);
	cout<<"AdjListGraph类广度优先搜索遍历图的结果：" << endl;
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



该图是包含3个顶点及3条弧组成的无向图!!!
各顶点名依次是:
[a1,-1,-1,-1],[a2,-1,-1,-1],[a3,-1,-1,-1]

各顶点及邻接表是:
vexId(m_cost)->
[a1,-1,-1,-1]->2)->1)->null
[a2,-1,-1,-1]->2)->0)->null
[a3,-1,-1,-1]->0)->1)->null

3条弧：
a1—a3：[0,null]
a1—a2：[0,null]

a2—a3：[0,null]


AdjListGraph类深度优先搜索遍历图的结果：
[a1,-1,-1,-1][a3,-1,-1,-1][a2,-1,-1,-1]
AdjListGraph类广度优先搜索遍历图的结果：
[a1,-1,-1,-1][a3,-1,-1,-1][a2,-1,-1,-1]

--------------------------------
Process exited after 0.5077 seconds with return value 0
请按任意键继续. . .

*/
