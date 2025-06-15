#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_CARTE 10
enum Directions { Nord=1 , Sud , Ouest , Est };

void creer_chemin( int x_init , int y_init , int direction , int pas ,int carte[][TAILLE_CARTE] ){
	int x_pos = x_init;
	int y_pos = y_init;
	int progression = 0;
	switch(direction){
		case Nord:
			while (progression < pas){
				if ( y_pos + progression == TAILLE_CARTE-1 ){
					return;
				} else {
					carte[x_pos][y_pos+progression] = 1;
					progression++;
				}
			}
			break;
		case Sud:
			while (progression < pas){
				if ( y_pos-progression == 0 ){
					return;
				} else {
					carte[x_pos][y_pos-progression] = 1;
					progression++;
				}
			}
			break;
		case Ouest:
			while (progression < pas){
				if ( x_pos-progression == 0 ){
					return;
				} else {
					carte[x_pos-progression][y_pos] = 1;
					progression++;
				}
			}
			break;
		case Est:
			while (progression < pas){
				if ( x_pos+progression == TAILLE_CARTE-1 ){
					return;
				} else {
					carte[x_pos+progression][y_pos] = 1;
					progression++;
				}
			}
			break;
	}
}

void initialiser_carte(int carte[][TAILLE_CARTE]){
	for ( int i = 0 ; i < TAILLE_CARTE ; i++ ){
		for ( int j = 0 ; j < TAILLE_CARTE ; j++ ){
			carte[i][j] = 0;
		}
	}
	return;
}

void afficher_carte( int carte[][TAILLE_CARTE] ){
	printf("\n");
	for ( int i = 0 ; i < TAILLE_CARTE ; i++ ){
		for ( int j = 0 ; j < TAILLE_CARTE ; j++ ){
			printf(" %d ",carte[i][j]);
		}
		printf("\n");
	}
	return;
}

int main(int argc , char** argv){

	srand(time(NULL));

	int carte_jeu[TAILLE_CARTE][TAILLE_CARTE];

	initialiser_carte(carte_jeu);

	afficher_carte(carte_jeu);

	creer_chemin(3,3,1,10,carte_jeu);

	afficher_carte(carte_jeu);

	return 0;
}
