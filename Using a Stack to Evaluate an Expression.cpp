#include <iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 100

class stack{
	//private:
		char A[MAX_SIZE];
		char top;
	public:
		stack(){
			top = -1;
		}
	
	void push(char x){
		if(top==MAX_SIZE-1){
			cout<<"Melebihi Batas Array"<<endl;
			return;
		}
		A[++top]=x;
	}
	
	void pop(){
		if(top==-1){
			cout<<"Tidak ada elemen yang bisa di POP"<<endl;
			return;
		}
		top--;
	}
	
	int Top(){
		return A[top];
	}
	
	bool IsEmpty(){
		if(top==-1) {
			return true;
		}
		else {
			return false;
		}
	}
	
	void print(){
		int i;
		cout<<"Stack :";
		for(i=0;i<=top;i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
};



int main(){
	
	
}
