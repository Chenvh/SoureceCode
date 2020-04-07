#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:KMPVector.h KMP算法,向量 
 *	Descripton:KMP算法匹配,用向量存储next 
 *
 *******************************/

 
/*
KMP(孔明牌) 算法
用;vector存储next的值 
*/
void visit(int& e){
	cout << e << ",";
}

template <typename T> 
class KMPVector{
private:
	vector<int> v_next;
	T m_str; //主串 
	T p_str;//模式串 
	
	int m_len;
	int p_len;
	
	bool opt_tag;//是否用改进的KMP算法 
 
public:
	//构造函数 
	KMPVector(T mStr, T pStr, bool tag = false){
		m_str = mStr; 
		p_str = pStr;
		
		//计算模式串与主串的长度 
		p_len = p_str.size();
		m_len = m_str.size();
		
		opt_tag = tag;
		
		initNext(); 
		
	}
	
	void initNext(){
		//初值为-1 ,长度为p_str 
		v_next.assign(p_len, -1);	
	}
	
	/*
	从主串的pos位置 开始与子串进行匹配算法, pos默认是0 
	@pos: 指定主串开始的位置 
	*/
	int matchString(int pos=0){
		T newMS; //新主串
		int mLen; 
		
		//按指定位置更新为新主串 newMS, 并更新长度 
		newMS = m_str.substr(pos, m_len-pos ); 
		mLen = newMS.size(); 
		
		//生成模式串的Next的值进行匹配		
		createNext(); 
		
		//主串,模式串的下标,初值皆为0 
		int i=0, j=0; 
		
		while(i<mLen && j<p_len){
			
			//j==-1表示模式串回溯至最先的位置
			// newMS[i] == p_str[j主串与模式串对应位置匹配 
			if(j == -1 || newMS[i] == p_str[j]){
				
				//取下一个 
				i++; j++; 
			}
			else{ //不匹配,主串不动,子串回溯
			 
				//模式串回溯:取next的值即是对应的回溯位置 
				j = v_next[j];
			}			
		} //loop ending,匹配结束
		
		
		printVecNext(); 
		
		//返回匹配的位置 
		return i-j+pos; 
		
	} 
	
	
	
	
	/*生成模式串 pattern_str的next的值 
		string patternS="AAABAAAD";
		INDEX:         [ 0, 1, 2, 3, 4, 5, 6, 7]
	   NEXT:          [-1, 0, 1, 2, 0, 1, 2, 3]
	   OPTIMIZE_NEXT: [-1,-1,-1, 2,-1,-1,-1, 3]
	*/
	void createNext() {
		int i=0;
		int j=-1;
		
		while(i< v_next.size()-1){
			if(j == -1 || p_str[i] == p_str[j]){ //模式串前后匹配
				i++;
				j++;
				
				//填写v_next
				if(opt_tag){ //改进的KMP
				 	v_next[i] = ( p_str[i] == p_str[j]) ? v_next[j] : j;			
				} 
				else{ //非改进的 
					v_next[i] = j;			
				} 
				
			}//if ending, 
			else{//前后失配
				j = v_next[j];
				//回溯至next[j]处.这也是next中保存的意义 
				 
			} 
		}
	}
	
	//输出next 
	void printVecNext(){
		
		
		for_each(v_next.begin(), v_next.end(), visit);
		cout << endl;
		
//		vector<int>::iterator it;
//		cout << "[";
//		for(it=v_next.begin(); it!=v_next.end(); it++){
//			cout << *it ;
//			it != v_next.end()-1? cout<< ",": cout << "]";
//		}
//		cout << endl;
	} 
	

			
};



/*
-1,0,1,2,0,1,2,3,


*/

void testKMPVector(){
	string mainS = "AAABAAABAAABAAAD";
	
	string patternS="AAABAAAD";
	//NEXT:          [-1, 0, 1, 2, 0, 1, 2,3]
	//OPTIMIZE_NEXT: [-1,-1,-1, 2,-1,-1,-1,3]
	
	//KMPVector<string> kmpVec(mainS, patternS);
	
	KMPVector<string> kmpVec(mainS, patternS, 1);
	
	//kmpVec.createNext();
	//kmpVec.printVecNext(); //[-1,0,1,2,0,1,2,3]
	cout << "\n匹配下标是:"; 
	cout << kmpVec.matchString();
	
	
	
	
} 
