#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int size_etat;
int size_fin;
int size_trans;
int i;
int n;
int size_alph;
typedef	struct Transition{
		int etatDep;
		int etatArr;
		char symbole;
	} Trans;

typedef	struct automate {
		char * etat;
		int ini;
		int * fin;
		Trans * tb_trans;
	} autom;

autom lire1 (autom M) {
	printf("taille d'alphabet \n");
	scanf("%d",&n);
	M.etat = (char*)malloc(n * sizeof(char));
	for (i = 0 ; i < n ; i++){
		printf(" donner l'alphabet %d\n",i);
		scanf(" %c",&M.etat[i]);
		}
	size_etat = n;
	printf("etat initial:\n ");
	scanf("%d",&(M.ini));
	printf("taille d'ensemble d'etat finaux:\n");
	scanf("%d",&n);
	M.fin = (int*)malloc(n * sizeof(int));
	for (i = 0 ; i < n ; i++){
		printf("etat final %d:\n", i);
		scanf("%d",&(M.fin[i]));
		}
	printf("nombre des transition lol	8^)  : ");
	size_fin = n;
	scanf("%d",&n);
	M.tb_trans = (Trans*)malloc(n * sizeof(Trans));
	for (i = 0; i < n ; i++){
		printf("transition %d\n", i);
		printf("etat depart	:");
		scanf("%d",&(M.tb_trans[i].etatDep));
		printf("etat d'arrivee	:");
		scanf("%d",&(M.tb_trans[i].etatArr));
		printf("symbole pls	:");
		scanf(" %c",&(M.tb_trans[i].symbole));
		}
	size_trans = n;
	return M;
}

autom lire (autom M){
	FILE * file;
	char filepath[20];
	int maxlenght = 80;
	printf("need the file name");
	scanf("%s",&filepath);
	file = fopen(filepath, "r");
	if (file == NULL) {
		printf("too quiet in this file");
		exit(EXIT_FAILURE);
	}

	char * linebuffer = (char *)malloc(sizeof(char) * maxlenght);
	if ( linebuffer == NULL) {
		printf("buffer empty");
		exit(EXIT_FAILURE);
	}
	






	return M;
		
}

autom switchLire(autom M){
	int choice;
	printf("choose to read autom from console (0) or file (1)");
	scanf("%d", &choice);
	switch(choice){
		case 0:
			lire1(M);
		case 1:
			lire(M);
	}

	return M;
}

void affichage(autom M){
	printf("\n\nles etats :\n M {");
	for (i=0; i < size_etat ; i++){
		printf(" %c, ", M.etat[i]);
	}
	printf(" }");
	printf("\n");
	printf(" etat initial %d ",M.ini);
	printf("\n");
	printf("les etats finaux d'amerique hhh smou7at :");
	for (i=0; i < size_fin; i++){
		printf(" %d ", M.fin[i]);
	}
	printf("\n");
	printf("les transitions\n");
	for (i=0; i < size_trans ; i++){
		printf(" %d ",M.tb_trans[i].etatDep);
		printf(" %d ",M.tb_trans[i].etatArr);
		printf(" %c ",M.tb_trans[i].symbole);
		printf("\n");	
	}
}
int Trans_existe(autom M, int nd, char sym){
	for (i = 0; i < size_trans ; i++){
		if (M.tb_trans[i].etatDep == nd && M.tb_trans[i].symbole == sym){
			return M.tb_trans[i].etatArr;
		}	

	}
	return -1;
}

char which_trans(autom M, int nd, int na){
	for (i = 0; i < size_trans ; i++){
		if (M.tb_trans[i].etatDep == nd && M.tb_trans[i].etatArr == na){
			return M.tb_trans[i].symbole;
			break;
			}
		}
	return 0;
	}
bool is_final(int e, autom M){
	for (i = 0; i < size_fin; i++){
		if (M.fin[i] == e)
			return 1;
		}
	return 0;
	}

