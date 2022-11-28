#pragma once
#include "Dish.h"

class Menu {
private:
	Dish* m_dishes;
	//int m_numOfDishes;
public:
	Menu(Dish* dish);
	~Menu();

	Dish* getDishes() { return m_dishes; }
	void setDishes(Dish* dishes) { m_dishes = dishes; }

	//int getNumOfDishes() { return m_numOfDishes; }
	//void setNumOfDishes(int numOfDishes) { m_numOfDishes = numOfDishes; }
};