#pragma once

enum DishType {
	Appetizer = 1,
	MainCourse,
	Dessert
};

class Dish {
private:
	const char* m_name;
	DishType m_dishtype;
	int m_value;

public:
	Dish(const char* name, DishType type, int value);
	Dish(Dish& dish);
	Dish();
	~Dish();

	const char* getName() { return m_name; }
	void setName(char* name) { m_name = name; }

	DishType getDishType() { return m_dishtype; }
	void setDishType(DishType dishtype) { m_dishtype = dishtype; }

	int getValue() { return m_value; }
	void setValue(int value) { m_value = value; }
};