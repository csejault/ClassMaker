/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMaker.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:47:09 by csejault          #+#    #+#             */
/*   Updated: 2021/12/15 15:24:30 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSMAKER_HPP
# define CLASSMAKER_HPP
# define HPP_EXT ".class.hpp"

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class	ClassMaker
{
	public:
		ClassMaker( void );
		~ClassMaker( void );
		int		ask_info( void );
		int		print_info( void ) const;
		int		create_hpp( void );
		int		create_define_protect( void );

	private:
		std::string	_file_name;
		std::string	_class_name;
		std::string	_define_protect;
};

#endif
