/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 14:59:37 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/13 20:11:45 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else if (arg >= 'a' && arg <= 'z')
		return (1);
	else if (arg >= 'A' && arg <= 'Z')
		return (1);
	else
		return (0);
}
