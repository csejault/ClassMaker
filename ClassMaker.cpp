/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMaker.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:49:32 by csejault          #+#    #+#             */
/*   Updated: 2021/12/16 13:10:44 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassMaker.hpp"
ClassMaker::ClassMaker( void )
{
	this->ask_info();
	this->print_info();
	this->create_content_hpp();
	this->create_file_from_content(this->_file_name.append(HPP_EXT), _content_hpp);
	this->create_content_cpp();
	this->create_file_from_content(this->_file_name.append(CPP_EXT), _content_cpp);
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

	std::cout << COL_YELLOW;
	std::cout << "File name = " << this->_file_name << std::endl;
	std::cout << "Class name = " << this->_class_name << std::endl;
	std::cout << COL_NORMAL;
	return (0);
}

int		ClassMaker::ask_info( void )
{
	std::cout << "====== ASKING INFO ======" << std::endl;
	std::cout << "File name without extention : ";
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

int		ClassMaker::replace_field(std::string &buff, std::string to_find, std::string new_str)
{
	size_t idx = 0;
	idx = buff.find(to_find);
	while ( idx != std::string::npos)
	{
		buff.replace(idx, to_find.size(), new_str);
		idx = buff.find(to_find);
	}
	return (0);
}


int		ClassMaker::create_content_hpp( void )
{
	//PRINT INFO
	std::cout << std::endl << "====== CREATING CONTENT HPP ======" << std::endl;

	//READ - CONVERT template_hpp INTO string PREVIEW
	std::ifstream template_hpp(TEMPLATE_HPP);
	std::stringstream ss;
   	ss << template_hpp.rdbuf();
	this->_content_hpp = ss.str();

	//FILL TEMPLATE FIELD
	create_define_protect();
	replace_field(this->_content_hpp, DEFINE_PROTECT, _define_protect);
	replace_field(this->_content_hpp, CLASS_NAME, _class_name);
	std::cout << "[" << COL_GREEN << "SUCCESS"  << COL_NORMAL <<  "]" << std::endl;
	return (0);
}

int		ClassMaker::create_content_cpp( void )
{
	//PRINT INFO
	std::cout << std::endl << "====== CREATING CONTENT CPP ======" << std::endl;

	//READ - CONVERT template_hpp INTO string PREVIEW
	std::ifstream template_cpp(TEMPLATE_CPP);
	std::stringstream ss;
   	ss << template_cpp.rdbuf();
	this->_content_cpp = ss.str();

	//FILL TEMPLATE FIELD
	replace_field(this->_content_cpp, HEADER_NAME, _file_name.append(HPP_EXT));
	std::cout << "[" << COL_GREEN << "SUCCESS"  << COL_NORMAL <<  "]" << std::endl;
	return (0);
}

int		ClassMaker::create_file_from_content(std::string & name, std::string & content)
{
	std::cout << std::endl << "====== PREVIEW CONTENT FOR [" << COL_YELLOW <<  name << COL_NORMAL << "] ======" << std::endl;

	//PRINT PREVIEW
	std::cout << COL_YELLOW << content << COL_NORMAL << std::endl;

	//HUMAN CHECK if data is GOOD
	std::cout << COL_RED << "IS [" << name << "] OK FOR CREATION? Y/N : " << COL_NORMAL;
	std::string	input;
	std::cin >> input;

	//IF GOOD CREATE FILE
	if (!input.compare("Y"))
	{
		std::ofstream ofs(name.c_str());
		ofs << content;
		ofs.close();
	}
	else {std::cout << "!!! NOK !!!" << std::endl; return (1);}
	return (0);
}
