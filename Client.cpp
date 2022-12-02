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
	m_credits = 100;
	m_address = Adress(adress);
}