/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:19:26 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/31 20:39:58 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_HPP
# define FILEREPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class	FileReplace {
	private:
		std::string	filename;
		std::string	s1;
		std::string	s2;
		std::ofstream	outfile;
	public:
		FileReplace(std::string filename, std::string s1, std::string s2);
		int	readFile();
		int	createFile();
		std::string	replaceString(std::string line);
		void	writeFile(std::string& line);			
};

#endif
