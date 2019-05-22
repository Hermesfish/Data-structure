# 结构体实现带头结点的单链表
> 用两个结构体实现带头结点的单链表，完成将递增顺序的A,B链表的共同元素拷贝到新链表C的功能。
## 带头结点的单链表
```txt
               p
               |
               v 
             +---+     +---+     +---+     +---+     +---+     +---+
   head  --> |   | --> | 2 | --> | 5 | --> | 7 | --> | 4 | --> | 6 | -->  NULL
             +---+     +---+     +---+     +---+     +---+     +---+
```
加入头结点的好处，有利于代码的统一，不必分两种情况讨论。以下插入均为尾插法，即在结点后部插入；头插法也有妙用。
### 在表头插入
```txt
		  +---+
            p --> | 1 |
	    	  +---+
                    |
             +---+  v  +---+     +---+     +---+     +---+     +---+
   head  --> |   | --> | 2 | --> | 5 | --> | 7 | --> | 4 | --> | 6 | -->  NULL
             +---+     +---+     +---+     +---+     +---+     +---+
```
```c++
p->next = head->next;
head->next = p;
```
### 在表中加入
```txt
		                      +---+
                                  pre | 8 | <-- p
	    	                   |  +---+
                                   v    |
             +---+     +---+     +---+  v  +---+     +---+     +---+
   head  --> |   | --> | 2 | --> | 5 | --> | 7 | --> | 4 | --> | 6 | -->  NULL
             +---+     +---+     +---+     +---+     +---+     +---+
```
```c++
p->next = pre->next;
pre->next = p;
```
### 在表尾加入
```txt
		                                                    +---+
                                   			       tail | 11 | <-- p
	    	                                                 |  +---+
                                     			         v    |
             +---+     +---+     +---+     +---+     +---+     +---+  v
   head  --> |   | --> | 2 | --> | 5 | --> | 7 | --> | 4 | --> | 6 | -->  NULL
             +---+     +---+     +---+     +---+     +---+     +---+
```
```c++
LNode* tail = Get_Tail(head);
p->next = tail->next;
tail->next = p;
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
### Append()函数
> Append(Linklist&, int) -> {bool}  
> 功能说明：参数为单链表和整数，添加成功返回true。
```c++
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
```
### Print()函数
> Print(Linklist&)
> 功能说明：参数为单链表，输出链表中的数据元素，无返回值。
```c++
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
```
### Empty()函数
> Empty(Linklist&) -> {bool}  
> 功能说明：参数为单链表，清空单链表的所有元素，释放内存。
```c++
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
```
### main()函数
> 功能说明：生成两个递增顺序的带头结点的单链表，输出新生成链表C的元素。
```c++
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
```
