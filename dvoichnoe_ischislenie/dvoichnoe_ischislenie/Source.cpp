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
		cout << "Введите 1, чтобы первести десятичное число, в доичное, введите  2, чтобы перевести двоичное число в десятичное" << endl << "Чтобы произвести циклический сдвиг числа нвведите 3, чтобы узнать, является ли заданное число степенью двойки введите 4" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "Введите десятичное число: ";
			cin >> value;
			des_v_dva(value);
			break;
		case 2:
			cout << "Введите двоичное число: ";
			cin >> bin;
			dva_v_des(bin);
			break;
		case 3:
			cout << "Введите двоичное число: ";
			cin >> bin;
			cycl_sdvig(bin);
			break;
		case 4:
			cout << "Введите десятичное число: ";
			cin >> value;
			stepen(value);
		}
		system("pause >> void");
	}
