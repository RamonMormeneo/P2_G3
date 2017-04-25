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

	std::vector<std::string> Linea_Separada;
	std::ifstream ftoread();
	std::string Linea="Oceanix = Agua + Infancia";
	Key key;
	std::size_t posdeligual = Linea.find("=");
	std::size_t posdelmas = Linea.find("+");
	std::string result = Linea.substr(0, posdeligual - 1);
	key.key1 = Linea.substr(posdeligual + 2, posdelmas);
	key.key2 = Linea.substr(posdelmas+2);
}
