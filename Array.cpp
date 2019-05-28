#include <iostream>
using namespace std;

const int m = 10;
const int n = 8;
const int size = 20;

int* Merge(int a[], int b[], int c[]){
	int k = 0;
	int i = 0;
	int j = 0;
	while(i<m&&j<n){
		if(a[i]<=b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}

	while(i<m){
		c[k++] = a[i++];
	}

	while(j<n){
		c[k++] = b[j++];
	}

	return c;
}

int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[8] = {2,5,5,5,7,10,16,22};
	int c[size];

	int* ans = Merge(a,b,c);

	for(int i = 0; i < m+n; i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;

	return 0;
}
