/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philisopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:08:41 by antbarbi          #+#    #+#             */
/*   Updated: 2021/11/07 16:08:41 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_info
{
	int				nb_philo;
	long long int	die;
	long long int	eat;
	long long int	sleep;
	int				max_eat;
	long long int	h_zero;
	int				death;
	int				done;
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_log;
	pthread_mutex_t	m_eat;
}					t_info;

typedef struct s_philo
{
	int				id;
	long long int	last_meal;
	pthread_t		thread;
	int				round;
	t_info			*info;
}					t_philo;

int				parsing(int ac, char **av, t_info *info);
int				ft_atoi(const char *str);
long long int	ft_atoll(const char *str);
void			ft_bzero(void *s, size_t n);
long long int	ft_get_time(void);
long long int	ft_get_time_log(t_info *info);
void			ft_usleep(long long int sleep);
void			*routine(t_philo *philo);
void			ft_log(t_philo *philo, char *str);
void			pick_forks(t_philo *philo);
void			release_forks(t_philo *philo);
void			*knock(t_info *info);
void			philo_exit(t_info *info);

#endif
