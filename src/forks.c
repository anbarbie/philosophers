/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:08:37 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/08 03:08:37 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	pick_forks(t_philo *philo)
{
	if (philo->id == philo->info->nb_philo)
		pthread_mutex_lock(&philo->info->fork[0]);
	else
		pthread_mutex_lock(&philo->info->fork[philo->id]);
	ft_log(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->fork[philo->id - 1]);
	ft_log(philo, "has taken a fork");
}

void	release_forks(t_philo *philo)
{
	if (philo->id == philo->info->nb_philo)
		pthread_mutex_unlock(&philo->info->fork[0]);
	else
		pthread_mutex_unlock(&philo->info->fork[philo->id]);
	ft_log(philo, "has dropped a fork");
	pthread_mutex_unlock(&philo->info->fork[philo->id - 1]);
	ft_log(philo, "has dropped a fork");
}
