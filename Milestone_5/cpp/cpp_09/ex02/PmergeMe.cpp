/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:42:56 by yoherfan          #+#    #+#             */
/*   Updated: 2026/02/11 17:10:28 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void insertNode(std::deque<unsigned int> *deq, unsigned int index, unsigned int n)
{
    std::deque<unsigned int>::iterator it_deq = (*deq).begin();
    std::deque<unsigned int>::iterator ite_deq = (*deq).end();
	unsigned int i = 0;
    while ((index != i) && it_deq != ite_deq)
	{
		i++;
        it_deq++;		
	}
	if (it_deq == ite_deq)
		return ;
	(*deq).insert(it_deq, n);
}

void binaryInsert(std::deque<unsigned int> *deq, unsigned int n, unsigned int min, unsigned int max)
{
    unsigned int len = max - min + 1;
    unsigned int index;
    
	if ((*deq)[0] >= n)
	{
		(*deq).push_front(n);
		return ;		
	}
	if (n > (*deq).at((*deq).size() - 1))
	{
		(*deq).push_back(n);
		return ;
	}
    index = (min + max) / 2;
    if (len == 1 || min >= max)
    {   
		if((*deq)[max] == n || (*deq)[max] > n)
            insertNode(deq, index, n);
    	else
		{
			if (index == (*deq).size() - 1)
				(*deq).push_back(n);
			else
            	insertNode(deq, index + 1, n);  			
		}        
    }
	// else if ((*deq)[index] == n)
	// 	insertNode(deq, index, n);
    else if ((*deq)[index] > n)
		binaryInsert(deq, n, min, index - 1);        
    else
		binaryInsert(deq, n, index + 1, max);     
}

std::deque<unsigned int> jacobsthalSeq(unsigned int dim)
{
	std::deque<unsigned int> deq;
	unsigned int n = 1;
	int i = 0;
	deq.push_back(n);
	n = 3;
	if (dim > 2)
		deq.push_back(n);		
	else
		return (deq);
	while(n < dim - 1)
	{
		n = n + deq.at(i) * 2;
		i++;
		deq.push_back(n);
	}		
	return (deq);
}

void showDq(std::deque<unsigned int> dq)
{
    std::deque<unsigned int>::iterator it;
    std::deque<unsigned int>::iterator ite;

	it = dq.begin();
	ite = dq.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++; 
	}
}

std::deque<unsigned int> pmerge_dq(std::deque<unsigned int> dq)
{
    std::deque<unsigned int> main;
    std::deque<unsigned int> pend;
    std::deque<unsigned int>::iterator it_1;
    std::deque<unsigned int>::iterator it_2;
    std::deque<unsigned int>::iterator ite;
    unsigned int extra;
    
    if(dq.size() == 1)
        return (dq);
    if (dq.size() % 2 == 1)
    {
        ite = dq.end();
        ite--;
        extra = *ite;
    }
	it_1 = dq.begin();
    it_2 = ++dq.begin();
    ite = dq.end();
    while (it_1 != ite && it_2 != ite)
    {
        if (*it_1 > *it_2)
        {
            main.push_back(*it_1++);
            it_2++;
        }
        else
        {
            main.push_back(*it_2++);
            it_1++;
        }
        it_1++;
        it_2++;
    }
	if (dq.size() != 2)
		main = pmerge_dq(main);
	it_1 = main.begin();
    ite = main.end();
	unsigned int i = 0;
	while(it_1 != ite)
	{
		it_2 = dq.begin();
		i = 0;
		while(*it_2 != *it_1)
		{
			it_2++;
			i++;			
		}
		if(i % 2 == 0)
			pend.push_back(dq.at(i + 1));
		else
			pend.push_back(dq.at(i - 1));
		it_1++;
	}
    if (dq.size() % 2 == 1)
		pend.push_back(extra);
    std::deque<unsigned int> jacob = jacobsthalSeq(pend.size());
	it_1 = jacob.begin();
    ite = jacob.end();
	if (pend.size() > 1)
	{
		binaryInsert(&main, pend.at(1), 0, 1);
	}
	binaryInsert(&main, pend.at(0), 0, 0);	
	it_1++;
	it_2 = it_1;
	it_1--;
	unsigned int step = 2;
	while(it_2 != ite)
	{
		i = *it_2;
		while (i > *it_1)
		{
			while(i > pend.size() - 1)
				i--;
			binaryInsert(&main, pend.at(i), 0, i + step);
			step++;
			i--;			
		}
		it_1++;
		it_2++;
	}
	return (main);
}

int check_clones(std::deque <unsigned int> dq)
{
    std::deque<unsigned int>::iterator it;
    std::deque<unsigned int>::iterator it_step;
    std::deque<unsigned int>::iterator ite;
    
    it = dq.begin();
    ite = dq.end();

    while (it != ite)
    {
        it_step = it;
		it_step++;
        while (it_step != ite)
        {
			if (*it == *it_step)
				return (1);
			it_step++;
        }
		it++;
    }
	return (0);
}



void fill_deque(std::deque<unsigned int> *dq, int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		(*dq).push_back((unsigned int)atoi(argv[i]));
		i++;
	}
}

int check_sorting(std::deque<unsigned int> dq)
{
    std::deque<unsigned int>::iterator it;
    std::deque<unsigned int>::iterator it_step;
    std::deque<unsigned int>::iterator ite;
	
	it_step = dq.begin();
	it = it_step;
	it_step++;
	ite = dq.end();

	while (it_step != ite)
	{
		if (*it > *it_step)
			return (1);
		it++;
		it_step++;
	}
	return (0);
}

long long get_time()
{
	timeval tv;
    gettimeofday(&tv, NULL);

    long long microseconds =
        static_cast<long long>(tv.tv_sec) * 1000000LL +
        static_cast<long long>(tv.tv_usec);

    return (microseconds);
}

int check_arguments(int argc, char **argv)
{
	int i = argc - 1;
	int j;
	while(i > 0)
	{
		j = 0;	
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);				
			j++;
		}
		i--;
	}
	return (0);
}

void insertNode2(std::vector<unsigned int> *deq, unsigned int index, unsigned int n)
{
    std::vector<unsigned int>::iterator it_deq = (*deq).begin();
    std::vector<unsigned int>::iterator ite_deq = (*deq).end();
	unsigned int i = 0;
    while ((index != i) && it_deq != ite_deq)
	{
		i++;
        it_deq++;		
	}
	if (it_deq == ite_deq)
		return ;
	(*deq).insert(it_deq, n);
}

void binaryInsert2(std::vector<unsigned int> *deq, unsigned int n, unsigned int min, unsigned int max)
{
    unsigned int len = max - min + 1;
    unsigned int index;
    
	if ((*deq)[0] >= n)
	{
		(*deq).insert((*deq).begin(), n);
		return ;		
	}
	if (n > (*deq).at((*deq).size() - 1))
	{
		(*deq).push_back(n);
		return ;
	}
    index = (min + max) / 2;
    if (len == 1 || min >= max)
    {   
		if((*deq)[max] == n || (*deq)[max] > n)
            insertNode2(deq, index, n);
    	else
		{
			if (index == (*deq).size() - 1)
				(*deq).push_back(n);
			else
            	insertNode2(deq, index + 1, n);  			
		}        
    }
	// else if ((*deq)[index] == n)
	// 	insertNode(deq, index, n);
    else if ((*deq)[index] > n)
		binaryInsert2(deq, n, min, index - 1);        
    else
		binaryInsert2(deq, n, index + 1, max);  
}

std::vector<unsigned int> jacobsthalSeq2(unsigned int dim)
{
	std::vector<unsigned int> deq;
	unsigned int n = 1;
	int i = 0;
	deq.push_back(n);
	n = 3;
	if (dim > 2)
		deq.push_back(n);		
	else
		return (deq);
	while(n < dim - 1)
	{
		n = n + deq.at(i) * 2;
		i++;
		deq.push_back(n);
	}		
	return (deq);
}

std::vector<unsigned int> pmerge_dq2(std::vector<unsigned int> dq)
{
    std::vector<unsigned int> main;
    std::vector<unsigned int> pend;
    std::vector<unsigned int>::iterator it_1;
    std::vector<unsigned int>::iterator it_2;
    std::vector<unsigned int>::iterator ite;
    unsigned int extra;
    
    if(dq.size() == 1)
        return (dq);
    if (dq.size() % 2 == 1)
    {
        ite = dq.end();
        ite--;
        extra = *ite;
    }
	it_1 = dq.begin();
    it_2 = ++dq.begin();
    ite = dq.end();
    while (it_1 != ite && it_2 != ite)
    {
        if (*it_1 > *it_2)
        {
            main.push_back(*it_1++);
            it_2++;
        }
        else
        {
            main.push_back(*it_2++);
            it_1++;
        }
        it_1++;
        it_2++;
    }
	if (dq.size() != 2)
		main = pmerge_dq2(main);
	it_1 = main.begin();
    ite = main.end();
	unsigned int i = 0;
	while(it_1 != ite)
	{
		it_2 = dq.begin();
		i = 0;
		while(*it_2 != *it_1)
		{
			it_2++;
			i++;			
		}
		if(i % 2 == 0)
			pend.push_back(dq.at(i + 1));
		else
			pend.push_back(dq.at(i - 1));
		it_1++;
	}
    if (dq.size() % 2 == 1)
		pend.push_back(extra);
    std::vector<unsigned int> jacob = jacobsthalSeq2(pend.size());
	it_1 = jacob.begin();
    ite = jacob.end();
	if (pend.size() > 1)
	{
		binaryInsert2(&main, pend.at(1), 0, 1);
	}
	binaryInsert2(&main, pend.at(0), 0, 0);	
	it_1++;
	it_2 = it_1;
	it_1--;
	unsigned int step = 2;
	while(it_2 != ite)
	{
		i = *it_2;
		while (i > *it_1)
		{
			while(i > pend.size() - 1)
				i--;
			binaryInsert2(&main, pend.at(i), 0, i + step);
			step++;
			i--;			
		}
		it_1++;
		it_2++;
	}
	return (main);	
}

void showVector(std::vector<unsigned int> dq)
{
    std::vector<unsigned int>::iterator it;
    std::vector<unsigned int>::iterator ite;

	it = dq.begin();
	ite = dq.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++; 
	}	
}

int check_clones2(std::vector<unsigned int> dq)
{
    std::vector<unsigned int>::iterator it;
    std::vector<unsigned int>::iterator it_step;
    std::vector<unsigned int>::iterator ite;
    
    it = dq.begin();
    ite = dq.end();

    while (it != ite)
    {
        it_step = it;
		it_step++;
        while (it_step != ite)
        {
			if (*it == *it_step)
				return (1);
			it_step++;
        }
		it++;
    }
	return (0);	
}

int check_sorting2(std::vector<unsigned int> dq)
{
    std::vector<unsigned int>::iterator it;
    std::vector<unsigned int>::iterator it_step;
    std::vector<unsigned int>::iterator ite;
	
	it_step = dq.begin();
	it = it_step;
	it_step++;
	ite = dq.end();

	while (it_step != ite)
	{
		if (*it > *it_step)
			return (1);
		it++;
		it_step++;
	}
	return (0);	
}

void fill_vector(std::vector<unsigned int> *dq, int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		(*dq).push_back((unsigned int)atoi(argv[i]));
		i++;
	}	
}
