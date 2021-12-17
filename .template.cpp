#include "___HEADER_NAME___"

bool	___CLASS_NAME___::_verbose = false;

___CLASS_NAME___::___CLASS_NAME___( void )
{
	if (___CLASS_NAME___::_verbose)
		std::cout << COL_YELLOW << "[___CLASS_NAME___] - Default constructor called" << COL_NORMAL <<std::endl;

	return;
}

___CLASS_NAME___::~___CLASS_NAME___( void )
{
	if (___CLASS_NAME___::_verbose)
		std::cout << COL_YELLOW << "[___CLASS_NAME___] - Destructor called" << COL_NORMAL <<std::endl;

	return;
}

___CLASS_NAME___::___CLASS_NAME___( ___CLASS_NAME___ const & src )
{
	if (___CLASS_NAME___::_verbose)
		std::cout << COL_YELLOW << "[___CLASS_NAME___] - Copy constructor called" << COL_NORMAL <<std::endl;
	*this = src;

	return;
}

___CLASS_NAME___ &	___CLASS_NAME___::operator=( ___CLASS_NAME___ const & rhs )
{
	if (___CLASS_NAME___::_verbose)
		std::cout << COL_YELLOW << "[___CLASS_NAME___] - Assignation operator called" << COL_NORMAL <<std::endl;

	if ( this != &rhs )
		this->VAR_TO_COPY = rhs.getVAR_TO_COPY();
	
	return *this;
}

void	___CLASS_NAME___::set_verbose( bool status )
{
	if (___CLASS_NAME___::_verbose)
		std::cout << COL_YELLOW << "[___CLASS_NAME___] - Set _verbose to [" << COL_GREEN << status << COL_YELLOW << "]" << COL_NORMAL <<std::endl;

	___CLASS_NAME___::_verbose = status;

	return;
}

bool	___CLASS_NAME___::get_verbose( void )
{
	if (___CLASS_NAME___::_verbose)
		std::cout << COL_YELLOW << "[___CLASS_NAME___] - Get _verbose" << COL_NORMAL <<std::endl;

	return (___CLASS_NAME___::_verbose);
}
