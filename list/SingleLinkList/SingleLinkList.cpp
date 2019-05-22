/*
	实现将递增顺序的A,B链表的共同元素拷贝到新链表C中。
*/
#include <iostream>
using namespace std;
struct LNode
{
	int data;
	LNode* next;
};

struct Linklist
{
	LNode* head;
};
//声明两个简单的struct，LNode和Linklist
//由于未对结构体进行初始化，所以要自己初始化，还要加上头结点。

LNode* Get_Tail(Linklist& L){
	LNode* p = L.head;
	while(p->next){
		p = p->next;
	}
	return p;
}

void Print(Linklist& L){
	LNode* p = L.head->next;
	int length = 0;
	while(p){
		cout<<p->data<<endl;
		p = p->next;
		length++;
	}

	cout << length << endl;
}

bool Append(Linklist& L, int x){
	LNode* tail;
	tail = Get_Tail(L);
	LNode* r = new LNode;
	r->data = x;
	r->next = tail->next;
	tail->next = r;
	tail = tail->next;
	return true;
}

Linklist* Get_Common(Linklist& La, Linklist& Lb){

	Linklist* Lc = new Linklist;	//同样也要为LC创建一个空结点
	LNode* temp2 = new LNode;
	Lc->head = temp2;	//如何实现带一个空节点
	Lc->head->next = NULL;

	LNode* pa = La.head->next;
	LNode* pb = Lb.head->next;
	LNode* tail = Lc->head;	//r为指向Lc链表尾部的指针

	while(pa&&pb){
		if(pa->data==pb->data){
			LNode* r = new LNode;
			r->data = pa->data;
			r->next = tail->next;
			tail->next = r;
			tail = tail->next;

			pa = pa->next;
			pb = pb->next;
		}
		else if(pa->data<pb->data)
			pa = pa->next;
		else
			pb = pb->next;
	}

	return Lc;
}

bool Empty(Linklist& L){
	LNode* p = L.head;
	LNode* q;
	while(p->next){
		q = p->next;
		p->next = q->next;
		delete(q);
	}
	if(p->next==NULL){
		cout<<"Linklist is Empty."<<endl;
	}
}

int main(){

	//将数组放入A链表中
	Linklist La;
	LNode* temp = new LNode;
	La.head = temp;	//如何实现带一个空节点
	La.head->next = NULL;
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i = 0; i < 10; i++){
		Append(La,array[i]);
	}

	//将数组放入B链表中
	Linklist Lb;
	LNode* temp1 = new LNode;
	Lb.head = temp1;	//如何实现带一个空节点
	Lb.head->next = NULL;	//可简略
	int array_1[8]={2,5,5,5,7,10,16,22};
	for(int i = 0; i < 8; i++){
		Append(Lb,array_1[i]);
	}
	
	Linklist* Lc;
	Lc = Get_Common(La,Lb);

	Print(*Lc);
	//Print(La);
	Empty(*Lc);
	Print(*Lc);

	Empty(La);
	Empty(Lb);

	return 0;
}
