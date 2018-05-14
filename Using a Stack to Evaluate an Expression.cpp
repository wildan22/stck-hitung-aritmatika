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

int prec(char x)
{
    if(x == '*' || x == '/')
    return 2;
    else if(x == '+' || x == '-')
    return 1;
    else
    return -1;
}

int main(){
	stack ms;
	int p_kata,hasil;
	string a,p;
	cout<<"Input Bentuk Infix : ";
	getline(cin,a);
	p_kata=a.length();
	for (int i=0;i<p_kata;i++){
		if (a[i] >= '0' && a[i] <= '9'){
			p+=a[i];
		}
		else if (a[i] ==  '('){
			ms.push(a[i]);
		}
		else if (a[i] == ')'){
			while (ms.IsEmpty() != true && ms.Top() != '('){
				char tmp=ms.Top();
				ms.pop();
				p+=tmp;
			}
			if (ms.Top() == '('){
				ms.pop();
			}
		}
		if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
			if (ms.IsEmpty() == true || ms.Top() == '('){
				ms.push(a[i]);
			}
		
		else{
			while (ms.IsEmpty() != true && ms.Top() != '(' && prec(a[i]) <= prec(ms.Top())){
				char tmp=ms.Top();
				ms.pop();
				p+=tmp;
			}
			ms.push(a[i]);
			}	
		}
	}
	while(ms.IsEmpty() != true){
			char tmp=ms.Top();
			ms.pop();
			p+=tmp;
	}
	
	for(int i=0;i<p_kata;i++){
		if (p[i] >= '0' && p[i] <= '9'){
			ms.push(p[i]);
		}
		if ( p[i]=='+' || p[i]=='-' || p[i]=='*' || p[i]=='/' ){
			int A=ms.Top() - '0';  	//Simpan top pada variabel A
			ms.pop();				//Pop Stack
			int B=ms.Top() - '0';	//Simpan top pada variabel B
			ms.pop();				//Pop Stack
			if (p[i]=='+'){
				hasil=B+A;
				char tmphasil=hasil + '0'; //Konversi dari int ke char
				ms.push(tmphasil);
			}
			else if (p[i]=='-'){
				hasil=B-A;
				char tmphasil=hasil + '0';
				ms.push(tmphasil);
			}
			else if (p[i]=='*'){
				hasil=B*A;
				char tmphasil=hasil + '0';
				ms.push(tmphasil);
			}
			else if (p[i]=='/'){
				hasil=B/A;
				char tmphasil=hasil + '0';
				ms.push(tmphasil);
			}
		}
	}
	
	char charhasil=ms.Top();
	int hasilakhir=charhasil - '0'; //Konversi dari char ke int
	
	
	//Print Postfix dan Hasil Akhir
	cout<<"Bentuk Postfix : "<<p<<endl;
	cout<<"Hasil Akhir = "<<hasilakhir<<endl;
}

