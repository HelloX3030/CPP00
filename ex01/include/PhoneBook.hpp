#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook
{
  private:
	Contact contacts[8];
	int index;
	int count;

  public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook &other);
	PhoneBook &operator=(const PhoneBook &other);

	void addContact();
	void searchContact();
};
