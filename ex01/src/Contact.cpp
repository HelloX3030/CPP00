#include "Contact.hpp"

void Contact::printContact() const
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}


Contact::Contact()
{
}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber,
	std::string darkestSecret) : firstName(firstName), lastName(lastName),
	nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret)
{
}

Contact::~Contact()
{
}

Contact::Contact(const Contact &other)
{
	*this = other;
}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		this->firstName = other.firstName;
		this->lastName = other.lastName;
		this->nickname = other.nickname;
		this->phoneNumber = other.phoneNumber;
		this->darkestSecret = other.darkestSecret;
	}
	return (*this);
}

std::string Contact::getFirstName() const
{
	return (firstName);
}

std::string Contact::getLastName() const
{
	return (lastName);
}

std::string Contact::getNickname() const
{
	return (nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (phoneNumber);
}
