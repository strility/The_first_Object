#ifndef HEAD_H
#define HEAD_H
#include<bits/stdc++.h>
class Relation;
using namespace std;
class openF {
	public:
		fstream o;
		openF(string filename) {
			o.open(filename.c_str(),ios::in|ios::app);//指针导到最后
		}
		~openF() {
			o.close();
		}
};
class Set {
	private:
		vector<char> v1,v2;
	public:
		//friend class Relation;
		Set() {cout<<"ss"<<endl;}
		Set(const Set&p);
		
		int get()
		{
			return 1;
		}
		vector<char> getV1() 
		{
			return v1;
		}
		void open_the_file();
		void enter_the_choice(const Set&);
		void Inspect(Set&,int *l,int *len);
		vector<char> intersection(Set&);
		vector<char> Union(Set&);
		void enter_the_choice(Set&);
		vector<char> Complement_set(Set&);
		int check(Set&c1,int l,int len,int count);
		int subset(Set&c1);
		void Empty_set(Set&c1);
		void True_subset(Set&c1);
		void Power_level(Set&c1);
		void relative_complement(Set&c1);
		void Absolute_complement(Set&c1);
		void Equal_set(Set&c1);
};

#endif
