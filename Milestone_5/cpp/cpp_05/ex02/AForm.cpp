/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:55:34 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 11:29:00 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name ("name_placeholder"), grade_to_sign (1), grade_to_execute (1)
{
    is_signed = false;
}

AForm::AForm(AForm &f) : name (f.name), grade_to_sign (f.grade_to_sign), grade_to_execute (f.grade_to_execute)
{
    is_signed = f.is_signed;
}

AForm::AForm(std::string n, int gs, int ge) : name (n), grade_to_sign(gs), grade_to_execute(ge)
{
    if (gs > 150)
        throw AForm::GradeTooLowException();
    if (gs < 1)
        throw AForm::GradeTooHighException();
    if (ge > 150)
        throw AForm::GradeTooLowException();
    if (ge < 1)
        throw AForm::GradeTooLowException();
    is_signed = false;
}

AForm &AForm::operator = (AForm const &value)
{
	if (this == &value)
		return (*this);
	is_signed = value.is_signed;
	return (*this);    
}

AForm::~AForm()
{
    
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getStatus() const
{
    return is_signed;
}

int AForm::getGradeToSign() const
{
    return grade_to_sign;
}

int	AForm::getGradeToExecute() const
{
    return grade_to_execute;
}

void AForm::beSigned(Bureaucrat b)
{
    if (b.getGrade() <= getGradeToSign())
        is_signed = true;
    else
        throw AForm::GradeTooLowException();        
}

std::ostream &operator << (std::ostream &os, const AForm &f)
{
	os  << "Form: "  << f.getName() 
        << "\nSigned: " << f.getStatus()
        << "\nGrade required to sign: " << f.getGradeToSign()
        << "\nGrade required to execute: " << f.getGradeToExecute();
	return (os);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}