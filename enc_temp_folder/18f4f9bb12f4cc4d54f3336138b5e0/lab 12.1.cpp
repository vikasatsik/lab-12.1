#include<iostream>
using namespace std;



struct Elem
{
	Elem* link1,
		* link2;
	int info;
};


int main()
{
	Elem* p;

	p = new Elem; // 1
	p->link1 = NULL; //2
	p->link1->info=1; //3
	p->link1 = new Elem;//4
	p->link2->info = 2; //5
	p->link2->link2->link2 = p->link1; //6
	p->link2->link1 = p; //7
	p->link2->link1->info = 3; //8
	p->link2->link1 = p->link1; //9
	p->link1->link2->link2 = p->link2; //10
	p->link1->link2->info = 4; //11
	p->link1->link2 = NULL; //12
	p->link2->link1 = p->link1; //13



	delete p->link1->link2; //������ 4 �������
	delete p->link2; //������ 3 �������
	delete p->link1; //������ 2 �������
	delete p; //������ 1 �������

	return 0;
}