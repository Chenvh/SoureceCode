#pragma once

/*��װ��:��Person���а�װ,��ɲ�����()���� 
*/
#include "Person.h"
class PersonCmp{
	public:
		bool operator()(const Person & p1, const Person & p2){
			return p1.age > p2.age;
		}
};
