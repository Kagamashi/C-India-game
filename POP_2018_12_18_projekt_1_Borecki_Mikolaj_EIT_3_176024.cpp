//	POP_2018_12_18_projekt_1_Borecki_Mikolaj_EIT_3_176024	Visual Studio 2017(podstawowa wersja)


#include <iostream>
#include <math.h>
using namespace std;
void start(char plansza_c[6][6], int plansza_i[6][6]);
void wyswietlanie(char plansza_c[6][6], int plansza_i[6][6]);
void sterowanie(char plansza_c[6][6], int plansza_i[6][6], char gracz);
void wsp(char w[3], int pozycja[2]);
void ruch(char plansza_c[6][6], int plansza_i[6][6], char gracz, int pozycja[2]);
bool spr_koniec(char plansza_c[6][6], int plansza_i[6][6]);
bool spr_w(char plansza_c[6][6], int plansza_i[6][6], char gracz, int pozycja_s[2], int pozycja_k[2]);

void start(char plansza_c[6][6], int plansza_i[6][6]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			plansza_c[i][j] = '#';
			plansza_i[i][j] = 1;
		}
	}
	for (int i = 2; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			plansza_c[i][j] = ' ';
			plansza_i[i][j] = 0;
		}
	}

	for (int i = 4; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			plansza_c[i][j] = 'O';
			plansza_i[i][j] = 1;
		}
	}

}
void wyswietlanie(char plansza_c[6][6], int plansza_i[6][6]) {
	system("cls");
	for (int i = 0; i < 6; i++) {
		cout << "   ";
		for (int j = 0; j < 6; j++) {
			cout << "+-----";
		}
		cout << "+" << endl;

		cout << "   ";
		for (int j = 0; j < 6; j++) {
			if (plansza_c[i][j] != ' ') cout << "|  " << plansza_i[i][j] << "  ";
			else cout << "|     ";
		}
		cout << "|" << endl;

		cout << " " << i + 1 << " ";
		for (int j = 0; j < 6; j++) {
			cout << "| " << plansza_c[i][j] << plansza_c[i][j] << plansza_c[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "   ";
	for (int j = 0; j < 6; j++) {
		cout << "+-----";
	}
	cout << "+" << endl;
	cout << "   ";
	for (int j = 0; j < 6; j++) {
		cout << "   " << char(j + 65) << "  ";
	}
}
void sterowanie(char plansza_c[6][6], int plansza_i[6][6], char gracz) {
	char w[3];
	int pozycja[2];
	cout << endl << " Ruch gracza '" << gracz << "'" << endl;
	cout << " Wybierz stos (np. A2)" << endl;
	do {
		cin >> w;
		wsp(w, pozycja);
	} while (plansza_c[pozycja[1]][pozycja[0]] != gracz);


	cout << "         Wybierz ruch" << endl;
	cout << "  1. Zwieksz wysokosc stosu" << endl;
	cout << "  2. Przesun stos" << endl;
	int wybor;

	do {
		cin >> wybor;
		switch (wybor) {
		case 1:plansza_i[pozycja[1]][pozycja[0]]++;
			break;
		case 2:ruch(plansza_c, plansza_i, gracz, pozycja);
			break;
		default: wybor = 0;
			break;
		}
	} while (wybor > 2 or wybor < 1);
}
void wsp(char w[3], int pozycja[2]) {
	pozycja[0] = w[0] - 65;
	pozycja[1] = w[1] - 49;
}
void ruch(char plansza_c[6][6], int plansza_i[6][6], char gracz, int pozycja_s[2]) {
	cout << "   Gdzie?" << endl;
	char w[3];
	int pozycja[2];
	cout << " Wybierz wspolrzedne (np. A2)" << endl;
	do {
		cin >> w;
		wsp(w, pozycja);
	} while (spr_w(plansza_c, plansza_i, gracz, pozycja_s, pozycja));

	plansza_c[pozycja[1]][pozycja[0]] = gracz;
	plansza_c[pozycja_s[1]][pozycja_s[0]] = ' ';
	plansza_i[pozycja[1]][pozycja[0]] = plansza_i[pozycja_s[1]][pozycja_s[0]];
	plansza_i[pozycja_s[1]][pozycja_s[0]] = 0;
}
bool spr_koniec(char plansza_c[6][6], int plansza_i[6][6]) {
	for (int i = 0; i < 6; i++) {
		if (plansza_c[0][i] == 'O' and plansza_i[0][i] == 1) {
			cout << "Wygral gracz 'O'" << endl;
			return 0;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (plansza_c[5][i] == '#' and plansza_i[5][i] == 1) {
			cout << "Wygral gracz '#'" << endl;
			return 0;
		}
	}
	int ilosc_O = 0;
	int ilosc_hasz = 0;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (plansza_c[i][j] == '#' and plansza_i[i][j] == 1) ilosc_hasz++;
			if (plansza_c[i][j] == 'O' and plansza_i[i][j] == 1) ilosc_O++;
		}
	}
	if (ilosc_hasz == 0) {
		cout << "Wygral gracz 'O'" << endl;
		return 0;
	}
	if (ilosc_O == 0) {
		cout << "Wygral gracz '#'" << endl;
		return 0;
	}
	return 1;

}
bool spr_w(char plansza_c[6][6], int plansza_i[6][6], char gracz, int pozycja_s[2], int pozycja_k[2]) {
	if (abs(pozycja_s[1] - pozycja_k[1]) > 1 or abs(pozycja_s[0] - pozycja_k[0]) > 1) return 1;
	if (plansza_c[pozycja_k[1]][pozycja_k[0]] != gracz) {
		if (plansza_c[pozycja_k[1]][pozycja_k[0]] != ' ') {
			if (plansza_i[pozycja_s[1]][pozycja_s[0]] - plansza_i[pozycja_k[1]][pozycja_k[0]] != 1) return 1;
			else return 0;
		}
		else return 0;
	}
	else return 1;
}

int main()
{
	char plansza_c[6][6];
	int plansza_i[6][6];
	start(plansza_c, plansza_i);
	wyswietlanie(plansza_c, plansza_i);
	do {
		sterowanie(plansza_c, plansza_i, '#');
		wyswietlanie(plansza_c, plansza_i);
		if (!spr_koniec(plansza_c, plansza_i)) break;
		sterowanie(plansza_c, plansza_i, 'O');
		wyswietlanie(plansza_c, plansza_i);
	} while (spr_koniec(plansza_c, plansza_i));

}