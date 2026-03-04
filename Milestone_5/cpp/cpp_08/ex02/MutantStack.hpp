/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:07:54 by yoherfan          #+#    #+#             */
/*   Updated: 2026/01/14 11:04:37 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <iterator>
#include <list>

template <typename T> class MutantStack : public std::stack<T>
{
	public:
	
	MutantStack();
	MutantStack(MutantStack &value);
	MutantStack &operator = (MutantStack const &value);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

#endif