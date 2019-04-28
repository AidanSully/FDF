/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:06:20 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/11 16:06:22 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		negative;

	i = 0;
	result = 0;
	negative = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
				|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	if (negative == 1)
		result = (-result);
	return (result);
}
