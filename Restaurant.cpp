#include "Restaurant.h"


Restaurant::Restaurant(const char* name, Adress* adress, Dish** dishes) {
	m_name = name;
	m_adress = adress;
	m_menu.setDishes(dishes);
}



Restaurant::Restaurant() : m_menu()
{
	m_name = nullptr;
	m_adress = nullptr;
}

Restaurant::~Restaurant() {
	delete m_name;
	delete m_adress;
}