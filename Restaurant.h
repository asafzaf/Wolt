#pragma once
#include "Menu.h"
#include "Adress.h"

class Restaurant {
private:
	const char* m_name;
	Adress* m_adress;
	Menu m_menu;

public:
	Restaurant();
	Restaurant(const char* name, Adress* adress, Dish** dishes);
	~Restaurant();

	const char* getName() { return m_name; }
	void setName(char* name) { m_name = name; }

	Adress* getAdress() { return m_adress; }
	void setAdress(Adress* adress) { m_adress = adress; }

	Menu getMenu() { return m_menu; }
	void setMenu(Menu menu) { m_menu = menu; }

	
};