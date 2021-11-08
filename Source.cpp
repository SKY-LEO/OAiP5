#include <math.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
using namespace std;
int Correct_Input();

int main()
{
	int a[25], i, min, variant, value_of_array, sum, number = 0;
	char code;
	bool flag = 0;
	srand(time(0));
	do
	{
		sum = 0;
		do
		{
			cout << "Please, enter number of elements in array(MAX=25) = ";
			value_of_array = Correct_Input();
		} while (value_of_array < 1 || value_of_array > 25);
		cout << "Do you want to randomise elements? Y/N" << endl;
		code = _getch();
		if (code == 'Y' || code == 'y')
		{
			for (i = 0; i < value_of_array; i++)
			{
				a[i] = rand() - 16384;
				cout << a[i] << setw(10);
			}
		}
		else
		{
			for (i = 0; i < value_of_array; i++)
			{
				cout << "Please, enter number of array " << i + 1 << " = ";
				a[i] = Correct_Input();
			}
		}
		min = a[0];
		do
		{
			cout << "\nTo what value do you want sum?\n";
			cout << "1. Before the first.\n";
			cout << "2. Until the last." << endl;
			variant = Correct_Input();
			switch (variant)
			{
			case 1: for (i = 0; i < value_of_array; i++)
			{
				if (a[i] < min)
				{
					min = a[i];
					number = i;
				}
			}
				  flag = 0;
				  break;
			case 2: for (i = 0; i < value_of_array; i++)
			{
				if (a[i] <= min)
				{
					min = a[i];
					number = i;
				}
			}
				  flag = 0;
				  break;
			default: cout << "Invalid value! Try again!" << endl;
				flag = 1;
			}
		} while (flag == 1);
		if (number == 0)
		{
			cout << "Error! Minimum value in the first place!" << endl;
		}
		else
		{
			for (i = 0; i < number; i++)
			{
				sum += a[i];
			}
			cout << "Min:\n" << min << "\nSum:\n" << sum << endl;
		}
		cout << "Do you want to continue? Y/N" << endl;
		code = _getch();
	} while (code == 'Y' || code == 'y');
	return 0;
}

int Correct_Input()
{
	int a;
	while (true)
	{
		cin >> a;
		if (cin.get() == '\n') {
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please write int numbers!\n" << "Try again!" << endl;
		}
	}
	return a;
}