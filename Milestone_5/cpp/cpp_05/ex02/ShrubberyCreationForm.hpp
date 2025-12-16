/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:59:54 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 13:31:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:

    std::string _target;
    
    public:
    
    ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm &f);
    ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm &operator = (ShrubberyCreationForm const &value);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;

	class InvalidExecuteRequest : public std::exception
	{
		public:
		
		const char *what() const throw();
	};
};

#endif