// aproksimatorcc.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Header.h"
#include <stdexcept>
#include <fstream>

using namespace std;

namespace headercc
{
	double count(int j, int k, int N, double w, double K, double m1, double m2, double m3, int mirror, int shag)
	{
		int i = 0, koeff = 0, l = 0;
		double buff1[3], buff = 0;
		const double eps = 0.00001;
		double *massiv = new double[N];
		double *x = new double[3];
		double *y = new double[3];
		double *okno = new double[mirror];
		ifstream fin;
		fin.open("E:\\input.txt"); // открываем файл("input1.txt");//открытие файла для считывания данных
		switch (k)
		{
		case 1://подсчитаем количество строк в файле, чтобы создать нужного объема массив
			char str[100];
			while (!fin.eof())//смотрим сколько строк в нашем файле, чтобы создать нужного размера матрицу
			{
				fin.getline(str, 100);
				N++;
			}
			return N;
		case 2://считаем наш файл
			fin.seekg(0, ios::beg);
			while (!fin.eof())//непосредственная запись в информации в массив
			{
				char str[100];
				fin.getline(str, 100);
				massiv[i] = atof(str);
				i++;
			}
			return massiv[j];
		case 3:
			int index;
			double a[3][3], max;
			//записали в наш массив значения точек которые y
			fin.seekg(0, ios::beg);
			while (!fin.eof())//значения y
			{
				char str[100];
				fin.getline(str, 100);
				massiv[i] = atof(str);
				i++;
			}
			for (i = 0; i < mirror; i++)
				okno[i] = massiv[i+shag];
			//высчитываем коэффициенты матрицы Гаусса до преобразования 
			for (i = 0; i < mirror; i++)
				buff += sin(pow(2, (w * i*0.5)));
			a[0][0] = buff;
			buff = 0;
			for (i = 0; i < mirror; i++)
				buff += sin(w*i*0.5)*cos(w*i*0.5);
			a[0][1] = a[1][0] = buff;
			buff = 0;
			for (i = 0; i < mirror; i++)
				buff += sin(w*i*0.5);
			a[0][2] = a[2][0] = buff;
			buff = 0;
			for (i = 0; i < mirror; i++)
				buff += cos(pow(2, (w * i*0.5)));
			a[1][1] = buff;
			buff = 0;
			for (i = 0; i < mirror; i++)
				buff += cos(w*i*0.5);
			a[1][2] = a[2][1] = buff;
			a[2][2] = 396;
			buff = 0;
			for (i = 0; i < mirror; i++)
				buff += okno[i] * sin(w*i*0.5);
			y[0] = buff;
			buff = 0;
			for (i = 0; i < mirror; i++)
				buff += okno[i] * cos(w*i*0.5);
			y[1] = buff;
			buff = 0;
			for (i = 0; i < mirror; i++)
				buff += okno[i];
			y[2] = buff;
			buff = 0;
			//собственно, само преобразование гаусса
			while (koeff < 3)
			{
				// Поиск строки с максимальным a[i][k]
				max = abs(a[koeff][koeff]);
				index = koeff;
				for (int i = koeff + 1; i < 3; i++)
				{
					if (abs(a[i][koeff]) > max)
					{
						max = abs(a[i][koeff]);
						index = i;
					}
				}
				// Перестановка строк
				if (max < eps)
				{
					// нет ненулевых диагональных элементов
					return 0;
				}
				for (int l = 0; l < 3; l++)
				{
					double temp = a[koeff][l];
					a[koeff][l] = a[index][l];
					a[index][l] = temp;
				}
				double temp = y[koeff];
				y[koeff] = y[index];
				y[index] = temp;
				// Нормализация уравнений
				for (int i = koeff; i < 3; i++)
				{
					double temp = a[i][koeff];
					if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
					for (int l = 0; l < 3; l++)
						a[i][l] = a[i][l] / temp;
					y[i] = y[i] / temp;
					if (i == koeff)  continue; // уравнение не вычитать само из себя
					for (int l = 0; l < 3; l++)
						a[i][l] = a[i][l] - a[koeff][l];
					y[i] = y[i] - y[koeff];
				}
				koeff++;
			}
			// обратная подстановка
			for (koeff = 3 - 1; koeff >= 0; koeff--)
			{
				x[koeff] = y[koeff];
				for (int i = 0; i < koeff; i++)
					y[i] = y[i] - a[i][koeff] * x[koeff];
			}
			return x[j];
		case 4://находим разность между исходной и апроксимированной точкой
			while (!fin.eof())//значения y
			{
				char str[100];
				fin.getline(str, 100);
				massiv[i] = atof(str);
				i++;
			}
			for (i = 0; i < mirror; i++)
				okno[i] = massiv[i+shag];
			double x;
			for (int i = 0; i < mirror; i++)
			{
				x = okno[i] - (m1 * sin(w*i*0.5) + m2 * cos(w*i*0.5 + m3));
				K += pow(2, x);
			}
			return K;
		case 5: //здесь найдем значение частоты, при котором разность координат апроксимированной и исходной функцией будет наименьшей
			double E, wmin = 0;
			if (l == 0)
			{
				wmin = w;
				E = K;
			}
			if (l != 0 && K < E)
			{
				E = K;
				wmin = w;
			}
			return wmin;
		}
		fin.close(); //закрываем файл
	}
}


