#include <iostream>

using namespace std;

int Func_1()
{
	for (int i = 0; i < 10000; i++) {
		cout << "#";
	}

	return 1;
}

int Func_2()
{
	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x <= y; x++) {
			cout << "#";
		}
	}

	return 2;
}

int n;
void abc()
{
	for (int i = 0; i < n; i++) {
		cout << "#";
	}
}


int Func_3()
{
	cin >> n;
	for (int y = 0; y < n; y++) {
		abc();
		abc();
		abc();
	}

	return 2;
}

int Func_4()
{
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 5; x++) {
			for (int z = 0; z < n; z++) {
				cout << "#";
			}
		}
	}

	return 2;
}

int main()
{
	int input;
	cin >> input;

	switch (input)
	{
	case 1:
		Func_1();
		break;

	case 2:
		Func_2();
		break;

	case 3:
		Func_3();
		break;

	case 4:
		Func_4();
		break;
	}

	return 0;
}