/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:59:44 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 12:09:51 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:

    std::string _target;
    
    public:
    
    PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm &f);
    PresidentialPardonForm(std::string target);
	PresidentialPardonForm &operator = (PresidentialPardonForm const &value);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;

	class InvalidExecuteRequest : public std::exception
	{
		public:
		
		const char *what() const throw();
	};
};

#endif