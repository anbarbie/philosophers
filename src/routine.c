/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:31:09 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/08 02:31:09 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	sleeping(t_philo *philo)
{
	ft_log(philo, "is sleeping");
	ft_usleep(philo->info->sleep);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->m_eat);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->info->m_eat);
	ft_log(philo, "is eating");
	if (philo->info->max_eat > -1)
		philo->round++;
	if (philo->round == philo->info->max_eat)
	{
		pthread_mutex_lock(&philo->info->m_log);
		philo->info->done++;
		pthread_mutex_unlock(&philo->info->m_log);
	}
	ft_usleep(philo->info->eat);
}

void	delay(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(10);
	if (philo->info->nb_philo % 2 > 0
		&& philo->id == philo->info->nb_philo
		&& philo->id > 1)
		ft_usleep(20);
	if (philo->id == 1 && philo->info->nb_philo == 1)
	{
		ft_log(philo, "has taken a fork");
		ft_usleep(philo->info->die);
		philo->info->death = 1;
	}
}

void	*routine(t_philo *philo)
{
	delay(philo);
	pthread_mutex_lock(&philo->info->m_log);
	while (!philo->info->death && philo->info->done != philo->info->nb_philo)
	{
		pthread_mutex_unlock(&philo->info->m_log);
		pick_forks(philo);
		eating(philo);
		release_forks(philo);
		sleeping(philo);
		ft_log(philo, "is thinking");
	}
	pthread_mutex_unlock(&philo->info->m_log);
	return (NULL);
}
