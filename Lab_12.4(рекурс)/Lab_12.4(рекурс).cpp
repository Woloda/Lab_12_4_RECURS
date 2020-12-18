#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link;
	inform inf;
};

int Creata(Spusok*& L, Spusok* T, inform inf, int N, int i);
int COUT(Spusok*& T, Spusok*& L, inform inf);
int Process(Spusok*& L, Spusok*& L1, Spusok*& L2, Spusok*& T, Spusok*& G, inform index);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* L = NULL;
	Spusok* L1 = NULL;
	Spusok* L2 = NULL;
	Spusok* T, * G;

	int x = 0, inf, N = 4, i = 0;
	T = L;
	inf = 6 - rand() % 12;
	Creata(L, T, inf, N, i);

	cout << "Список сформований:" << endl << endl;
	T = L;
	COUT(T, L, inf);

	T = L;
	Process(L, L1, L2, T, G, i);
	cout << "Список з додатніми числами сформований:" << endl << endl;
	T = L1;
	COUT(T, L1, inf);
	cout << "Список з від'ємними числами сформований:" << endl << endl;
	T = L2;
	COUT(T, L2, inf);

	return 0;
}

int Creata(Spusok*& L, Spusok* T, inform inf, int N, int i)
{
	Spusok* tmp = new Spusok;

	if (L != NULL)
		while (T->link != L)
			T = T->link;

	tmp->inf = inf;
	if (L == NULL)
		L = tmp;
	else
		T->link = tmp;
	tmp->link = L;

	if (i < N - 1)
		return Creata(L, L, 6 - rand() % 12, N, i + 1);
	else
		return 0;
}

int COUT(Spusok*& T, Spusok*& L, inform inf)
{
	while (T->link != L)
	{
		inf = T->inf;
		cout << inf << "   ";
		T = T->link;
	}

	if (T->link != L)
		return COUT(T, L, inf);
	else
	{
		inf = T->inf;
		cout << inf << "   ";
		cout << endl << endl;
		return 0;
	}
}

int Process(Spusok*& L, Spusok*& L1, Spusok*& L2, Spusok*& T, Spusok*& G, inform index)
{
	index = T->inf;                             // 1('index' отримує значення від елемента(інформаційного поля))
	T = T->link;                                // 2(перехід вказівника 'T' на наступну позицію(вперед))
	if (index >= 0)
	{
		G = L1;                                 // 3(якщо 'index >= 0' то вказівник 'G' отримує(значення) адресу вказівника 'L1')
		Creata(L1, G, index, 1, 0);             // 4(якщо 'index >= 0' то відбувається створення нового списку(першого) і добавлення певного елемнта)
	}
	else
	{
		G = L2;                                 // 3(інкаше вказівник 'G' отримує(значення) адресу вказівника 'L2')
		Creata(L2, G, index, 1, 0);             // 4(інакше відбуваєтьься створення нового списку(другого) і добавлення певного елемнта)
	}
	if (T->link != L)
		return Process(L, L1, L2, T, G, index);
	else
	{
		index = T->inf;                         //для перевірки останнього елемна
		if (index >= 0)
		{
			G = L1;
			Creata(L1, G, index, 1, 0);
		}
		else
		{
			G = L2;
			Creata(L2, G, index, 1, 0);
		}
		return 0;
	}
}