#include "Voyageur_de_commerce.h"

using namespace std;

void lecture_fichier(string nom_fichier, t_probleme & probleme) {
	ifstream mon_fichier(nom_fichier);

	if (mon_fichier) {									// Si lecture OK
		string ligne;
		getline(mon_fichier, ligne);
		istringstream iss(ligne);
		iss >> probleme.nb_sommets;

		int valeur1, valeur2;
		int tmp;
		for (int i = 0; i < probleme.nb_sommets; i++) {
			mon_fichier >> tmp;
			mon_fichier >> probleme.X[i];
			mon_fichier >> probleme.Y[i];
		}
	}
/*	else {
		cout << "Lecture echouee !" << endl;
	}*/
}



void pre_calcul_probleme(t_probleme & probleme){
	float delta_x;
	float delta_y;
	for (int i = 0; i < probleme.nb_sommets; i++){
		for (int j = 0; j < probleme.nb_sommets; j++){
			delta_x = probleme.X[i] - probleme.X[j];
			delta_y = probleme.Y[i] - probleme.Y[j];
			probleme.distance[i][j] = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
		}
	}
}

void generer_chemin_aleatoire(t_probleme & probleme, t_solution & solution) {
	int tab[nb_sommets_max], max = probleme.nb_sommets;
	int alea;

	for (int i = 0; i <= max; i++) {
		tab[i] = i;
	}

	for (int i = 0; i < probleme.nb_sommets; i++) {
		alea = std::rand();
		alea = alea % max;
		solution.chemin[i] = tab[alea];
		max--;
		tab[alea] = tab[max];
	}
	solution.chemin[probleme.nb_sommets] = solution.chemin[0];
}

void calculer_cout(t_solution & solution, t_probleme & probleme){
	solution.cout = 0;
	for (int i = 0; i < probleme.nb_sommets ; i++){
		solution.cout += probleme.distance[solution.chemin[i]][solution.chemin[i+1]];
	}
}

