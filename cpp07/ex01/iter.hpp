/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:29:28 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/25 20:52:04 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename f>
void	iter(T* array, size_t length, f function) {
	if (array == NULL)
		return ;
	for (int i = 0; i < static_cast<int>(length); i++) {
		function(array[i]);
	}
}

template <typename T>
void	printArray(const T &array) {
	std::cout << array << std::endl;
}

#endif
