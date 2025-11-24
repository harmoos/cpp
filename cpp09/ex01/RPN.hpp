/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:36:29 by nleoni            #+#    #+#             */
/*   Updated: 2025/05/02 18:12:35 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <list>

class RPN {
	private:
		std::string expr;
		std::list<int> sequence;
	public:
		RPN();
		RPN(std::string expr);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		void calculate();
		int parseNumbers();
		int pushToList();
		void printList();
};

#endif