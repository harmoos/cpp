/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:40:29 by nleoni            #+#    #+#             */
/*   Updated: 2025/06/11 22:33:16 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : expr(0) {
	
}

RPN::RPN(std::string expr) : expr(expr) {
	
}

RPN::RPN(const RPN& other) {
	this->expr = other.expr;
}

RPN& RPN::operator=(const RPN& other) {
	this->expr = other.expr;
	return *this;
}

RPN::~RPN() {
	
}

int RPN::parseNumbers() {
	std::string str = this->expr;
	int i = 0;
	if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
		return 1;
	i = str.size() - 1;
	while (str[i]) {
		if (str[i] == ' ')
			i--;
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			break ;
		else
			return 1;
	}
	while (str[i]) {
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			return 1;
		else
			i++;
	}
	while (str[i]) {
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-'
			|| str[i] == '*' || str[i] == '/' || str[i] == ' ')
			i++;
		else
			return 1;
	}
	return 0;
}

void RPN::printList() {
    std::list<int>::iterator it;
    for (it = this->sequence.begin(); it != this->sequence.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int RPN::pushToList() {
	std::string str = this->expr;
	int i = 0;
	while (str[i]) {
		// printList();
		if (str[i] == ' ')
			i++;
		else if (str[i] >= '0' && str[i] <= '9') {
			int nbr = str[i] - '0';
			this->sequence.push_back(nbr);
			i++;
		}
		else {
			if (this->sequence.size() < 2) {
				std::cout << "Error: bad characteres" << std::endl;
				return -1234;
			}
			else {
				int n2 = this->sequence.back();
				this->sequence.pop_back();
				int n1 = this->sequence.back();
				this->sequence.pop_back();
				if (str[i] == '+')
					this->sequence.push_back(n1 + n2);
				if (str[i] == '-')
					this->sequence.push_back(n1 - n2);
				if (str[i] == '*')
					this->sequence.push_back(n1 * n2);
				if (str[i] == '/') {
					if (n2 == 0) {
						std::cout << "Error: division by zero" << std::endl;
						return -1234;
					}
					this->sequence.push_back(n1 / n2);
				}
				i++;
			}
		}
	}
	return this->sequence.back();
}

void RPN::calculate() {
	if (parseNumbers() == 1) {
		std::cout << "Error: bad characters" << std::endl;
		return ;
	}
	int res = pushToList();
	if (res == -1234)
		return ;
	std::cout << res << std::endl;
	return ;
}

