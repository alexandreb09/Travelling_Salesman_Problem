#include "Voyageur_de_commerce.h"
#include "time.h"

int main(int, char **) {
	t_probleme probleme;

	srand(236855554);
	lectureFichier("../Sources/a280.txt", probleme);
	pre_calculProbleme(probleme);

	clock_t begin = clock();										// Début mesure temps
	
	/************************************************************/
	/*					RESOLUTION Nearest Neighbor 			*/
	/* Pour chaque sommet : construction chemin avec plus proche*/
	/*						voisin								*/	
	/************************************************************/
	/*
	Solution solution(probleme.nb_sommets);
	resolutionNearestNeighbour(probleme, solution);
	std::cout << std::endl << "Meilleure solution Nearest Neightbour: " << std::endl;
	solution.afficherSolution();
	*/
	
	/************************************************************/
	/*				RESOLUTION CheapestInsertion				*/
	/* Pour chaque sommet de depart : resolution cheapest		*/
	/*								  insertion 				*/
	/************************************************************/
	/*
	Solution solution_2(probleme.nb_sommets);
	resolutionCheapestInsertion(probleme, solution_2);
	std::cout << std::endl << "Meilleure solution Cheapest Insertion: " << std::endl;
	solution_2.afficherSolution();
	*/

	/************************************************************/
	/*			RESOLUTION 2-OPT sur solution aléatoire			*/
	/* construction n solutions aléatoire + RL avec 2-opt	 	*/
	/************************************************************/
	/*
	int nb_sol_random = 280;
	Solution solution_3(probleme.nb_sommets);
	resolutionTwoOpt_SolutionRandom(probleme, solution_3, nb_sol_random);
	std::cout << std::endl << "Meilleure solution 2 Opt sur " << nb_sol_random << " solutions random : " << std::endl;
	solution_3.afficherSolution();
	*/

	/************************************************************/
	/*		RESOLUTION 2-OPT sur solution cheapest insertion	*/
	/* Application 2-Opt sur n solutions obtenues par cheapest 	*/
	/*	insertion												*/
	/************************************************************/
	/*
	Solution solution_4 = Solution(probleme.nb_sommets);
	resolutionTwoOpt_CheapestInsertion(probleme, solution_4);
	std::cout << std::endl << "Meilleure solution Cheapest insertion + 2-Opt : " << std::endl;
	solution_4.afficherSolution();
	*/	

	double tps_ecoule = double(clock() - begin) / CLOCKS_PER_SEC;			// Temps écoulé
	// std::cout << "Temps execution : " << tps_ecoule << "s" << std::endl;	// Affichage temps écoulé

	std::string quitter;
	std::cout << "Appuyer pour quitter : ";
	std::cin >> quitter;

	return 0;
}