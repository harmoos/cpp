/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:02:27 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/27 13:19:32 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

template <typename T>
class listExemple {
	private:
		std::list<T> data;
	public:
		listExemple() {}
		listExemple(const listExemple& other) {this = &other;}
		listExemple& operator=(const listExemple& other) {if (this != &other) {this = &other;} return *this}
		~listExemple() {}
		typedef typename std::list<T>::iterator iterator;
		void push(const T& value){data.push_back(value);}
		void pop() {if (!data.empty()){data.pop_back();}}
		T& top() {return data.back();}
		size_t size(){return data.size();}
		typename std::list<T>::iterator begin(){return data.begin();}
		typename std::list<T>::iterator end(){return data.end();}
};

int main() {
	listExemple<int> listExemple;

	listExemple.push(5);
	listExemple.push(17);
	
	std::cout << listExemple.top() << std::endl;
	listExemple.pop();
	std::cout << listExemple.size() << std::endl;
	
	listExemple.push(3);
	listExemple.push(5);
	listExemple.push(737);
	listExemple.push(0);

	::listExemple<int>::iterator it = listExemple.begin();
	::listExemple<int>::iterator ite = listExemple.end();

	++it;
	--it;	

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	
	return 0;
}