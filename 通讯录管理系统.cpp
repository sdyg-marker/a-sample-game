#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//结构体 联系人
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//结构体 通讯录
struct Addressbooks {
	Person personArr[MAX];
	int m_Size;
};
//添加联系人
  void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		string name;
		cout << "输入姓名" << endl;
		cin >> name;
		abs->personArr[abs->m_Size].m_Name=name;

		int sex;
		cout << "输入性别" << endl;
		cout << "1----男" << "   " << "2----女" << endl;
		
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "请重新输入" << endl;

		}
		cout << "输入年龄" << endl;
		int age;
		cin >> age;
		abs->personArr[abs->m_Size].m_Age = age;
		cout << "输入电话号码" << endl;
		string number;
		cin >> number;
		abs->personArr[abs->m_Size].m_Phone = number;
		cout << "输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArr[abs->m_Size].m_Addr = address;
		cout << "添加成功" << endl;
		abs->m_Size++;
		system("pause");
		system("cls");
	}


}
  //显示所有联系人
void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {

		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << i + 1 << " " << "姓名：" << abs->personArr[i].m_Name <<"\t";
			cout << "性别：" << (abs->personArr[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout<< "年龄：" << abs->personArr[i].m_Age  << "\t";
			cout << "电话：" << abs->personArr[i].m_Phone  <<"\t";
			cout << "住址：" << abs->personArr[i].m_Addr<<endl;
		}
		system("pause");
		system("cls");
	}


}
//判断有没有这个人
int isexist(Addressbooks* abs, string name) {
	if (abs->m_Size >= 1) {
		for (int i = 0; i < abs->m_Size; i++) {
			if (abs->personArr[i].m_Name == name) {
				return i;
			}
		}

	}
	
	return -1;
}
//删除联系人
void deledePerson(Addressbooks* abs)
{
	cout << "输入想删除的人" << endl;
	string name;
	cin >> name;
	int xx = isexist(abs, name);
	if (xx == -1) {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = xx; i < abs->m_Size; i++) {
			abs->personArr[i] = abs->personArr[i + 1];

		}
		abs->m_Size--;
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
}
//寻找联系人
void findPerson(Addressbooks* abs) {
	cout << "输入查找的人名" << endl;
	string name;
	cin >> name;
	int xx = isexist(abs, name);
	if (xx == -1) {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << xx + 1 << " " << "姓名：" << abs->personArr[xx].m_Name << "   ";
		cout << "性别：" << (abs->personArr[xx].m_Sex == 1 ? "男" : "女") << "   ";
		cout << "年龄：" << abs->personArr[xx].m_Age << "   ";
		cout << "电话：" << abs->personArr[xx].m_Phone << "   ";
		cout << "住址：" << abs->personArr[xx].m_Addr << endl;
		system("pause");
		system("cls");
	}

}
//修改联系人
void modifyPerson(Addressbooks* abs){
	cout << "输入修改的人名" << endl;
	string name;
	cin >> name;
	int xx = isexist(abs, name);
	if (xx == -1) {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << xx + 1 << " " << "姓名：" << abs->personArr[xx].m_Name << "   ";
		cout << "性别：" << (abs->personArr[xx].m_Sex == 1 ? "男" : "女") << "   ";
		cout << "年龄：" << abs->personArr[xx].m_Age << "   ";
		cout << "电话：" << abs->personArr[xx].m_Phone << "   ";
		cout << "住址：" << abs->personArr[xx].m_Addr << endl;
		cout << "输入新的姓名" << endl;
		cin >> name;
		abs->personArr[xx].m_Name = name;

		int sex;
		cout << "输入新的性别" << endl;
		cout << "1----男" << "   " << "2----女" << endl;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[xx].m_Sex = sex;
				break;
			}
			cout << "请重新输入" << endl;

		}
		cout << "输入新的年龄" << endl;
		int age;
		cin >> age;
		abs->personArr[xx].m_Age = age;
		cout << "输入新的电话号码" << endl;
		string number;
		cin >> number;
		abs->personArr[xx].m_Phone = number;
		cout << "输入新的家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArr[xx].m_Addr = address;
		cout << "修改成功" << endl;
		system("pause");
		system("cls");

	}
}
//清空联系人
void cleanPerson(Addressbooks* abs) {
	cout << "你确定清空联系人" << endl;
	cout << "确定---1  不确定---2" << endl;
	int xx;
	cin >> xx;
	if (xx == 1) {
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
		system("pause");
		system("cls");
	}
	else {  
		system("pause");
		system("cls");
	}
}
//显示屏幕
void showMenu() {
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
}




int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select;
	
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			addPerson(&abs);

			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deledePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
	 		break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			system("pause");
			system("cls");
			break;

		}
	}
}