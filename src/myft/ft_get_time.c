/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:35:25 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/09 00:35:25 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

long long int	ft_get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * (long long int)1000 + (tv.tv_usec / 1000));
}

long long int	ft_get_time_log(t_info *info)
{
	return (ft_get_time() - info->h_zero);
}
