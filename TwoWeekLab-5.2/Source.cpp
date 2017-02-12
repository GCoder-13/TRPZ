#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ITINERARY
{
	string FIRST;			//Ц назва початкового пункту маршруту;
	string FINAL;			//Ц назва к≥нцевого пункту маршруту;
	unsigned int NUM;		//Ц номер маршруту.
	double DISTANCE;		//- в≥дстань у к≥лометрах.
};

int main()
{
	fstream database;
	database.open("database.txt", ios_base::in | ios_base::out | ios_base::binary);

	
	database.close();
	system("pause");
	return NULL;
}