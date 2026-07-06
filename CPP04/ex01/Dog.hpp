/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:29:27 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 17:28:47 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog(void);

		Brain		*getBrain(void) const;
		void		makeSound(void) const;
};

#endif
