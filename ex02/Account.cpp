#include "Account.hpp"

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}	
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}


void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);

  	std::cout << "["
  	            << (ltm->tm_year + 1900)
  	            << std::setw(2) << std::setfill('0') << (ltm->tm_mon + 1)
  	            << std::setw(2) << std::setfill('0') << ltm->tm_mday
  	            << "_"
  	            << std::setw(2) << std::setfill('0') << ltm->tm_hour
  	            << std::setw(2) << std::setfill('0') << ltm->tm_min
  	            << std::setw(2) << std::setfill('0') << ltm->tm_sec
  	            << "] ";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_amount = initial_deposit;
    _totalAmount += initial_deposit;
	_nbDeposits = 0;
    _nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
          << ";amount:" << _amount
          << ";created" << std::endl;
}
