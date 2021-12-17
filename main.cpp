/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:31:31 by csejault          #+#    #+#             */
/*   Updated: 2021/12/17 13:11:08 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClassMaker.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		ClassMaker cm;
	else if (ac == 2)
		ClassMaker cm(av[1]);
	else
		std::cout << "please enter o or 1 args(class_name)" << std::endl;
	return (0);
}
