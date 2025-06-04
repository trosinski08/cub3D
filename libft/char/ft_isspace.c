/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:00:00 by trosinsk          #+#    #+#             */
/*   Updated: 2024/01/15 12:00:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Checks if the given character is a whitespace character.
 * 
 * Whitespace characters include:
 * - Space (' ')
 * - Tab ('\t')
 * - Newline ('\n')
 * - Vertical tab ('\v')
 * - Form feed ('\f')
 * - Carriage return ('\r')
 *
 * @param c The character to be checked.
 * @return Non-zero if the character is a whitespace character, 0 otherwise.
 */
int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (c);
	if (c == '\v' || c == '\f' || c == '\r')
		return (c);
	return (0);
}
