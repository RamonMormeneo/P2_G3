#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
struct Key
{
	std::string key1;
	std::string key2;
};
void main()
{
	std::unordered_map<std::pair<std::string,std::string>, std::string, Key> fusions;
	std::vector<std::string> Linea_Separada;
	std::ifstream ftoread("elements.dat");
	std::string Linea;
	while (std::getline(ftoread, Linea))
	{
		Key key;
		std::size_t posdeligual = Linea.find("=");
		std::string result = Linea.substr(0, posdeligual - 1);
		Linea = Linea.substr(posdeligual + 2);
		std::size_t posdelmas = Linea.find("+");
		key.key1 = Linea.substr(0, posdelmas - 1);
		key.key2 = Linea.substr(posdelmas + 2);
	}
}
