#include <iostream>
#include <string>
#include <bitset>
using namespace std;

void des_v_dva(int a)
{
	int i; 
	bitset<32> svalue(a);
	cout << svalue << endl;
}
void dva_v_des(string bin)
{
	cout << bitset<32>(bin).to_ulong() << endl;
}

void cycl_sdvig(string as)
{
	const int kol1 = as.size();
	bitset<8> svalue(as);
	svalue = (svalue >> 1) | (svalue << (8 - 1));
	cout << svalue;
}

void stepen(int a)
{
	bool res = (a&(a - 1));
	if (res == false)
		cout << "true";
	else
		cout << "false";
}
	
	int main()
	{
		int i;
		string bin;
		int value;
		char svalue[255];
		setlocale(LC_ALL, "Russian");
		cout << "������� 1, ����� �������� ���������� �����, � �������, �������  2, ����� ��������� �������� ����� � ����������" << endl << "����� ���������� ����������� ����� ����� �������� 3, ����� ������, �������� �� �������� ����� �������� ������ ������� 4" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "������� ���������� �����: ";
			cin >> value;
			des_v_dva(value);
			break;
		case 2:
			cout << "������� �������� �����: ";
			cin >> bin;
			dva_v_des(bin);
			break;
		case 3:
			cout << "������� �������� �����: ";
			cin >> bin;
			cycl_sdvig(bin);
			break;
		case 4:
			cout << "������� ���������� �����: ";
			cin >> value;
			stepen(value);
		}
		system("pause >> void");
	}
