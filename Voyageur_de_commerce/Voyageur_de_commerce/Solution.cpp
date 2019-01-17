#include "Solution.h"

/****************************************************/
/*					CONSTRUCTEURS					*/		
/****************************************************/

Solution::Solution() :cout(0), nb_sommets_visites(0) {
	chemin = std::vector<int>(nb_sommets_max + 1, -1);
	sommetsVisites = std::vector<int>(nb_sommets_max, 0);
}

Solution::Solution(int nb_sommets) : cout(0), nb_sommets_visites(0) {
	sommetsVisites = std::vector<int>(nb_sommets_max+1,0);
	chemin = std::vector<int>(nb_sommets_max + 1, -1);
}


/****************************************************/
/*						FONCTIONS					*/	
/****************************************************/
void Solution::setCout(float n_cout) {
	cout = n_cout;
}
float Solution::getCout() {
	return cout;
}

int Solution::getNbSommetsVisites() {
	return nb_sommets_visites;
}
int Solution::getSommetCheminI(int i) {
	return chemin[i];
}

bool Solution::sommetsDejaVisites(int i) {
	return 1 == sommetsVisites[i];
}
void Solution::resetSommetsVisites() {
	nb_sommets_visites = 0;
	std::fill(sommetsVisites.begin(), sommetsVisites.end(), 0);		// Remise à 0 sommets visités
}

void Solution::InsertionSommetCheminFin(int sommet) {
	nb_sommets_visites++;
	chemin[nb_sommets_visites] = sommet;
	chemin[nb_sommets_visites + 1] = chemin[1];
	sommetsVisites[sommet] = 1;
}
void Solution::InsertionSommetChemin(int sommet, int position) {
	chemin.insert(chemin.begin() + position+1, sommet);
	nb_sommets_visites++;
	sommetsVisites[sommet] = 1;
}

void Solution::modif2Opt(int index_sommet_dep, int index_sommet_arr) {
	std::reverse(chemin.begin() + index_sommet_dep+1, chemin.begin() + index_sommet_arr+1);
}


void Solution::afficherSolution() {
	std::cout << "Chemin : ";
	for (int i = 1; i <= nb_sommets_visites; i++) {
		std::cout << chemin[i] << " ";
	}
	std::cout << chemin[1] << std::endl;
	std::cout << "Cout solution : " << cout << std::endl;
}