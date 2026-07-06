/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:37:04 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:37:07 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat(void);

		Brain		*getBrain(void) const;
		void		makeSound(void) const;
};

#endif
