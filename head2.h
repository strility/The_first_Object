#ifndef HEAD
#define HEAD
#include"head.h"
#include<bits/stdc++.h>

class Relation{
	private:
		vector<char> v3;
	public:
		Relation(){};
		Relation(const &p);
		friend class Set;
		void the_date(Set &a){
			a.getV1();
		}
    	void myP()
		{
			cout<<"ok"<<endl;
		 } 
		void enter_the_choice(Relation&);
		string AB(Relation&); //A上B
		string Inverse(Relation&);
		void All_relations(Relation&);
		void Identity(Relation&);//恒等
		void less_than(Relation&);//小于
		void Multiple(Relation&);//整除
		void Contain(Relation&);//包含
		void Domain_of_definition(Relation&);//定义域
		void range(Relation&);//值域
		void domain(Relation&);//全域
		void Right_complex(Relation&);
		void Mirror(Relation&,string k);
		void Limit(Relation&,string k);
};

#endif
