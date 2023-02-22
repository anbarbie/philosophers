/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:56:56 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/08 20:56:56 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philo_exit(t_info *info)
{
	int	i;

	i = 0;
	ft_usleep(1000);
	pthread_mutex_lock(&info->m_eat);
	free(info->philo);
	pthread_mutex_unlock(&info->m_eat);
	pthread_mutex_destroy(&info->m_eat);
	pthread_mutex_destroy(&info->m_log);
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	free(info->fork);
}
