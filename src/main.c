/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:26:14 by maze              #+#    #+#             */
/*   Updated: 2026/01/09 14:07:31 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

static void	help(char *elf_name)
{
	AUTO_LOG;
	printf("Usage: %s <hostname>\n", elf_name);
}

static void	init_ping_struct(t_ping *ping, char **argv)
{
	AUTO_LOG;
	ping->is_bonus = (strstr(argv[0], "ft_ping_bonus") == NULL) ? false : true;
	ping->is_root = (getuid() == 0) ? true : false;
	ping->hostname = argv[1];
	LOG(BLUE "is_bonus: %d" RESET, ping->is_bonus);
	LOG(BLUE "hostname: %s" RESET, ping->hostname);
}

int	main(int argc, char **argv unused)
{
	AUTO_LOG;
	if (argc < 2)
		return (help(argv[0]), EXIT_FAILURE);

	t_ping	pingu;
	t_ping	*ping = &pingu;

	init_ping_struct(ping, argv);
	return (0);
}