#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, int> spys;

void FindSpy(std::string name, int age)
{
	if (!spys.count(name))
	{
		spys[name] = age;
		return;
	}

	std::cout << name << std::endl;
	std::cout << spys[name] << ' ' << age;
}

int main()
{
	FindSpy("Jason", 32);
	FindSpy("Tom", 22);
	FindSpy("Pom", 26);
	FindSpy("Samson", 46);
	FindSpy("Tim", 26);
	FindSpy("Bam", 51);
	FindSpy("Tom", 43);

	return 0;
}