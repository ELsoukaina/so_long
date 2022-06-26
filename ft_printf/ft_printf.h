/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:20:04 by sel-jala          #+#    #+#             */
/*   Updated: 2022/06/26 20:20:05 by sel-jala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int nbr);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr_lower(unsigned int nbr);
int		ft_putnbr_upper(unsigned int nbr);
int		ft_putnbr_p(unsigned long nbr);
int		ft_putnbr_u(unsigned int nbr);
char	*ft_strchr(const char *s, int c);

#endif