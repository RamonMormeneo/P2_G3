#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
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
	std::ifstream ftoread("elements.dat");
	std::string Linea;
	while (std::getline(ftoread, Linea))
	{
		std::pair <std::string,std::string> key;
		std::size_t posdeligual = Linea.find("=");
		std::string result = Linea.substr(0, posdeligual - 1);
		Linea = Linea.substr(posdeligual + 2);
		std::size_t posdelmas = Linea.find("+");
		key.first = Linea.substr(0, posdelmas - 1);
		key.second = Linea.substr(posdelmas + 2);
		fusions[key] = result;
	}
	std::vector <std::string> items({ "Agua","Fuego","Tierra","Aire" });
	std::cout << items[0];
}
