/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:28:10 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/27 13:31:26 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cstdlib>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		size_t size();
		void pop();
		void push(const T& toPush);
		T& top();
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {
	std::stack<T> tmp;
	tmp = other;
	while (!tmp.empty()) {
		T temp = tmp.top();
		other.push(temp);
		this->push(temp);
		tmp.pop();
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& e);

#include "MutantStack.tpp"

#endif
