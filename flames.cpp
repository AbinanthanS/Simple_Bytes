#include<bits/stdc++.h>
using namespace std;

string result(string s1,string s2){
	
	vector<char> v;
	int n,i,j,i1=0;
	
	for (i = 0;i<s1.length();i++){
		for (j = i1;j<s2.length();j++){
			if (s1[i]==s2[j]){
				s1[i]=s2[j] = '*';
				i1++;
				break;
			}
		}
	}
	for (int i = 0;i<s1.length();i++){
		if (s1[i] != '*') v.push_back(s1[i]);
	}
	for (int i = 0;i<s2.length();i++){
		if (s2[i] != '*') v.push_back(s2[i]);
	}
	
	int n1 = v.size();
	string f = "flames";
	
	int pos = 0;
	for (int cnt = 6;cnt>1;cnt--){        
		pos = (pos+n1-1)%cnt;              
		f.erase(f.begin()+pos);            
	}
	char result = f[0];
	switch(result){
		case 'f':return "are friends";
		case 'l':return "love each other";
		case 'a':return "have affection b/w each other";
		case 'm':return "are married";
		case 'e':return "are probably enemies";
		case 's':return "are siblings";
	}
}

int main(){
	cout<<"FIND IT !"<<"\n";
	
	string s1,s2;
	cout<<"Enter your name > "; cin>>s1;
	cout<<"\n";
	cout<<"Enter name in your mind > "; cin>>s2;
	cout<<"\n";
    
    cout<<"You Both "<<result(s1,s2)<<"\n";
     
	return 0;
}
