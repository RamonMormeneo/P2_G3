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
	// mapa para saber si la combinacion esta echa o no
	std::unordered_map<std::pair<std::string, std::string>, bool> newitems;
	// mapa para guardar las combinaciones
	std::unordered_map<std::pair<std::string, std::string>, std::string> fusions;
	//Los elementos que dispone el jugador
	std::vector <std::string> items({ "Water","Fire","Earth","Air" });
	//Los elementos base
	std::vector <std::string> basics({ "Water","Fire","Earth","Air" });
	std::ifstream ftoread("elements.dat");
	std::string Linea;
	std::string toRead;
	bool discobernewitem = false, createknownitem = false, ayuda = true, tryagain = false;
	int puntuacion=0;
	int item;
	int inicio = 0;
	std::string wiki = "https://en.wikipedia.org/wiki/";
	// Llenar los mapas
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
	// Si no se crea correctamente
	if (fusions.size() != 390)
	{
		system("pause");
	}
	while (puntuacion < 395)
	{
		//imprimir los comandos
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
		//Combinacion fallida
		if (tryagain == true)
		{
			tryagain = false;
			std::cout << "Combination failure" << std::endl;
		}
		//Si se descubre una fusion
		if (discobernewitem == true)
		{
			std::cout << "Congratulations! You have unlocked " << items[items.size()-1] << std::endl;
			discobernewitem = false;
		}
		//Si la fusion ya habia sido descubierta
		if (createknownitem == true)
		{
			std::cout << "You have unlocked " << items[items.size() - 1] << std::endl;
			createknownitem = false;
		}
		std::cout << std::endl;
		std::cout << "Puntuacion:" << ' ' << puntuacion << std::endl;
		// Imprimir los elementos que puede usar el jugador
		for (int i = 1; i <= items.size(); i++){
			std::cout << i << "-" << ' ' << items[i-1] << std::endl;
		}


		std::cin >> toRead;
		int x = atoi(toRead.c_str());
		//añadir un elemento
		if (toRead == "add")
		{
			std::string aux;
			std::cin >> aux;
			int aux2 = atoi(aux.c_str());
			//añadir los elementos base
			if (aux=="basics")
			{
				int aux = 4;
				for (int i = 0; i < aux; i++)
				{
					items.push_back(basics[i]);
				}
			}
			//añadir un elemento en concreto, si combiertes una frase a int su valor sera 0
			else if (aux2!=0 && aux2<= items.size())
			{
				items.push_back(items[aux2 - 1]);
			}

		}
		//eliminar en concreto
		else if (toRead == "delete")
		{
			int aux;
			std::cin >> aux;
			if (aux < items.size())
			{
				items.erase(items.begin() + (aux - 1));
			}
		}
		// eliminar repetidos
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
		//ordenar
		else if (toRead == "sort")
		{
			std::sort(items.begin(), items.end());
		}
		// informacion sobre los elementos
		else if (toRead == "info")
		{

			int aux;
			std::cin >> aux;

			std::string url;

			url.operator+= (wiki);
			url.operator+= (items[aux - 1]);

			ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

		}
		//si se tiene que imprimir el menu con los comandos
		else if (toRead == "help")
		{
			ayuda = true;
		}
		// fusion de elementos
		else if (x != 0 && x <= items.size())
		{
			std::pair<std::string, std::string> key;
			key.first = items[x - 1];
			system("cls");
			std::cout << "Choose another element" << std::endl;
			int aux;
			std::cin >> aux;
			//No se puede elgir el mismo elemento
			while(aux == x)
			{
				system("cls");
				std::cout << "This element has been chosen. Choose another one" << std::endl;
				std::cin >> aux;
			}
			key.second = items[aux - 1];
			auto it = newitems[key];
			//comprovar que no se ha generado un nuevo elemento en el mapa de fusiones
			// si es el caso significa que la key esta mal introducidad y entra en el bucle
			if (newitems.size() > 390)
			{
				//borrar el elemento creado
				auto erase = newitems.find(key);
				newitems.erase(erase);
				//cambiar la primera key por la segunda y viceversa
				key.first = items[aux - 1];
				key.second = items[x - 1];
				it = newitems[key];
			}
			//Si se ha vuelto a generar un nuevo elemento significa que esa combinacion no existe
			if (newitems.size() > 390)
			{
				auto erase = newitems.find(key);
				newitems.erase(erase);
	
				tryagain = true;
			}
			// Si la combinacion es correcta o no
			if (tryagain == false)
			{
				//Si el segundo es mas grande que el primero se cambian
				if (aux < x)
				{
					int aux2 = x;
					x = aux;
					aux = aux2;
				}
				//en el caso que no se haya echo esta combinacion
				if (it == true)
				{
					newitems[key] = false;
					puntuacion++;
					items.erase(items.begin() + (x - 1));
					items.erase(items.begin() + (aux-2));
					items.push_back(fusions[key]);
					discobernewitem = true;
				}
				//si esa combinacion se havia echo anteriormente
				if (it == false)
				{
					items.erase(items.begin() + (x - 1));
					items.erase(items.begin() + (aux-2));
					items.push_back(fusions[key]);
					createknownitem = true;
				}
			}
		}
		system("cls");
	}
}
