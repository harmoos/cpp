/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:19:36 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 17:33:11 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"

FileReplace::FileReplace(std::string filename, std::string s1, std::string s2) : filename(filename), s1(s1), s2(s2) {}

void	FileReplace::writeFile(std::string& line) {
	outfile << line << std::endl;
}

std::string	FileReplace::replaceString(std::string line) {
	size_t	pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos += s2.length();
	}
	return (line);	
}

int	FileReplace::readFile() {
	std::string line;
	std::ifstream	infile;

	infile.open(filename.c_str(), std::ios::in);
	if (infile.fail()) {
		std::cout << "infile couldn't be open" << std::endl;
		return (1); 
	}
	if (createFile() != 0) {
		infile.close();
		return (1);
	}
	while (std::getline(infile, line)) {
		line = replaceString(line);
		FileReplace::writeFile(line);
	}
	infile.close();
	outfile.close();
	std::cout << "replacement done! Created file: " << filename << ".replace" << std::endl;
	return (0);
}

int	FileReplace::createFile() {
	std::string		outfile_name;

	outfile_name = filename;
	outfile_name.append(".replace");
	outfile.open(outfile_name.c_str(), std::ios::out);
	if (outfile.fail()) {
		std::cout << "outfile couldn't be open" << std::endl;
		return (1);
	}
	return (0);
}
