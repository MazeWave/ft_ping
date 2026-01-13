/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:22:23 by ldalmass          #+#    #+#             */
/*   Updated: 2026/01/13 16:56:30 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

int	create_icmp_socket(t_ping *ping)
{
	AUTO_LOG;
	
	ping->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->sockfd < 0)
	{
		if (!ping->is_root)
		{
			printf(RED "%s: socket: Operation not permitted. Raw sockets require root privileges.\n" RESET, ping->program_name);
			return (EXIT_FAILURE);
		}
		else
		{
			printf(RED "%s: socket: Failed to create socket.\n sockfd: %d" RESET, ping->program_name, ping->sockfd);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	resolve_hostname(t_ping *ping)
{
	AUTO_LOG;
	
	struct addrinfo	hints;
	struct addrinfo	*res;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;

	if (getaddrinfo(ping->hostname, NULL, &hints, &res) != 0)
	{
		printf(RED "%s: getaddrinfo: Failed to resolve hostname." RESET, ping->program_name);
		freeaddrinfo(res);	// free
		res = NULL;			// free
		return (EXIT_FAILURE);
	}
	ping->addr_info = res;
	print_addr_info(ping);
	return (EXIT_SUCCESS);
}