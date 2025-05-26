#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return 0;
}

int Account::getTotalAmount( void )
{
    return 0;
}

int Account::getNbDeposits( void )
{
    return 0;
}

int Account::getNbWithdrawals( void )
{
    return 0;
}

void Account::displayAccountsInfos( void )
{

}

Account::Account( int initial_deposit )
{
    (void)initial_deposit;
}

Account::~Account( void )
{
    
}

void	Account::makeDeposit( int deposit )
{
    (void)deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    (void)withdrawal;
    return (false);
}

int		Account::checkAmount( void ) const
{
    return (0);
}
void	Account::displayStatus( void ) const
{

}

void	Account::_displayTimestamp( void )
{
    
}

Account::Account( void )
{

}