bool Chain_existe_scan(autom M){
	int state = 0;
	int nextState =0;
	int k=0;
	printf("length of chain     :");
	scanf("%d",&n);
	char * chaine;
	chaine = (char*)malloc(n * sizeof(char)); 
	printf("\nneed the chain\n    ");
	scanf(" %s", chaine);
	while (chaine[k] != '\0') {
			nextState = Trans_existe(M, state, chaine[k]);
			if ( nextState == -1){
				free(chaine);
				return 0;
				}
			state = nextState;
			k++;
			}
	if (is_final(state, M) == 1)
		return 1;
	else
		return 0;

		}
bool Chain_existe(autom M, char * chaine){
	int state = 0;
	int nextState =0;
	int k=0;
	while (chaine[k] != '\0') {
			nextState = Trans_existe(M, state, chaine[k]);
			if ( nextState == -1){
				free(chaine);
				return 0;
				}
			state = nextState;
			k++;
			}
	if (is_final(state, M) == 1)
		return 1;
	else
		return 0;


	}

	

/*char short_path(autom M){
	char * short_chaine;
	int current = M.ini;
	char * liste.sym;
	int j;
	liste.sym = (char*)malloc(size_trans * sizeof(char));
	for (i = 0; i < size_trans; i++){
		liste.sym = M.tb_trans[i].sym;
		}
	for ( i = 0; i < size_trans; i++){
		for (j=1; j < size_trans; j++){
			if (liste.sym[i] == liste.sym[j]){
				liste.sym[j] = liste
				}
			}
		}

	for ( j = 0; i  < size_trans ; i++){
		short_chaine = Trans_exist(autom M, current
		}

		}
*/

char * TransAlph(autom M){
	char * test_alphabet = (char*)malloc(sizeof(char) * size_trans);
	if ( test_alphabet = NULL){
		printf("error in Trans_alphabet test_alphabet");
		exit(EXIT_FAILURE);
	}
	char * alphabet;
	int block =0;
	for (i=0 ; i < size_trans; i++){
		int rep =0;
		for (n=0; n < size_trans; n++){
			if (test_alphabet[n] != M.tb_trans[i].symbole){
				rep++;
			}
			if (rep == size_trans){
				test_alphabet[block] == M.tb_trans[i].symbole;
				block++;
				}
		}
	}
	alphabet = (char*)malloc(sizeof(char) * block);
	if ( alphabet == NULL){
		printf("error in Trans_alphabet alphabet");
		exit(EXIT_FAILURE);
	}
	strncpy (alphabet, test_alphabet, block);
	free(test_alphabet);
	size_alph = block;
	return alphabet;
}
int power(int a, int b){
	int result;
	for(int loop=0;loop<b;loop){
		 result = a*a;
	}
	return result;
}
/*char * generateChaine(int len, autom M){
	char * alphabet = TransAlph(M);
	size_t pw = power(size_alph,len);	
	char * randomString = (char *)malloc(len);
	char * StringTable = (char*)malloc(sizeof(randomString) * pw);
	char * table;
	if (randomString == NULL){
		perror("memory fail, can't generate a bullsh");
		exit(EXIT_FAILURE);
	}
	int len_alpha = strlen(alphabet);
	for (int loop=0; loop < pw; loop++){
		for (i = 0; i< len_alpha; i++){
			int randomIndex = rand() % len_alpha;
			randomString[i] = alphabet[randomIndex];
			}
		StringTable[i] = rand
	}
	bool success = Chain_existe(M, randomString);
	if (bool){
		for 
	}
}*/
	
int main (){
	int nd;
	char sym;
	autom M;
	M = lire1(M);
	affichage(M);
	printf("give depart \n");
	scanf("%d", &nd);
	printf("give symbole pls \n");
	scanf(" %c", &sym);	
	int test = Trans_existe(M, nd, sym);
	if ( test != -1)
	printf("etat arrivéé est %d \n",test);
	else printf("nope\n ");
	bool ch = Chain_existe_scan(M);
	printf("chaine exist: %s \n", ch ? "\033[32m true \033[0m" : "\033[31m false \033[0m");
	printf("chaine exist: %s \n", gn ? "\033[32m true \033[0m" : "\033[31m false \033[0m");
	free(M.etat);
	free(M.tb_trans);
	free(M.fin);
	printf("\n the end  8^O  ");
	return 0;
	}

