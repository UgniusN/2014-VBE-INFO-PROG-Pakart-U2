#include <fcntl.h>
#include <io.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
//--------------------------------
struct Robotas {
	int k;
	int ejimusk;
	int sekossk[30];
	int x;
	int y;
	string rezultatas;
};
//--------------------------------
void Skaitymas(int& x0, int& y0, int& x1, int& y1, int& n, Robotas A[]);
void Vaziavimas(int& x0, int& y0, int& x1, int& y1, int& n, Robotas A[]);
void Spausdinimas(Robotas A[], int& n);
int main()
{
	setlocale(LC_ALL, "Lithuanian");
	//-------------------------------------------------
	int x0, y0; // pradines koordinates
	int x1, y1; // galo koordinates
	int n; // komandu seku skaicius
	//int k; // s e k o s   i l g i s
	Robotas ejimai[20];
	Skaitymas(x0, y0, x1, y1, n, ejimai);
	Vaziavimas(x0, y0, x1, y1, n, ejimai);
	Spausdinimas(ejimai, n);
	return 0;
}
//--------------------------------
void Skaitymas(int& x0, int& y0, int& x1, int& y1, int& n, Robotas A[])
{
	ifstream fd("duomenys.txt");
	fd >> x0 >> y0;
	fd >> x1 >> y1;
	fd >> n;
	for (int i = 1; i <= n; i++)
	{
		fd >> A[i].k;
		for (int j = 1; j <= A[i].k; j++)
		{
			fd >> A[i].sekossk[j];
		}
	}
}
//--------------------------------
void Vaziavimas(int& x0, int& y0, int& x1, int& y1, int& n, Robotas A[])
{
	for (int i = 1; i <= n; i++)
	{
		A[i].ejimusk = 0;
		A[i].x = x0;
		A[i].y = y0;
		cout << A[i].k << endl;
		while (A[i].x != x1 && A[i].y != x1 && A[i].ejimusk != A[i].k)
		{
			A[i].ejimusk++;
			cout << "Ejimas: " << A[i].ejimusk << endl;
			if (A[i].sekossk[A[i].ejimusk] == 1)
			{
				A[i].y += 1;
				cout << "Paeinama y asimi ir dabar koordinates: " << A[i].x << " " << A[i].y << endl;
			}
			if (A[i].sekossk[A[i].ejimusk] == 2)
			{
				A[i].x += 1;
				cout << "Paeinama x ir dabar koordinates: " << A[i].x << " " << A[i].y << endl;;
			}
			if (A[i].sekossk[A[i].ejimusk] == 3)
			{
				A[i].y += -1;
				cout << "Paeinama -y ir dabar koordinates: " << A[i].x << " " << A[i].y << endl;
			}
			if (A[i].sekossk[A[i].ejimusk] == 4)
			{
				A[i].x += -1;
				cout << "Paeinama -x ir dabar koordinates: " << A[i].x << " " << A[i].y << endl;
			}
		}
		if (A[i].x == x1 && A[i].y == y1)
			A[i].rezultatas = "pasiektas tikslas ";
		else
			A[i].rezultatas = "sekos pabaiga ";
	}
}
//--------------------------------
void Spausdinimas(Robotas A[], int& n)
{
	ofstream fr("rezultatai.txt");
	for (int i = 1; i <= n; i++)
	{
		fr << A[i].rezultatas << " ";
		for (int j = 1; j <= A[i].ejimusk; j++)
		{
			fr << A[i].sekossk[j] << " ";
		}
		fr << A[i].ejimusk << endl;
	}
		
}
