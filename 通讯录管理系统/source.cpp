#include<iostream>
#include<string>
#include<ctime>
#define MAX 100
using namespace std;
//��ϵ�˺�ͨѶ¼�ṹ��
struct People {
	string name;
	int age;
	string sex;
	string addrees;
	string phonenumber;
};
struct Phonebook
{
	struct People peopleArray[MAX];
	int M_num;
};
//1����ʾ�˵�����(�ú�����װ)
void showMenu() {
	cout << "\nͨѶ¼����" << endl;
	cout << "��ѡ�����²�����" << endl;
	cout << "\t1__�����ϵ��" << endl;
	cout << "\t2__��ʾ��ϵ��" << endl;
	cout << "\t3__ɾ����ϵ��" << endl;
	cout << "\t4__������ϵ��" << endl;
	cout << "\t5__�޸���ϵ��" << endl;
	cout << "\t6__�����ϵ��" << endl;
	cout << "\t7__�˳�ͨѶ¼" << endl;
	cout << endl;
	cout << endl;
}
//�����ϵ��
void addPeople(Phonebook* abs) {
	if (abs->M_num>= MAX) {
		cout<<"��������" << endl;
		return;
	}
	else {
		string name;
		cout << "������\t";
		cin >> name;
		abs->peopleArray[abs->M_num].name = name;
		string sex;
		cout<<"ѡ���Ա�(��/Ů):\t";
		cin >> sex;
		int chage = 1;
		while (chage) {
			if (sex == "��" || sex == "Ů") {
				abs->peopleArray[abs->M_num].sex = sex;
				chage = 0;
			}
			else {
				cout << "����������������룺" << endl;
				cout << endl;
				cin >> sex;
			}
		}
		int age;
		cout << "��������:" ;
		cin >> age;
		abs->peopleArray[abs->M_num].age = age;
		string addrees;
		cout << "�����ַ:" ;
			cin >> addrees;
			abs->peopleArray[abs->M_num].addrees = addrees;
		string phonenumber;
		cout << "�����ֻ���:" ;
		cin >> phonenumber;
		abs->peopleArray[abs->M_num].phonenumber = phonenumber;
		abs->M_num++;
		system("pause");
		system("cls");
	}
}
//���ҹ��ܵĺ��� 
int isexesit(Phonebook* abs,string name) {
	for (int i = 0; i < abs->M_num; i++) {
		if (abs->peopleArray[i].name == name) {
			return i;
		}
	}
	return  -1;
}
//��ʾ��ϵ��
void showPeople(Phonebook* abs) {
	cout << "��ǰͨѶ¼��" << abs->M_num << "��" << endl;
	if (abs->M_num == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->M_num; i++) {
			cout << "---------------------------------" << endl;
			cout << "|����: " << abs->peopleArray[i].name <<endl;
			cout << "|�Ա�: " << abs->peopleArray[i].sex << endl;
			cout << "|����: " << abs->peopleArray[i].age << endl;
			cout << "|�绰: " << abs->peopleArray[i].phonenumber << endl;
			cout << "|סַ: " << abs->peopleArray[i].addrees << endl;
			cout << "---------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}
//ɾ����ϵ��
void deletePeople(Phonebook* abs) {
	string name;
	int flag = NULL;
	cout << "������Ҫɾ������ϵ��:";
	cin >> name;
	for (int i = 0; i < abs->M_num; i++) {
		if (abs->peopleArray[i].name == name) {
			for (int j = i; j < abs->M_num; j++) {
				abs->peopleArray[j] = abs->peopleArray[j + 1];
				flag = 1;
			}
		}
	}
	if (flag == 1) {
		abs->M_num--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void searchPeople(Phonebook* abs) {
	string name;
	cout << "������ϵ�˵�����:";
	cin >> name;
	int flag = isexesit(abs, name);
	if (flag != -1) {
		cout << "���˵���ϢΪ��" << endl;
		cout << "����: " << abs->peopleArray[flag].name << endl;
		cout << "�Ա�: " << abs->peopleArray[flag].sex << endl;
		cout << "����: " << abs->peopleArray[flag].age << endl;
		cout << "�绰: " << abs->peopleArray[flag].phonenumber << endl;
		cout << "סַ: " << abs->peopleArray[flag].addrees << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void changePeople(Phonebook* abs) {
	string name;
	int op;
	cout << "������ϵ�˵�����:";
	cin >> name;
	int flag = isexesit(abs, name);
	if (flag != -1) {
		cout << "��ѡ���޸ĵ����ݣ�" << endl;
		cout << "1������\t2: �Ա�\t3: ����\t4: �绰:5: סַ" << endl;
		cin >> op;
		switch (op){
		case 1: {
			string name_1;
			cout << "�����޸ĺ������:";
			cin >> name_1;
			abs->peopleArray[flag].name = name_1;
			cout << "�޸ĳɹ�" << endl;
		}
			  break;
		case 2: {
			string sex_1;
			cout << "�����޸ĺ���Ա�:";
			cin >> sex_1;
			abs->peopleArray[flag].sex = sex_1;
			cout << "�޸ĳɹ�" << endl;
		}
			  break;
		case 3: {
			int age_1;
			cout << "�����޸ĺ������:";
			cin >> age_1;
			abs->peopleArray[flag].age = age_1;
			cout << "�޸ĳɹ�" << endl;
		}
			  break;
		case 4: {
			string num;
			cout << "�����޸ĺ���ֻ���:";
			cin >> num;
			abs->peopleArray[flag].phonenumber = num;
			cout << "�޸ĳɹ�" << endl;
		}
			  break;
		case 5: {
			string addrees_1;
			cout << "�����޸ĺ�ĵ�ַ:";
			cin >> addrees_1;
			abs->peopleArray[flag].addrees = addrees_1;
			cout << "�޸ĳɹ�" << endl;
		}
			  break;
		default: {
				  cout << "ѡ�����" << endl;
			  }
			break;
		}
	}
	else {
	cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanPeople(Phonebook*abs) {
	abs->M_num = 0;
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Phonebook abs;
	abs.M_num = NULL;
	int flag = NULL;
	while (true) {
		showMenu();
		cin >> flag;
		switch(flag) {
			case 1://���
				addPeople(&abs);
				break;
			case 2://��ʾ
				showPeople(&abs);
				break;
			case 3://ɾ�� 
				deletePeople(&abs);
				break;
			case 4://����
				searchPeople(&abs);
				break;
			case 5://�޸�
				changePeople(&abs);
				break;
			case 6://���
				cleanPeople(&abs);
				break;
			case 7://�˳�
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				break;
			default:
				cout << "ѡ���ܴ���" << endl;
				cout << endl;
				break;
		}	
	}
	return 0;
}
