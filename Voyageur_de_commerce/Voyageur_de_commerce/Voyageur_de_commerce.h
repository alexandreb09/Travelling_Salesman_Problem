#pragma once

#include "Solution.h"


#include <cstdlib>			// rand()
#include <fstream>
#include <sstream>
#include "math.h"


const int nbDeVoisins = 5;
const float infini = 999999;
const double epsilon = 0.00001;

typedef struct probleme {
	int nb_sommets;
	float X[nb_sommets_max];
	float Y[nb_sommets_max];
	float distance[nb_sommets_max][nb_sommets_max];
}t_probleme;


void lectureFichier(std::string nom_fichier, t_probleme & probleme);
void pre_calculProbleme(t_probleme & probleme);
int nearestVoisin(t_probleme & probleme, Solution & solution, int sommetDeDepart);
void calculerCout(t_probleme & probleme, Solution & solution);

void genererCheminAleatoire(t_probleme & probleme, Solution & solution);
void genererCheminNearestVoisin(t_probleme & probleme, Solution & solution, int sommetDeDepart);
void CheapestInsertion(t_probleme & probleme, Solution & solution, int sommet_depart);

void resolutionNearestNeighbour(t_probleme & probleme, Solution & solution);
void resolutionCheapestInsertion(t_probleme & probleme, Solution & solution);
void resolutionTwoOpt(t_probleme & probleme, Solution & solution);
void resolution(t_probleme & probleme, Solution & solution);


