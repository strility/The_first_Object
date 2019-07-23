
#include"head2.h"
void Cout(string s1){//最后输出数据带{} 
	int leng=s1.size();
	s1.erase(leng-2);
	s1.insert(leng-2,"}");
	cout<<s1<<endl;
}/*
void Print_f_(vector<char>v){//输出向量 
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
} */
void  Preprocessing(vector<char> s,vector<char>*v1,vector<char>*v2){//对文件中的数据处理，分离出数字和字母 然后再对他们进行处理 
	int number1=0,size1=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
			v1->push_back(s[i]);	
		if(s[i]>='a'&&s[i]<='z')
			v2->push_back(s[i]);
	}
}
string EnterTheSteing(string s1,vector<char>v1,vector<char>v2){//对输出数据的插入，最终形成{<a,b>}二元关系格式输出 
	for(int i=0;i<v2.size();++i){
		for(int j=0;j<v1.size();++j){
			stringstream t;
			t<<"<"<<v2[i]<<","<<v1[j]<<">";
			t<<",";
			s1.insert(1+i*6,t.str());
			}
		}
	return s1;
}

string Relation::AB(Relation&c2){//A上B 
	int i,number1=0,size1=0;
	vector<char> v1,v2;
	Preprocessing(c2.v3,&v1,&v2);
	string s1;
	s1="{}";
	s1=EnterTheSteing(s1,v1,v2);
	Cout(s1);
	return s1;
}
string Relation::Inverse(Relation&c2){ 
	int i,number1=0,size1=0;
	vector<char> v1,v2;
	Preprocessing(c2.v3,&v1,&v2);
	string s1;
	s1=("{}");
	for(i=0;i<v2.size();++i)
		for(int j=0;j<v1.size();++j){
			stringstream t;
			t<<"<"<<v1[j]<<","<<v2[i]<<">"<<",";
			s1.insert(1+i*6,t.str());
		}
	Cout(s1);
	return s1;
}

void Relation::Mirror(Relation&c2,string v){//使用向量的话整 
	string s1,s3,s6,s5=("{}");
	s1=AB(c2);
	int i,len1=s1.size(),k=0;
	for(i=0;i<v.size();++i)
	if(v[i]>='0'&&v[i]<='9'||v[i]>='a'&&v[i]<='z')
		s6[k++]=v[i];
	int j,z=0,p=0;	
	for(i=0;i<len1;++i)
		if(s1[i]>='0'&&s1[i]<='9'||s1[i]>='a'&&s1[i]<='z')
			s3[p++]=s1[i];
	char c[10];
	for(i=0;i<k;++i){
		for(j=0;j<p;j+=2){
			if(s6[i]==s3[j]){
				c[z++]=s3[j+1];
				c[z++]=',';
			}
		}
		s5.insert(1,c);
		memset(c,0,sizeof(c));
	}
	Cout(s5);
}
void Relation::Limit(Relation&c2,string v){
	cout<<"限制"<<endl;cout<<"二元关系"<<endl;
	string s1,s3,s6,s5;s5=("{}");
	s1=AB(c2);
	int i,len1=s1.size(),k=0;for(i=0;i<v.size();++i)
	if(v[i]>='0'&&v[i]<='9'||v[i]>='a'&&v[i]<='z')
		s6[k++]=v[i];
	int j,z=0,p=0;	
	for(i=0;i<len1;++i)
		if(s1[i]>='0'&&s1[i]<='9'||s1[i]>='a'&&s1[i]<='z')
			s3[p++]=s1[i];
	for(i=0;i<k;++i){
		for(j=0;j<p;j+=2){
			if(s6[i]==s3[j]){
				stringstream t;t<<"<"<<s3[j]<<","<<s3[j+1]<<">"<<","; 
				s5.insert(1+z*6,t.str());
				z++;
			}
		}
	}
	Cout(s5);
}
void Relation::Right_complex(Relation&c2){
	string s1,s2;
	s1=AB(c2);
	s2=Inverse(c2);
	int len1=s1.size(),len2=s2.size();int i,k=0,p=0;string s3,s4;
	for(i=0;i<len1;++i)
		if(s1[i]>='0'&&s1[i]<='9'||s1[i]>='a'&&s1[i]<='z')
			s3[k++]=s1[i];
	for(i=0;i<len2;++i)
		if(s2[i]>='0'&&s2[i]<='9'||s2[i]>='a'&&s2[i]<='z')
			s4[p++]=s2[i];
	string s5=("{}");int j,z=0;	
	for(i=1;i<p;i+=2){
		for(j=0;j<p;j+=2)
		if(s3[i]==s4[j]){
			stringstream t;t<<"<"<<s4[i]<<","<<s3[j]<<">"<<",";
			s5.insert(1+z*6,t.str());
			z++;
		}
	}
	Cout(s5);
}

