#pragma once

#ifndef VOYAGEUR_COMMERCE
#define VOYAGEUR_COMMERCE

#include <iostream>
#include <cstdlib>			// rand()

#include <fstream>
#include <sstream>
#include <vector>


const int nb_sommets_max = 281;

typedef struct probleme {
	int nb_sommets;
	float distance[nb_sommets_max][nb_sommets_max];
	int X[nb_sommets_max];
	int Y[nb_sommets_max];
}t_probleme;


typedef struct solution{
	int chemin[nb_sommets_max+1];
	float cout;
}t_solution;


void lecture_fichier(std::string nom_fichier, t_probleme & probleme);
void pre_calcul_probleme(t_probleme & probleme);
void generer_chemin_aleatoire(t_probleme & probleme, t_solution & solution);
void calculer_cout(t_solution & solution, t_probleme & probleme);

void cheapest_construction(t_probleme &probleme, t_solution &solution);

#endif