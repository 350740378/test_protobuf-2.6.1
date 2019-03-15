// test_protobuf.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>  
#include "person.pb.h"  

using namespace std;
using namespace tutorial;

int main()
{
	Person person;

	person.set_name("liyifeng");
	person.set_age(26);
	person.set_email("liyifeng1989@126.com");

	cout << person.name() << endl;
	cout << person.age() << endl;
	cout << person.email() << endl;

	//���л� b
	tutorial::Person* p = new tutorial::Person();
	p->set_name("liyifeng");
	p->set_age(26);
	p->set_email("liyifeng1989@126.com");

	int buffsize = p->ByteSize();
	void* buff = malloc(buffsize);
	p->SerializeToArray(buff, buffsize);
	//���л� e

	//�����л� b
	tutorial::Person personx;
	int length = 100 ;
	personx.ParseFromArray(buff, length);

	string name = personx.name();
	int age = personx.age();
	string email = personx.email();
	//�����л� e

	getchar();
	system("pause");
	return 0;
}
