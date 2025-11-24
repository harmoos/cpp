/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:09:43 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 22:55:18 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : size(0) {
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int N) {
	if (N > 4294967290)
		throw NumberNotFoundException();
	this->size = N;
	std::cout << "Span constructor called with size: " << N << std::endl;
}

Span::Span(const Span& other) {
	for (unsigned int i = 0; i < this->size; i++) {
		this->array[i] = other.array[i];
	}
	this->size = other.size;
}

Span& Span::operator=(const Span& other) {
	for (unsigned int i = 0; i < this->size; i++) {
		this->array[i] = other.array[i];
	}
	this->size = other.size;
	return *this;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int nbr) {
	if (this->array.size() < this->size)
		this->array.push_back(nbr);
	else
		throw SpanIsAlreadyFullException();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (array.size() + std::distance(begin, end) > this->size)
		throw SpanIsAlreadyFullException();
	array.insert(array.end(), begin, end);
}

int Span::shortestSpan() {
	if (this->size < 2)
		throw NumberNotFoundException();

	std::vector<int> tmp = this->array;
	std::sort(tmp.begin(), tmp.end());
	
	int shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++) {
		if (std::abs(tmp[i] - tmp[i - 1]) < shortest)
			shortest = std::abs(tmp[i] - tmp[i - 1]);
	}
		
	return shortest;
}

int Span::longestSpan() {
	if (this->size < 2)
		throw NumberNotFoundException();

	std::vector<int> tmp = this->array;
	std::sort(tmp.begin(), tmp.end());

	int longest = tmp[tmp.size() - 1] - tmp[0];

	return longest;
}

int Span::getArrayAt(unsigned int idx) {
	if (idx > this->size)
		throw NumberNotFoundException();
	return array[idx];
}

const char* Span::SpanIsAlreadyFullException::what() const throw() {
	return ("Span is already full");
}

const char* Span::NumberNotFoundException::what() const throw() {
	return ("Number not found");
}
