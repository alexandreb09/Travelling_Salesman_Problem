#include "Voyageur_de_commerce.h"


int main(int, char **) {
	t_probleme probleme;

	srand(236855554);
	lectureFichier("../Sources/a280.txt", probleme);
	pre_calculProbleme(probleme);

	/*
	Solution solution(probleme.nb_sommets);
	resolutionNearestNeighbour(probleme, solution);
	std::cout << std::endl << "Meilleure solution Nearest Neightbour: " << std::endl;
	solution.afficherSolution();
	*/
	
	/*
	Solution solution_2(probleme.nb_sommets);
	resolutionCheapestInsertion(probleme, solution_2);
	std::cout << std::endl << "Meilleure solution Cheapest Insertion: " << std::endl;
	solution_2.afficherSolution();
	*/

	/*
	Solution solution_3(probleme.nb_sommets);
	resolutionTwoOpt(probleme, solution_3);
	std::cout << std::endl << "Meilleure solution 2 Opt: " << std::endl;
	solution_3.afficherSolution();
	*/

	
	Solution solution_4 = Solution(probleme.nb_sommets);
	resolution(probleme, solution_4);
	std::cout << std::endl << "Meilleure solution Cheapest insertion + 2-Opt : " << std::endl;
	solution_4.afficherSolution();

	std::string quitter;
	std::cout << "Appuyer pour quitter : ";
	std::cin >> quitter;

	return 0;
}