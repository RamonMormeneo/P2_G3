#include <iostream>
#include <unordered_map>
#include <fstream>
#include "Functions.h"
#include <string>
struct Key
{
	std::string key1;
	std::string key2;
};
void main()
{
	const int aux1 = 0;
	const int aux2 = 2;
	const int aux3 = 4;
	std::vector<std::string> Linea_Separada;
	std::ifstream ftoread("elements.dat");
	std::string Linea;
	Linea_Separada = separar(Linea);
	std::cout << Linea_Separada[1];
	ftoread.close;
}
