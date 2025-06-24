#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

Account::Account( int initial_deposit ) {
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    _totalAmount += this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;

    _nbAccounts++;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

static void put_two_digits(int number) {
    if (number < 10) {
        std::cout << "0";
    }
    std::cout << number;
}

void	Account::_displayTimestamp( void ) {
    time_t now;
    struct tm *local_time;

    time(&now);
    local_time = localtime(&now);
    std::cout << "[" << local_time->tm_year + 1900;
    put_two_digits(local_time->tm_mon + 1);
    put_two_digits(local_time->tm_mday);
    std::cout << "_";
    put_two_digits(local_time->tm_hour);
    put_two_digits(local_time->tm_min);
    put_two_digits(local_time->tm_sec);
    std::cout << "] ";
}

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts <<";";
    std::cout << "total:" << _totalAmount <<";";
    std::cout << "deposits:" << _totalNbDeposits <<";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    int prev_amount = this->_amount;

    this->_nbDeposits++;
    _totalNbDeposits++;
    this->_amount += deposit;
    _totalAmount += deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << prev_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    int prev_amount = this->_amount;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << prev_amount << ";";

    if (withdrawal > this->_amount) {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    } else {
        this->_amount -= withdrawal;
        _totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << this->_amount << ";";
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    }
    return (true);
}

int		Account::checkAmount( void ) const {
    return this->_amount;
}
