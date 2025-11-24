/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:43:28 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/29 00:05:59 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	this->data.open("data.csv", std::ios::in);
	if (!this->data)
		throw FileNotOpenException();
	
}

BitcoinExchange::BitcoinExchange(std::string infile) {
	this->data.open("data.csv", std::ios::in);
	if (!this->data)
		throw FileNotOpenException();
	this->infile.open(infile.c_str(), std::ios::in);
	if (!this->infile) {
		std::cout << "ICI2" << std::endl;
		throw FileNotOpenException();
	}	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	
}

bool BitcoinExchange::isValidDate(std::string date) {
	if (date.size() != 10)
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day > 29)
				return false;
		}
		else {
			if (day > 28)
				return false;
		}
	}
	else if (month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	}
	return true;
}

double	BitcoinExchange::getNumber(std::string line) {
	int i = line.find('|');
	std::string newLine = line.substr(i + 2);
	if (newLine == "2147483648")
		return -2;
	double nbr = atof(newLine.c_str());
	if (nbr < 0 || newLine[0] == '-')
		return -1;
	if (nbr > 1000 || newLine.size() > 5)
		return -2;
	return nbr;
}

void	BitcoinExchange::getCalcules(std::string line, std::string key) {
	double nbr = getNumber(line);
	if (nbr == -1) {
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	else if (nbr == -2) {
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	std::map<std::string, double>::iterator it = this->map.find(key);
	if (it != this->map.end()) {
		double price = it->second;
		std::cout << key << " => " << nbr << " = " << price * nbr << std::endl;
	}
	else {
		std::map<std::string, double>::iterator it = this->map.begin();
		it = this->map.lower_bound(key);
		if (it != this->map.begin() && it->first != key)
			--it;
		double res = it->second;
		if (res < 0)
			std::cout << "No price for key " << key << std::endl;
		else
			std::cout << key << " => " << nbr << " = " << res * nbr << std::endl;			
	}
}

bool	parseLine(std::string line) {
	for(unsigned int i = 0; i < line.size(); i++) {
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-' || line[i] == '|'
			|| line[i] == '.' || line[i] == ' ' || line[i] == '\n')
			continue ;
		else
			return false;
	}
	return true;
}

void	BitcoinExchange::compareDatas() {
	loadData();
	if (this->infile.is_open()) {
		std::string line;
		getline(this->infile, line);
		line.clear();
		while (getline(this->infile, line)) {
			if (line.empty())
				break ;
			std::string key;
			key = line.substr(0, 10);
			if (!isValidDate(key) || !parseLine(line)) {
				std::cout << "Error: bad input => " << key << std::endl;
			}
			else {
				getCalcules(line, key);
			}
			line.clear();
		}
		this->infile.close();
	}
	else {
		throw FileNotOpenException();
	}
}

void BitcoinExchange::loadData() {
	if (this->data.is_open()) {
		std::string line;
		std::getline(this->data, line);
		while (!line.empty()) {
			line.clear();
			std::getline(this->data, line);
			if (line.size() < 12)
				break ;
			std::string key = line.substr(0, 10);
			double price = atof(line.substr(11).c_str());
			this->map[key] = price;
			// std::cout << "Key: " << key << " price: " << price << std::endl;
		}
		this->data.close();
	}
	else {
		throw FileNotOpenException();
	}
}

const char* BitcoinExchange::FileNotOpenException::what() const throw() {
	return ("Error: could not open file.");
}

const char* BitcoinExchange::NumberNotFoundException::what() const throw() {
	return ("Error: number not found -- parsing problems");
}
