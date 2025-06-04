/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:22:01 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 00:54:40 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_LIST "-0.# +123456789"
# define SPEC_LIST "cspdiuxX%"

# include "../../include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_format
{
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hash;
	int				dot;
	int				width;
	int				prec;
	char			type;
	struct s_format	*next;
}	t_format;

//./mandatory
int				ft_printf(const char *str, ...);
int				print_char(int c, t_format *f);
unsigned long	print_h_up(unsigned long nbr, unsigned int base, t_format *f);
int				print_digit_prep(long nbr, int base, t_format *f);
unsigned long	print_point(unsigned long nbr, unsigned int base, t_format *f);
unsigned long	print_hexa(unsigned long nbr, unsigned int base, t_format *f);
int				print_string(char *str, t_format *f);
void			flag_spec(char fspec, t_format *flags);
int				ft_putchar(char c);
int				ft_digit_len(long nbr, int base, t_format *f);
int				print_digit(long nbr, int base);
int				minus_nbr(t_format *f);
int				plus_conv(t_format *f);
int				non_minus_conv(long nbr, t_format *f, int len);
// int				zero_conv(long nbr, int base, t_format *f, int len);
// int				prec_conv(long nbr, int base, t_format *f, int len);
int				space_conv(t_format *f);

// Declarations for functions moved to nbr_utils.c (if they are not static)
// Ensure these match the non-static functions in nbr_utils.c
char			determine_padding_char(t_format *f);
int				get_precision_zeros_len(long nbr, t_format *f, int len);
int				get_width_padding_len(t_format *f, int len, \
int precision_zeros);
int				apply_width_padding_and_sign(long nbr, t_format *f, \
int width_pad_len_char_pad);
int				print_padding_chars(int count, char pad_char_val);
int				print_hash_flag_prefix(long nbr, t_format *f);
void			zero_val_prec_effect(t_format *f, long nbr, int *current_i_ptr);
int				ft_itoa_base(char *buffer, unsigned long long n, \
int base, int uppercase);

#endif
