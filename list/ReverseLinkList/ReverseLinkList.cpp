#include <iostream>
using namespace std;

struct LNode{
	int data;
	LNode* next;
};

LNode* Get_Tail(LNode* head){
	LNode* p = head;
	while(p->next){
		p = p->next;
	}
	return p;
}

void Print(LNode* head){
	LNode* p = head->next;
	while(p){
		cout<<p->data<<endl;
		p = p->next;
	}
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

bool Reverse(LNode* head){
	LNode* p = head->next;
	LNode* r;
	head->next = NULL;
	if(p==NULL)
		return false;	//链表为空，无法转置

	while(p!=NULL){
		r = p->next;		//r保存p的下一个节点
		p->next = head->next;
		head->next = p;
		p = r;
	}
	return true;
}

void Empty(LNode* head){
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
	LNode* head = new LNode;	//创建链表head,并且创建了头结点
	head->next = NULL;

	int array_1[8]={2,5,5,5,7,10,16,22};
	for(int i = 0; i < 8; i++){
		Append(head,array_1[i]);
	}

	Reverse(head);
	Print(head);
	Empty(head);
}
