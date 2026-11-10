#include <iostream>
#include <vector>

std::vector<std::string> vec;

std::string startWord[] =
{
	"http://",
	"https://",
};

std::string endWord[] =
{
	".com",
	".co.kr",
	".org",
	".net"
};

void Parsing(std::string& str)
{
    for (std::string s : startWord)
    {
        int startIndex = 0;

        while (1)
        {
            startIndex = str.find(s, startIndex);

            if (startIndex == -1)
                break;

            for (std::string e : endWord)
            {
                int endIndex = str.find(e, startIndex);

                if (endIndex != -1)
                {
                    int length = endIndex - (startIndex + s.size());

                    if (length >= 3)
                    {
                        std::string parStr = str.substr(startIndex, endIndex - startIndex + e.size());
                        vec.push_back(parStr);
                    }

                    startIndex = endIndex + e.size();
                    break;
                }
            }

            if (startIndex == -1)
                break;
        }
    }
}

int main()
{
	std::string str = "ABhttp://bbq.comhttps://a.co.krBBQhttps://KFC.org";
	Parsing(str);

	std::cout << vec.size();

	return 0;
}