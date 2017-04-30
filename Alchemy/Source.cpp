#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <windows.h>

template<>
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> &c) const
	{

		return((std::hash<std::string>()(c.first)
			^ (std::hash <std::string> ()(c.second) << 1)) >> 1);
	}
};
void main()
{
	std::unordered_map<std::pair<std::string, std::string>, std::string> fusions;
	std::vector <std::string> items({ "Water","Fire","Earth","Wind" });
	std::vector <std::string> basics({ "Water","Fire","Earth","Wind" });
	std::ifstream ftoread("elements.dat");
	std::string Linea;
	std::string toRead;
	std::string separaciones[3];
	bool actions = true;
	int item;
	int inicio = 0;
	std::string wiki = "https://en.wikipedia.org/wiki/";

	while (std::getline(ftoread, Linea))
	{
		std::pair <std::string, std::string> key;
		std::size_t posdeligual = Linea.find("=");
		std::string result = Linea.substr(inicio, posdeligual - 1);
		Linea = Linea.substr(posdeligual + 2);
		std::size_t posdelmas = Linea.find("+");
		key.first = Linea.substr(inicio, posdelmas - 1);
		key.second = Linea.substr(posdelmas + 2);
		fusions[key] = result;
	}

		std::cin >> toRead;
		int x = atoi(toRead.c_str());
		if (toRead == "add")
		{
			int aux;
			std::cin >> aux;
			if (aux < items.size())
			{
				items.push_back(items[aux - 1]);
			}
		}
		else if (toRead == "add basics")
		{
			int aux = 4;
			for (int i = 0; i < aux; i++)
			{
				items.push_back(basics[i]);
			}
		}
		else if (toRead == "delete")
		{
			int aux;
			std::cin >> aux;
			if (aux < items.size())
			{
				items.erase(items.begin() + (aux - 1));
			}
		}
		else if (toRead == "clean")
		{
			std::set <std::string> repes;

			for (auto i = items.begin(); i != items.end(); ++i){
				repes.insert(*i);
			}

			items.clear();

			for (auto i = repes.begin(); i != repes.end(); ++i){
				items.push_back(*i);
			}
		}
		else if (toRead == "sort")
		{
			std::sort(items.begin(), items.end());
		}
		else if (toRead == "info")
		{

			int aux;
			std::cin >> aux;

			std::string url;

			url.operator+= (wiki);
			url.operator+= (items[aux - 1]);

			ShellExecuteA(nullptr, "open", url.c_str() , nullptr, nullptr, SW_SHOWNORMAL);

		}
		else if (toRead == "help")
		{
			std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
			std::cout << "- Enter the word 'add' and the number of an element to add a new instance of that element." << std::endl;
			std::cout << "- Enter 'add basics' to add new instances of the 4 basic elements." << std::endl;
			std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
			std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
			std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl;
			std::cout << "- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl;
			std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
		}
		else if ((x != 0 || toRead == "0")&& x<items.size())
		{
			std::pair<std::string, std::string> key;
		}


}
