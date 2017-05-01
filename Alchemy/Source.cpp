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
	std::unordered_map<std::pair<std::string, std::string>, bool> newitems;
	std::unordered_map<std::pair<std::string, std::string>, std::string> fusions;
	std::vector <std::string> items({ "Water","Fire","Earth","Air" });
	std::vector <std::string> basics({ "Water","Fire","Earth","Air" });
	std::ifstream ftoread("elements.dat");
	std::string Linea;
	std::string toRead;
	std::string separaciones[3];
	bool ayuda = true;
	bool tryagain = false;
	int puntuacion=0;
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
		newitems[key] = true;
	}
	while (puntuacion < 395)
	{
		if (ayuda == true){

			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << "                       FULLENTI ALCHEMY                       " << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
			std::cout << "- Enter the word 'add' and the number of an element to add a new instance of that element." << std::endl;
			std::cout << "- Enter 'add basics' to add new instances of the 4 basic elements." << std::endl;
			std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
			std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
			std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl;
			std::cout << "- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl;
			std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
			
			ayuda = false;
		}

		std::cout << std::endl;
		std::cout << "Puntuacion:" << ' ' << puntuacion << std::endl;
		
		for (int i = 1; i <= items.size(); i++){
			std::cout << i << "-" << ' ' << items[i-1] << std::endl;
		}


		std::cin >> toRead;
		int x = atoi(toRead.c_str());
		if (toRead == "add")
		{
			std::string aux;
			std::cin >> aux;
			int aux2 = atoi(aux.c_str());
			if (aux=="basics")
			{
				int aux = 4;
				for (int i = 0; i < aux; i++)
				{
					items.push_back(basics[i]);
				}
			}
			else if (aux2!=0 && aux2<= items.size())
			{
				items.push_back(items[aux2 - 1]);
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

			for (auto i = items.begin(); i != items.end(); ++i) {
				repes.insert(*i);
			}

			items.clear();

			for (auto i = repes.begin(); i != repes.end(); ++i) {
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

			ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

		}
		else if (toRead == "help")
		{
			ayuda = true;
		}
		else if (x != 0 && x <= items.size())
		{
			std::pair<std::string, std::string> key;
			key.first = items[x - 1];
			system("cls");
			std::cout << "Choose another element" << std::endl;
			int aux;
			std::cin >> aux;
			if (aux == x)
			{
				system("cls");
				std::cout << "This element has been chosen. Choose another one" << std::endl;
				std::cin >> aux;
			}
			key.second = items[aux - 1];
			auto it = newitems[key];
			if (newitems.size() > 390)
			{
				auto erase = newitems.find(key);
				newitems.erase(erase);
				key.first = items[aux - 1];
				key.second = items[x - 1];
				it = newitems[key];
			}
			if (newitems.size() > 390)
			{
				auto erase = newitems.find(key);
				newitems.erase(erase);
				std::cout << "Try Again";
				tryagain = true;
			}
			if (tryagain == false)
			{
				if (aux < x)
				{
					int aux2 = x;
					x = aux;
					aux = aux2;
				}
				if (it == true)
				{
					newitems[key] = false;
					puntuacion++;
					items.erase(items.begin() + (x - 1));
					items.erase(items.begin() + (aux-2));
					items.push_back(fusions[key]);
				}
				if (it == false)
				{
					items.erase(items.begin() + (x - 1));
					items.erase(items.begin() + (aux-2));
					items.push_back(fusions[key]);
				}
			}
			tryagain = false;
		}
		system("cls");
	}
}
