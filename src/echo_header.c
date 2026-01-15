/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:09:13 by ldalmass          #+#    #+#             */
/*   Updated: 2026/01/15 16:39:21 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

uint16_t	calculate_checksum(t_echo_header echo_request unused)
{
	uint16_t	checksum = 0;

	// TODO : Calculate the checksum
	
	return (checksum);
}

void	populate_echo_request(t_ping *ping, uint32_t *payload unused)
{
	// TODO : Put the payload in the echo request
	
	// Calculate the checksum
	ping->echo_request.checksum = calculate_checksum(ping->echo_request);
}

t_echo_header	init_echo_header(size_t type)
{
	AUTO_LOG;

	t_echo_header	echo_header;
	echo_header.type = type;
	echo_header.code = 0;
	echo_header.checksum = 0;
	echo_header.identifier = 0;
	echo_header.sequence_number = 0;
	echo_header.payload = NULL;

	return (echo_header);
}

void    parse_echo_reply(t_ping *ping unused)
{
	return;
}