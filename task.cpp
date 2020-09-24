/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:05:46 by ppepperm          #+#    #+#             */
/*   Updated: 2020/09/24 19:05:49 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int	find_nth_occ(string str, int n)
{
	int iter = 0;

	//cout << n << " dfsadasdfsa"<<endl;
	for(int k = 0; k < n; k++)
	{
		iter = str.find_first_of(" ", iter + 1);
		//cout << iter << " jopa"<< endl;
		if (iter == -1)
		{
			return -1;
		}
	}
	return iter;
}

void swap_char(string &string, char from, char to)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (string[i] == from)
			string[i] = to;
	}
}

int	main(int ac, char **av)
{
	ifstream	fin;
	string		iter;
	vector		<string> strings;

	fin.open(av[1]);
	while (!fin.eof())
	{
		getline(fin, iter);
		strings.push_back(iter);
	}

	int *ids = new int [strings.size()];

	for (int i = 2; i < ac; i++)
	{
		string num;
		string op;
		int index;
		int	N;

		iter = string(av[i]);
		index = iter.find_first_of(":");
		num = iter.substr(0,index);
		op = iter.substr(index + 1);
		N = atoi(num.c_str());
		if (op == "u")
		{
			int begin, end;
			string field;

			for (int i = 0; i < strings.size(); i ++)
			{
				begin = find_nth_occ(strings[i], N);
				end = find_nth_occ(strings[i], N + 1);
				if (begin < 0)
					continue ;
				ids[i] = 1;
				if (begin > 0)
					begin ++;
				field = strings[i].substr(begin, end - begin);
				transform(field.begin(), field.end(), field.begin(), ::tolower);
				strings[i].replace(begin, end - begin, field);
			}
		}
		else if (op == "U")
		{
			int begin, end;
			string field;

			for (int i = 0; i < strings.size(); i ++)
			{
				begin = find_nth_occ(strings[i], N);
				end = find_nth_occ(strings[i], N + 1);
				if (begin < 0)
					continue ;
				ids[i] = 1;
				if (begin > 0)
					begin ++;
				field = strings[i].substr(begin, end - begin);
				transform(field.begin(), field.end(), field.begin(), ::toupper);
				strings[i].replace(begin, end - begin, field);
			}
		}
		else if (op.length() == 2)
		{
			int begin, end;
			string field;

			for (int i = 0; i < strings.size(); i ++)
			{
				begin = find_nth_occ(strings[i], N);
				end = find_nth_occ(strings[i], N + 1);
				if (begin < 0)
					continue ;
				ids[i] = 1;
				if (begin > 0)
					begin ++;
				field = strings[i].substr(begin, end - begin);
				swap_char(field, op[0], op[1]);
				strings[i].replace(begin, end - begin, field);
			}
		}
	}
	for (int i = 0; i < strings.size(); i++)
	{
		if (ids[i] > 0)
			cout << strings[i]<< endl;
	}
}