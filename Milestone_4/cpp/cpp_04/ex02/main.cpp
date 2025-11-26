/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:48 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 15:01:00 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    int     i = -1;
    Animal  *animals[10];

    while(++i < 5)
        animals[i] = new Dog();
    i--;
    while(++i < 10)
        animals[i] = new Cat();
    i = -1;
    while (++i < 10)
        delete(animals[i]);
    return 0;
}
