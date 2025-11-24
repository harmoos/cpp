/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:16:04 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/28 23:55:58 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>
#include<bits/stdc++.h>

struct Data {
	std::string line;
	std::string key;
	int year;
	int month;
	int day;
	double nbr;
};

class BitcoinExchange {
	private:
		std::ifstream data;
		std::ifstream infile;
		std::map<std::string, double> map;
		Data d1;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string infile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadData();
		void compareDatas();
		double getNumber(std::string line);
		bool isValidDate(std::string date);
		void getCalcules(std::string line, std::string key);
		double findNewDate();
		std::string getNewDate(int *year, int *month, int *day);
		
		class FileNotOpenException : public std::exception {
			virtual const char *what() const throw();
		};

		class NumberNotFoundException : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif
