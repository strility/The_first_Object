#include"head.h"
void Set::Empty_set(Set&c1) {//是否空集 
	int l=c1.v1.size();
	if(c1.v1.size()==0)
		cout<<"Empty set"<<endl;
	else
		cout<<"no empty set"<<endl;
}
void Set::Equal_set(Set&c1) {//是否相等集 
	int l,len;l=c1.v1.size();len=c1.v2.size();
	sort(c1.v1.begin(),c1.v1.end());sort(c1.v2.begin(),c1.v2.end());
	if(c1.v1[0]==c1.v2[0]&&l==len&&c1.v1[l]==c1.v2[len])
		cout<<" equal  set"<<endl;
	else
		cout<<"no equal set"<<endl;
}
void Set::True_subset(Set&c1) {//是否有输出真子集 
	int l,len,i,count=0;int sum;
	Inspect(c1,&l,&len);
	count=check(c1,l,len,count);
	sum=subset(c1);
	if(count==1||sum==1)
		cout<<"no true set"<<endl;
	else 
		cout<<"true set"<<endl;
}
void Set::Power_level(Set&c1) {//幂级 
	int l=c1.v2.size(),len;
	len=pow(2,l);
	cout<<len<<endl;
}
int Set::subset(Set&c1) {//是有否子集 
	int l,len,i,count=0,sum=0;
	Inspect(c1,&l,&len);
	count=check(c1,l,len,count);
	if(count==1&&v1[0])
		cout<<"subset"<<endl;
	else  {
	cout<<"no subset"<<endl;sum=1;}return sum;
}
