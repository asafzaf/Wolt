#include "Menu.h"

Menu::Menu(Dish* dish) {
	m_dishes = dish;
}

Menu::~Menu() {
	delete m_dishes;
}