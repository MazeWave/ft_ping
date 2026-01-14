/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:26:14 by maze              #+#    #+#             */
/*   Updated: 2026/01/14 13:40:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

static	int	ping_loop(t_ping *ping)
{
	AUTO_LOG;

	while (ping->count > 0 )
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv unused)
{
	AUTO_LOG;

	if (argc < 2)
		return (help(argv[0]), EXIT_FAILURE);

	t_ping	pingu;
	t_ping	*ping = &pingu;

	init_ping_struct(ping, argv);
	if (parse_args(argc, argv, ping) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	// create the icmp socket
	if (create_icmp_socket(ping) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	// resolve the hostname
	if (resolve_hostname(ping) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
	// create the ECHO_REQUEST header
	// create_echo_request_header(ping);
	
	// calculate the checksum
	// calculate_checksum(ping);
	
	// start pinging
	// ping_loop(ping);
	print_ping_struct(ping);
	return (0);
}