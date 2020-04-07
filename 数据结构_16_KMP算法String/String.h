#pragma once

#include "..\comm.h"

class String{
private:
	char *ch;
	int length;
public:
	String()
	{
		ch=NULL;
		length=0;
	}
	String(const char* str)
	{
		length=strlen(str);
		
		ch=new char[length];
		
		assert(ch!=NULL);
		
		for(int i=0; i<length; i++){
			ch[i]=str[i];
		}
			
	}
	String(const String &S)
	{
		length=S.length;
		ch=new char[length];
		assert(ch!=NULL);
		
		for(int i=0; i<length; i++){
			ch[i]=S[i];
		}
			
	}
	~String()
	{
		clearString();
	}
	void clearString()
	{
		if(ch!=NULL)
		{
			delete[]ch;
			ch=NULL;
		}
		length=0;
	}
	void assignStr(const char* str)
	{
		clearString();
		length=strlen(str);
		if(length)
		{
			ch=new char[length];
			assert(ch!=NULL);
			for(int j=0; j<length; j++)
				ch[j]=str[j];
		}
	}
	void copyStr(const String &S)
	{
		clearString();
		length=S.length;
		ch=new char[length];
		assert(ch!=NULL);
		for(int i=0; i<S.length; i++)
			ch[i]=S[i];
	}
	bool isEmpty()const
	{
		return length==0;
	}
	int cmpStr(const String &S)const
	{
		for(int i=0; i<length && i<S.length; i++){
			if(ch[i]!=S[i]){
				return ch[i]-S[i];
			}
				
		}
			
		return length-S.length;
	}
	int size()const
	{
		return length;
	}
	void Concat(const String &S1, const String &S2)
	{
		int i;
		clearString();
		length=S1.length+S2.length;
		
		delete[] ch;		
		ch=new char[length];
		assert(ch!=NULL);
		for(i=0; i<S1.length; i++){
			ch[i]=S1[i];
		}
			
		for(i=0; i<S2.length; i++){
			ch[S1.length+i]=S2[i];
		}
			
	}
	String substr(int pos, int len)const
	{
		String Sub; 
		if(!(pos<0 || pos>=length || len<=0 || len>length-pos))
		{
			Sub.length=len;
			Sub.ch=new char[len];
			assert(Sub.ch!=NULL);
			for(int i=0; i<len; i++)
				Sub.ch[i]=ch[pos+i];
		}
		return Sub;
	}
	bool insertStr(int pos, const String &S)
	{
		int i;
		if(pos<0 || pos>length)
			return false;
		if(S.length)
		{
			char *p=new char[length+S.length];
			assert(p!=NULL);
			for(i=0; i<pos; i++)
				p[i]=ch[i];
			for(i=0; i<S.length; i++)
				p[pos+i]=S[i];
			for(i=pos; i<length; i++)
				p[i+S.length]=ch[i];
			length+=S.length;
			delete[]ch;
			ch=p;
		}
		return true;
	}
	bool delStr(int pos, int len)
	{
		int i;
		char *p;
		if(length<pos+len)
			return false;
		p=new char[length-len];
		assert(p!=NULL);
		for(i=0; i<pos; i++)
			p[i]=ch[i];
		for(i=pos; i<length-len; i++)
			p[i]=ch[i+len];
		length-=len;
		delete[]ch;
		ch=p;
		return true;
	}
	int Index(const String &S, int pos)const
	{
	 
		String sub;
		if(pos>=0)
			for(int i=pos; i<=length-S.length; i++)
			{
				sub=substr(i, S.length);
				
				if(sub.cmpStr(S)==0)
					return i;
			}
		return -1;
	}
	bool replaceStr(const String &T, const String &V)
	{
	 
		if(T.length==0)
			return false;
		int i=0;
		while(i>-1)
		{
			i=Index(T, i);
			if(i>-1)
			{
				StrDelete(i, T.length);
				StrInsert(i, V);
				i+=V.length;
			}
		}
		return true;
	}
	
	//操作符重载
	 
	char& operator[](int i)const
	{
		return ch[i];
	}
	String& operator=(const String &right_str)
	{
		if(this!= &right_str)
		{
			if(ch!=NULL){
				delete ch;
			}
				
			ch=new char[right_str.length];
			assert(ch!=NULL);
			for(int i=0; i<right_str.length; i++){
				ch[i]=right_str[i];
			}
				
			length=right_str.length;
		}
		return *this;
	}
	

    void operator+=(const String& right_str)
    {
      char* pTemp = new char[length+right_str.length];
      assert(ch!=NULL);
      int i;  
      for(i=0; i< this->length; i++){
			pTemp[i]=ch[i];
		}
		for(i=0; i<right_str.length; i++){
			pTemp[length+i]=right_str[i];
		}
      
      delete[]ch;
      ch = pTemp;
      length += right_str.length;
    }

   
   String operator+(const String& right_str)
   {
   	//此处需要多加1个空间,用于存放 '\0' 
      char* pTemp = new char[length + right_str.length +1];
        
      int i;  
      for(i=0; i< this->length; i++){
			pTemp[i]=ch[i];
		}
		for(i=0; i<right_str.length; i++){
			pTemp[length+i]=right_str[i];
		}
		
		pTemp[i] = 0;//加上'\0'变成char*  
        
      return String(pTemp);
   }
  	
	ostream& operator << (ostream& out, String& str)
	{
		str.Output(out);
		return out;
	}
	
	void Output( ostream& out )
	{
		for(int i=0; i<length; i++){
			out<<ch[i];
		}
			
	}
};




