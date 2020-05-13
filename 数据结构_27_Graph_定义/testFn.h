#include "AGraph.h"

void testAGraph(){
	AGraph<string, int> g;
	
	//fstream fin("udgData.txt", ios::in);
	ifstream ifs("udgData.txt");
	g.init(ifs);
	
	
}
