#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> vec;

void Push(std::string parStr)
{
	for (int i = 0; i < parStr.size(); ++i)
	{
		if (parStr[i] >= '0' && parStr[i] <= '9')
		{
			int num = std::stoi(parStr.substr(i));
			parStr = parStr.substr(0, i) + "#" + std::to_string(num + 17);
			break;
		}
	}

	vec.push_back(parStr);
}

void Parsing(std::string& str)
{
	char prev = '@';
	int startIndex = 0, endIndex = 0;
	for (auto c : str)
	{
		bool isNum = (prev >= '0' && prev <= '9');
		bool isWord = (c >= 'A' && c <= 'Z' );
		if (isNum && isWord)
		{
			std::string parStr = str.substr(startIndex, endIndex - startIndex);
			Push(parStr);
			startIndex = endIndex;
		}

		prev = c;
		endIndex++;
	}

	std::string parStr = str.substr(startIndex);
	Push(parStr);
}

int main()
{
	std::string str = "AB100CDEF112F4G5";
	Parsing(str);

	return 0;
}