// This project made by:
// Asaf Zafrir (205929029)
// Moran Benjamin (212139869)

#include <iostream>
#include "Client.h"
#include "Adress.h"

//---              Client.cpp               ---//
//---     Con's, Dis's & lot of methods     ---//

Client::~Client() { // Default Constractor.
	delete m_name;
	delete m_phone_num;
}

Client::Client(char* name, char* phone_num, Adress adress) { // Constractor.
	m_name = name;
	m_phone_num = phone_num;
	//m_name = new char[strlen(name) + 1];
	//strncpy(m_name, name, strlen(name));
	//m_phone_num = new char[11];
	//strncpy(m_phone_num, phone_num, strlen(phone_num));
	m_credits = 100;
	m_address = Adress(adress);
}