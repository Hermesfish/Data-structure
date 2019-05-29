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

int main(){

	SqStack Stack;

	Push(Stack,8);
	Push(Stack,5);

	int x = 0;
	Pop(Stack,x);
	cout<<x<<endl;

	Pop(Stack,x);
	cout<<x<<endl;

	bool flag = StackEmpty(Stack);
	if(flag)
		cout<<"the Stack is Empty."<<endl;

	for(int i = 0; i < 10; i++)
		Push(Stack,i);

	flag = StackOverflow(Stack);
	if(flag)
		cout<<"Ooooops, the Stack is Overflow."<<endl;

	return 0;
}
