#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

const int nb_sommets_max = 281;

class Solution {
	int nb_sommets_visites;
	std::vector<int> sommetsVisites;
	std::vector<int> chemin;
	float cout;

public:
	Solution();
	Solution(int nb_sommets);

	void setCout(float cout);
	float getCout();

	int getNbSommetsVisites();
	int getSommetCheminI(int i);
	
	bool sommetsDejaVisites(int i);
	void resetSommetsVisites();

	void InsertionSommetCheminFin(int sommet);
	void InsertionSommetChemin(int sommet, int position);
	void modif2Opt(int sommet_dep, int sommet_arr);

	void afficherSolution();
};