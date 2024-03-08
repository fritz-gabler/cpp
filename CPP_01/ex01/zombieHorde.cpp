/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:35:11 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/08 10:50:12 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*ZombieHorde;

	i = 0;
	ZombieHorde = new Zombie[N];
	if (ZombieHorde == NULL)
		return (NULL);
	while (i < N)
	{
		ZombieHorde[i].set_name(name);
		i++;
	}
	return (ZombieHorde);
}
