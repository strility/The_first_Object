#include"head.h"
void Set::open_the_file() {
	char c,c1;
	openF  a("离散作业4.txt");
	while(!a.o.eof()) {
		a.o>>c; 
		v1.push_back(c);
	}
	for (int i = 0; i < v1.size()-1; i++)
		cout <<v1[i]<<" ";
	cout<<endl;
	cout<<"if you enter the 'T' will break"<<endl;
	while(cin>>c1) {
		if(c1=='T')break;
		v2.push_back(c1);
	}
	sort(v1.begin(),v1.end());
	v1.erase(unique(v1.begin(),v1.end()),v1.end());
	cout<<endl;
}

Set::Set(const Set&p){
	v1=p.v1;v2=p.v2;
}
void Set::Inspect(Set&c1,int *l,int *len) 
	{
		//检查v1或者v的大小
		if(c1.v1.size()>c1.v2.size()) {
			*l=c1.v2.size();
			*len=c1.v1.size();
		} else {
			*len=c1.v2.size();
			*l=c1.v1.size();
		}
	}
int Set::check(Set&c1,int l,int len,int count){
	vector<char>v1=c1.v1,v2=c1.v2;
	for(int i=0; i<len; ++i) {
		for(int j=0; j<l; j++)
			if(v1[i]==v2[j]) {
				count==1;
				break;
		}
	}
}

