/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:36:17 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/08 20:36:17 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	scythe(t_info *info)
{
	pthread_mutex_lock(&info->m_log);
	if (info->done == info->nb_philo)
	{
		pthread_mutex_unlock(&info->m_log);
		return (1);
	}
	pthread_mutex_unlock(&info->m_log);
	return (0);
}

void	*knock(t_info *info)
{
	long long int	death;
	int				i;

	while (!scythe(info))
	{
		i = -1;
		while (++i < info->nb_philo)
		{
			pthread_mutex_lock(&info->m_eat);
			death = ft_get_time() - info->philo[i].last_meal;
			pthread_mutex_unlock(&info->m_eat);
			pthread_mutex_lock(&info->m_log);
			if (death >= info->die && !info->death)
			{
				info->death = 1;
				printf("%-6lld %d died\n", ft_get_time_log(info),
					info->philo[i].id);
				pthread_mutex_unlock(&info->m_log);
				return (NULL);
			}
			pthread_mutex_unlock(&info->m_log);
		}
		ft_usleep(1);
	}
	return (NULL);
}
