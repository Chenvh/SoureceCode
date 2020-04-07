#include "..\comm.h"
//#include "..\comm\Func1-1.h"
#include "KMPVector.h"
/*
STL�еĴ�
find

	 size_type find( const basic_string &str, size_type index );
	 size_type find( const char *str, size_type index );  
  	����str���ַ����е�һ�γ��ֵ�λ�ã���index��ʼ���ң���
	  ���û�ҵ��򷵻�string::npos (-1)
  
	size_type find( const char *str, size_type index, size_type length );
	����str���ַ����е�һ�γ��ֵ�λ�ã���index��ʼ���ң�����Ϊlength����
	���û�ҵ��ͷ���string::npos (-1) 
	
	size_type find( char ch, size_type index );
	�����ַ�ch���ַ����е�һ�γ��ֵ�λ�ã���index��ʼ���ң���
	���û�ҵ��ͷ���string::npos (-1)

s=God bye!
r=Good luck!
u=Good luck!
t=God bye!
t�Ĵ���Ϊ8��t�Ĵ洢����Ϊ8�����շ�false
s=God luck!
��s>��t
r=t+s=God bye!God luck!
r=Good bye!Good luck!
s��պ󣬴���Ϊ0�����շ�true
��sΪ�Ӵ�r��[5]���4���ַ���s=bye!
�ɴ�r���Ƶô�t��t=Good bye!Good luck!
�ڴ�t��[5]ǰ���봮s�󣬴�t=Good bye!bye!Good luck!
�Ӵ�t��[0]��ɾ��5���ַ���t=bye!bye!Good luck!

--------------------------------
Process exited after 0.5565 seconds with return value 0
�밴���������. . .

*/
void testStringSTL()
{
	int i;
	char c, *p="God bye!", *q="God luck!";
	string t, s(p),r("Good luck!");
	cout<<"s="<<s<<endl; //s=God bye!
	cout<<"r="<<r<<endl; //r=Good luck!
	
	string u(r);
	cout<<"u="<<u<<endl; //u==Good luck!
	
	t.assign(p);
	cout<<"t="<<t<<endl; //t==God bye!
	cout <<"t�Ĵ���Ϊ"<<t.size(); //8
	cout <<"��t�Ĵ洢����Ϊ"<<t.capacity();//8
	cout <<"�����շ�"<<boolalpha<<t.empty()<<endl;//false
	
	s.assign(q);
	cout<<"s="<<s<<endl; //s=God luck!
	
	i=s.compare(t);
	if(i<0)
		c='<';
	else if(i==0)
		c='=';
	else
		c='>';
	cout<<"��s"<<c<<"��t"<<endl; // >
	
	r=t+s;
	cout<<"r=t+s="<<r<<endl; //r=t+s=God bye!God luck!
	
	s="oo";
	t="o";
	i=-2;
	while(true)
	{
		/*
	   size_type find( const basic_string &str, size_type index );
  	  	����str���ַ����е�һ�γ��ֵ�λ�ã���index��ʼ���ң���
		  ���û�ҵ��򷵻�string::npos(-1), 	  
		*/
		i=r.find(t, i+2); //cout << "i=" << i << endl;
		if(i>=0){
			/*
			string& replace (size_t pos, size_t len, const string& str);
			��str�滻ָ���ַ�������ʼλ��pos��ʼ����Ϊlen���ַ�
			*/			
			r.replace(i, 1, s);
		}			
		else{
			break;
		}
			
	}
	cout <<"r="<<r<<endl; //r=Good bye!Good luck!
	
	s.erase();
	cout <<"s��պ󣬴���Ϊ"<<s.size(); //0
	cout <<"�����շ�" << boolalpha <<s.empty()<<endl;//true
	
	s=r.substr(5, 4); 
	cout<<"��sΪ�Ӵ�r��[5]���4���ַ���s="<<s<<endl; //bye!
	
	t=r;
	cout<<"�ɴ�r���Ƶô�t��t="<<t<<endl; //Good bye!Good luck!
	
	t.insert(5, s);
	cout<<"�ڴ�t��[5]ǰ���봮s�󣬴�t="<<t<<endl; //Good bye!bye!Good luck!
	
	t.erase(0, 5);
	cout<<"�Ӵ�t��[0]��ɾ��5���ַ���t="<<t<<endl;//bye!bye!Good luck!
}




int main(int argc, char** argv) {
	
	testKMPVector();
	
	//testStringSTL();
	return 0;
}
