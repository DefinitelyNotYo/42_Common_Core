/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:54:54 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 15:27:34 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    
}

Intern::Intern(Intern &i)
{
    (void)i;
}

Intern &Intern::operator = (Intern const &value)
{
    (void)value;
    return(*this);
}

Intern::~Intern()
{
    
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    AForm *f;
    
    if (form_name != "presidential pardon" && form_name != "robotomy request" && form_name != "shrubbery creation")
        throw Intern::InvalidForm();
    int len = form_name.length();
    switch(len)
    {
        case 19:
            f = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << *f;
            return (f);
            break;
        case 16:
            f = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << *f;
            return (f);
            break;
        case 18:
            f = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << *f;
            return (f);
            break;
    }
    return (NULL);
}

const char *Intern::InvalidForm::what() const throw()
{
	return ("Error: form not found\n");
}