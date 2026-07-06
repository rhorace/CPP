/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:29:06 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 17:28:35 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
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
