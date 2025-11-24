/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:44:22 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/25 16:49:45 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	if (this != &other)
		*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other)
		*this = other;
	return *this;	
}

ScalarConverter::~ScalarConverter() {
}

int	pseudoLiteral(std::string param) {
	std::string pseudof[] =  {"-inff", "+inff", "nanf"};
	for (int i = 0; i < 3; i++) {
		if (param.compare(pseudof[i]) == 0)
			return 1;
	}
	std::string pseudod[] =  {"-inf", "+inf", "nan"};
	for (int i = 0; i < 3; i++) {
		if (param.compare(pseudod[i]) == 0)
			return 2;
	}
	return 0;
}

bool	is_number(std::string param) {
	int	i = 0;
	
	if (param[i] == '+' || param[i] == '-')
		i++;
	while (param[i] >= '0' && param[i] <= '9')
		i++;
	if (param[i] == '.')
		i++;
	while (param[i] >= '0' && param[i] <= '9')
		i++;
	if (param[i] == 'f')
		i++;
	if (param[param.length() - 1] == '.')
		return false;
	if (static_cast<int>(param.length()) == i)
		return true;
	else
		return false;
}

static bool parse_literal(std::string param) {
	if (param.empty())
		return false;
	if (param.length() == 1)
		return true;
	if (pseudoLiteral(param))
		return true;
	if (is_number(param)) 
		return true;
	else
		return false;
}

bool is_printable(char c) {
	if (c <= 32 || c >= 127)
		return false;
	return true;
		
}

int	detectType(std::string param) {
	if (param == " ")
		return 1;
	if (param.length() == 1 && (param[0] < '0' || param[0] > '9') && is_printable(param[0]))
		return 1;
	if (pseudoLiteral(param) == 1)
		return 5;
	else if (pseudoLiteral(param) == 2)
		return 6;
	if (param[param.length() - 1] == 'f')
		return 3;
	for (int i = 0; i < static_cast<int>(param.length()); i++) {
		if (param[i] == '.')
			return 4;
	}
	return 2;
}

void	printChar(char c, bool pos) {
	if (pos)
		std::cout << "Char: impossible" << std::endl;
	else if (c < 31 || c > 126)
	std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: '" << c << "'" << std::endl;
}

void	printInt(int nbr, bool pos) {
	if (pos)
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << nbr << std::endl;
}

void	printFloat(float nbr, bool pos) {
	if (pos)
		std::cout << "Float: impossible" << std::endl;
	else {
		std::cout << "Float: " << std::fixed << nbr << "f" << std::endl;
	}
}

void	printDouble(double nbr, bool pos) {
	if (pos)
		std::cout << "Double: impossible" << std::endl;
	else
		std::cout << "Double: " << nbr << std::endl;
}

void	toChar(std::string param) {
	char c;

	c = param[0];
	std::cout << "'" << c << "'" << std::endl; 
	printChar(c, 0);
	printInt(static_cast<int>(c), 0);
	printFloat(static_cast<float>(c), 0);
	printDouble(static_cast<double>(c), 0);
}

void	toInt(std::string param) {
	std::istringstream ss(param);
	int	i;

	ss >> i;
	if (i >= 0 && i <= 255)
		printChar(static_cast<char>(i), 0);
	else
		printChar('x', 1);
	if (ss.fail())
		printInt(0, 1);
	else
		printInt(i, 0);
	ss.clear();
	ss.str(param);
	float f;
	ss >> f;
	if (ss.fail()) {
		printFloat(0.0, 1);
		printDouble(0, 1);
	}
	else {
		printFloat(f, 0);
		printDouble(static_cast<double>(f), 0);
	}
	ss.clear();
}

void	toFloat(std::string param) {
	std::istringstream ss(param);
	float	f;

	ss >> f;
	if (f >= 0 && f <= 255)
		printChar(static_cast<char>(f), 0);
	else
		printChar('x', 1);
	if (ss.fail()) {
		printInt(0, 1);
		printFloat(0, 1);
		printDouble(0, 1);
	}
	else {
		printInt(static_cast<int>(f), 0);
		printFloat(static_cast<float>(f), 0);
		printDouble(static_cast<double>(f), 0);
	}
	ss.clear();
}

void	toDouble(std::string param) {
	std::istringstream ss(param);
	std::istringstream ss1(param);
	double	d;
	int i;

	ss >> d;
	if (d >= 0 && d <= 255)
		printChar(static_cast<char>(d), 0);
	else
		printChar('x', 1);
	ss1 >> i;
	if (ss1.fail())
		printInt(0, 1);
	else
		printInt(static_cast<int>(i), 0);
	if (ss.fail()) {
		printFloat(0, 1);
		printDouble(0, 1);
	}
	else {
		printFloat(static_cast<float>(d), 0);
		printDouble(d, 0);
	}
	ss.clear();
}

void	toPseudoLiteral(std::string param, int i) {
	printChar('x', 1);
	printInt(1, 1);
	if (i == 5) {
		std::cout << "Float: " << param << std::endl;
		std::cout << "Double: " << param.substr(0, param.length() - 1) << std::endl;
	}
	else if (i == 6) {
		std::cout << "Float: " << param + "f" << std::endl;
		std::cout << "Double: " << param << std::endl;
	}
}

void	convertType(std::string param) {
	int i = detectType(param);
	if (i == 5 || i == 6) {
		toPseudoLiteral(param, i);
		return ;
	}
	switch (i)
	{
		case 1:
			std::cout << param << " is a char" << std::endl;
			toChar(param);
			break;
		case 2:
			std::cout << param << " is a int" << std::endl;
			toInt(param);
			break;
		case 3:
			std::cout << param << " is a float" << std::endl;
			toFloat(param);
			break;
		case 4:
			std::cout << param << " is a double" << std::endl;
			toDouble(param);
			break;
		default:
			std::cout << "A problem has occured" << std::endl;
			return;
	}
}

void	ScalarConverter::convert(std::string param) {
	if (parse_literal(param)) {
		std::cout << param << " is good!" << std::endl;
	}
	else {
		std::cout << param << " is not good" << std::endl;
		return ;
	}

	convertType(param);
}
