#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:KMPVector.h KMP�㷨,���� 
 *	Descripton:KMP�㷨ƥ��,�������洢next 
 *
 *******************************/

 
/*
KMP(������) �㷨
��;vector�洢next��ֵ 
*/
void visit(int& e){
	cout << e << ",";
}

template <typename T> 
class KMPVector{
private:
	vector<int> v_next;
	T m_str; //���� 
	T p_str;//ģʽ�� 
	
	int m_len;
	int p_len;
	
	bool opt_tag;//�Ƿ��øĽ���KMP�㷨 
 
public:
	//���캯�� 
	KMPVector(T mStr, T pStr, bool tag = false){
		m_str = mStr; 
		p_str = pStr;
		
		//����ģʽ���������ĳ��� 
		p_len = p_str.size();
		m_len = m_str.size();
		
		opt_tag = tag;
		
		initNext(); 
		
	}
	
	void initNext(){
		//��ֵΪ-1 ,����Ϊp_str 
		v_next.assign(p_len, -1);	
	}
	
	/*
	��������posλ�� ��ʼ���Ӵ�����ƥ���㷨, posĬ����0 
	@pos: ָ��������ʼ��λ�� 
	*/
	int matchString(int pos=0){
		T newMS; //������
		int mLen; 
		
		//��ָ��λ�ø���Ϊ������ newMS, �����³��� 
		newMS = m_str.substr(pos, m_len-pos ); 
		mLen = newMS.size(); 
		
		//����ģʽ����Next��ֵ����ƥ��		
		createNext(); 
		
		//����,ģʽ�����±�,��ֵ��Ϊ0 
		int i=0, j=0; 
		
		while(i<mLen && j<p_len){
			
			//j==-1��ʾģʽ�����������ȵ�λ��
			// newMS[i] == p_str[j������ģʽ����Ӧλ��ƥ�� 
			if(j == -1 || newMS[i] == p_str[j]){
				
				//ȡ��һ�� 
				i++; j++; 
			}
			else{ //��ƥ��,��������,�Ӵ�����
			 
				//ģʽ������:ȡnext��ֵ���Ƕ�Ӧ�Ļ���λ�� 
				j = v_next[j];
			}			
		} //loop ending,ƥ�����
		
		
		printVecNext(); 
		
		//����ƥ���λ�� 
		return i-j+pos; 
		
	} 
	
	
	
	
	/*����ģʽ�� pattern_str��next��ֵ 
		string patternS="AAABAAAD";
		INDEX:         [ 0, 1, 2, 3, 4, 5, 6, 7]
	   NEXT:          [-1, 0, 1, 2, 0, 1, 2, 3]
	   OPTIMIZE_NEXT: [-1,-1,-1, 2,-1,-1,-1, 3]
	*/
	void createNext() {
		int i=0;
		int j=-1;
		
		while(i< v_next.size()-1){
			if(j == -1 || p_str[i] == p_str[j]){ //ģʽ��ǰ��ƥ��
				i++;
				j++;
				
				//��дv_next
				if(opt_tag){ //�Ľ���KMP
				 	v_next[i] = ( p_str[i] == p_str[j]) ? v_next[j] : j;			
				} 
				else{ //�ǸĽ��� 
					v_next[i] = j;			
				} 
				
			}//if ending, 
			else{//ǰ��ʧ��
				j = v_next[j];
				//������next[j]��.��Ҳ��next�б�������� 
				 
			} 
		}
	}
	
	//���next 
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
	cout << "\nƥ���±���:"; 
	cout << kmpVec.matchString();
	
	
	
	
} 
