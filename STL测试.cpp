/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName: STLMain.cpp 
 *	Descripton:STL list vector简单测试 
 *
 *******************************/

#include "..\comm.h"

/*
测试用例:
 
2020,2021,2022,2023,2024,2025,2026,

--------------------------------
Process exited after 0.891 seconds with return value 0
请按任意键继续. . .

*/
void testList(){
	list<int> li;
	int i;
	for(i=0; i<7; i++){
		li.push_back(2020+i);	
	}
	
	//下标法
//	for(i=0; i<li.size(); i++){
//		
//		cout << li[i] << ",";//error	
//	} 
	cout << endl;
	
	//迭代器方法 
	list<int>::iterator ip;//指针
	for(ip = li.begin(); ip != li.end(); ip++){
		cout << *ip << ",";
	} 
	cout <<endl;
} 

/*
测试用例 
2020,2021,2022,2023,2024,2025,2026,
2020,2021,2022,2023,2024,2025,2026,

--------------------------------
Process exited after 1.379 seconds with return value 0
请按任意键继续. . .


*/

void testVector(){
	vector<int> vi;
	int i;
	for(i=0; i<7; i++){
		vi.push_back(2020+i);	
	}
	
	//下标法
	for(i=0; i<vi.size(); i++){
		
		cout << vi[i] << ",";//error	
	} 
	cout << endl;
	
	//迭代器方法 
	vector<int>::iterator ip;//指针
	for(ip = vi.begin(); ip != vi.end(); ip++){
		cout << *ip << ",";
	} 
	cout <<endl;
}
int main(){
	
	//testList();
	testVector();
	return 0;
}

