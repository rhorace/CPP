/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:01:48 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/15 16:01:51 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		Point(const float x_val, const float y_val);
		Point(const Point &copy);
		~Point(void);

		Point	&operator=(const Point &other);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

// Prototype demandé par le sujet
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
