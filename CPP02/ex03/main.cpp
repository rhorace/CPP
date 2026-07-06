/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:01:13 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/15 16:01:17 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int	main(void)
{
	// Triangle :
	// A(0,0)
	// B(10,0)
	// C(0,10)
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 0.0f);
	Point	c(0.0f, 10.0f);

	// Point situé à l'intérieur du triangle
	Point	inside(2.0f, 2.0f);

	// Point situé à l'extérieur du triangle
	Point	outside(15.0f, 15.0f);

	// Point situé exactement sur une arête
	Point	on_edge(5.0f, 0.0f);

	// Point situé exactement sur un sommet
	Point	on_vertex(0.0f, 0.0f);

	std::cout << "Point (2, 2) : ";
	if (bsp(a, b, c, inside))
		std::cout << "INTERIEUR" << std::endl;
	else
		std::cout << "EXTERIEUR" << std::endl;

	std::cout << "Point (15, 15) : ";
	if (bsp(a, b, c, outside))
		std::cout << "INTERIEUR" << std::endl;
	else
		std::cout << "EXTERIEUR" << std::endl;

	std::cout << "Point (5, 0) : ";
	if (bsp(a, b, c, on_edge))
		std::cout << "INTERIEUR" << std::endl;
	else
		std::cout << "EXTERIEUR (sur une arete)" << std::endl;

	std::cout << "Point (0, 0) : ";
	if (bsp(a, b, c, on_vertex))
		std::cout << "INTERIEUR" << std::endl;
	else
		std::cout << "EXTERIEUR (sur un sommet)" << std::endl;

	return (0);
}
