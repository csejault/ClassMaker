/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMaker.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:49:32 by csejault          #+#    #+#             */
/*   Updated: 2022/01/03 12:39:08 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassMaker.hpp"
ClassMaker::ClassMaker( std::string input) : _class_name(input)
{
	std::cout << COL_YELLOW;
	std::cout << "++++++++++++++++++++++++++++++++++++++" <<std::endl;
	std::cout << "+=====  WELCOME TO CLASS MAKER  =====+" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++" <<std::endl;
	std::cout << COL_NORMAL;
	this->_template_hpp_loc = std::string(PROGRAM_DIR).append("/").append(TEMPLATE_HPP);
	this->_template_cpp_loc = std::string(PROGRAM_DIR).append("/").append(TEMPLATE_CPP);
	this->_hpp_file_name = this->_class_name + std::string(HPP_EXT);
	this->_cpp_file_name = this->_class_name + std::string(CPP_EXT);
	if (this->print_info())
		return;
	else if (this->create_content_hpp())
		return;
	else if (this->create_file_from_content(this->_hpp_file_name, _content_hpp))
		return;
	else if (this->create_content_cpp())
		return;
	else if (this->create_file_from_content(this->_cpp_file_name, _content_cpp))
		return;
	return;
}

ClassMaker::ClassMaker( void )
{
	std::cout << COL_YELLOW;
	std::cout << "++++++++++++++++++++++++++++++++++++++" <<std::endl;
	std::cout << "+=====  WELCOME TO CLASS MAKER  =====+" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++" <<std::endl;
	std::cout << COL_NORMAL;
	this->_template_hpp_loc = std::string(PROGRAM_DIR).append("/").append(TEMPLATE_HPP);
	this->_template_cpp_loc = std::string(PROGRAM_DIR).append("/").append(TEMPLATE_CPP);
	if (this->ask_info())
		return;
	this->_hpp_file_name = this->_class_name + std::string(HPP_EXT);
	this->_cpp_file_name = this->_class_name + std::string(CPP_EXT);
	if (this->print_info())
		return;
	else if (this->create_content_hpp())
		return;
	else if (this->create_file_from_content(this->_hpp_file_name, _content_hpp))
		return;
	else if (this->create_content_cpp())
		return;
	else if (this->create_file_from_content(this->_cpp_file_name, _content_cpp))
		return;
	return;
}

ClassMaker::~ClassMaker( void )
{
	return;
}

int		ClassMaker::ask_info( void )
{
	std::cout << "Class name : ";
	std::cin >> this->_class_name;

	return (0);
}

int		ClassMaker::print_info( void ) const
{
	std::string input;
	std::cout << std::endl;
	std::cout << "====== INFO ======" << std::endl;
	std::cout << COL_RED << "This program will create cpp/hpp file based on these infos:" << COL_NORMAL << std::endl;

	std::cout << COL_YELLOW;
	std::cout << "Class name = " << this->_class_name << std::endl;
	std::cout << "Hpp file name = " << this->_hpp_file_name << std::endl;
	std::cout << "Cpp file name = " << this->_cpp_file_name << std::endl;
	std::cout << "Template hpp loc = " << this->_template_hpp_loc << std::endl;
	std::cout << "Template cpp loc = " << this->_template_cpp_loc << std::endl;
	std::cout << COL_NORMAL;

	std::cout << COL_RED << "Continue? y/n" << COL_NORMAL << std::endl;
	std::cin >> input;
	if (input.compare("y"))
		return(1);

	return (0);
}

int		ClassMaker::create_define_protect( void )
{
	std::string::size_type	pos = 0;
	std::stringstream ss;

	for (std::string::size_type i = 0; i < this->_hpp_file_name.size(); i++)
		ss.put(toupper(this->_hpp_file_name[i]));
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

int		ClassMaker::replace_field(std::string &buff, std::string to_find, std::string new_str) const
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
	std::cout << "Opening template : [" << COL_YELLOW << this->_template_hpp_loc << COL_NORMAL << "] - ";
	std::ifstream template_hpp(this->_template_hpp_loc.c_str());
	if (template_hpp.fail())
	{
		std::cout << "[" << COL_RED << "FAILLED"  << COL_NORMAL <<  "]" << std::endl;
		return (1);
	}
	else
		std::cout << "[" << COL_GREEN << "SUCCESS"  << COL_NORMAL <<  "]" << std::endl;

	std::stringstream ss;
	ss << template_hpp.rdbuf();
	this->_content_hpp = ss.str();

	//FILL TEMPLATE FIELD
	create_define_protect();
	replace_field(this->_content_hpp, DEFINE_PROTECT, _define_protect);
	replace_field(this->_content_hpp, CLASS_NAME, _class_name);
	replace_field(this->_content_cpp, TEMPLATE_HPP, _hpp_file_name);
	std::cout << "Content created with - [" << COL_GREEN << "SUCCESS"  << COL_NORMAL <<  "]" << std::endl;
	return (0);
}

int		ClassMaker::create_content_cpp( void )
{
	//PRINT INFO
	std::cout << std::endl << "====== CREATING CONTENT CPP ======" << std::endl;

	//READ - CONVERT template_hpp INTO string PREVIEW
	std::cout << "Opening template : [" << COL_YELLOW << this->_template_cpp_loc << COL_NORMAL << "] - ";
	std::ifstream template_cpp(this->_template_cpp_loc.c_str());
	if (template_cpp.fail())
	{
		std::cout << "[" << COL_RED << "FAILLED"  << COL_NORMAL <<  "]" << std::endl;
		return (1);
	}
	else
		std::cout << "[" << COL_GREEN << "SUCCESS"  << COL_NORMAL <<  "]" << std::endl;
	std::stringstream ss;
	ss << template_cpp.rdbuf();
	this->_content_cpp = ss.str();

	//FILL TEMPLATE FIELD
	replace_field(this->_content_cpp, HEADER_NAME, _hpp_file_name);
	replace_field(this->_content_cpp, TEMPLATE_HPP, _hpp_file_name);
	replace_field(this->_content_cpp, TEMPLATE_CPP, _cpp_file_name);
	replace_field(this->_content_cpp, CLASS_NAME, _class_name);
	std::cout << "Content created with - [" << COL_GREEN << "SUCCESS"  << COL_NORMAL <<  "]" << std::endl;
	return (0);
}

int		ClassMaker::create_file_from_content(std::string name, std::string & content) const
{
	std::cout << std::endl << "====== PREVIEW CONTENT FOR [" << COL_YELLOW <<  name << COL_NORMAL << "] ======" << std::endl;

	//PRINT PREVIEW
	std::cout << COL_YELLOW << content << COL_NORMAL << std::endl;

	//HUMAN CHECK if data is GOOD
	std::cout << COL_RED << "IS [" << name << "] OK FOR CREATION? y/n : " << COL_NORMAL;
	std::string	input;
	std::cin >> input;

	//IF GOOD CREATE FILE
	if (!input.compare("y"))
	{
		std::cout << "Creating: [" << COL_YELLOW << name << COL_NORMAL << "] - ";
		//CHECK if EXIST
		std::ifstream check_if_exit;
		check_if_exit.open(name.c_str());
		if(check_if_exit) 
		{
			std::cout << "[" << COL_RED << "FAILLED"  << COL_NORMAL <<  "] - File already exit. Please remove it manualy." << std::endl;
			check_if_exit.close();
			return (1);
		}
		std::ofstream ofs(name.c_str());
		if (ofs.fail())
		{
			std::cout << "[" << COL_RED << "FAILLED"  << COL_NORMAL <<  "]" << std::endl;
			return (1);
		}
		ofs << content;
		ofs.close();
		std::cout << "[" << COL_GREEN << "SUCCESS"  << COL_NORMAL <<  "]" << std::endl;
		return (0);
	}
	//ELSE CONTINUE
	std::cout << "[" << COL_YELLOW << name << COL_NORMAL << "] has not been created." << std::endl;
	return (0);
}
