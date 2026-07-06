/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:00:36 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/16 10:28:32 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Un point situé a l'interieur d'un triangle est toujours :
 * soit à gauche des 3 arêtes
 * soit à droite des 3 arêtes */

/* Cette fonction calcule de quel côté du segment [p1 p2]
   se trouve test_point.

   Résultat :
    - positif : le point est d'un côté
	- négatif : le point est de l'autre côté
	- zéro     : le point est exactement sur la ligne */
static Fixed	calculateSide(Point const &p1, Point const &p2,
					Point const &test_point)
{
	Fixed	p1_x;
	Fixed	p1_y;
	Fixed	p2_x;
	Fixed	p2_y;
	Fixed	test_x;
	Fixed	test_y;

	p1_x = p1.getX();
	p1_y = p1.getY();
	p2_x = p2.getX();
	p2_y = p2.getY();
	test_x = test_point.getX();
	test_y = test_point.getY();

	// Formule du produit vectoriel en 2D
	return ((test_x - p1_x) * (p2_y - p1_y)
		- (test_y - p1_y) * (p2_x - p1_x));
}

/* bsp = Binary Space Partitioning.

   On vérifie que le point est du même côté des 3 arêtes du triangle.

   Si le point est sur une arête ou sur un sommet, une des valeurs sera égale à 0.
   Cela doit retourner false. */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	sideAB;
	Fixed	sideBC;
	Fixed	sideCA;
	bool	all_positive;
	bool	all_negative;

	sideAB = calculateSide(a, b, point);
	sideBC = calculateSide(b, c, point);
	sideCA = calculateSide(c, a, point);

	all_positive = (sideAB > Fixed(0)
			&& sideBC > Fixed(0)
			&& sideCA > Fixed(0));

	all_negative = (sideAB < Fixed(0)
			&& sideBC < Fixed(0)
			&& sideCA < Fixed(0));

	return (all_positive || all_negative);
}