void Relation::All_relations(Relation&c2){
	cout<<"全域关系"<<endl; 
	int len1,i;
	len1=c2.v3.size();
	vector<char> v1,v2;
	Preprocessing(c2.v3,&v1,&v2);
	string s1,s2;
	s1=("{}");s2=("{}");
	s1=EnterTheSteing(s1,v1,v1);
	Cout(s1);
	s2=EnterTheSteing(s2,v2,v2);
	Cout(s2);
}
void Relation::Identity(Relation&c2){
	cout<<"恒等关系"<<endl;
	int len1,i;
	len1=c2.v3.size();
	vector<char> v1,v2;
	Preprocessing(c2.v3,&v1,&v2);
	string s1,s2;
	s1=("{}");s2=("{}");
	for(i=0;i<v1.size();++i){
			stringstream t;
			t<<"<"<<v1[i]<<","<<v1[i]<<">";
			t<<",";
			s1.insert(1+i*6,t.str());
			}
	Cout(s1);
	for(i=0;i<v2.size();++i){
			stringstream t;
			t<<"<"<<v2[i]<<","<<v2[i]<<">";
			t<<",";
			s2.insert(1+i*6,t.str());
			}
	Cout(s2);
}

void Relation::less_than(Relation&c2){
	cout<<"小于关系"<<endl;
	int i;
	vector<char> v1,v2;
	Preprocessing(c2.v3,&v1,&v2);
	string s1,s2;
	s1=("{}");s2=("{}");
	for(i=0;i<v1.size();++i){	
		for(int j=i;j<v1.size();++j){
			stringstream t;
			t<<"<"<<v1[i]<<","<<v1[j]<<">";
			t<<",";
			s1.insert(1+i*6,t.str());
			}
		}
	Cout(s1);
	for(i=0;i<v2.size();++i){
		for(int j=i;j<v2.size();++j){
			stringstream t;
			t<<"<"<<v2[i]<<","<<v2[j]<<">";
			t<<",";
			s2.insert(1+i*6,t.str());
			}
		}
	Cout(s2);
}

void Relation::Multiple(Relation&c2){//字符串需要-48的到数字才能进行运算 
	cout<<"整除关系"<<endl;
	int len1,i,number1=0,size1=0;
	len1=c2.v3.size();
	vector<char> v1,v2;
	sort(c2.v3.begin(),c2.v3.end(),greater<char>());
	Preprocessing(c2.v3,&v1,&v2);
	string s1;s1=("{}");int j;
	for(i=0;i<v1.size();++i){
		stringstream t;
		t<<"<"<<v1[i]<<","<<v1[i]<<">";
			t<<",";
			s1.insert(1+i*6,t.str());
		}
	int len=s1.size();
	for(i=0;i<v1.size();++i)		
		for(j=i+1;j<v1.size();++j){
			stringstream t;
			if((v1[i]-48)/(v1[j]-48)>1&&(v1[i]-48)%(v1[j]-48)==0){
			t<<"<"<<v1[i]<<","<<v1[j]<<">";
			t<<",";
			s1.insert(len+i*6-1,t.str());
			}
		}
	Cout(s1);
}

void Relation::Contain(Relation&c2){//使用一个O来表示空集然后把空集加到两个几何中再进行操作 
	cout<<"包含关系"<<endl;
	cout<<"空集用O表示"<<endl;
	int len1,i,number1=0,size1=0;
	len1=c2.v3.size();
	vector<char> v1,v2;
	v1.push_back('O'); 
	v2.push_back('O'); 
	Preprocessing(c2.v3,&v1,&v2);
	string s1;
	s1=("{}");
	s1=EnterTheSteing(s1,v2,v1);
	Cout(s1);
}

void Relation::Domain_of_definition(Relation&c2){
	cout<<"定义域"<<endl;//我们规定字母为定义域 
	int len1,i,size1=0;
	len1=c2.v3.size();
	vector<char> v1,v2;
	for(i=0;i<len1;i++){
		if(c2.v3[i]>='a'&&c2.v3[i]<='z')
			v2.push_back(c2.v3[i]);
	}v2.erase(unique(v2.begin(),v2.end()),v2.end());
	string s1;
	s1=("{}");
	stringstream t;
	for(i=0;i<v2.size();i++)
		t<<v2[i]<<",";
	s1.insert(1,t.str());
	Cout(s1);
}

void Relation::range(Relation&c2){
	cout<<"值域"<<endl;int i;//数字为值域 
	vector<char> v1,v2;
	for(i=0;i<c2.v3.size();i++){
		if(c2.v3[i]>='0'&&c2.v3[i]<='9')
			v1.push_back(c2.v3[i]);
	} v1.erase(unique(v1.begin(),v1.end()),v1.end());
	string s1;
	s1=("{}");
	stringstream t;
	for(i=0;i<v1.size();i++)
		t<<v1[i]<<",";
	s1.insert(1,t.str());
	Cout(s1);
}

void Relation::domain(Relation&c2){
	cout<<"全域"<<endl;
	int i;
	vector<char> v1,v2;
	Preprocessing(c2.v3,&v1,&v2);
	string s1;
	s1=("{");
	for(i=0;i<max(v1.size(),v2.size());++i){
		stringstream t;
		t<<v1[i]<<","<<v2[i]<<",";
		s1.insert(1+i*4,t.str());
		}
	Cout(s1);
}

