#include <iostream>
#include "Adress.h"

Adress::Adress(char* city, int street) {
	m_city = city;
	m_street = street;
}

Adress::Adress(const Adress& adress) {
	m_street = adress.m_street;
	m_city = adress.m_city;

}

Adress::~Adress() {
	delete m_city;
}