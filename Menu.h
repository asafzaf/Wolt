#pragma once
#include "Dish.h"

//---        Menu.h          ---//

class Menu {
private:
	Dish** m_dishes;
	int m_num_of_dishes;
public:
	Menu();
	Menu(Dish** dish, int numOfDishes);
	Menu& operator = (Menu& menu);
	~Menu();

	//---      Methods      ---//
	void printDishes();
	Dish* SelectDishByIndex(int Index);

	//--- Getters & setters ---//
	Dish** getDishes() { return m_dishes; }
	void setDishes(Dish** dishes) { m_dishes = dishes; }

	int getNumOfDishes() { return m_num_of_dishes; }
	void setNumOfDishes(int num_of_dishes) { m_num_of_dishes = num_of_dishes; }


};