/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 15:40:48 by tclement      #+#    #+#                 */
/*   Updated: 2020/05/13 20:31:04 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int arg)
{
	if (arg >= 'A' && arg <= 'Z')
		return (arg + 32);
	else
		return (arg);
}
