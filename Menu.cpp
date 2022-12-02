#include <iostream>
#include "Menu.h"


Menu::Menu() : m_dishes()
{};

Menu::Menu(Dish** dish) {
	m_dishes = dish;
}

Menu& Menu::operator = (Menu& menu) {
	delete m_dishes;
	m_dishes = new Dish * [5];
	for (int i = 0; i < 5; i++) {
		m_dishes[i] = new Dish();
		m_dishes[i] = menu.m_dishes[i];
	}
	return *this;
}


Menu::~Menu() {
	delete m_dishes;
}

void Menu::printDishes() {
	std::cout << "Dishes Menu:" << std::endl
		<< "No.	|Name	|Type	|cost (nis)" << std::endl;
	Dish** list = getDishes();
	
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1
			<< list[i]->getName() 
			<< "	|" << list[i]->getDishType() 
			<< "	|" << list[i]->getValue() 
			<< std::endl;
	}
}

Dish* Menu::SelectDishByIndex() {
	std::cout << "Select Dish: ";
	int Index;
	std::cin >> Index;
	Dish* ptr = m_dishes[Index - 1];
	return ptr;
}