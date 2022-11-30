#include <iostream>
#include "Menu.h"

Menu::Menu(Dish** dish) {
	m_dishes = dish;
}

Menu::Menu() : m_dishes()
{};

Menu::~Menu() {
	delete m_dishes;
}

void Menu::printDishes() {
	std::cout << "Dishes Menu:" << std::endl
		<< "Name	|Type	|cost (nis)" << std::endl;
	Dish** list = getDishes();
	
	for (int i = 0; i < 5; i++) {
		std::cout << list[i]->getName() 
			<< "	|" << list[i]->getDishType() 
			<< "	|" << list[i]->getValue() 
			<< std::endl;
	}
}
