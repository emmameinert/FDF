/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:08:46 by emeinert          #+#    #+#             */
/*   Updated: 2022/10/31 11:51:56 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	answer;

	answer = 0;
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
		answer = 1;
	else
		answer = 0;
	return (answer);
}
