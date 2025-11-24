/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:34:14 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/27 13:20:44 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (std::stack<T>::c.end());
}

template <typename T>
size_t MutantStack<T>::size() {
	return (std::stack<T>::c.size());
}

template <typename T>
void MutantStack<T>::pop() {
	std::stack<T>::pop();
}

template <typename T>
void MutantStack<T>::push(const T& toPush) {
	std::stack<T>::push(toPush);
}

template <typename T>
T& MutantStack<T>::top() {
	return (std::stack<T>::top());
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& e) {
	typename MutantStack<T>::iterator it = e.begin();
	for (; it != e.end(); ++it)
		os << *it << " " << std::endl;
	return os;
}

#endif
