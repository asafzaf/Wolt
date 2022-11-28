#include "Restaurant.h"


Restaurant::Restaurant(char* name, Adress* adress, Dish* dishes) {
	m_name = name;
	m_adress = adress;
	m_menu.setDishes(dishes);
}

Restaurant::Restaurant(Dish* dishes) {
	m_name = nullptr;
	m_adress = nullptr;
	m_menu.setDishes(dishes);
}

Restaurant::Restaurant() : m_menu()
{
	m_name = nullptr;
	m_adress = nullptr;
}