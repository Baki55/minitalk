/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:17:03 by bkhatib           #+#    #+#             */
/*   Updated: 2022/05/04 14:29:05 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putnbr(int nbr, int baselen, char *base);
void	ft_error(char *str);
int		ft_atoi(const char *str);

#endif