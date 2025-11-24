/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:44:04 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 20:56:27 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span {
	private:
		std::vector<int> array;
		unsigned int size;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int nbr);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		int shortestSpan();
		int longestSpan();
		
		int getArrayAt(unsigned int idx);
		
		class SpanIsAlreadyFullException : public std::exception {
			virtual const char *what() const throw();
		};
		class NumberNotFoundException : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif
