#pragma once

/*包装类:对Person进行包装,完成操作符()重载 
*/
#include "Person.h"
class PersonCmp{
	public:
		bool operator()(const Person & p1, const Person & p2){
			return p1.age > p2.age;
		}
};
