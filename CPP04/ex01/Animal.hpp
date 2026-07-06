/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:28:23 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 17:28:56 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(const Animal &copy);
		Animal &operator=(const Animal &other);
		virtual ~Animal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
