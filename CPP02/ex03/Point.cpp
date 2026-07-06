/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:01:35 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/15 16:01:40 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Constructeur par défaut.
   Le point créé est placé en (0, 0). */
Point::Point(void) : _x(0), _y(0)
{
}

/* Constructeur avec coordonnées.
   Les float sont convertis en Fixed grâce au constructeur Fixed(float). */
Point::Point(const float x_val, const float y_val) : _x(x_val), _y(y_val)
{
}

/* Constructeur de copie.
   Comme _x et _y sont const, ils doivent être initialisés ici. */
Point::Point(const Point &copy) : _x(copy._x), _y(copy._y)
{
}

Point::~Point(void)
{
}

/* Opérateur d'affectation.

	_x et _y sont const, donc on ne peut pas modifier leurs valeurs
	après la construction de l'objet.

	Cette fonction existe seulement pour respecter la forme canonique. */
Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

//	Retourne la coordonnée x du point.
Fixed	Point::getX(void) const
{
	return (this->_x);
}

//	Retourne la coordonnée y du point.
Fixed	Point::getY(void) const
{
	return (this->_y);
}
