/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:11 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 15:37:22 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	std::cout << "Constructor called" << std::endl;
	this->_size = 0;
	this->array = new T[this->_size];
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->_size = n;
	this->array = new T[this->_size];
}

template <typename T>
Array<T>::Array(const Array& other) {
	this->_size = other._size;
	this->array = new T[_size];
	for (unsigned int i = 0; i < _size; i++) {
		this->array[i] = other.array[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this->array != NULL)
		delete [] array;
	this->_size = other._size;
	if (this->_size != 0)
		this->array = new T[this->_size];
	for (unsigned int i = 0; i < _size; i++) {
		this->array[i] = other.array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (this->array != NULL)
		delete [] array;
}

template <typename T>
size_t	Array<T>::size() {
	return this->_size;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
	if (idx >= _size) 
		throw std::out_of_range("Out of range!!!!!");
	return this->array[idx];
}



#endif
