/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .template.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:30:35 by csejault          #+#    #+#             */
/*   Updated: 2022/01/11 18:33:39 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//Class_Name = ___CLASS_NAME___

#include "___HEADER_NAME___"

//debug{
//priv_debug{
bool	___CLASS_NAME___::_verbose = true;
//priv_debug - END}

//pub_debug{
void	___CLASS_NAME___::set_verbose( bool status ) {
	if (___CLASS_NAME___::_verbose) std::cout << COL_YELLOW << "[___CLASS_NAME___] - Set _verbose to [" << COL_GREEN << status << COL_YELLOW << "]" << COL_NORMAL <<std::endl;
	___CLASS_NAME___::_verbose = status;
}

bool	___CLASS_NAME___::get_verbose( void ) {
	if (___CLASS_NAME___::_verbose) std::cout << COL_YELLOW << "[___CLASS_NAME___] - Get _verbose" << COL_NORMAL <<std::endl;
	return (___CLASS_NAME___::_verbose);
}
//pub_debug - END}
//debug - END}


//pub_constructor{
___CLASS_NAME___::___CLASS_NAME___( void ) {
	if (___CLASS_NAME___::_verbose) std::cout << COL_YELLOW << "[___CLASS_NAME___] - Default constructor called" << COL_NORMAL <<std::endl;
}

___CLASS_NAME___::~___CLASS_NAME___( void ) {
	if (___CLASS_NAME___::_verbose) std::cout << COL_YELLOW << "[___CLASS_NAME___] - Destructor called" << COL_NORMAL <<std::endl;
}

___CLASS_NAME___::___CLASS_NAME___( ___CLASS_NAME___ const & src ) {
	if (___CLASS_NAME___::_verbose)std::cout << COL_YELLOW << "[___CLASS_NAME___] - Copy constructor called" << COL_NORMAL <<std::endl;
	*this = src;
}

___CLASS_NAME___ &	___CLASS_NAME___::operator=( ___CLASS_NAME___ const & rhs ) {
	if (___CLASS_NAME___::_verbose) std::cout << COL_YELLOW << "[___CLASS_NAME___] - Assignation operator called" << COL_NORMAL <<std::endl;

	if ( this != &rhs )
	{
		this->VAR_TO_COPY = rhs.getVAR_TO_COPY();
	}
	return *this;
}
//pub_constructor - END}

//pub_getter{

//pub_getter - END}

//pub_setter{

//pub_setter - END}

//priv_constructor{

//priv_constructor - END}

