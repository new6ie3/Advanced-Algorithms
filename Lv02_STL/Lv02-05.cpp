#include <iostream>
#include <vector>

using namespace std;

vector<string> vec;

bool Compare(const string& str1, const string& str2)
{
	if (str1.length() != str2.length())
		return str1.length() < str2.length();

	return str1 < str2;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		vec.push_back(name);
	}

	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = 0; j < vec.size() - 1 - i; ++j)
		{
			if (!Compare(vec[j], vec[j + 1]))
			{
				string temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}

	for (auto& p : vec)
	{
		cout << p << endl;
	}
	

	return 0;
}