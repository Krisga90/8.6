#include <iostream>
#include <cstdlib>

template<typename T>
T Max(T *a, const int size = 1);
template<>
const char* Max(const char(*a[]), const int size);

template<typename T>
void Show(T *a, const int size = 1);

template<>
void Show(const char(*a[]), const int size);


const int SIZE = 5;

int main()
{
	int im[SIZE] = { 1,2,3,4,5 };
	double dm[7] = { 12.1,12.3,22.2,43.3,4,54.66,1 };
	const char *cm[] = { "dasasd","asdfadsffds","sdf787 sdkh ","asdfkh9938!@#","1sdfkjhasdfjhasdfhj asdfasdasdf asf","asdfkj893hjfbndkj  asdf" };
	Show(im, SIZE);
	Show(im);
	Show(dm, SIZE);
	Show(dm, 7);
	Show(cm, 5);

	std::cin.get();
	return 0;
}




template<typename T>
T Max(T *a, const int size)
{
	T temp = a[0];
	for (int i = 1; i < size; i++)
		temp = temp > a[i] ? temp : a[i];
	return temp;
}

template<>
const char* Max(const char* a[], const int size)
{
	unsigned int rozmiar = std::strlen(a[0]);
	const char * adres = *a;
	for (int i = 1; i < size; i++)
	{

		if (rozmiar < std::strlen(a[i]))
		{
			rozmiar = std::strlen(a[i]);
			adres = a[i];
		}

	}

	return adres;
}


template<typename T>
void Show(T *a, const int size)
{
	std::cout << "najwieksza liczba z liczb:\t";
	for (int i = 0; i < size; i++)
		std::cout << a[i] << '\t';

	std::cout << "\nto: " << Max(a, size) << std::endl << std::endl;
}

template<>
void Show(const char(*a[]), const int size)
{
	std::cout << "Najdluzszy lancuch z lancuchow:\n";
	for (int i = 0; i < size; i++)
		std::cout << i + 1 << ":\t" << a[i] << std::endl;
	std::cout << "to:\t" << Max(a, size) << std::endl;
}