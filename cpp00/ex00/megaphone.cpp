/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:42:23 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 16:22:34 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char **av)
{
	int		i = 1;
	int		j = 0;
	std::string	input;
	
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				input += std::toupper(av[i][j]);
				j++;
			}
			std::cout << input;
			input.clear();
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
