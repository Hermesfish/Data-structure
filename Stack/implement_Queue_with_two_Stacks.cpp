#include <iostream>
using namespace std;
const int maxSize = 10;

struct SqStack{
	int data[maxSize];
	int top = -1;
};

bool Pop(SqStack& S, int& x){
	bool StackEmpty(SqStack&); 
	if(StackEmpty(S))
		return false;
	x = S.data[S.top--];
	return true;
}

bool Push(SqStack& S, int x){
	bool StackOverflow(SqStack&);
	if(StackOverflow(S))
		return false;
	S.data[++S.top] = x;
	return true;
}

bool StackEmpty(SqStack& S){
	if(S.top==-1)
		return true;
	return false;
}

bool StackOverflow(SqStack& S){
	if(S.top==maxSize-1)
		return true;
	return false;
}

//------------------------------------------------------------------------//

bool Enqueue(SqStack& S1, SqStack& S2, int x){
	//分情况讨论，如果S1未满，直接压入S1；
	if(!StackOverflow(S1)){
		Push(S1,x);
		return true;
	}

	//如果S1已满，S2为空，则先把S1中的元素全部压入S2中，再将x压入S1；
	if(StackOverflow(S1)&&StackEmpty(S2)){
		while(!StackEmpty(S1)&&!StackOverflow(S2)){
			int temp = 0;
			Pop(S1, temp);
			Push(S2, temp);
		}
		Push(S1,x);
		return true;
	}

	//如果S1已满，S2不为空，则无法压入，否则会造成顺序混乱
	if(StackOverflow(S1)&&!StackEmpty(S2))
		return false;

}

bool QueueEmpty(SqStack& S1, SqStack& S2){
	if(StackEmpty(S1)&&StackEmpty(S2))
		return true;
	return false;
}

bool Dequeue(SqStack& S1, SqStack& S2, int& x){
	//如果队列为空，则无元素出队
	if(QueueEmpty(S1,S2))
		return false;

	//如果S2不为空，则直接出队
	if(!StackEmpty(S2)){
		Pop(S2, x);
		return true;
	}

	//如果S2为空，S1不为空
	if(StackEmpty(S2)&&!StackEmpty(S1)){
		while(!StackEmpty(S1)&&!StackOverflow(S2)){
			int temp = 0;
			Pop(S1, temp);
			Push(S2, temp);
		}

		if(StackEmpty(S1)){
			Pop(S2,x);
			return true;
		}

		return false;
	}
}

//------------------------------------------------------------------------//

int main(){
	SqStack S1,S2;
	Enqueue(S1, S2, 1);
	Enqueue(S1, S2, 2);
	Enqueue(S1, S2, 3);
	Enqueue(S1, S2, 4);

	int x = 0;
	for(int i = 0; i < 4; i++){
		Dequeue(S1, S2, x);
		cout<<x<<endl;
	}
	
	bool flag = QueueEmpty(S1, S2);
	if(flag)
		cout<<"the Queue is Empty."<<endl;
	
}