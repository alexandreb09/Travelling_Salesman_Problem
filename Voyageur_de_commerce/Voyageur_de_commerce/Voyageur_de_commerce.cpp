#include "Voyageur_de_commerce.h"

void lectureFichier(std::string nom_fichier, t_probleme & probleme)
{
	std::ifstream mon_fichier(nom_fichier);

	if (mon_fichier) // Si lecture OK
	{
		std::string ligne;
		getline(mon_fichier, ligne);
		std::istringstream iss(ligne);
		iss >> probleme.nb_sommets;
		std::cout << "Nombre de sommets " << probleme.nb_sommets << std::endl;
		int num_point;

		for (int i = 1; i <= probleme.nb_sommets; i++)
		{
			mon_fichier >> num_point;
			mon_fichier >> probleme.X[num_point];
			mon_fichier >> probleme.Y[num_point];
		}
		std::cout << "Lecture reussie !" << std::endl;

	}
	else
	{
		std::cout << "Lecture echouee !" << std::endl;
	}
}

void pre_calculProbleme(t_probleme & probleme)                //calcul des distances
{
	float delta_x;
	float delta_y;
	for (int i = 1; i <= probleme.nb_sommets; i++) {
		for (int j = 1; j <= probleme.nb_sommets; j++) {
			delta_x = probleme.X[i] - probleme.X[j];
			delta_y = probleme.Y[i] - probleme.Y[j];
			probleme.distance[i][j] = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
		}
	}
}

void calculerCout(t_probleme & probleme, Solution & solution) {
	float cout = 0;
	for (int i = 1; i <= solution.getNbSommetsVisites(); i++) {
		cout += probleme.distance[solution.getSommetCheminI(i)][solution.getSommetCheminI(i + 1)];
	}
	solution.setCout(cout);
}

void genererCheminAleatoire(t_probleme & probleme, Solution & solution) {
	int tab[nb_sommets_max], max = probleme.nb_sommets, num_sommet_alea;

	for (int i = 1; i <= max; i++) {
		tab[i] = i;
	}

	for (int i = 1; i <= probleme.nb_sommets; i++) {
		num_sommet_alea = std::rand() % max + 1;
		solution.InsertionSommetCheminFin(tab[num_sommet_alea]);
		tab[num_sommet_alea] = tab[max];
		max--;
	}
}


int nearestVoisin(t_probleme & probleme, Solution & solution, int sommetDeDepart)
{
	int nearestVoisin = 1;
	while ((nearestVoisin <= probleme.nb_sommets) && solution.sommetsDejaVisites(nearestVoisin)) {
		nearestVoisin++;
	}

	for (int i = 1; i <= probleme.nb_sommets; i++)
	{
		if (!solution.sommetsDejaVisites(i) & (i != sommetDeDepart))
		{
			if (probleme.distance[sommetDeDepart][i] < probleme.distance[sommetDeDepart][nearestVoisin])
			{
				nearestVoisin = i;
			}
		}
	}
	// cout << "nearestVoisin = " << nearestVoisin << endl;	
	return nearestVoisin;
}



void genererCheminNearestVoisin(t_probleme & probleme, Solution & solution, int sommetDeDepart)
{
	int i = 2, suivant;
	int depart = sommetDeDepart;
	solution.InsertionSommetCheminFin(depart);

	while (i <= probleme.nb_sommets)
	{
		suivant = nearestVoisin(probleme, solution, depart);
		solution.InsertionSommetCheminFin(suivant);
		depart = suivant;
		i++;
	}
	calculerCout(probleme, solution);
}

void resolutionNearestNeighbour(t_probleme & probleme, Solution & solution) {
	int sommet_depart = 1;
	Solution solution_courante(probleme.nb_sommets);						// Creation solution courante

	genererCheminNearestVoisin(probleme, solution, sommet_depart);
	// solution.afficherSolution();
	std::cout << "i : " << 1 << " Cout i : " << solution_courante.getCout() << " Best cout : " << solution.getCout() << std::endl;

	for (int i = 2; i <= probleme.nb_sommets; i++) {
		solution_courante.resetSommetsVisites();
		genererCheminNearestVoisin(probleme, solution_courante, i);
		// solution_courante.afficherSolution();
		if (solution_courante.getCout() < solution.getCout()) {
			solution = solution_courante;
			sommet_depart = i;
		}
		std::cout << "i : " << i << " Cout i : " << solution_courante.getCout() << ":  Best cout : " << solution.getCout() << std::endl;
	}
}

