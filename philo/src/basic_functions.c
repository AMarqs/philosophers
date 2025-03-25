/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:25:36 by albmarqu          #+#    #+#             */
/*   Updated: 2025/03/25 22:20:31 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_digit(char *s)
{
	size_t	i;

	i = 0;
	if (!s[i])
		return (1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (i != ft_strlen(s))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	num *= sign;
	return (num);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// char	*put_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1)
// 		return (ft_strdup(s2));
// 	i = ft_strlen(s1) + ft_strlen(s2);
// 	str = (char *)malloc(sizeof(char) * (i + 1));
// 	if (!str)
// 		return (NULL);
// 	i = -1;
// 	while (s1[++i])
// 		str[i] = s1[i];
// 	j = 0;
// 	while (s2[j])
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	return (str);
// }
