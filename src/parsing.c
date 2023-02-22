/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:29:11 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/08 21:29:11 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	str_not_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	not_number(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (str_not_digits(av[i]))
		{
			printf("arg[%d] is not digits\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_info(t_info *info, int ac, char **av)
{
	info->nb_philo = ft_atoi(av[1]);
	if (info->nb_philo <= 0)
	{
		printf("Not enough philosophers\n");
		return (1);
	}
	info->die = ft_atoll(av[2]);
	info->eat = ft_atoll(av[3]);
	info->sleep = ft_atoll(av[4]);
	if (ac == 6)
	{
		info->max_eat = ft_atoi(av[5]);
		if (info->max_eat <= 0)
		{
			printf("Philosophers die of starvation\n");
			return (1);
		}
	}
	else
		info->max_eat = -1;
	return (0);
}

int	parsing(int ac, char **av, t_info *info)
{
	if (ac >= 5 && ac <= 6)
	{
		ft_bzero(info, sizeof(t_info));
		if (not_number(ac, av) || get_info(info, ac, av))
			return (1);
	}
	else
	{
		printf("Wrong number of args\n");
		return (1);
	}
	return (0);
}
