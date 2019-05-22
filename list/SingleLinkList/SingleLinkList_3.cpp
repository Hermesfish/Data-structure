/*
	实现将递增顺序的A,B链表的共同元素拷贝到新链表C中。
	只用一个结构体。
*/
#include <iostream>
using namespace std;
struct LNode
{
	int data;
	LNode* next;
};

//struct Linklist
//{
//	LNode* head;
//};
//声明两个简单的struct，LNode和Linklist
//由于未对结构体进行初始化，所以要自己初始化，还要加上头结点

LNode* Get_Tail(LNode* head){
	LNode* p = head;
	while(p->next){
		p = p->next;
	}
	return p;
}

void Print(LNode* head){
	LNode* p = head->next;
	int length = 0;
	while(p){
		cout<<p->data<<endl;
		p = p->next;
		length++;
	}

	cout << length << endl;
}

bool Append(LNode* head, int x){
	LNode* tail;
	tail = Get_Tail(head);
	LNode* r = new LNode;
	r->data = x;
	r->next = tail->next;
	tail->next = r;
	tail = tail->next;
	return true;
}

LNode* Get_Common(LNode* head_A, LNode* head_B){

	LNode* head_C = new LNode;			//实现头结点的简单方式
	head_C->next = NULL;

	LNode* pa = head_A->next;
	LNode* pb = head_B->next;
	LNode* tail = head_C;	//r为指向Lc链表尾部的指针

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

	return head_C;
}

bool Empty(LNode* head){
	LNode* p = head;
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
	LNode* head_A = new LNode;	//实现头结点的简单方式
	head_A->next = NULL;
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i = 0; i < 10; i++){
		Append(head_A,array[i]);
	}

	//将数组放入B链表中
	LNode* head_B = new LNode;	//实现头结点的简单方式
	head_B->next = NULL;	//可简略，已经实现了
	int array_1[8]={2,5,5,5,7,10,16,22};
	for(int i = 0; i < 8; i++){
		Append(head_B,array_1[i]);
	}
	
	LNode* head_C = Get_Common(head_A,head_B);

	Print(head_C);
	//Print(La);
	Empty(head_C);
	Print(head_C);

	Empty(head_A);
	Empty(head_B);

	return 0;
}
