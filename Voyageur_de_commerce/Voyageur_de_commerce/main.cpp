#include "Voyageur_de_commerce.h"


int main(int, char **) {
	t_probleme probleme;

	srand(236855554);
	lectureFichier("../Sources/a280.txt", probleme);
	pre_calculProbleme(probleme);

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
	/*					RESOLUTION 2-OPT 						*/
	/* construction 1 solution random	+ RL avec 2-opt		 	*/
	/* ATTENTION ! Vérifier que la ligne 182 de					*/
	/*			   Voyageur_de_commerce.cpp est décommentée		*/
	/*			   (génération solution aléatoire)				*/
	/************************************************************/
	/*
	Solution solution_3(probleme.nb_sommets);
	resolutionTwoOpt(probleme, solution_3);
	std::cout << std::endl << "Meilleure solution 2 Opt: " << std::endl;
	solution_3.afficherSolution();
	*/

	/************************************************************/
	/*					RESOLUTION GENERALE						*/
	/*  construction cheapest insertion + RL avec 2-opt 		*/
	/* ATTENTION ! Vérifier que la ligne 182 de					*/
	/*			   Voyageur_de_commerce.cpp est commentée		*/
	/*			   (génération solution aléatoire)				*/
	/************************************************************/
	/*
	Solution solution_4 = Solution(probleme.nb_sommets);
	resolution(probleme, solution_4);
	std::cout << std::endl << "Meilleure solution Cheapest insertion + 2-Opt : " << std::endl;
	solution_4.afficherSolution();
	*/
	

	std::string quitter;
	std::cout << "Appuyer pour quitter : ";
	std::cin >> quitter;

	return 0;
}