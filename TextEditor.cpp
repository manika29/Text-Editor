#include<bits/stdc++.h>
using namespace std;
void write();
void undo();
void redo();
void backspace();

stack<string>s1;
stack<string>s2;

void PrintStack(stack<string> &s1)
{
    if (s1.empty())
        return;
     
 
    string x = s1.top();
    s1.pop();   
    PrintStack(s1);
    cout << x << " ";
    s1.push(x);
}

string str;

int main()
{
	int ch;
	

	do{

		cout<<"\n";
		cout<<"\n";
		cout<<"***** Text Editor Application *****\n\n";
		cout<<"1. Write\n";
		cout<<"2. Undo\n";
		cout<<"3. Redo\n";
		cout<<"4. Backspace\n";
		cout<<"0. Exit\n";

		
		cout<<"Please Enter your Choice : ";
		cin>>ch;		
		
		switch(ch){
			case 1: write();
			        break;

			case 2: undo();
					break;

			case 3: redo();
					break;

			case 4: backspace();
					break;

			case 0:	cout<<"\nThanks for using the application\n";
			        return 0;

			default: cout<<"Wrong choice selected";
			         main();
		}

		}while(ch!=0);

	
	
	return 0;
}

void write(){
	system("cls");
	cout<<"Enter the string : ";
	cin.clear();
	fflush(stdin);
	getline(cin,str);
	string temp="";
	for(int i=0; i<str.length(); i++){
		if(str[i]==' '){
			s1.push(temp);
			temp="";
		}
		else
			temp+=str[i];
	}
	s1.push(temp);
	temp="";

	PrintStack(s1);

	

}

void undo(){
	system("cls");
		
	cout<<"String after performing undo operation is : ";
	string temp1=s1.top();
	s1.pop();
	s2.push(temp1);


	PrintStack(s1);
}

void redo(){
	system("cls");
	string temp2=s2.top();
	s2.pop();
	s1.push(temp2);

	cout<<"String after performing redo operation is : ";
	PrintStack(s1);

}
void backspace(){
	system("cls");
	string temp3=s1.top();
	s1.pop();
	string temp4=temp3.substr(0,temp3.length()-1);
	s1.push(temp4);

	PrintStack(s1);
}