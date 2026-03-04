/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:47:37 by yoherfan          #+#    #+#             */
/*   Updated: 2026/01/14 11:06:38 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    int i = 0;
    i = 0;
    while (it != ite)
    {
        std::cout << "index " << i << ": ";
        std::cout << *it << std::endl;
        ++it;
        i++;
    }
    // std::cout << "\nelement on top: " << mstack.top() << std::endl << std::endl;
    std::stack<int> s(mstack);
    return 0;
}
