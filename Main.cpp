#include "Application.h"

int main() {
	Restaurant** Restaurant_List = RestaurantList();
	Application app(Restaurant_List);



	return 0;
}


Restaurant** RestaurantList() {
	Dish** dishset1 = new Dish*[4];
	Dish** dishset2 = new Dish*[5];
	Dish** dishset3 = new Dish*[5];
	Dish** dishset4 = new Dish*[5];
	Dish** dishset5 = new Dish*[5];

	dishset1[0] = new Dish("Hot Wings", Appetizer, 15);
	dishset1[1] = new Dish("Half Chicken", MainCourse, 30);
	dishset1[2] = new Dish("Nuggets", MainCourse, 20);
	dishset1[3] = new Dish("American Ice-Cream", Dessert, 10);

	dishset2[0] = new Dish("Carrot Salad", Appetizer, 15);
	dishset2[1] = new Dish("Onion Soup", Appetizer, 15);
	dishset2[2] = new Dish("Vegan Burger", MainCourse, 30);
	dishset2[3] = new Dish("HotVegDog", MainCourse, 25);
	dishset2[4] = new Dish("NOT cheese cake", Dessert, 20);

	dishset3[0] = new Dish();
	dishset3[1] = new Dish();
	dishset3[2] = new Dish();
	dishset3[3] = new Dish();
	dishset3[4] = new Dish();

	dishset4[0] = new Dish();
	dishset4[1] = new Dish();
	dishset4[2] = new Dish();
	dishset4[3] = new Dish();
	dishset4[4] = new Dish();

	dishset5[0] = new Dish();
	dishset5[1] = new Dish();
	dishset5[2] = new Dish();
	dishset5[3] = new Dish();

	Adress add1("Tel Aviv", 11);
	//Adress add2("Ramat Gan", 7);
	//Adress add3("Beer Sheva", 23);
	//Adress add4("Tel aviv", 29);
	//Adress add5("lisbon", 55);

	Restaurant** list = new Restaurant*[5];
	list[0] = new Restaurant("KFC", add1, dishset1);
	list[1] = new Restaurant("OnlyVegan", add2, dishset2);
	list[2] = new Restaurant("Asaf's Caffe", add3, dishset3);
	list[3] = new Restaurant("Show Room", add4, dishset4);
	list[4] = new Restaurant("The Thai House", add5, dishset5);

	return list;
}