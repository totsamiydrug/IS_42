#include <iostream>
#include <cmath>
#include <iomanip>

double task(double* arr, int n, int c)
{
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		if (c > arr[i])
		{
			k++;
		}
	}

	return k;

}

double checkelem(int n)
{
	double elem;

	std::cout << "Type element: ";

	while (true)
	{
		try
		{
			if (!(std::cin >> elem))
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "element is non digit!";
			}
			else
				break;
		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new element: ";
		}
	}
	return elem;
}


int sizecheckerN(int n)
{
	while (true)
	{
		try
		{
			if (!(std::cin >> n)) // проверка на букву или спец.символы
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "Size is non digit!";
			}
			else
				if (n <= 0 || n > 10)
					throw "Size is out of range!";
				else
					break;

		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new size: ";
		}
	}
	return n;
}



int main()
{
	int n = 0;

	int c;

	double t;

	std::cout << "C:";

	std::cin >> c;

	std::cout << "Type size of the array: ";

	n = sizecheckerN(n);

	double* arr = new double[n];

	std::cout << "Type elements of the array: \n";

	for (int i = 0; i < n; i++)
		arr[i] = checkelem(n);

	t = task(arr, n, c);

	std::cout << "K: " << t;

	delete[] arr;

	return 0;
}