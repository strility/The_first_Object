#include"head.h"
#include"head2.h"
void Relation::enter_the_choice(const Relation&c1) {
	int choice;
	while(cin>>choice) {
		switch(choice) {
			case 1:
				All_relations(c1);
				break;//ȫ��
			case 2:
				Identity(c1);
				break;
			case 3:
				less_than(c1);
				break;
			case 4:
				Multiple(c1);
				break;
			case 5:
				Contain(c1);
				break;
			case 6:
				Domain_of_definition(c1);
				break;//������
			case 7:
				range(c1);
				break;
			case 8:
				domain(c1);
				break;
			case 9:
				cout<<"������"<<endl;
				string k1;
				cin>>k;
				cout<<"��"<<endl;
				Mirror(c1,k);
				break;
			case 10:
				cout<<"������������"<<endl;
				string k1;
				cin>>k1;
				Limit(c1,k1);
				break;
			case 11:
				cout<<"�Ҹ���"<<endl;
				Right_complex(c1);
				break;
			case 12:
				if(chouice==12)return;
			default:
				cout"enter error"<<endl;
				break;
		}
	}
}
