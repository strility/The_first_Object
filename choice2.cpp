
#include"head2.h"

void Relation::enter_the_choice(Relation&c1) {
	int choice;
	string k,k1;
	while(cin>>choice) {
		switch(choice) {
			case 1:
				c1.All_relations(c1);
				break;//ȫ��
			case 2:
				c1.Identity(c1);
				break;
			case 3:
				c1.less_than(c1);
				break;
			case 4:
				c1.Multiple(c1);
				break;
			case 5:
				c1.Contain(c1);
				break;
			case 6:
				c1.Domain_of_definition(c1);
				break;//������
			case 7:
				c1.range(c1);break;
			case 8:
				c1.domain(c1);break;
			case 9:	cout<<"������"<<endl;
				cin>>k;
				cout<<"��"<<endl;
				c1.Mirror(c1,k);
				break;
			case 10:
				cout<<"������������"<<endl;
				cin>>k1;
				c1.Limit(c1,k1);
				cout<<"�Ҹ���"<<endl;
				break;
			case 11:
				c1.Right_complex(c1);
				break;
			case 12:return;
			default:cout<<"enter error"<<endl;break;
		}
	}
	return;
}
