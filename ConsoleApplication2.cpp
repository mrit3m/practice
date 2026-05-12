#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <vector>
#include <iomanip>

using namespace std;


struct emisiuni {
	string name;
	string type;
	string code;
	string beginning_time;
	string ending_time;

};
struct Program {
	string name;
	string begin_time;
	string end_time;
	int start_in_minutes; //для последней функции
	int duration;
};


vector <string> for_del;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void first_case()
{
	int counter = 0;
	string in;
	vector<string> data;
	ifstream despre_canale("channel.txt");

	while (getline(despre_canale, in))
		data.push_back(in);
	despre_canale.close();

	cout << left << setw(15) << "Code" << setw(25) << "Name" << setw(20) << "Type" << endl;
	cout << string(75, '-') << endl;

	for (int i = 0; i + 2 < data.size(); i += 3) {
		cout << left << setw(15) << data[i]
			<< setw(25) << data[i + 1]
			<< setw(20) << data[i + 2] << endl;
	}
	cout << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void second_case()
{
	int counter = 0;
	string in;
	vector<string> data;
	ifstream despre_emisiuni("Telecast.txt");

	while (getline(despre_emisiuni, in))
		data.push_back(in);
	despre_emisiuni.close();

	cout << left << setw(30) << "Name" << setw(20) << "Type"
		<< setw(20) << "Code" << setw(20) << "Begin" << setw(20) << "End" << endl;
	cout << string(100, '-') << endl;

	for (int i = 0; i + 4 < data.size(); i += 5) {
		cout << left << setw(30) << data[i]
			<< setw(20) << data[i + 1]
			<< setw(20) << data[i + 2]
			<< setw(20) << data[i + 3]
			<< setw(20) << data[i + 4] << endl;
	}
	cout << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void third_case()
{
	string in, code, name, type;
	int counter = 0;

	cout << "what you want to add? " << endl;

	cout << "code of channel: ";
	cin >> code;
	cout << "name of channel: ";
	cin >> name;
	cout << "type of channel: ";
	cin >> type;

	ifstream cheking_canale("channel.txt");
	while (cheking_canale >> in) {
		if (in == code || in == name) {
			cout << "you already have channel like this";
			cheking_canale.close();
			return;
		}
	}
	cheking_canale.close();

	ofstream despre_canale("channel.txt", ios::app);
	despre_canale << code << endl;
	despre_canale << name << endl;
	despre_canale << type << endl;
	despre_canale.close();
	cout << "Channel added successfully" << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fourth_case()
{
	string name, type, code, begin, end, searching;
	int counter = 0;

	cout << "what you want to add? " << endl;
	cout << "name of show: ";
	getline(cin, name);
	cout << "type of show: ";
	getline(cin, type);
	cout << "code of channel: ";
	getline(cin, code);
	cout << "begin time of show: ";
	getline(cin, begin);
	cout << "end time of show: ";
	getline(cin, end);
	ifstream cheking_canale("channel.txt");
	while (getline(cheking_canale,searching)) {
		if (searching == code) counter++;
		
	}
	cheking_canale.close();

	if (counter == 0) {
		cout << "you cant add new show without channel";
		return;
	}
	counter = 0;
	ifstream cheking_emisiuni("Telecast.txt");
	while (getline(cheking_emisiuni, searching)) {
		if (searching == name) counter++;

	}

	if (counter != 0) {
		cout << "you cant add it";
		return;
	}

	ofstream despre_emisiuni("Telecast.txt", ios::app);
	despre_emisiuni << name << endl;
	despre_emisiuni << type << endl;
	despre_emisiuni << code << endl;
	despre_emisiuni << begin << endl;
	despre_emisiuni << end << endl;
	despre_emisiuni.close();
	cout << "show added successfully" << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fifth_case() {
	int counter = 0, position = 0;
	string name, in, code;
	cout << "what you want to delete?" << endl;
	cout << "name of channel: ";
	getline(cin, name);

	ifstream despre_canale("channel.txt");
	while (getline(despre_canale, in))
	{
		for_del.push_back(in);
		counter++;
		if (in == name) position = counter;
	}
	despre_canale.close();

	if (position == 0) { cout << "something was wrong..."; for_del.clear(); return; }

	code = for_del[position - 2];
	for_del.erase(for_del.begin() + (position - 2), for_del.begin() + (position + 1));

	ofstream rewrite("channel.txt", ios::trunc);
	for (int i = 0; i < for_del.size(); i++) {
		rewrite << for_del[i] << endl;
	}
	rewrite.close();
	for_del.clear();

	ifstream edit("Telecast.txt");
	while (getline(edit, in)) {
		for_del.push_back(in);
	}
	edit.close();

	for (int i = (int)for_del.size() - 5; i >= 0; i -= 5) {
		if (for_del[i + 2] == code) {
			for_del.erase(for_del.begin() + i, for_del.begin() + i + 5);
		}
	}

	ofstream rewrite_t("Telecast.txt", ios::trunc);
	for (int i = 0; i < for_del.size(); i++) {
		rewrite_t << for_del[i] << endl;
	}
	rewrite_t.close();
	for_del.clear();
	cout << "Deletion complete!" << endl;
}

void sixth_case() {
	string name, in;
	int counter = 0, pos = 0;
	cout << "what you want to delete?" << endl << "Name of show: ";
	getline(cin, name);
	fstream despre_emisiuni("Telecast.txt");
	while (getline(despre_emisiuni, in)) {
		counter++;
		for_del.push_back(in);
		if (in == name) pos = counter;
	}
	despre_emisiuni.close();

	if (pos == 0) { cout << "something was wrong..."; for_del.clear(); return;}

	for_del.erase(for_del.begin() + pos - 1, for_del.begin() + pos + 4);

	ofstream edit("Telecast.txt", ios::trunc);
	for (int i = 0; i < for_del.size(); i++)
	{
		edit << for_del[i] << endl;
	}
	cout << "delition complited";
	for_del.clear();
	edit.close();
}

void seventh_case() {
	char input;
	string in, code, new_code, name, new_name, type, new_type;
	int counter = 0, pos = 0;
	cout << "what you want to edit?" << endl
		<< "1: information about code" << endl
		<< "2: information about name" << endl
		<< "3: information about type" << endl;
	cin >> input;





	switch (input) {
	case '1': {
		fstream despre_canale("channel.txt");
		cout << "what code you want to edit?" << endl << "Code: ";
		cin >> code;

		cout << endl << "new code: ";
		cin >> new_code;
		while (getline(despre_canale, in)) {
			counter++;
			for_del.push_back(in);
			if (in == code) pos = counter;
		}
		if (pos == 0) { cout << "something was wrong..."; for_del.clear(); return; }
		for_del[pos - 1] = new_code;
		ofstream edit("channel.txt", ios::trunc);

		for (int i = 0; i < for_del.size(); i++) {
			edit << for_del[i] << endl;
		}
		for_del.clear();
		pos = 0;
		counter = 0;

		fstream despre_emisiuni("Telecast.txt");
		while (getline(despre_emisiuni, in)) {
			counter++;
			for_del.push_back(in);
			if (in == code) pos = counter;
		}
		if (pos == 0) { cout << "something was wrong..."; for_del.clear(); return; }

		for_del[pos - 1] = new_code;
		ofstream edit_t("Telecast.txt", ios::trunc);
		for (int i = 0; i < for_del.size(); i++) {
			edit_t << for_del[i] << endl;
		}

		edit_t.close();
		for_del.clear();
		despre_emisiuni.close();
		edit.close();
		despre_canale.close();
		cout << "updated successfully!" << endl;
	}; break;
	case '2': {
		fstream despre_canale("channel.txt");
		cout << "what name you want to edit?" << endl << "name: ";
		cin >> name;

		cout << endl << "new name: ";
		cin >> new_name;
		while (getline(despre_canale, in)) {
			counter++;
			for_del.push_back(in);
			if (in == name) pos = counter;
		}
		if (pos == 0) { cout << "something was wrong..."; for_del.clear(); return; }
		for_del[pos - 1] = new_name;
		ofstream edit("channel.txt", ios::trunc);

		for (int i = 0; i < for_del.size(); i++) {
			edit << for_del[i] << endl;
		}




		for_del.clear();

		edit.close();
		despre_canale.close();
		cout << "updated successfully!" << endl;

	}; break;
	case '3': {
		fstream despre_canale("channel.txt");
		cout << "what type you want to edit?" << endl << "name of channel: ";
		cin >> name;
		cin.ignore(); // очистка буфера

		cout << "new type: ";
		cin >> new_type;
		cin.ignore();

		while (getline(despre_canale, in)) {
			counter++;
			for_del.push_back(in);
			if (in == name) pos = counter;
		}
		despre_canale.close();

		if (pos == 0) { cout << "something was wrong..."; for_del.clear(); return; }

		// проверка что pos+1 не выходит за границы
		if (pos + 1 > (int)for_del.size()) {
			cout << "something was wrong...";
			for_del.clear();
			return;
		}

		for_del[pos] = new_type; // pos это 1-based индекс типа (строка после имени)
		ofstream edit("channel.txt", ios::trunc);

		for (int i = 0; i < for_del.size(); i++) {
			edit << for_del[i] << endl;
		}

		for_del.clear();
		edit.close();
		cout << "updated successfully!" << endl;
	}
	} /////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void eighth_case() {
	string name, new_name, in, new_type, code, new_code, new_begin, new_end;
	int counter = 0, pos = -1;
	cout << "what you want to edit?" << endl
		<< "1: information about name of show" << endl
		<< "2: information about type of show" << endl
		<< "3: information about code of show" << endl
		<< "4: information about begining show" << endl
		<< "5: information about ending show" << endl;
	char input; cin >> input; cin.ignore();

	switch (input) {
	case '1': {
		fstream despre_emisiuni("Telecast.txt");
		cout << "what show you wanna edit?" << endl << "name: " << endl;
		getline(cin, name);
		cout << "new name: ";
		getline(cin, new_name);
		while (getline(despre_emisiuni, in)) {

			for_del.push_back(in);
			if ((in == name)) pos = counter;
			counter++;
		}
		if (pos == -1) { cout << "something was wrong..."; for_del.clear(); return; }
		for_del[pos] = new_name;
		despre_emisiuni.close();
		ofstream edit("Telecast.txt", ios::trunc);

		for (int i = 0; i < for_del.size(); i++) {
			edit << for_del[i] << endl;
		}
		for_del.clear();
		edit.close();
		cout << "updated successfully!" << endl;

	} break; // Убрана лишняя точка с запятой

	case '2': {
		fstream despre_emisiuni("Telecast.txt");
		cout << "what show you wanna edit?" << endl << "name of show you wanna edit: " << endl;
		getline(cin, name);
		cout << "new type: ";
		getline(cin, new_type);
		while (getline(despre_emisiuni, in)) {

			for_del.push_back(in);
			if ((in == name)) pos = counter;
			counter++;
		}
		if (pos == -1) { cout << "something was wrong..."; for_del.clear(); return; }
		for_del[pos + 1] = new_type;
		despre_emisiuni.close();
		ofstream edit("Telecast.txt", ios::trunc);

		for (int i = 0; i < for_del.size(); i++) {
			edit << for_del[i] << endl;
		}
		for_del.clear();
		edit.close();
		cout << "updated successfully!" << endl;

	} break;

	case '3': {
		ifstream despre_emisiuni("Telecast.txt");
		cout << "what show you wanna edit?" << endl << "code: " << endl;
		getline(cin, code);
		cout << "new code: ";
		getline(cin, new_code);
		while (getline(despre_emisiuni, in)) {

			for_del.push_back(in);
			if ((in == code)) pos = counter;
			counter++;
		}
		if (pos == -1) { cout << "something was wrong..."; for_del.clear(); return; }
		for_del[pos] = new_code;
		despre_emisiuni.close();
		ofstream edit("Telecast.txt", ios::trunc);

		for (int i = 0; i < for_del.size(); i++) {
			edit << for_del[i] << endl;
		}
		for_del.clear();
		edit.close();
		pos = -1;
		counter = 0;

		ifstream despre_canale("channel.txt");
		while (getline(despre_canale, in)) {
			for_del.push_back(in);
			if ((in == code)) pos = counter;
			counter++;
		}
		if (pos == -1) { cout << "something was wrong..."; for_del.clear(); return; }
		for_del[pos] = new_code;
		despre_canale.close();
		ofstream edit_t("channel.txt", ios::trunc);
		for (int i = 0; i < for_del.size(); i++) {
			edit_t << for_del[i] << endl;
		}
		for_del.clear();
		edit_t.close();
		cout << "updated successfully!" << endl;

	} break;
	case '4': {
		fstream despre_emisiuni("Telecast.txt");
		cout << "what show you wanna edit?" << endl << "name of show you wanna edit begining time: " << endl;
		getline(cin, name);
		cout << "new begining time: ";
		getline(cin, new_begin);
		while (getline(despre_emisiuni, in)) {

			for_del.push_back(in);
			if ((in == name)) pos = counter;
			counter++;
		}
		if (pos == -1) { cout << "something was wrong..."; for_del.clear(); return; }
		for_del[pos + 3] = new_begin;
		despre_emisiuni.close();
		ofstream edit("Telecast.txt", ios::trunc);

		for (int i = 0; i < for_del.size(); i++) {
			edit << for_del[i] << endl;
		}
		for_del.clear();
		edit.close();
		cout << "updated successfully!" << endl;


	} break;
	case '5': {
		fstream despre_emisiuni("Telecast.txt");
		cout << "what show you wanna edit?" << endl << "name of show you wanna edit begining time: " << endl;
		getline(cin, name);
		cout << "new begining time: ";
		getline(cin, new_end);
		while (getline(despre_emisiuni, in)) {

			for_del.push_back(in);
			if ((in == name)) pos = counter;
			counter++;
		}
		if (pos == -1) { cout << "something was wrong..."; for_del.clear(); return; }
		for_del[pos + 4] = new_end;
		despre_emisiuni.close();
		ofstream edit("Telecast.txt", ios::trunc);

		for (int i = 0; i < for_del.size(); i++) {
			edit << for_del[i] << endl;
		}
		for_del.clear();
		edit.close();
		cout << "updated successfully!" << endl;

	}
	}
}


void ninth_case() { // для файла с каналами и кол-вом программ на них
	ofstream TVprogram("TVprogram.txt",ios::trunc);
	fstream despre_canale("channel.txt");
	fstream despre_emisiuni("Telecast.txt");
	string in, input;
	int counter = 0, counter1 = 0, counter2 = 0, counter3 = 0;
	vector<string> timp;
	vector<int> count;

	while (getline(despre_canale, in)) {
		if ((counter) % 3 == 0) {
			timp.push_back(in); //код
		}
		if ((counter - 1) % 3 == 0) {
			for_del.push_back(in); //имя
		}
		counter++;
	}

	for (int i = 0; i < timp.size(); i++) {
		despre_emisiuni.clear();
		despre_emisiuni.seekg(0, ios::beg); //чтобы курсор в файле перешел на начало
		while (getline(despre_emisiuni, in)) {
			if (!in.empty() and in.back() == '\r') in.pop_back(); //проверка на пробелы и пустые строки
			if (in == timp[i]) counter2++;
		}
		count.push_back(counter2);
		counter2 = 0;
	}
	for (int i = 0; i < count.size(); i++) {
		TVprogram << for_del[i] << " " << count[i] << endl;
	}
	cout << "everything was done!";


	TVprogram.close();
	despre_canale.close();
	despre_emisiuni.close();
	for_del.clear();
}
void tenth_case()
{
	fstream despre_canale("channel.txt");
	fstream despre_emisiuni("Telecast.txt");

	vector<string> timeB;
	vector<string> timeE;
	vector<int> time;
	string in;
	int counter = 0;

	while (getline(despre_emisiuni, in)) {
		if (counter % 5 == 3) timeB.push_back(in);
		if (counter % 5 == 4) timeE.push_back(in);
		counter++;
	}

	for (int i = 0; i < timeB.size(); i++) {
		int hours, mins, hours1, mins1;
		int begin, end;
		hours = stoi(timeB[i].substr(0, 2));
		mins = stoi(timeB[i].substr(3, 2));
		hours1 = stoi(timeE[i].substr(0, 2));
		mins1 = stoi(timeE[i].substr(3, 2));

		begin = hours * 60 + mins;
		end = hours1 * 60 + mins1;

		int duration = end - begin;
		if (duration < 0) duration += 1440;
		time.push_back(duration);
	}

	if (time.empty()) return;

	int min_val = time[0], max_val = time[0];
	double avg = 0;

	for (int i = 0; i < time.size(); i++) {
		if (time[i] < min_val) min_val = time[i];
		if (time[i] > max_val) max_val = time[i];
		avg += time[i];
	}

	cout << max_val << " the longest show" << endl
		<< min_val << " the shortest show" << endl
		<< avg / time.size() << " avg shows";
}


//void eleventh_case() {
//	ifstream despre_emisiuni ("Telecast.txt");
//	string code, in,name;
//	string begin, end;
//	vector<string> begin_time;
//	vector<string> end_time;
//	vector<string> name;
//	vector<int> time;
//
//	cout << "What you want to know?" << endl << "code of channel: ";
//	getline(cin, code);
//
//	while (getline(despre_emisiuni, in)) {
//		if (in == code) {
//			if (getline(despre_emisiuni, begin) && getline(despre_emisiuni, end)) { //чтобы считать две строки сразу
//				begin_time.push_back(begin);
//				end_time.push_back(end);
//
//			}
//		}
//	}
//	for (int i = 0; i < begin_time.size(); i++) {
//		int hours, mins, hours1, mins1;
//		int begin, end;
//		hours = stoi(begin_time[i].substr(0, 2));
//		mins = stoi(begin_time[i].substr(3, 2));
//		hours1 = stoi(end_time[i].substr(0, 2));
//		mins1 = stoi(end_time[i].substr(3, 2));
//
//		begin = hours * 60 + mins;
//		end = hours1 * 60 + mins1;
//
//		int duration = end - begin;
//		if (duration < 0) duration += 1440;
//		time.push_back(duration);
//	}
//	despre_emisiuni.close();
//}
void eleventh_case() {
	ifstream file("Telecast.txt");
	string t_code;

	cout << "What channel code: ";
	getline(cin, t_code);

	vector<Program> list;
	string name, type, code, b_time, e_time;


	while (getline(file, name)) {
		if (getline(file, type) && getline(file, code) && //чтение имени типа кода время начала и время конца
			getline(file, b_time) && getline(file, e_time)) {

			if (code == t_code) {

				int h1 = stoi(b_time.substr(0, 2)); //сразу перевод в минуты
				int m1 = stoi(b_time.substr(3, 2));
				int h2 = stoi(e_time.substr(0, 2));
				int m2 = stoi(e_time.substr(3, 2));

				int start_total = h1 * 60 + m1;
				int end_total = h2 * 60 + m2;
				int dur = end_total - start_total;
				if (dur < 0) dur += 1440;


				Program p;
				p.name = name;
				p.begin_time = b_time;
				p.end_time = e_time;
				p.start_in_minutes = start_total;
				p.duration = dur;

				list.push_back(p);
			}
		}
	}
	file.close();


	if (list.size() > 1) {
		for (int i = 0; i < list.size() - 1; i++) {
			for (int j = 0; j < list.size() - i - 1; j++) {
				if (list[j].start_in_minutes > list[j + 1].start_in_minutes) { //сортировка
					Program temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
			}
		}
	}


	cout << endl << "schedule for channel " << t_code << ":" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].begin_time << " - " << list[i].end_time //вывод
			<< " " << list[i].name
			<< " " << list[i].duration << " min" << endl;
	}
}











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
			<< "c: for exit"<<endl;

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
