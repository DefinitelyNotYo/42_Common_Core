/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:01 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 10:35:39 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	
}

Base *generate(void)
{
	int r = rand() % 3;
	Base *b;
	if (r == 0)
		b = new A();
	if (r == 1)
		b = new B();
	if (r == 2)
		b = new C();
	return (b);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "object of type A pointed\n";
	if (b)
		std::cout << "object of type B pointed\n";
	if (c)
		std::cout << "object of type C pointed\n";
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "object of type A pointed\n";
	}
	catch(const std::exception& e)
	{

	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "object of type B pointed\n";
	}
	catch(const std::exception& e)
	{

	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "object of type C pointed\n";
	}
	catch(const std::exception& e)
	{

	}
}