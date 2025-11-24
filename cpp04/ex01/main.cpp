/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:49:47 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 18:45:25 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <sstream>

int main()
{
	std::cout << "_____________________MAIN FROM SUBJECT_____________________" << std::endl;
	const int numAnimals = 6;
    Animal* animals[numAnimals];
	
    for (int i = 0; i < numAnimals; ++i) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		}
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
    }
	
    for (int i = 0; i < numAnimals; ++i) {
		delete animals[i];
    }

	std::cout << "_____________________SHALLOW/DEEP COPIES_____________________" << std::endl;
	
	Cat	catA;
	catA.setIdea("First Idea", 0);
	Cat catB;
	catB.setIdea("Second Idea", 0);
	Cat catC = catB;
	catB.setIdea("Third Idea", 0);
	Cat* catD = catB.clone();

	std::cout << "Adress of catA first idea: " << catA.getIdeaAdress(0) << " | Idea: " << catA.getIdea(0) << std::endl;
	std::cout << "Adress of catB first idea: " << catB.getIdeaAdress(0) << " | Idea: " << catB.getIdea(0) << std::endl;
	std::cout << "Adress of catC first idea: " << catC.getIdeaAdress(0) << " | Idea: " << catC.getIdea(0) << std::endl;
	std::cout << "Adress of catD first idea: " << catD->getIdeaAdress(0) << " | Idea: " << catD->getIdea(0) << std::endl;

	delete catD;

	std::cout << "_____________________TEST BRAIN IDEAS_____________________" << std::endl;
	
	std::string hoho[100];
	for(int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << i;
		hoho[i] = "Idea WHITE " + ss.str();
	}
	
	std::string haha[100];
	for(int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << i;
		haha[i] = "Idea BLACK " + ss.str();
	}
	
    Dog dog1;
	dog1.setBrain(haha);
    Dog* dog2 = dog1.clone();
	dog2->makeSound();
	std::string* dog1Ideas = dog1.getBrain();
	std::cout << "DOG1 IDEAS" << std::endl;	
	for (int i = 0; i < 100; i++) {
		std::cout << dog1Ideas[i] << std::endl; 
	}
	std::string* dog2Ideas = dog2->getBrain();
	std::cout << "DOG2 IDEAS" << std::endl;	
	for (int i = 0; i < 100; i++) {
		std::cout << dog2Ideas[i] << std::endl; 
	}
	dog2->setBrain(hoho);
	std::string* dog2newIdeas = dog2->getBrain();
	std::cout << "DOG2 NEW IDEAS" << std::endl;	
	for (int i = 0; i < 100; i++) {
		std::cout << dog2newIdeas[i] << std::endl; 
	}
	std::string* dog1newIdeas = dog1.getBrain();
	std::cout << "DOG1 NEW IDEAS" << std::endl;	
	for (int i = 0; i < 100; i++) {
		std::cout << dog1newIdeas[i] << std::endl; 
	}
	Cat	cat1;
	cat1.setBrain(hoho);
	std::string* catIdeas = cat1.getBrain();
	for (int i = 0; i < 100; i++) {
		std::cout << catIdeas[i] << std::endl; 
	}
	cat1.makeSound();

	std::string idea10 = cat1.getIdea(100);
	std::cout << idea10 << std::endl;
	delete dog2;

    return 0;
}
