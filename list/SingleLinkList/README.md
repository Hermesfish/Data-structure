# 结构体实现带头结点的单链表
> 用两个结构体实现带头结点的单链表，完成将递增顺序的A,B链表的共同元素拷贝到新链表C的功能。
## 带头结点的单链表
```txt
               p
               |
               V 
             +---+     +---+     +---+     +---+     +---+     +---+
 L.head  --> |   | --> | 2 | --> | 5 | --> | 7 | --> | 4 | --> | 6 | -->  NULL
             +---+     +---+     +---+     +---+     +---+     +---+
```
## step1 定义两个结构体
```c++
struct LNode
{
	int data;
	LNode* next;
};

struct Linklist
{
	LNode* head;
};
```
## step2 实现最主要的功能函数Get_Common()
> Get_Common(Linklist&, Linklist&) -> {Linklist*}  
> 功能说明：参数为两个递增排序的单链表，将两个单链表的共同元素拷贝到新建链表C，返回链表指针C。
```c++
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
```
## 一些其他辅助函数
### Get_Tail()函数
> Get_Tail(Linklist&) -> {LNode*}
> 功能说明：参数为单链表，获取单链表的尾指针，返回尾指针。
```c++
LNode* Get_Tail(Linklist& L){
	LNode* p = L.head;
	while(p->next){
		p = p->next;
	}
	return p;
}
```
