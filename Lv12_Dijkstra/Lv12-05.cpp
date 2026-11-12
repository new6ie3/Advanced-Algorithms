#include <iostream>
#include <vector>
constexpr int sourage = 1000000000;

class Sours
{
public:
	void AddSour(std::string name, int age)
	{
		bucket[age % sourage] = name;
	}

	void PrintSour(int age)
	{
		std::cout << bucket[age % sourage];
	}

private:
	std::string bucket[100];
};


int main()
{
	Sours sours;
	sours.AddSour("Sour", sourage + 5);
	sours.AddSour("Dav", sourage + 2);
	sours.AddSour("Nica", sourage + 3);
	sours.AddSour("Timer", sourage + 6);
	sours.AddSour("Pico", sourage + 15);
	sours.AddSour("Topisl", sourage + 22);

	sours.PrintSour(sourage + 5);
	return 0;
}