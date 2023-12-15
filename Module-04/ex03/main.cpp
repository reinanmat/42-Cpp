/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:31:37 by revieira          #+#    #+#             */
/*   Updated: 2023/12/15 15:00:13 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <cstdlib>

void	subjectTest(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	copyCharacterTest(void)
{
	Character	bob("Bob_original");
	Character	cpyBob("Bob_copy");
	IMateriaSource	*src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	bob.equip(src->createMateria("ice"));
	bob.equip(src->createMateria("cure"));

	std::cout << CYN "Original:" RESET << std::endl;
	bob.use(0, bob);
	bob.use(1, bob);
	bob.use(2, bob);
	bob.use(-1, bob);
	bob.use(42, bob);
	bob.use(100, bob);

	cpyBob = bob;
	std::cout << CYN "Copy:" RESET << std::endl;
	bob.use(0, bob);
	bob.use(1, bob);
	bob.use(2, bob);
	bob.use(-1, bob);
	bob.use(42, bob);
	bob.use(100, bob);

	delete src;
}

void	copyMateriaSourceTest(void)
{
	Character	bob("Bob");
	Character	any("Any");
	IMateriaSource	*src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << CYN "Original:" RESET << std::endl;
	bob.equip(src->createMateria("ice"));
	bob.equip(src->createMateria("cure"));
	bob.use(0, bob);
	bob.use(1, bob);
	bob.use(2, bob);
	bob.use(-1, bob);
	bob.use(42, bob);
	bob.use(100, bob);

	IMateriaSource	*cpySrc = new MateriaSource(*dynamic_cast<MateriaSource *>(src));
	std::cout << CYN "Copy:" RESET << std::endl;
	any.equip(src->createMateria("ice"));
	any.equip(src->createMateria("cure"));
	any.use(0, any);
	any.use(1, any);
	any.use(2, any);
	any.use(-1, any);
	any.use(42, any);
	any.use(100, any);

	delete src;
	delete cpySrc;
}

void	inventoryAndMaterialsTest()
{
	IMateriaSource	*src = new MateriaSource();
	ICharacter		*character = new Character("character");

	std::cout << CYN "Learning materials (MAX_MATERIALS + 1)" RESET << std::endl;
	for (int i = 0; i < MAX_MATERIALS + 1; i++)
		src->learnMateria(new Cure());
	std::cout << std::endl;

	std::cout << CYN "Equipment materials in inventory (MAX_SLOTS + 1)" RESET << std::endl;
	for (int i = 0; i < MAX_SLOTS + 1; i++)
		character->equip(src->createMateria("cure"));
	std::cout << std::endl;

	std::cout << CYN "Using the materials" RESET << std::endl;
	character->use(0, *character);
	character->use(1, *character);
	character->use(2, *character);
	character->use(3, *character);
	std::cout << std::endl;

	std::cout << CYN "Unequipping everything (MAX_SLOTS + 1)" RESET << std::endl;
	character->unequip(0);
	character->unequip(1);
	character->unequip(2);
	character->unequip(3);
	character->unequip(4);
	std::cout << std::endl;

	std::cout << CYN "Using the materials again (INVENTORY EMPTY)" RESET << std::endl;
	character->use(0, *character);
	character->use(1, *character);
	character->use(2, *character);
	character->use(3, *character);

	delete src;
	delete character;
}

void	battleTest(void)
{
	std::srand(time(NULL));

	ICharacter	*a = new Character("Cleiton");
	ICharacter	*b = new Character("Funestos");
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	a->equip(src->createMateria("ice"));
	a->equip(src->createMateria("cure"));
	b->equip(src->createMateria("ice"));
	b->equip(src->createMateria("cure"));

	std::cout << MAG << a->getName() << " x " << b->getName() << RESET << std::endl;

	for (int i = 0; i < 20; i++)
	{
		int idx = rand() % 2;
		if (idx == 1) {
			a->use(idx, *a);
			b->use(idx, *b);
		} else {
			a->use(idx, *b);
			b->use(idx, *a);
		}
	}

	delete a;
	delete b;
	delete src;
}

int main(void)
{
	{
		std::cout << MAG "TEST 1 (SUBJECT TEST)" RESET << std::endl;
		subjectTest();
	}
	std::cout << std::endl;
	{
		std::cout << MAG "TEST 2 (COPY)" << std::endl;
		std::cout << "-Character:" RESET << std::endl;
		copyCharacterTest();
		std::cout << std::endl;
		std::cout << MAG "-Materia Source:" RESET << std::endl;
		copyMateriaSourceTest();
	}
	std::cout << std::endl;
	{
		std::cout << MAG "TEST 3 (INVENTORY AND MATERIA SOURCE)" RESET << std::endl;
		inventoryAndMaterialsTest();
	}
	std::cout << std::endl;
	{
		std::cout << MAG "TEST 4 (BATTLE)" RESET << std::endl;
		battleTest();
	}
	return 0;
}
