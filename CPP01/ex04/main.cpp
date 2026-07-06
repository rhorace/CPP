/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:44:15 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:44:18 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int ac, char **av)
{
	// *** Vérification des arguments ***

    if (ac != 4)
    {
        std::cout << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    // Éviter une boucle infinie si la chaîne à remplacer est vide
    if (s1.empty())
    {
        std::cout << "Erreur : s1 ne peut pas être vide." << std::endl;
        return (1);
    }

	// *** Ouverture des fichiers ***

    // Ouvrir le fichier d'entrée en lecture
    std::ifstream inputFile(filename.c_str());

    if (!inputFile.is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier d'entrée." << std::endl;
        return (1);
    }

    // Construire le nom du fichier de sortie
    std::string outputFilename = filename + ".replace";

    // Ouvrir le fichier de sortie en écriture
    std::ofstream outputFile(outputFilename.c_str());

    if (!outputFile.is_open())
    {
        std::cout << "Erreur : impossible de créer le fichier de sortie." << std::endl;
        return (1);
    }

	// *** Lecture du fichier entier ***

    /* Créer un objet stringstream vide
 	Le stringstream sert de tampon temporaire */
    std::stringstream buffer;

    // Copier tout le contenu du fichier dans le buffer
    buffer << inputFile.rdbuf();

    // Convertir le contenu du buffer en une seule grande chaîne
    std::string content = buffer.str();

	// Recherche et remplacement

    size_t pos = 0;

    // Chercher toutes les occurrences de s1
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        // Supprimer l'ancienne chaîne
        content.erase(pos, s1.length());

        // Insérer la nouvelle chaîne
        content.insert(pos, s2);

        // Continuer la recherche après la chaîne insérée
        pos += s2.length();
    }

	//  *** Écriture du résultat ***
    outputFile << content;   

    return (0);
}
