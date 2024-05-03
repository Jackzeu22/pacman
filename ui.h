#include <stdio.h>
#include "mapa.h"

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_CIAN     "\x1b[36m"
#define ANSI_COLOR_WHITE    "\x1b[37m"
#define ANSI_COLOR_RESET    "\x1b[0m"

char desenhoparede[4][7] = {
	{"......"},
	{"......"},
	{"......"},
	{"......"}
};

char desenhofantasma[4][7] = {
	{" .-.  "},
	{"| OO| "},
	{"|   | "},
	{"'^^^' "}
};

char desenhoheroi[4][7] = {
	{" .--. "},
	{"/ _.-'"},
	{"\\  '-."},
	{" '--' "}
};

char desenhopilula[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char desenhovazio[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void imprimeparte(char desenho[4][7], int parte) {
	printf("%s", desenho[parte]);
}

void imprimemapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {

		for(int parte = 0; parte < 4; parte++) {
			for(int j = 0; j < m->colunas; j++) {

				switch(m->matriz[i][j]) {
					case FANTASMA:
						printf(ANSI_COLOR_WHITE);
						imprimeparte(desenhofantasma, parte);
						printf(ANSI_COLOR_RESET);
						break;
					case HEROI:
						printf(ANSI_COLOR_YELLOW);
						imprimeparte(desenhoheroi, parte);
						printf(ANSI_COLOR_RESET);
						break;
					case PILULA:
						printf(ANSI_COLOR_CIAN);
						imprimeparte(desenhopilula, parte);
						printf(ANSI_COLOR_RESET);
						break;
					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						printf(ANSI_COLOR_RED);
						imprimeparte(desenhoparede, parte);
						printf(ANSI_COLOR_RESET);
						break;
					case VAZIO:
						imprimeparte(desenhovazio, parte);
						break;
				}
				
			}
			printf("\n");
		}

	}
}
