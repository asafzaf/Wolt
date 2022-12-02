#include <iostream>
#include "Menu.h"

//---        Menu.cpp          ---//
//--- Con's, Dis's and methods ---//

Menu::Menu() : m_dishes() // Default Constractor.
{
	m_num_of_dishes = 0;
};

Menu::Menu(Dish** dish, int numOfDishes) { // Constractor.
	m_dishes = dish;
	m_num_of_dishes = numOfDishes;
}

Menu& Menu::operator = (Menu& menu) { // operator '=' assigment.
	delete m_dishes;
	m_dishes = new Dish * [5];
	for (int i = 0; i < 5; i++) {
		m_dishes[i] = new Dish();
		m_dishes[i] = menu.m_dishes[i];
	};
	m_num_of_dishes = menu.m_num_of_dishes;
	return *this;
}

Menu::~Menu() { // Distractor.
	delete m_dishes;
}

void Menu::printDishes() { // Printing a list of dishes from Menu.
	std::cout << "Dishes Menu:" << std::endl
		<< "No.	|Name	|Type	|cost (nis)" << std::endl;
	Dish** list = getDishes();
	
	for (int i = 0; i < m_num_of_dishes; i++) {
		std::cout << i + 1
			<< "	|" << list[i]->getName()
			<< "	|" << list[i]->getDishType() 
			<< "	|" << list[i]->getValue() 
			<< std::endl;
	}
}

Dish* Menu::SelectDishByIndex(int Index) { // Returning pointer of Dish from index.
	Dish* ptr = m_dishes[Index];
	return ptr;
}