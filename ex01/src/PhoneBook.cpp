#include "PhoneBook.hpp"

static std::string getInput(const std::string &prompt)
{
	std::string input = "";
	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

static bool validPhoneNumber(const std::string &phoneNumber)
{
	if (phoneNumber.empty() || phoneNumber.length() > 20)
		return false;

	bool hasDigit = false;
	for (size_t i = 0; i < phoneNumber.length(); ++i)
	{
		char c = phoneNumber[i];
		if (std::isdigit(c))
		{
			hasDigit = true;
		}
		else if (c == '+')
		{
			if (i != 0)
				return false;
		}
		else if (c != '-' && c != ' ')
		{
			return false;
		}
	}
	return hasDigit;
}

static int getValidatedInt(const std::string &prompt, int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max())
{
	if (max < min)
		return (-1);

	std::string input;
	int number;
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);

		if (std::cin.eof())
		{
			std::cerr << "Input aborted (EOF received)." << std::endl;
			exit(1);
		}

		std::stringstream ss(input);
		if (ss >> number && ss.eof())
		{
			if (number >= min && number <= max)
				return number;
			else
				std::cerr << "Number must be between " << min << " and " << max << "." << std::endl;
		}
		else
			std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
	}
}

static std::string formatField(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

PhoneBook::PhoneBook()
    : index(0), count(0)
{
}

PhoneBook::~PhoneBook()
{
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	for (int i = 0; i < 8; i++)
		contacts[i] = other.contacts[i];
	index = other.index;
	count = other.count;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 8; i++)
			contacts[i] = other.contacts[i];
		index = other.index;
		count = other.count;
	}
	return (*this);
}

void PhoneBook::addContact()
{
	std::string firstName = getInput("Enter first name: ");
	std::string lastName = getInput("Enter last name: ");
	std::string nickname = getInput("Enter nickname: ");
	std::string phoneNumber;
	while (!validPhoneNumber(phoneNumber))
		phoneNumber = getInput("Enter phone number: ");
	
	std::string darkestSecret = getInput("Enter darkest secret: ");
	if (count < 8)
		count++;
	else
		std::cout << "PhoneBook is full, overwriting oldest contact." << std::endl;
	contacts[index] = Contact(firstName, lastName, nickname, phoneNumber,
			darkestSecret);
	index = (index + 1) % 8;
}

void PhoneBook::searchContact()
{
	std::cout << "Contacts in PhoneBook:" << std::endl;
	std::cout << std::right << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << formatField(std::to_string(i)) << "|" << std::setw(10)
			<< formatField(contacts[i].getFirstName()) << "|" << std::setw(10)
			<< formatField(contacts[i].getLastName()) << "|" << std::setw(10)
			<< formatField(contacts[i].getNickname()) << std::endl;
	}

	int index = -1;
	index = getValidatedInt("Enter index of contact to view: ", 0, count - 1);
	if (index < 0 || index >= count)
		return ;
	std::cout << "Contact at index " << index << ":" << std::endl;
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
}
