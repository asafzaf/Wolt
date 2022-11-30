#include "Client.h"
#include "Adress.h"

Client::Client(char* name, char* phone_num, Adress adress) {
	m_name = name;
	m_phone_num = phone_num;
	m_credits = 100;
	m_address = adress;
}

Client::~Client() {
	delete m_name;
	delete m_phone_num;
}