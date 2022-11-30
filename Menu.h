#pragma once
#include "Dish.h"

class Menu {
private:
	Dish** m_dishes;
public:
	Menu();
	Menu(Dish** dish);
	~Menu();

	Dish** getDishes() { return m_dishes; }
	void setDishes(Dish** dishes) { m_dishes = dishes; }
	void printDishes();
	Dish* SelectDishByIndex();
};