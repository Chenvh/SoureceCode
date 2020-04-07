#include "..\comm.h"
//#include "..\comm\Func1-1.h"
#include "KMPVector.h"
/*
STL中的串
find

	 size_type find( const basic_string &str, size_type index );
	 size_type find( const char *str, size_type index );  
  	返回str在字符串中第一次出现的位置（从index开始查找）。
	  如果没找到则返回string::npos (-1)
  
	size_type find( const char *str, size_type index, size_type length );
	返回str在字符串中第一次出现的位置（从index开始查找，长度为length）。
	如果没找到就返回string::npos (-1) 
	
	size_type find( char ch, size_type index );
	返回字符ch在字符串中第一次出现的位置（从index开始查找）。
	如果没找到就返回string::npos (-1)

s=God bye!
r=Good luck!
u=Good luck!
t=God bye!
t的串长为8，t的存储容量为8，串空否？false
s=God luck!
串s>串t
r=t+s=God bye!God luck!
r=Good bye!Good luck!
s清空后，串长为0，串空否？true
串s为从串r的[5]起的4个字符，s=bye!
由串r复制得串t，t=Good bye!Good luck!
在串t的[5]前插入串s后，串t=Good bye!bye!Good luck!
从串t的[0]起删除5个字符后，t=bye!bye!Good luck!

--------------------------------
Process exited after 0.5565 seconds with return value 0
请按任意键继续. . .

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
	cout <<"t的串长为"<<t.size(); //8
	cout <<"，t的存储容量为"<<t.capacity();//8
	cout <<"，串空否？"<<boolalpha<<t.empty()<<endl;//false
	
	s.assign(q);
	cout<<"s="<<s<<endl; //s=God luck!
	
	i=s.compare(t);
	if(i<0)
		c='<';
	else if(i==0)
		c='=';
	else
		c='>';
	cout<<"串s"<<c<<"串t"<<endl; // >
	
	r=t+s;
	cout<<"r=t+s="<<r<<endl; //r=t+s=God bye!God luck!
	
	s="oo";
	t="o";
	i=-2;
	while(true)
	{
		/*
	   size_type find( const basic_string &str, size_type index );
  	  	返回str在字符串中第一次出现的位置（从index开始查找）。
		  如果没找到则返回string::npos(-1), 	  
		*/
		i=r.find(t, i+2); //cout << "i=" << i << endl;
		if(i>=0){
			/*
			string& replace (size_t pos, size_t len, const string& str);
			用str替换指定字符串从起始位置pos开始长度为len的字符
			*/			
			r.replace(i, 1, s);
		}			
		else{
			break;
		}
			
	}
	cout <<"r="<<r<<endl; //r=Good bye!Good luck!
	
	s.erase();
	cout <<"s清空后，串长为"<<s.size(); //0
	cout <<"，串空否？" << boolalpha <<s.empty()<<endl;//true
	
	s=r.substr(5, 4); 
	cout<<"串s为从串r的[5]起的4个字符，s="<<s<<endl; //bye!
	
	t=r;
	cout<<"由串r复制得串t，t="<<t<<endl; //Good bye!Good luck!
	
	t.insert(5, s);
	cout<<"在串t的[5]前插入串s后，串t="<<t<<endl; //Good bye!bye!Good luck!
	
	t.erase(0, 5);
	cout<<"从串t的[0]起删除5个字符后，t="<<t<<endl;//bye!bye!Good luck!
}




int main(int argc, char** argv) {
	
	testKMPVector();
	
	//testStringSTL();
	return 0;
}
