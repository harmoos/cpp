/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:21:29 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/25 17:26:53 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>
#include "whatever.hpp"

template <typename T>
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

template <typename T>
	T min(const T& a, const T& b) {
		return (a > b ? b : a);
	}

template <typename T>
	T max(const T& a, const T& b) {
		return (a < b ? b : a);
	}

#endif
