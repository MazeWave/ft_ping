/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:35:54 by ldalmass          #+#    #+#             */
/*   Updated: 2026/01/12 13:28:48 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

void    print_ping_struct(t_ping *ping)
{
	LOG(BLUE);
	LOG("is_bonus: %d", ping->is_bonus);
	LOG("is_root: %d", ping->is_root);
	LOG("count: %d", ping->count);
	LOG("hostname: %s", ping->hostname);
	LOG(RESET);
}

void	help(char *elf_name)
{
	printf("Usage: %s <hostname>\n", elf_name);
}

void	version(void)
{
	LOG(GREEN "ft_ping -- ldalmass -- version: 1.0.0" RESET);
}
void	init_ping_struct(t_ping *ping, char **argv)
{
	AUTO_LOG;
	ping->is_bonus = (strstr(argv[0], "ft_ping_bonus") == NULL) ? false : true;
	ping->is_root = (getuid() == 0);
	ping->hostname = NULL;
	ping->count = 0;

}

int parse_args(int argc, char **argv, t_ping *ping)
{
    AUTO_LOG;
    // get the options
    int opt = 0;
	while ((opt = getopt(argc, argv, "hvc:")) != -1)
	{
		switch (opt)
		{
            case 'c':
                ping->count = atoi(optarg);
                break;
            case 'v':
                return (version(), EXIT_SUCCESS);
			case 'h':
				return (help(argv[0]), EXIT_SUCCESS);
		}
	}
    // check a hostname is provided
    if (optind != argc - 1)
        return (help(argv[0]), EXIT_FAILURE);
    ping->hostname = argv[optind];
    return (EXIT_SUCCESS);
}