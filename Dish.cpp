#include <iostream>
#include "Dish.h"


Dish::Dish(char* name, DishType type, int value) {
	m_dishtype = type;
	m_value = value;
	
	m_name = new char[strlen(name) + 1];
	if (m_name == NULL) {
		std::cout << "Memory Erorr!" << std::endl;
		return;
	}
	m_name = name;

}

//Dish::Dish(Dish& dish) { // Copy constructor;
//
//}

Dish::~Dish() {
	delete m_name;
}