/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:13:12 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 14:31:18 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T &container, int nbr) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), nbr);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif
