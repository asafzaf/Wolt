#include <iostream>
#include "Adress.h"

//---        Adress.cpp          ---//
//---  Con's, Dis's and methods  ---//

Adress::Adress() { // Default Constractor.
	m_city = new char[10];
	m_street = 0;
}

Adress::Adress(const char* city, int street) { // Constractor.
	m_city = new char[strlen(city)];
	strncpy(m_city, city, strlen(city));
	m_street = street;
}

Adress::Adress(const Adress& adress) { // Copy Constractor.
	m_street = adress.m_street;
	m_city = new char[strlen(adress.m_city)];
	strncpy(m_city, adress.m_city, strlen(adress.m_city));
}

Adress& Adress::operator=(const Adress& adress) { // Assignment operator.
	if (this == &adress) return *this;
	if (strlen(adress.m_city) != strlen(m_city)) {
		delete m_city;
		m_city = new char[strlen(adress.m_city) + 1];
	}
	m_city = adress.m_city;
	m_street = adress.m_street;

	return *this;
}

Adress::~Adress() { // Distractor.
	delete m_city;
}