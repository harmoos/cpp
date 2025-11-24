/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:13:59 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 22:50:36 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called with target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
	this->target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	std::ofstream	file;
	std::string filename = target;
	
	file.open(filename.append("_shrubbery").c_str(), std::ios::out);
	if (file.fail()) {
		std::cout << "File " << filename.append("_shrubbery") << " couldn't be open" << std::endl;
		return ;
	}
	
	file << "          &&& &&  & &&" << std::endl <<
	"      && &\'/&\'|& ()|/ @, &&" << std::endl <<
	"      &\'/'(/&/&||/& /_/)_&/_&" << std::endl <<
	"   &() &\'/&|()|/&\'/ % & ()"  << std::endl <<
	"  &_\'_&&_\' |& |&&/&__%_/_& &&"  << std::endl <<
	"&&   && & &| &| /& & % ()& /&&" << std::endl <<
	" ()&_---()&\'&'\'|'&&-&&--%---()~"  << std::endl <<
	"     &&     \'|||'"  << std::endl <<
	"            \'|||'"  << std::endl <<
	"            \'|||'" << std::endl <<
	"            \'|||'"  << std::endl <<
	"       , -=-~  .-^- _"  << std::endl;
	file.close();
	std::cout << "The form " << this->getName() << " was execute by " << executor.getName() << std::endl;
}