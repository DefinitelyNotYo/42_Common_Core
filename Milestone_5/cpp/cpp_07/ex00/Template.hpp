/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:19:39 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/17 15:54:24 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template <typename T> void swap(T x, T y)
{
    T n = x;
    x = y;
    y = n;
}

template <typename T> T max(T x, T y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

template <typename T> T min (T x, T y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

#endif