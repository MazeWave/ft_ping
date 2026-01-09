/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:35:54 by ldalmass          #+#    #+#             */
/*   Updated: 2026/01/09 14:45:57 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

void	help(char *elf_name)
{
	AUTO_LOG;
	printf("Usage: %s <hostname>\n", elf_name);
}

void	init_ping_struct(t_ping *ping, char **argv)
{
	AUTO_LOG;
	ping->is_bonus = (strstr(argv[0], "ft_ping_bonus") == NULL) ? false : true;
	ping->is_root = (getuid() == 0);
	ping->hostname = argv[1];

	LOG(BLUE);
	LOG("is_bonus: %d", ping->is_bonus);
	LOG("is_root: %d", ping->is_root);
	LOG("hostname: %s", ping->hostname);
	LOG(RESET);
}

int parse_args(int argc, char **argv)
{
    int opt = 0;
	while ((opt = getopt(argc, argv, "h")) != -1)
	{
		switch (opt)
		{
			case 'h':
				return (help(argv[0]), EXIT_SUCCESS);
			default:
				return (help(argv[0]), EXIT_FAILURE);
		}
	}
    return (0);
}