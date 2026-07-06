/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:36:24 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:36:27 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class AAnimal
{
protected:
	std::string	_type;

public:
	AAnimal(void);
	AAnimal(const AAnimal &copy);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal(void);

	// Getter
	std::string	getType(void) const;

	// Fonction virtuelle pure :
	// AAnimal devient une classe abstraite et ne peut pas être instanciée.
	virtual void	makeSound(void) const = 0;
};

#endif
