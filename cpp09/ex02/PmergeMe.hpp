/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:49:59 by nleoni            #+#    #+#             */
/*   Updated: 2025/06/12 16:53:44 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <climits>
#include <sstream>
#include <set>

class PmergeMe {
	public:
	std::vector<int> vector;
	std::deque<int> deque;
	PmergeMe();
		PmergeMe(char **sequence);
		PmergeMe(const PmergeMe& other);
		PmergeMe operator=(const PmergeMe& other);
		~PmergeMe();
		void initVector(char **av);
		void initDeque(char **av);
		template <typename T>
		void algo(T& array, int rec_level, T& main, T& pend);
		template <typename T>
		void binaryInsert(T& main, T& pend, T& array);
};

int parse(char **av);

long jacobsthal(long n);

template <typename T>
void printArray(T& array);

#endif
