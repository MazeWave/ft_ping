/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:26:14 by maze              #+#    #+#             */
/*   Updated: 2026/01/09 12:23:23 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"


static int	help(char *elf_name)
{
	printf("Usage: %s <hostname>\n", elf_name);
	return (1);
}

static void	init_ping(t_ping *ping, char **argv)
{
	ping->is_bonus = (strstr(argv[0], "ft_ping_bonus") == NULL) ? false : true;
	ping->hostname = argv[1];
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
		return (help(argv[0]));

	t_ping	pingu;
	t_ping	*ping = &pingu;

	init_ping(ping, argv);
	printf("is_bonus: %d\n", ping->is_bonus);
	return (0);
}