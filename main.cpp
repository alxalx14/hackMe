#include <iostream>
#include <windows.h>
#include <vector>


#define HP 100
int BASE_HP{ HP };
int HP_DIFFERENCE;
std::string awaitInput; // Defines useless variable just to wait until the console closes
std::vector<int> usedHP(HP);


bool antiCheat()
{
	for(int i{0}; i < usedHP.size(); ++i)
	{
		if (BASE_HP == usedHP[i])
			return false;
	}

	if (HP - HP_DIFFERENCE != BASE_HP || BASE_HP > 100 || BASE_HP < 0)
		return false;

	return true;
}

int main()
{	
	while (BASE_HP <= HP && BASE_HP != 0)
	{
		if (antiCheat())
		{
			usedHP.push_back(BASE_HP);
			--BASE_HP;
			++HP_DIFFERENCE;
		}
		else
		{
			fprintf_s(stdout, "%s", "Anti Cheat triggered!");
			std::cin >> awaitInput; 
			return EXIT_FAILURE;
		}
		
		fprintf_s(stdout, "Current HP: %d\n", BASE_HP);
		Sleep(2000);
	}
	fprintf_s(stdout, "%s\n", "You are dead!");
	std::cin >> awaitInput;
	return EXIT_SUCCESS;
}
