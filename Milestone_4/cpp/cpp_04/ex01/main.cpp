/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:48 by yoherfan          #+#    #+#             */
/*   Updated: 2026/01/14 16:24:12 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    // int     i = -1;
    // Animal  *animals[10];

    // while(++i < 5)
    //     animals[i] = new Dog();
    // i--;
    // while(++i < 10)
    //     animals[i] = new Cat();
    // i = -1;
    // while (++i < 10)
    //     delete(animals[i]);
    // return 0;
    // Dog b;
    // Dog d(b);
    // Animal *c = new Dog(b);
    
    // b.name = "ciao";
    // (*c).name = "casa";
    // d.name = "D";
    // std::cout << b.name << std::endl << (*c).name << std::endl
    //           << d.name << std::endl << b.name << std::endl;
    // (void)c;
    Dog *b = new Dog();
    Dog c = *b;
    Dog d = c;
    // d = *b;
    (void) b;
    // (void) d;
}