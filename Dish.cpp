// This project made by:
// Asaf Zafrir (205929029)
// Moran Benjamin (212139869)

#include <iostream>
#include "Dish.h"

//---        Dish.cpp          ---//
//--- Con's, Dis's and methods ---//

Dish::Dish() { // Default Constractor.
	m_name = nullptr;
	m_dishtype = Appetizer;
	m_value = 0;
}

Dish::Dish(const char* name, DishType type, int value) { // Constractor.
	m_dishtype = type;
	m_value = value;
	int len = strlen(name) + 1;
	m_name = new char[len];
	if (m_name == NULL) {
		std::cout << "Memory Erorr!" << std::endl;
		return;
	}
	strncpy(m_name, name, strlen(name));
}

Dish::Dish(Dish& dish) { // Copy constructor.
	m_name = new char[strlen(dish.getName() + 1)];
	strncpy(m_name, dish.m_name, strlen(dish.getName()));
	m_dishtype = dish.m_dishtype;
	m_value = dish.m_value;
}

Dish& Dish::operator = (Dish& dish) { // Assignment operator.
	if (this == &dish) return *this;
	if (strcmp(dish.m_name, m_name)) {
		delete m_name;
		m_name = new char[strlen(dish.m_name) + 1];
		strncpy(m_name, dish.m_name, strlen(dish.m_name));
	}
	m_dishtype = dish.m_dishtype;
	m_value = dish.m_value;

	return *this;
}

Dish::~Dish() { // Distractor.
	delete m_name;
}