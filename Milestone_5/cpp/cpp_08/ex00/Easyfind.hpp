/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:19:39 by yoherfan          #+#    #+#             */
/*   Updated: 2026/01/12 10:37:06 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

template <typename T> typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), n);

    if (it == container.end())
    {
        std::cout << "No occurrence of " << n << " found" << std::endl;
        return (container.begin() - 1);        
    }
    std::cout << "First occurrence of " << n << " found at index "
              << std::distance(container.begin(), it) << std::endl;
    return (it);
}

#endif