#include<iostream>
#include<cmath>
#include<string>

using namespace std;

string add(string a, string b);											//add function prototype
string shift(string a,int m);											// function shift prototype
int main(){																//main function
	string a1,a2;
	while(true){
	cout<<"Enter 2 strings representing 2 large integers: "<<endl;		//USER INPUTS
	cout<<"First Number: ";
	cin>>a1;
	if(a1=="done" || a1=="Done" || a1=="DONE"){
		break;
	}
	while(a1.length()>100){
		cout<<"Enter 100 digits or less: ";
		cin>>a1;
	}
	cout<<"2nd Number: ";
	cin>>a2;
	cout<<endl;
	while(a2.length()>100){
		cout<<"Enter 100 digits or less: ";
		cin>>a2;
	}
	
	int la1=a1.length();
	int la2=a2.length();
	if(la1<la2){
		a1=shift(a1,la2-la1);
	}else if(la1>la2){
		a2=shift(a2,la1-la2);
	}
	
	cout<<a1<<endl<<"+"<<endl;
	cout<<a2<<endl;
	cout<<"="<<endl;
	cout<<add(a1,a2)<<endl<<endl;										//FUNCTION CALL
	}
	
	return 0;
}

string shift(string a,int m){
	for(int i=1;i<=m;i++){
		a="0"+a;
	}
	return a;
	}
	
	
string add(string a, string b){	
	string result=" ";													//add function definition
	char sum[a.length()];
	int carry=0;
	for(int i=a.length()-1;i>=0;i--){
		int IntSum=(int(a[i])-48)+(int(b[i])-48)+carry;
		if(IntSum>10){
			IntSum=IntSum-10;
			sum[i]=(char)48+IntSum;
			carry=1;	
		}else if(IntSum==10){
			IntSum=IntSum-10;
			sum[i]=(char)48;
			carry=1;
		}else{
			sum[i]=(char)48+IntSum;
			carry=0;
		}
	result=sum[i]+result;
		
	}
	if(carry==1){
		result="1"+result;
	}
	
	
	return result;
}


