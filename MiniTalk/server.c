/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:43:45 by ogozturk          #+#    #+#             */
/*   Updated: 2022/05/26 11:39:23 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "./libft/libft.h"

// Karakteri mesaja çevirdiğim ve yazdırdığım yer
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	message(int num)
{
	static int	power;
	static int	byte;

	if (num == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar(byte);
		power = 0;
		byte = 0;
	}
}

int	main(void)
{
	ft_putstr("| Server running PID : ");
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, message);
	signal(SIGUSR2, message);
	while (1)
	{
		pause();
	}
}
