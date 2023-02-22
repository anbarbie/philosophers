/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 02:27:04 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/09 02:27:04 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_usleep(long long int sleep)
{
	long long int	done;

	done = ft_get_time() + sleep;
	while (ft_get_time() < done)
		usleep(sleep);
}
