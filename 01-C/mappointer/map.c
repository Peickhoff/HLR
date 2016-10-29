#include <stdio.h>

// Definieren Sie ein enum cardd
typedef enum {N = 1, E = 2, S = 4, W = 8} cardd; //2er Potenzen als Werte, um or Operation zu ermöglichen

// Definieren Sie ein 3x3-Array namens map, das Werte vom Typ cardd enthält
static cardd map[3][3];

// Die Funktion set_dir soll an Position x, y den Wert dir in das Array map eintragen
// Überprüfen Sie x und y um mögliche Arrayüberläufe zu verhindern
// Überprüfen Sie außerdem dir auf Gültigkeit
void set_dir (int x, int y, cardd dir)
{
	if (x >= 0 && x < 3 && y >= 0 && y < 3) { //Abfrage gegen Überläufe
		int validdirs[13] = {0,1,1,1,1,0,1,0,1,1,0,0,1}; //Werte, für die sich korrekte Himmelsrichtungen ergeben (validdirs[N] = 1, validdirs[N|S] = 0)
		if (dir > 0 && dir <= 12 && validdirs[dir]) { //Prüfung für korrekte Himmelsrichtungen
			map[y][x] = dir;
		}
	}
}

// Die Funktion show_map soll das Array in Form einer 3x3-Matrix ausgeben
void show_map (void)
{
	for (size_t y = 0; y < 3; y++) {
		for (size_t x = 0; x < 3; x++) {
			cardd dir = map[x][y];
			switch (dir) { //entsprechend der enum Werte werden die zugehörigen Himmelsrichtungen ausgegeben
				case 1: printf(" N "); break;
				case 2: printf(" E "); break;
				case 3: printf(" NE"); break;
				case 4: printf(" S "); break;
				case 6: printf(" SE"); break;
				case 8: printf(" W "); break;
				case 9: printf("NW "); break;
				case 12: printf("SW "); break;
				default: printf(" 0 "); break;
			}
		}
		printf("\n");
	}
	printf("\n");
}

int main (void)
{
	// In dieser Funktion darf nichts verändert werden!
	set_dir(0, 1, N);
	set_dir(1, 0, W);
	set_dir(1, 4, W);
	set_dir(1, 2, E);
	set_dir(2, 1, S);

	show_map();

	set_dir(0, 0, N|W);
	set_dir(0, 2, N|E);
	set_dir(0, 2, N|S);
	set_dir(2, 0, S|W);
	set_dir(2, 2, S|E);
	set_dir(2, 2, E|W);

	show_map();

	return 0;
}
