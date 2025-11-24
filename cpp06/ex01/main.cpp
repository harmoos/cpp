/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:38:08 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/24 23:02:15 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	printData(Data* data) {
	std::cout << "double: " << data->d << std::endl;
	std::cout << "int: " << data->nbr << std::endl;
	std::cout << "string: " << data->str << std::endl;
}

int	main() {
	Data	data;
	
	data.d = 45.2;
	data.nbr = 5555;
	data.str = "Bonjour le correcteur";
	printData(&data);

	uintptr_t raw = Serializer::serializer(&data);

	std::cout << "raw: " << raw << std::endl;

	Data* data2 = Serializer::deserialize(raw);
	printData(data2);
	
}
