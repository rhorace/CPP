/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:37:22 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:37:29 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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
