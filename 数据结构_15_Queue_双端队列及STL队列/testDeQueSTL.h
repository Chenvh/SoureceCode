#pragma once

#include "..\comm.h"

 
void visit(int e){
	cout << e << ","; 
}

void testDeQueSTL(){
	deque<int>  Q(8);
	cout << boolalpha << Q.empty() << endl;
	for(int i=1; i<=3; i++){
		Q.push_back( i);
		Q.push_front(2*i);
		
	}	
	
	//for_each(Q.begin(), Q.end(), visit);
	
	
	deque<int>::iterator it;
	for(it = Q.begin(); it != Q.end(); it++){
		cout << *it << ",";
	}
	cout << endl;
}
