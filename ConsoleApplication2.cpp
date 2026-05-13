#include <iostream>
using namespace std;



void first_case();
void second_case();
void third_case();
void fourth_case();
void fifth_case();
void sixth_case();
void seventh_case();
void eighth_case();
void ninth_case();
void tenth_case();
void eleventh_case();






int main() {
	char input;
	while (true) {

		cout << "MENU: " << endl
			<< "1: information about channels" << endl
			<< "2: information about shows" << endl
			<< "3: adding information about channels" << endl
			<< "4: adding information about shows" << endl
			<< "5: delete information about channels" << endl
			<< "6: delete information about shows" << endl
			<< "7: editing information about channels" << endl
			<< "8: editing information about shows" << endl
			<< "9: file with info about enum shows" << endl
			<< "0: information about the shortest, longest shows, avg. time shows" << endl
			<< "q: for schedule" << endl
			<< "c: for exit" << endl;

		cin >> input;
		cin.ignore(); // очистит буфер от лишнего энтера


		switch (input) {
		case '1': first_case(); break;
		case '2': second_case(); break;
		case '3': third_case(); break;
		case '4': fourth_case(); break;
		case '5': fifth_case(); break;
		case '6': sixth_case(); break;
		case '7': seventh_case(); break;
		case '8': eighth_case(); break;
		case '9': ninth_case(); break;
		case '0':tenth_case(); break;
		case 'q': eleventh_case(); break;//Отображение списка телепередач на экране в порядке трансляции на указанном канале.
		case 'c': return 0;
		}


		cout << endl << endl << endl << endl;
	}
	return 0;
}