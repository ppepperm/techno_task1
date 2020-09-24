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
		iter = str.find_first_of(" ", iter);
		//cout << iter << " jopa"<< endl;
		if (iter == -1)
		{
			return -1;
		}
		k++;
	}
	return iter;
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

	for (int i = 0; i < strings.size(); i ++)
	{
		cout << strings[i]<< endl;
	}

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

			cout << N << " to lower" << endl;
			for (int i = 0; i < strings.size(); i ++)
			{
				begin = find_nth_occ(strings[i], N);
				end = find_nth_occ(strings[i], N + 1);
				//cout << begin << " "<< end<<endl;
				field = strings[i].substr(begin, end);
				cout << field << endl;
			}

		}
		else if (op == "U")
		{
			int begin, end;
			string field;

			cout << N << " to upper" << endl;
			for (int i = 0; i < strings.size(); i ++)
			{
				begin = find_nth_occ(strings[i], N);
				end = find_nth_occ(strings[i], N + 1);
				//cout << begin << " "<< end<<endl;
				field = strings[i].substr(begin, end);
				cout << field << endl;

			}
		}
		else if (op.length() == 2)
		{
			int begin, end;
			string field;

			cout << N << " swap " << op[0] << " to " << op[1]<< endl;
			for (int i = 0; i < strings.size(); i ++)
			{
				begin = find_nth_occ(strings[i], N);
				end = find_nth_occ(strings[i], N + 1);
				//cout << begin << " "<< end<<endl;
				field = strings[i].substr(begin, end);
				cout << field << endl;
			}
		}
	}
}