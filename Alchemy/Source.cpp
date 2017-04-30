#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
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
	std::vector <std::string> items({ "Agua","Fuego","Tierra","Aire" });
	std::vector <std::string> basics({ "Agua","Fuego","Tierra","Aire" });
	std::ifstream ftoread("elements.dat");
	std::string Linea;
	std::string toRead;
	std::string separaciones[3];
	bool actions = true;
	int item;
	int inicio = 0;

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
			items.push_back(items[aux - 1]);
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
			items.erase(items.begin() + (aux - 1));
		}
		else if (toRead == "clear")
		{




		}
		else if (toRead == "sort")
		{
			std::sort(items.begin(), items.end());
		}
		else if (toRead == "info")
		{

		}
		else if (toRead == "help")
		{
			actions = true;

		}
		else if (x == 0 && toRead != "0")
		{
			std::cout << "funciona";
		}
		else
		{

		}


}
