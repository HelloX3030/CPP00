#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
    : _accountIndex(_nbAccounts++),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > _amount) {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:" << withdrawal;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);
    std::cout << '['<< std::put_time(now_tm, "%Y%m%d_%H%M%S") << "] ";
}

Account::Account( void )
    : _accountIndex(_nbAccounts++),
      _amount(0),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
}
