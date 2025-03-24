#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//�ṹ�� ��ϵ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//�ṹ�� ͨѶ¼
struct Addressbooks {
	Person personArr[MAX];
	int m_Size;
};
//�����ϵ��
  void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		string name;
		cout << "��������" << endl;
		cin >> name;
		abs->personArr[abs->m_Size].m_Name=name;

		int sex;
		cout << "�����Ա�" << endl;
		cout << "1----��" << "   " << "2----Ů" << endl;
		
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "����������" << endl;

		}
		cout << "��������" << endl;
		int age;
		cin >> age;
		abs->personArr[abs->m_Size].m_Age = age;
		cout << "����绰����" << endl;
		string number;
		cin >> number;
		abs->personArr[abs->m_Size].m_Phone = number;
		cout << "�����ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArr[abs->m_Size].m_Addr = address;
		cout << "��ӳɹ�" << endl;
		abs->m_Size++;
		system("pause");
		system("cls");
	}


}
  //��ʾ������ϵ��
void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {

		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << i + 1 << " " << "������" << abs->personArr[i].m_Name <<"\t";
			cout << "�Ա�" << (abs->personArr[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout<< "���䣺" << abs->personArr[i].m_Age  << "\t";
			cout << "�绰��" << abs->personArr[i].m_Phone  <<"\t";
			cout << "סַ��" << abs->personArr[i].m_Addr<<endl;
		}
		system("pause");
		system("cls");
	}


}
//�ж���û�������
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
//ɾ����ϵ��
void deledePerson(Addressbooks* abs)
{
	cout << "������ɾ������" << endl;
	string name;
	cin >> name;
	int xx = isexist(abs, name);
	if (xx == -1) {
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = xx; i < abs->m_Size; i++) {
			abs->personArr[i] = abs->personArr[i + 1];

		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//Ѱ����ϵ��
void findPerson(Addressbooks* abs) {
	cout << "������ҵ�����" << endl;
	string name;
	cin >> name;
	int xx = isexist(abs, name);
	if (xx == -1) {
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << xx + 1 << " " << "������" << abs->personArr[xx].m_Name << "   ";
		cout << "�Ա�" << (abs->personArr[xx].m_Sex == 1 ? "��" : "Ů") << "   ";
		cout << "���䣺" << abs->personArr[xx].m_Age << "   ";
		cout << "�绰��" << abs->personArr[xx].m_Phone << "   ";
		cout << "סַ��" << abs->personArr[xx].m_Addr << endl;
		system("pause");
		system("cls");
	}

}
//�޸���ϵ��
void modifyPerson(Addressbooks* abs){
	cout << "�����޸ĵ�����" << endl;
	string name;
	cin >> name;
	int xx = isexist(abs, name);
	if (xx == -1) {
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << xx + 1 << " " << "������" << abs->personArr[xx].m_Name << "   ";
		cout << "�Ա�" << (abs->personArr[xx].m_Sex == 1 ? "��" : "Ů") << "   ";
		cout << "���䣺" << abs->personArr[xx].m_Age << "   ";
		cout << "�绰��" << abs->personArr[xx].m_Phone << "   ";
		cout << "סַ��" << abs->personArr[xx].m_Addr << endl;
		cout << "�����µ�����" << endl;
		cin >> name;
		abs->personArr[xx].m_Name = name;

		int sex;
		cout << "�����µ��Ա�" << endl;
		cout << "1----��" << "   " << "2----Ů" << endl;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[xx].m_Sex = sex;
				break;
			}
			cout << "����������" << endl;

		}
		cout << "�����µ�����" << endl;
		int age;
		cin >> age;
		abs->personArr[xx].m_Age = age;
		cout << "�����µĵ绰����" << endl;
		string number;
		cin >> number;
		abs->personArr[xx].m_Phone = number;
		cout << "�����µļ�ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArr[xx].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
		system("pause");
		system("cls");

	}
}
//�����ϵ��
void cleanPerson(Addressbooks* abs) {
	cout << "��ȷ�������ϵ��" << endl;
	cout << "ȷ��---1  ��ȷ��---2" << endl;
	int xx;
	cin >> xx;
	if (xx == 1) {
		abs->m_Size = 0;
		cout << "ͨѶ¼�����" << endl;
		system("pause");
		system("cls");
	}
	else {  
		system("pause");
		system("cls");
	}
}
//��ʾ��Ļ
void showMenu() {
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			system("pause");
			system("cls");
			break;

		}
	}
}