/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 14:03:52 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/20 10:40:03 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_skip(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int				value;
	int				i;
	int				sign;

	i = ft_skip(str, 0);
	value = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	return (value * sign);
}
