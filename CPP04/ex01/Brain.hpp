/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:28:45 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 17:25:21 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		// Tableau contenant les pensées des animaux.
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain &copy);
		Brain &operator=(const Brain &other);
		~Brain(void);

		std::string	getIdea(int index) const;
		void		setIdea(int index, const std::string &idea);
	};

#endif
