#include"head.h"
void Print_f(vector<char> v) {
	for(int i=0; i<v.size(); i++) //相同的成员变量所以可以访问私有域
		cout<<v[i]<<" ";
	cout<<endl;
}
vector<char> Coomplement_set(vector<char>v,vector<char>v1) {//补集 
	vector<char>::iterator i;
	vector<char>::iterator j;
	for(i=v.begin(); i<v.end(); i++) {
		for(j=v1.begin(); j<v1.end(); j++)
			if(*i==*j) {
				v.erase(i);
			}
	}
	return v;
}
vector<char> Set::Union(Set&c1) {//并集
			vector<char>v2;
			int l=c1.v1.size(),len=c1.v2.size(),k,i,j;
			for(i=0; i<l; ++i)
				v2.push_back(c1.v1[i]);
			k=v2.size();
			for(i=k,j=0; i<k+len; i++,j++)
				v2.push_back(c1.v2[j]);
			sort(v2.begin(),v2.end());
			v2.erase(unique(v2.begin(),v2.end()),v2.end());
			return v2;
		}
vector<char> Set::intersection(Set&c1) {//交集
			int l,len;vector<char>v1,v2,v3;
			v2=c1.v2;v1=c1.v1;
			Inspect(c1,&l,&len);
			for(int i=0; i<len+1; ++i) {
				for(int j=0; j<l+1; j++)
					if(v1[i]==v2[j])
						v3.push_back(v2[i]);
			}
			return v3;
		}
vector<char> Set::Complement_set(Set&c1) {//补集 
	vector<char>::iterator i;
	vector<char>::iterator j;
	vector<char>v1,v2;v1=c1.v1;v2=c1.v2;
	for(i=v1.begin(); i<v1.end(); ++i) {
		for(j=v2.begin(); j<v2.end(); j++)
			if(*i==*j) {
				v1.erase(i);
			}
	}
	return v1;
}
void Set::relative_complement(Set&c1){//相对补集 
	int l=c1.v1.size(),len=c1.v2.size();vector<char>v3,v4;int i,j;
	for(i=0;i<l;++i)
		for(j=0;j<len;++j)
			if(c1.v1[i]==c1.v2[j])
				v3.push_back(c1.v1[j]);
	v4=c1.Union(c1);
	v3=Coomplement_set(v4,v3);
	Print_f(v3);
}

void Set::Absolute_complement(Set&c1){//绝对补集 
	vector<char>v1,v2;
	v1=Union(c1);
	v2=intersection(c1);
	v2=Coomplement_set(v1,v2);
	Print_f(v2); 
	return;
}
