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
		string AB(Relation&); //A��B
		string Inverse(Relation&);
		void All_relations(Relation&);
		void Identity(Relation&);//���
		void less_than(Relation&);//С��
		void Multiple(Relation&);//����
		void Contain(Relation&);//����
		void Domain_of_definition(Relation&);//������
		void range(Relation&);//ֵ��
		void domain(Relation&);//ȫ��
		void Right_complex(Relation&);
		void Mirror(Relation&,string k);
		void Limit(Relation&,string k);
};

#endif
