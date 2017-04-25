#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>
struct Key
{
	std::string key1;
	std::string key2;
};

std::vector<std::string> separar(const std::string& str)
{
	std::vector<std::string> resultado;

	std::string::const_iterator itBegin = str.begin();
	std::string::const_iterator itEnd = str.end();

	int numItems = 1;
	for (std::string::const_iterator it = itBegin; it != itEnd; ++it)
		numItems += *it == ' ';

	resultado.reserve(numItems);

	for (std::string::const_iterator it = itBegin; it != itEnd; ++it)
	{
		if (*it == ' ')
		{
			resultado.push_back(std::string(itBegin, it));
			itBegin = it + 1;
		}
	}

	if (itBegin != itEnd)
		resultado.push_back(std::string(itBegin, itEnd));

	return resultado;
}
void main()
{
	std::vector<std::string> Linea_Separada;
	std::string Linea= "Ola que tal buenas tardes";
	Linea_Separada = separar(Linea);
	std::cout << Linea_Separada[1];
}
