#include "HfmTree.cpp"
/*
[7,6,-1,-1]
[5,5,-1,-1]
[2,4,-1,-1]
[4,4,-1,-1]
[6,5,2,3]
[11,6,1,4]
[18,-1,0,5]
0
10
110
111

--------------------------------
Process exited after 1.209 seconds with return value 0
请按任意键继续. . .

*/

void createHfmTeeFromArr(){
	int a[4] = {7,5,2,4};
	HfmTree<int> hfm;
	hfm.createHfmTeeFromArr(a,4);
	hfm.codeFromLeaf();
}


void testInit(){
	HfmTree<int> hfm;
	hfm.initHfm(4);
} 




