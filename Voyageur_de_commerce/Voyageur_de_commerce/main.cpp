#include "Voyageur_de_commerce.h"

using namespace std;


int main(int, char **) {
	t_probleme probleme;
	t_solution solution;


	srand(23685555);

	lecture_fichier("../Sources/a280.txt", probleme);

	pre_calcul_probleme(probleme);

	solution.chemin[0] = 0;
	solution.chemin[1] = 1;
	solution.chemin[2] = 2;
	solution.chemin[3] = 0;

	calculer_cout(solution,probleme);
	generer_chemin_aleatoire(probleme, solution);

	string quitter;
	cout << "Appuyer pour quitter : ";
	cin >> quitter;

	return 0;
}