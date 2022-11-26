#pragma once

enum DishType {
	Appetizer = 1,
	MainCourse,
	Dessert
};

class Dish {
private:
	char* m_name;
	DishType m_dishtype;
	int m_value;

public:
	Dish();
	~Dish();

	
};