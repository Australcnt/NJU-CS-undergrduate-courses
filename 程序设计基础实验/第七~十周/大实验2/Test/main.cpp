#include<iostream>
using namespace std;
#include<string>
#include"command.h"

bool startWith(string str,string s){
	return s==str.substr(0,s.length());
}

int main(){
	cout<<"Four command:  cp  cat  cd  exit ! "<<endl;
	char command[1000];
	while(true){
		cout<<"Insert command: ";
		cin.getline(command,1000);
		string order=command;
		if(startWith(order,"cp")){
			copy();		
		}
		else if(startWith(order,"cd")){
			cd();		
		} 
		else if(startWith(order,"cat")){
			cat();		
		} 
    		else if(startWith(order,"exit")){
			cout<<"Exit...."<<endl;
			break;		
		}


	}

}
