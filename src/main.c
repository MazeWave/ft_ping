/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:26:14 by maze              #+#    #+#             */
/*   Updated: 2026/01/15 15:50:33 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

bool	g_is_running = true;

static void	handle_sigint(int signum unused)
{
	AUTO_LOG;

	LOG(YELLOW "signal %d received, stopping ping" RESET, signum);
	g_is_running = false;
	return;
}

static void	ping_loop(t_ping *ping)
{
	AUTO_LOG;

	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, &handle_sigint);
	while (g_is_running)
	{
		// Account for count
		if (ping->count == 0) break;
		if (ping->count != -1) ping->count--;
		LOG(YELLOW "pinging... count: %d" RESET, ping->count);
		// Send the ping
		// send_ping(ping);
		// Account for interval
		usleep((size_t)(ping->interval * 1000000.0));
	}
	return;
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
	populate_echo_request(ping, ping->payload);
	
	// calculate the checksum
	// calculate_checksum(ping);
	
	// start pinging
	ping_loop(ping);
	print_ping_struct(ping);
	close(ping->sockfd);
	return (0);
}