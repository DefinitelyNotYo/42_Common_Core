/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:59:41 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 14:51:51 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5)
{
    _target = "NULL";
}
    
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &f) : AForm(f)
{
    _target = f._target;
    *this = f;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5)
{
    _target = target; 
}
PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &value)
{
	if (this == &value)
		return (*this);
	_target = value._target;
	return (*this);    
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (getStatus() == true && executor.getGrade() <= getGradeToExecute())
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
    else
        throw PresidentialPardonForm::InvalidExecuteRequest();
}

const char *PresidentialPardonForm::InvalidExecuteRequest::what() const throw()
{
	return ("Invalid request for execute Presidential Pardon Form\n");
}