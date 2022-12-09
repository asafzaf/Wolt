// This project made by:
// Asaf Zafrir (205929029)
// Moran Benjamin (212139869)

#include <iostream>
#include "Restaurant.h"

//---        Restaurant.cpp          ---//
//---    Con's, Dis's and methods    ---//

Restaurant::Restaurant() : m_menu() // Default Constractor.
{
	m_name = nullptr;
	m_adress = nullptr;
}

Restaurant::Restaurant(const char* name, Adress* adress, Dish** dishes, int numOfDishes) { // Constractor.

	m_name = new char[strlen(name) + 1];
	strncpy(m_name, name, strlen(name));
	m_adress = adress;
	m_menu.setDishes(dishes);
	m_menu.setNumOfDishes(numOfDishes);
}

Restaurant::~Restaurant() { // Distractor.
	delete m_name;
	delete m_adress;
}