#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// AIE AIE AIE

#define TAILLE_CARTE 10
enum Directions { Non=-1 , Nord=1 , Sud , Ouest , Est };

typedef struct {
	int pos_x;
	int pos_y;
	int derniere_direction;
	struct t_vertex* vertex_suivant;	
} t_vertex;

t_vertex creer_vertex( int x_init , int y_init , int dir_init , t_vertex* vertex_parent ){
	t_vertex nouveau_vertex = { x_init , y_init , dir_init , NULL };
	if ( vertex_parent != NULL ){
		vertex_parent->vertex_suivant = &nouveau_vertex;
	}
	return nouveau_vertex;
}

void afficher_vertex(t_vertex vertex_cible){
	printf("[ %d , %d , %d , %x ] ...\n",vertex_cible.pos_x,vertex_cible.pos_y,vertex_cible.derniere_direction,vertex_cible.vertex_suivant);
}

void afficher_vertex_cascade( t_vertex* vertex_cible ){
	t_vertex* tete = vertex_cible;
	while ( tete != NULL ){
		afficher_vertex(*tete);
		tete = tete->vertex_suivant;
	}	
}

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

	//initialiser_carte(carte_jeu);

	//creer_chemin(3,3,1,10,carte_jeu);

	t_vertex vertex1 = creer_vertex(3,3,-1,NULL);

	t_vertex vertex2 = creer_vertex(4,4,-1,&vertex1);
	
	t_vertex vertex3 = creer_vertex(4,4,-1,&vertex2);

	afficher_vertex(vertex3);

	printf("--- TEST CASCADE ---\n");

	afficher_vertex_cascade(&vertex1);

	return 0;
}
