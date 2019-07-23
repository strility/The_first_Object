#include"head.h"
void Print_(vector<char> v) {
	for(int i=0; i<v.size(); i++) //相同的成员变量所以可以访问私有域
		cout<<v[i]<<" ";
	cout<<endl;
}
void Set::enter_the_choice(Set&c1) {
	cout<<"1 is intersection. 2 is Union. 3 is Complement set. "<<endl;
	cout<<"4 is subset. 5 is True subset. 6 is Empty set. 7 is Equal set." <<endl;
	cout<<"8 is Power level,9 is relative complement"<<endl;
	int choice;
	vector<char>v1,v2,v3,v4,v5;
	while(cin>>choice)
		switch(choice) {
			case 1:
				v1=c1.intersection(c1);
				Print_(v1);
				break;
			case 2:
				v2=c1.Union(c1);
				Print_(v2);
				break;
			case 3:
				v4=c1.Complement_set(c1);
				Print_(v4);
				break;
			case 4:
				c1.subset(c1);
				break;
			case 5:
				c1.True_subset(c1);
				break;
			case 6:
				c1.Empty_set(c1);
				break;
			case 7:
				c1.Equal_set(c1);
				break;
			case 8:
				c1.Power_level(c1);
				break;
			case 9:
				c1.relative_complement(c1);
				break;
			case 10:
				c1.Absolute_complement(c1);
				break;
			case 11:return;
			default:
				cout<<"enter error"<<endl;
				break;
		}
}

