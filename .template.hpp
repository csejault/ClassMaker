/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .template.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:50:03 by csejault          #+#    #+#             */
/*   Updated: 2022/01/03 12:50:30 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

#ifndef ___DEFINE_PROTECT___
# define ___DEFINE_PROTECT___

# ifndef COL_GREEN
#  define COL_GREEN 		"\033[0;32m"
# endif
# ifndef COL_RED
#  define COL_RED		"\033[0;31m"
# endif
# ifndef COL_YELLOW
#  define COL_YELLOW		"\033[0;33m"
# endif
# ifndef COL_NORMAL
#  define COL_NORMAL		"\033[0m"
# endif

# include <iostream>

class	___CLASS_NAME___ {

	public:
		___CLASS_NAME___( void );
		___CLASS_NAME___( ___CLASS_NAME___ const & src );
		___CLASS_NAME___ &	operator=( ___CLASS_NAME___ const & rhs );
		~___CLASS_NAME___( void );
		static bool	get_verbose( void );
		static void	set_verbose( bool status );

	private:
		static bool _verbose;

};

#endif
