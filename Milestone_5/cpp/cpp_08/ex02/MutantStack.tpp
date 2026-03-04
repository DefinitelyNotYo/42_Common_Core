/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:29:17 by yoherfan          #+#    #+#             */
/*   Updated: 2026/01/14 10:13:52 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T> MutantStack<T>::MutantStack()
{
    
}

template<typename T> MutantStack<T>::MutantStack(MutantStack &value) : std::stack<T>(value)
{
    
}

template<typename T> MutantStack<T> &MutantStack<T>::operator = (MutantStack const &value)
{
    if (*this != value)
        std::stack<T>::operator=(value);
    return (*this);
}

template<typename T> MutantStack<T>::~MutantStack()
{
    
}

template<typename T> typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template<typename T> typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}

#endif