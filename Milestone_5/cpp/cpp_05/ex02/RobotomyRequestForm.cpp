/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:59:47 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 14:52:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45)
{
    _target = "NULL";
}
    
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &f) : AForm(f)
{
    _target = f._target;
    *this = f;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45)
{
    _target = target; 
}
RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &value)
{
	if (this == &value)
		return (*this);
	_target = value._target;
	return (*this);    
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (getStatus() == true && executor.getGrade() <= getGradeToExecute())
    {
        int r = rand() % 2;
        if (r)
            std::cout << "*drill* *drill* *drill*\n" << _target << " has been robotomized successfully\n";
        else
            std::cout << "*drill* *drill* *drill*\n" << _target << " robotomy failed\n";             
    }
    else
        throw RobotomyRequestForm::InvalidExecuteRequest();
}

const char *RobotomyRequestForm::InvalidExecuteRequest::what() const throw()
{
	return ("Invalid request for execute Shrubbery Creation Form\n");
}