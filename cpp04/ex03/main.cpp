/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:20:00 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 18:47:33 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void) {
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	delete tmp;
	tmp = src->createMateria("");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	ICharacter*	Nath = new Character("Nath");	
	IMateriaSource* materia = new MateriaSource();

	materia->learnMateria(new(Ice));
	AMateria* mat;
	ICharacter*	Luana = new Character("Luana");

	mat = materia->createMateria("ice");
	
	Nath->equip(mat);
	Nath->equip(mat);
	Nath->use(0, *Luana);
	Nath->use(1, *Luana);
	Nath->use(2, *Luana);
	Nath->use(3, *Luana);
	Nath->unequip(1);
	Nath->unequip(0);
	
	delete Nath;
	delete Luana;
	delete mat;
	delete materia;
	
	return 0;
}