void CheapestInsertion(t_probleme & probleme, Solution & solution, int sommet_depart) {
	solution.InsertionSommetCheminFin(sommet_depart);									// Chemin : ajout sommet initial
	int plusProcheVoisin = nearestVoisin(probleme, solution, sommet_depart);			// Recherche plus proche voisin
	solution.InsertionSommetCheminFin(plusProcheVoisin);								// Chemin : ajout 2nd sommet (le plus proche)
	calculerCout(probleme, solution);

	int sommet_prec, sommet_suiv;
	float new_cout, best_cout ;
	int best_posi = -1, best_sommet = -1;

	while (solution.getNbSommetsVisites() < probleme.nb_sommets){
		best_cout = infini;																					// Valeur par défault (on la suppose assez grande)
		
		for (int k = 1; k <= probleme.nb_sommets; k++){														// Numéro de sommets
			if (!solution.sommetsDejaVisites(k)) {
				for (int posi = 1; posi <= solution.getNbSommetsVisites(); posi++){							// Position
					sommet_prec = solution.getSommetCheminI(posi);
					sommet_suiv = solution.getSommetCheminI(posi + 1);
					new_cout = solution.getCout() - probleme.distance[sommet_prec][sommet_suiv] +
						probleme.distance[sommet_prec][k] + probleme.distance[k][sommet_suiv];

					if (new_cout < best_cout) {
						best_sommet = k;
						best_posi = posi;
						best_cout = new_cout;
					}
				}
			}
		}
		solution.InsertionSommetChemin(best_sommet, best_posi);
		calculerCout(probleme, solution);
	}
}

void resolutionCheapestInsertion(t_probleme & probleme, Solution & solution){
	int sommet_depart = 1;
	Solution solution_courante(probleme.nb_sommets);						// Creation solution courante

	CheapestInsertion(probleme, solution, sommet_depart);
	std::cout << "i: 1   Cout i: " << solution.getCout() << "   Best cout: " << solution.getCout() << std::endl;
	// solution.afficherSolution();

	for (int i = 2; i <= probleme.nb_sommets; i++) {
		solution_courante.resetSommetsVisites();
		CheapestInsertion(probleme, solution_courante, i);
		// solution_courante.afficherSolution();
		if (solution_courante.getCout() < solution.getCout()) {
			solution = solution_courante;
			sommet_depart = i;
		}
		std::cout << "i: " << i << "   Cout i: " << solution_courante.getCout() << "   Best cout: " << solution.getCout() << std::endl;
	}
}

void TwoOpt(t_probleme & probleme, Solution & solution, bool solutionRandom) {
	if (solutionRandom) {
		solution.resetSommetsVisites();
		genererCheminAleatoire(probleme, solution);
	}
	calculerCout(probleme, solution);

	int nb_sommets = solution.getNbSommetsVisites();
	float best_cout = solution.getCout();
	bool amelioration = true;

	while (amelioration) {
		amelioration = false;
		
		for (int i = 1; i <= nb_sommets && !amelioration; i++) {
			for (int j = i+2; j <= nb_sommets && !amelioration; j++) {
				int sommet_i = solution.getSommetCheminI(i);
				int sommet_i_suiv = solution.getSommetCheminI(i + 1);
				int sommet_j = solution.getSommetCheminI(j);
				int sommet_j_suiv = solution.getSommetCheminI(j + 1);

				float dist_var = probleme.distance[sommet_i][sommet_i_suiv] + probleme.distance[sommet_j][sommet_j_suiv]
					- probleme.distance[sommet_i][sommet_j] - probleme.distance[sommet_i_suiv][sommet_j_suiv];

				if (dist_var > 0) {
					solution.modif2Opt(i, j);
					solution.setCout(solution.getCout() - dist_var);
				}

				/* Ajout condition arrêt sur différence de couts car erreur numérique dans calcul dist_var */
				if (solution.getCout() < best_cout ) {
					amelioration = true;
					best_cout = solution.getCout();

					// std::cout << "Cout sol: " << solution.getCout() << "    Var: " << dist_var << std::endl;
				}
			}
		}
	}
}


void resolutionTwoOpt_SolutionRandom(t_probleme & probleme, Solution & solution, int nb_test) {
	TwoOpt(probleme, solution, flag_solution_random);
	Solution solution_courante = Solution(probleme.nb_sommets);
	std::cout << "iteration: 1   Cout i: " << solution.getCout() << "   Best cout: " << solution.getCout() << std::endl;
	for (int i = 1; i <= nb_test; i++) {
		TwoOpt(probleme, solution_courante, flag_solution_random);
		if (solution_courante.getCout() < solution.getCout()) {
			solution = solution_courante;
		}
		std::cout << "iteration: " << i << "  Cout i: " << solution_courante.getCout() << "   Best cout: " << solution.getCout() << std::endl;
	}
}


void resolutionTwoOpt_CheapestInsertion(t_probleme & probleme, Solution & solution) {
	int sommet_depart = 1;
	Solution solution_courante(probleme.nb_sommets);						// Creation solution courante

	CheapestInsertion(probleme, solution, sommet_depart);
	TwoOpt(probleme, solution_courante, flag_solution_non_random);
	std::cout << "i : " << 1 << " Cout i : " << solution.getCout() << " Best cout : " << solution.getCout() << std::endl;

	for (int i = 2; i <= probleme.nb_sommets; i++) {
		solution_courante.resetSommetsVisites();
		CheapestInsertion(probleme, solution_courante, i);
		TwoOpt(probleme, solution_courante, flag_solution_non_random);
		// solution_courante.afficherSolution();
		if (solution_courante.getCout() < solution.getCout()) {
			solution = solution_courante;
			sommet_depart = i;
		}
		std::cout << "i : " << i << " Cout i : " << solution_courante.getCout() << " Best cout : " << solution.getCout() << std::endl;
	}
}