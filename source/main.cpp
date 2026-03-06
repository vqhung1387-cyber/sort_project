#include "count_comparison.h"
#include "command.h"
#include "sort_runtime.h"


using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 5)
	{
		if (string(argv[1]) == "-c")
		{
			do_command_4(argc, argv);
		}
		else if (string(argv[1]) == "-a")
		{
			char* temp = argv[3];

			while (*temp != '\0' && *temp != '.')
			{
				temp += 1;
			}
			if (*temp == '.')
			{
				do_command_1(argc, argv);
			}
			else
			{
				do_command_3(argc, argv);
			}
		}
	}
	else if (argc == 6)
	{
		if (string(argv[1]) == "-a")
		{
			do_command_2(argc, argv);
		}
		else if (string(argv[1]) == "-c")
		{
			do_command_5(argc, argv);
		}
	}

    return 0;
}
