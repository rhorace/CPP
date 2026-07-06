/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:45:05 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:45:08 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	harl;

	harl.complain("DEBUG");	
	harl.complain("INFO");	
	harl.complain("WARNING");	
	harl.complain("ERROR");	
	harl.complain("RANDOM");

	return 0;
}

