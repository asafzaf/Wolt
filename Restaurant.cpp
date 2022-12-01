#include <iostream>
#include "Restaurant.h"


Restaurant::Restaurant(const char* name, Adress* adress, Dish** dishes) {

	m_name = new char[strlen(name) + 1];
	strncpy(m_name, name, strlen(name));
	m_adress = adress;
	m_menu.setDishes(dishes);
}

//Restaurant& Restaurant::operator = (const Restaurant& restaurant) {
//	if (this == &restaurant) return *this;
//	if ()
//}


Restaurant::Restaurant() : m_menu()
{
	m_name = nullptr;
	m_adress = nullptr;
}

Restaurant::~Restaurant() {
	delete m_name;
	delete m_adress;
}