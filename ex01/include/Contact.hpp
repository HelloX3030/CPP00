#pragma once

#include <string>
#include <iostream>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
    void printContact() const;

  public:
	Contact();
	Contact(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret);
	~Contact();
	Contact(const Contact &other);
	Contact &operator=(const Contact &other);
	Contact(Contact &&other) noexcept;
	Contact &operator=(Contact &&other) noexcept;

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
};
