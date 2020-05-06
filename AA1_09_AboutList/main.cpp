#include <iostream>
#include <list>

#pragma region funciones
//SuperMerge devuelve: list<int> / une 2 list<int> ordenandolas de mayor a menor
std::list<int> SuperMerge(std::list<int> l1, std::list<int> l2)
{
	int totalSize = l1.size() + l2.size();
	std::list<int>::iterator l1it = l1.begin();
	std::list<int>::iterator l2it = l2.begin();
	std::list<int> retList;
	for (int i = 0; i < totalSize; )
	{
		if (l1it != l1.end())
		{
			if (l2it == l2.end())
			{
				retList.push_back(*l1it);
				l1it++;
				i++;
			}
			else if (*l1it > *l2it)
			{
				retList.push_back(*l1it);
				l1it++;
				i++;
			}
		}
		if (l2it != l2.end())
		{
			if (l1it == l1.end())
			{
				retList.push_back(*l2it);
				l2it++;
				i++;
			}
			else if (*l1it < *l2it)
			{
				retList.push_back(*l2it);
				l2it++;
				i++;
			}
		}
	}
	return retList;
}

//PrintReverse printa en orden inverso
void PrintReverse(std::list<int> l1)
{
	for (std::list<int>::reverse_iterator it = l1.rbegin(); it != l1.rend(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

//IsBalanced bool type recive list<char> devuelve true mientras se cierran los parentesi
bool IsBalanced(std::list<char> l1)
{
	int controlVar = 0;
	for (std::list<char>::iterator it = l1.begin(); it != l1.end(); ++it)
	{
		if (*it == '(') { controlVar++; }
		if (*it == ')') { controlVar--; }
		if (controlVar < 0) { return false; }
	}
	return true;
}

//sobrecarga operador << para list<int>
std::ostream& operator<< (std::ostream& os, const std::list<int>& l1)
{
	int aux = 0;
	for (std::list<int>::const_iterator it = l1.cbegin(); it != l1.cend(); ++it, aux++)
	{
		std::cout << "Value num." << aux << ": " << *it << std::endl;
	}
	return os;
}
#pragma endregion

int main()
{
	//List prueba supermerge + printReverse
	std::list<int> list1{ 30,25,20,10 };
	std::list<int> list2{ 28,22,6,1 };
	
	//List isBalanced
	std::list<char> listC{ '(','(' ,'(' ,')','(' ,')',')' ,')' ,'(',')' };

	std::cout << "Sobrecarga operador<< en list1: " << std::endl << list1 << std::endl << "PrintReverse list1: " << std::endl;
	PrintReverse(list1);

	if (IsBalanced(listC)) 
	{
		std::cout << "IsBalanced Funciona" << std::endl;
	}
	std::list<int> listSupermerge = SuperMerge(list1, list2);

	std::cout << "Supermerge list1+list2: " << listSupermerge << std::endl;

	system("pause");
}
