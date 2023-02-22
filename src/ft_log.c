/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:50:03 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/08 03:50:03 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_log(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->m_log);
	if (philo->info->death || philo->info->done == philo->info->nb_philo)
	{
		pthread_mutex_unlock(&philo->info->m_log);
		return ;
	}
	if (str)
		printf("%-6lld %d %s\n", ft_get_time_log(philo->info), philo->id, str);
	pthread_mutex_unlock(&philo->info->m_log);
}
