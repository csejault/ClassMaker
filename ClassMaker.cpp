/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMaker.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:49:32 by csejault          #+#    #+#             */
/*   Updated: 2021/12/15 15:35:51 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassMaker.hpp"

ClassMaker::ClassMaker( void )
{
	this->ask_info();
	this->print_info();
	this->create_hpp();
	return;
}

ClassMaker::~ClassMaker( void )
{
	return;
}

int		ClassMaker::print_info( void ) const
{
	std::cout << std::endl;
	std::cout << "====== PRINT INFO ======" << std::endl;
	std::cout << "File name = " << this->_file_name << std::endl;
	std::cout << "Class name = " << this->_class_name << std::endl;
	return (0);
}

int		ClassMaker::ask_info( void )
{
	std::cout << "Filename without extention : ";
	std::cin >> this->_file_name; 

	std::cout << "Class name : ";
	std::cin >> this->_class_name;

	return (0);
}

int		ClassMaker::create_define_protect( void )
{
	std::string::size_type	pos = 0;
	std::stringstream ss;

	for (std::string::size_type i = 0; i < this->_file_name.size(); i++)
		ss.put(toupper(this->_file_name[i]));
	for (std::string::size_type i = 0; i < std::string(HPP_EXT).size(); i++)
		ss.put(toupper(std::string(HPP_EXT)[i]));
	this->_define_protect = ss.str();
	pos = this->_define_protect.find(".");
	while (pos!= std::string::npos)
	{
		this->_define_protect.erase(pos, 1);
		this->_define_protect.insert(pos, "_");
		pos = this->_define_protect.find(".");
	}
	return (0);
}

int		ClassMaker::create_hpp( void )
{
	std::string	input;
	std::stringstream ss;

	std::cout << std::endl;
	std::cout << "====== CREATING HPP ======" << std::endl;
	std::cout << "PREVIEW HPP FILE:" << std::endl;
	create_define_protect();
	ss << "#ifndef "<< this->_define_protect;
	std::cout << std::endl;
	//HUMAN CHECK if DATA IS ALL GOOD
	std::cout << "IS HPP FILE OK? Y/N : ";
	std::cout << ss.str() << std::endl;
	std::cin >> input;
	//IF Y create file _class_name.HPP_EXT
	if (!input.compare("Y"))
	{
		std::ofstream ofs((this->_file_name.append(HPP_EXT)).c_str());
		ofs << ss.str();
		ofs.close();
	}
	else
	{
		std::cout << "!!! NOK !!!" << std::endl;
		return (1);
	}
	return (0);
}
