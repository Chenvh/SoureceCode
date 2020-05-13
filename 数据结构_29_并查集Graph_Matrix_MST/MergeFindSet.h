#pragma once

/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:MergeFindSet.h 并查集(优化版) 
 *	Descripton:
 *
 *******************************/
 #include "comm.h"
 typedef vector<int> VI;
 class MergeFindSet{
 private:
 	//m_count is the number of disjoint sets.
	int m_count;
	
	//records distinct identity of each set,when two sets are merged ,their id will be same.
 	VI mv_boss; 
 	
 	//records the child number of each set including the set self.
 	VI mv_rank;
 	
public:
	
	//constructor, init 
	MergeFindSet(): mv_boss(), mv_rank(){
	}
	
	MergeFindSet(int max_size) : m_count(max_size), 
			mv_boss( VI(max_size)), 
			mv_rank( VI(max_size,0) ) {
		
		for(int i=0; i<max_size; i++){
			mv_boss[i] = i;
		}		
	} 
	
	void init(int max_size) {
		m_count= max_size; 
		mv_rank.assign(max_size,0);
		
		for(int i=0; i<max_size; i++){
			mv_boss.push_back(i);//mv_boss[i] = i;
			//mv_rank.push_back(0);//mv_rank[i] = 0;
		}	
	}
	
	//merge :Replace sets containing x and y with their union
	void merge (int x1, int x2){
		
		int leader1 = find(x1);
		int leader2 = find(x2);
		
		if(leader1 == leader2) {
			return;
		}
		
		if( mv_rank[leader1] > mv_rank[leader2] ){
			mv_boss[leader2] = leader1;
		}
		else{
			mv_boss[leader1] = leader2;
			if(mv_rank[leader1] == mv_rank[leader2]){
				mv_rank[leader2] ++;	
			}
		}
		
		m_count --;
		
	}//--- merge() END	

	int find(int x){
		return x == mv_boss[x] ? x :( mv_boss[x] = find(mv_boss[x]) );
	}//--- find () END
	
	bool isSameTeam(int x1, int x2){
		return find(x1) == find(x2);
	}
	
	int getCount(){
		return m_count;
	}
	void show(){
		for(int i=0;i<mv_boss.size();i++){
			cout << mv_boss[i] << " ";
		}
		cout << endl;
	}
	
 };
 
 /*
 TestCase
 
 5
1,1,3

 */
 
 void testMergeFindSet(){
 	MergeFindSet set;
	 set.init(7);
 	
 	set.merge(0,1);
 	set.merge(0,2);
 	cout << set.getCount() << endl;
 	cout << set.find(0) << "," << set.find(2);
	cout << "," << set.find(3) << endl;
 	
 }
