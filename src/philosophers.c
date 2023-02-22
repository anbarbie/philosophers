/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:25:11 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/07 20:25:11 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	init(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->nb_philo);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
	if (!info->philo || !info->fork)
		return (1);
	while (i < info->nb_philo)
	{
		if ((pthread_mutex_init(&info->fork[i], NULL)))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&info->m_log, NULL)
		|| pthread_mutex_init(&info->m_eat, NULL))
		return (1);
	info->h_zero = ft_get_time();
	return (0);
}

void	init_philo(t_philo *philo, t_info *info, int i)
{
	philo->id = i + 1;
	philo->round = 0;
	philo->info = info;
	pthread_mutex_lock(&info->m_eat);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&info->m_eat);
}

void	reaper(t_info *info)
{
	int			i;
	pthread_t	death;

	i = 0;
	while (i < info->nb_philo)
	{
		init_philo(&info->philo[i], info, i);
		if (pthread_create(&info->philo[i].thread,
				NULL, (void *)routine, &info->philo[i]))
		{
			printf("pthread_create failed\n");
			return ;
		}
		if (pthread_detach(info->philo[i].thread))
		{
			printf("pthread_detached failed\n");
			return ;
		}
		i++;
	}
	if (pthread_create(&death, NULL,
			(void *)knock, info) || pthread_join(death, NULL))
		return ;
}

int	main(int ac, char **av)
{
	t_info	info;

	if (parsing(ac, av, &info) || init(&info))
		return (1);
	reaper(&info);
	if (info.max_eat > -1 && !info.death)
		printf("Philosophers ate %d times\n", info.max_eat);
	philo_exit(&info);
	return (0);
}
