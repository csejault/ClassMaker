/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMaker.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:47:09 by csejault          #+#    #+#             */
/*   Updated: 2021/12/17 13:08:08 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// cout << "\033[1;31mbold red text\033[0m\n";
//
//Here, \033 is the ESC character, ASCII 27. It is followed by [, then zero or more numbers separated by ;
//, and finally the letter m. The numbers describe the colour and format to switch to from that point onwards.
//
//The codes for foreground and background colours are:
//
//         foreground background
//black        30         40
//red          31         41
//green        32         42
//yellow       33         43
//blue         34         44
//magenta      35         45
//cyan         36         46
//white        37         47

#ifndef CLASSMAKER_HPP
# define CLASSMAKER_HPP
# define PROGRAM_DIR	"/sgoinfre/goinfre/Perso/csejault/ClassMaker"
# define COL_GREEN 		"\033[0;32m"
# define COL_RED		"\033[0;31m"
# define COL_YELLOW		"\033[0;33m"
# define COL_NORMAL		"\033[0m"
# define HPP_EXT		".hpp"
# define CPP_EXT		".cpp"
# define TEMPLATE_HPP	".template.hpp"
# define TEMPLATE_CPP	".template.cpp"
# define DEFINE_PROTECT	"___DEFINE_PROTECT___"
# define CLASS_NAME		"___CLASS_NAME___"
# define HEADER_NAME	"___HEADER_NAME___"

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class	ClassMaker {

	public:
		ClassMaker( void );
		ClassMaker( std::string input );
		~ClassMaker( void );

		int			ask_info( void );
		int			print_info( void ) const;
		int			replace_field(std::string &buff, std::string to_find, std::string new_str) const;
		int			create_define_protect( void );
		int			create_content_hpp( void );
		int			create_content_cpp( void );
		int			create_file_from_content(std::string name, std::string & content) const;

	private:
		std::string	_class_name;

		std::string	_template_hpp_loc;
		std::string	_hpp_file_name;
		std::string	_define_protect;
		std::string	_content_hpp;
		
		std::string	_template_cpp_loc;
		std::string	_cpp_file_name;
		std::string	_content_cpp;
};

#endif
