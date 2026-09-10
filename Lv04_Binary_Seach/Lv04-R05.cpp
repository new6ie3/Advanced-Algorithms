#include <iostream>

std::string ban_message[5] =
{
	"Chicken",
	"Pizza",
	"Jockbal",
	"Bread",
	"Samhap",
};
std::string message = "HeyBread!DoYouWannaBuildAChicken";

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		size_t idx = message.find(ban_message[i]);
		for (int j = idx; j < idx + ban_message[i].length(); ++j)
		{
			if (j < idx + 3)
				message[j] = '#';
			else
				message[j] = 0;
		}
	}


	std::cout << message;
	return 0;
}