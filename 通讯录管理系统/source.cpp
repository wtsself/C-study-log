#include<iostream>
#include<string>
#include<ctime>
#define MAX 100
using namespace std;
//联系人和通讯录结构体
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
//1：显示菜单界面(用函数封装)
void showMenu() {
	cout << "\n通讯录管理" << endl;
	cout << "请选择以下操作：" << endl;
	cout << "\t1__添加联系人" << endl;
	cout << "\t2__显示联系人" << endl;
	cout << "\t3__删除联系人" << endl;
	cout << "\t4__查找联系人" << endl;
	cout << "\t5__修改联系人" << endl;
	cout << "\t6__清空联系人" << endl;
	cout << "\t7__退出通讯录" << endl;
	cout << endl;
	cout << endl;
}
//添加联系人
void addPeople(Phonebook* abs) {
	if (abs->M_num>= MAX) {
		cout<<"人数已满" << endl;
		return;
	}
	else {
		string name;
		cout << "姓名：\t";
		cin >> name;
		abs->peopleArray[abs->M_num].name = name;
		string sex;
		cout<<"选择性别(男/女):\t";
		cin >> sex;
		int chage = 1;
		while (chage) {
			if (sex == "男" || sex == "女") {
				abs->peopleArray[abs->M_num].sex = sex;
				chage = 0;
			}
			else {
				cout << "输入错误，请重新输入：" << endl;
				cout << endl;
				cin >> sex;
			}
		}
		int age;
		cout << "输入年龄:" ;
		cin >> age;
		abs->peopleArray[abs->M_num].age = age;
		string addrees;
		cout << "输入地址:" ;
			cin >> addrees;
			abs->peopleArray[abs->M_num].addrees = addrees;
		string phonenumber;
		cout << "输入手机号:" ;
		cin >> phonenumber;
		abs->peopleArray[abs->M_num].phonenumber = phonenumber;
		abs->M_num++;
		system("pause");
		system("cls");
	}
}
//查找功能的函数 
int isexesit(Phonebook* abs,string name) {
	for (int i = 0; i < abs->M_num; i++) {
		if (abs->peopleArray[i].name == name) {
			return i;
		}
	}
	return  -1;
}
//显示联系人
void showPeople(Phonebook* abs) {
	cout << "当前通讯录有" << abs->M_num << "人" << endl;
	if (abs->M_num == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->M_num; i++) {
			cout << "---------------------------------" << endl;
			cout << "|名字: " << abs->peopleArray[i].name <<endl;
			cout << "|性别: " << abs->peopleArray[i].sex << endl;
			cout << "|年龄: " << abs->peopleArray[i].age << endl;
			cout << "|电话: " << abs->peopleArray[i].phonenumber << endl;
			cout << "|住址: " << abs->peopleArray[i].addrees << endl;
			cout << "---------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}
//删除联系人
void deletePeople(Phonebook* abs) {
	string name;
	int flag = NULL;
	cout << "请输入要删除的联系人:";
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
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void searchPeople(Phonebook* abs) {
	string name;
	cout << "输入联系人的名字:";
	cin >> name;
	int flag = isexesit(abs, name);
	if (flag != -1) {
		cout << "该人的信息为：" << endl;
		cout << "名字: " << abs->peopleArray[flag].name << endl;
		cout << "性别: " << abs->peopleArray[flag].sex << endl;
		cout << "年龄: " << abs->peopleArray[flag].age << endl;
		cout << "电话: " << abs->peopleArray[flag].phonenumber << endl;
		cout << "住址: " << abs->peopleArray[flag].addrees << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void changePeople(Phonebook* abs) {
	string name;
	int op;
	cout << "输入联系人的名字:";
	cin >> name;
	int flag = isexesit(abs, name);
	if (flag != -1) {
		cout << "请选择修改的内容：" << endl;
		cout << "1：名字\t2: 性别\t3: 年龄\t4: 电话:5: 住址" << endl;
		cin >> op;
		switch (op){
		case 1: {
			string name_1;
			cout << "输入修改后的名字:";
			cin >> name_1;
			abs->peopleArray[flag].name = name_1;
			cout << "修改成功" << endl;
		}
			  break;
		case 2: {
			string sex_1;
			cout << "输入修改后的性别:";
			cin >> sex_1;
			abs->peopleArray[flag].sex = sex_1;
			cout << "修改成功" << endl;
		}
			  break;
		case 3: {
			int age_1;
			cout << "输入修改后的年龄:";
			cin >> age_1;
			abs->peopleArray[flag].age = age_1;
			cout << "修改成功" << endl;
		}
			  break;
		case 4: {
			string num;
			cout << "输入修改后的手机号:";
			cin >> num;
			abs->peopleArray[flag].phonenumber = num;
			cout << "修改成功" << endl;
		}
			  break;
		case 5: {
			string addrees_1;
			cout << "输入修改后的地址:";
			cin >> addrees_1;
			abs->peopleArray[flag].addrees = addrees_1;
			cout << "修改成功" << endl;
		}
			  break;
		default: {
				  cout << "选择错误" << endl;
			  }
			break;
		}
	}
	else {
	cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanPeople(Phonebook*abs) {
	abs->M_num = 0;
	cout << "清空成功" << endl;
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
			case 1://添加
				addPeople(&abs);
				break;
			case 2://显示
				showPeople(&abs);
				break;
			case 3://删除 
				deletePeople(&abs);
				break;
			case 4://查找
				searchPeople(&abs);
				break;
			case 5://修改
				changePeople(&abs);
				break;
			case 6://清空
				cleanPeople(&abs);
				break;
			case 7://退出
				cout << "欢迎下次使用" << endl;
				system("pause");
				break;
			default:
				cout << "选择功能错误" << endl;
				cout << endl;
				break;
		}	
	}
	return 0;
}
