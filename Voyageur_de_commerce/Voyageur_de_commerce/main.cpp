#include "Voyageur_de_commerce.h"

using namespace std;


int main(int, char **) {
	t_probleme probleme;
	t_solution solution;


	srand(23685555);

	lecture_fichier("../Sources/a280.txt", probleme);

	pre_calcul_probleme(probleme);
	
	// cheapest_construction(probleme, solution);

	
	// generer_chemin_aleatoire(probleme, solution);

	
	for (int i = 0; i < probleme.nb_sommets; i++) {
		solution.chemin[i] = i;
	}
	solution.chemin[probleme.nb_sommets] = 0;
	

	calculer_cout(solution,probleme);


	cout << "Cout solution : " << solution.cout << endl;

	
	string quitter;
	cout << "Appuyer pour quitter : ";
	cin >> quitter;

	return 0;
}