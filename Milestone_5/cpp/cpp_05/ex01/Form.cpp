/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:55:34 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 10:40:12 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name ("name_placeholder"), grade_to_sign (1), grade_to_execute (1)
{
    is_signed = false;
}

Form::Form(std::string n, int gs, int ge) : name (n), grade_to_sign(gs), grade_to_execute(ge)
{
    if (gs > 150)
        throw Form::GradeTooLowException();
    if (gs < 1)
        throw Form::GradeTooHighException();
    if (ge > 150)
        throw Form::GradeTooLowException();
    if (ge < 1)
        throw Form::GradeTooLowException();
    is_signed = false;
}

Form::Form(Form &f) : name (f.name), grade_to_sign (f.grade_to_sign), grade_to_execute (f.grade_to_execute)
{
    is_signed = f.is_signed;
}

Form &Form::operator = (Form const &value)
{
	if (this == &value)
		return (*this);
	is_signed = value.is_signed;
	return (*this);    
}

Form::~Form()
{
    
}

std::string Form::getName() const
{
    return name;
}

bool Form::getStatus() const
{
    return is_signed;
}

int Form::getGradeToSign() const
{
    return grade_to_sign;
}

int	Form::getGradeToExecute() const
{
    return grade_to_execute;
}

void Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() <= getGradeToSign())
        is_signed = true;
    else
        throw Form::GradeTooLowException();        
}

std::ostream &operator << (std::ostream &os, const Form &f)
{
	os  << "Form: "  << f.getName() 
        << "\nSigned: " << f.getStatus()
        << "\nGrade required to sign: " << f.getGradeToSign()
        << "\nGrade required to execute: " << f.getGradeToExecute();
	return (os);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}