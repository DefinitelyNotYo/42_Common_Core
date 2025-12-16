/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:59:51 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 14:53:21 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137)
{
    _target = "NULL";
}
    
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &f) : AForm(f)
{
    _target = f._target;
    *this = f;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137)
{
    _target = target; 
}
ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm const &value)
{
	if (this == &value)
		return (*this);
	_target = value._target;
	return (*this);    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (getStatus() == true && executor.getGrade() <= getGradeToExecute())
    {
        std::fstream file;
        file.open((_target + "_shrubbery").c_str(), std::ios::out);
        if (!file)
        {
            std::cout << "file creation failed\n";
            return ;
        }
        file << "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n";
        file.close();
    }
    else
        throw ShrubberyCreationForm::InvalidExecuteRequest();
}

const char *ShrubberyCreationForm::InvalidExecuteRequest::what() const throw()
{
	return ("Invalid request for execute Shrubbery Creation Form\n");
}