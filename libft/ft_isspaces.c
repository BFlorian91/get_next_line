/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:58:45 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/26 19:01:41 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\n'
			|| c == '\r');
}