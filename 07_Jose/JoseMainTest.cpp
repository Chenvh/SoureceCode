#include "Cpp.h"
#include "BoyRing.h"
#include "Jose.h"

int main(int argc, char** argv) {
	Jose jose(8, 3, 1);
	jose.getWinner();
	
	
	
	
	
	
	BoyRing ring(8);
	ring.showAll();
	
	ring.countNum(3);
	cout << ring.getCodeCur() << endl; 
	
	ring.delNode();
	ring.showAll();
	
	return 0;
}
