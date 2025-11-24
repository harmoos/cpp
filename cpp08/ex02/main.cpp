/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:27:19 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/27 13:16:03 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	
	//[...]
	
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "----------------------------" << std::endl;

	MutantStack<double> newMutant;

	srand(static_cast<double>(time(NULL)));
	for (int i = 0; i < 15; i++) {
		double random = rand() / 10000000;
		newMutant.push(random);
	}

	newMutant.push(424242);

	MutantStack<double>::iterator newit = newMutant.begin();
	MutantStack<double>::iterator newite = newMutant.end();
	
	++newit;
	--newit;
	
	while (newit != newite)
	{
		std::cout << *newit << std::endl;
		++newit;
	}
	std::stack<double> s2(newMutant);
	
	return 0;
}
