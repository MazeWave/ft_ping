/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:35:54 by ldalmass          #+#    #+#             */
/*   Updated: 2026/01/14 12:30:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"

void    print_ping_struct(t_ping *ping)
{
	AUTO_LOG;
	LOG(BLUE);
	LOG("is_bonus: %d", ping->is_bonus);
	LOG("is_root: %d", ping->is_root);
	LOG("count: %d", ping->count);
	LOG("hostname: %s", ping->hostname);
	LOG("sockfd: %d", ping->sockfd);
	LOG(RESET);
}

void	print_sockaddr(struct sockaddr_in *ai_addr)
{
	AUTO_LOG;
	
	char ip_str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &ai_addr->sin_addr, ip_str, INET_ADDRSTRLEN);
	
	LOG(GREEN "ip as int: %d" RESET, ai_addr->sin_addr);
	LOG(GREEN "ip as string: %s" BLUE, ip_str);
}

void	print_addr_info(t_ping *ping)
{
	AUTO_LOG;

	// return;
	struct addrinfo	*temp = ping->addr_info;
	while (temp)
	{
		LOG(BLUE);
		LOG("--------------------------------");
		LOG("ai_canonname: %s", temp->ai_canonname);
		LOG("ai_family: %d", temp->ai_family);
		LOG("ai_socktype: %d", temp->ai_socktype);
		LOG("ai_protocol: %d", temp->ai_protocol);
		LOG("ai_addrlen: %d", temp->ai_addrlen);
		LOG("ai_addr: %p", temp->ai_addr);
		print_sockaddr((struct sockaddr_in *)temp->ai_addr);
		LOG("ai_canonname: %s", temp->ai_canonname);
		LOG(RESET);
		temp = temp->ai_next;
	}
}

void	help(char *elf_name)
{
	AUTO_LOG;
	printf("Usage: %s <hostname>\n", elf_name);
}

void	version(void)
{
	AUTO_LOG;
	LOG(GREEN "ft_ping -- ldalmass -- version: 1.0.0" RESET);
}
void	init_ping_struct(t_ping *ping, char **argv)
{
	AUTO_LOG;
	ping->program_name = argv[0];
	ping->is_bonus = (strstr(argv[0], "ft_ping_bonus") == NULL) ? false : true;
	ping->is_root = (getuid() == 0);
	ping->hostname = NULL;
	ping->count = 0;
	ping->interval = 0;
}

int parse_args(int argc, char **argv, t_ping *ping)
{
	AUTO_LOG;

	int opt = 0;
	while (optind < argc)
	{
		// Checks for options
		while ((opt = getopt(argc, argv, "hvc:")) != -1)
		{
			switch (opt)
			{
				case 'c':
				ping->count = atoi(optarg);
				LOG(GREEN "count: %d" RESET, ping->count);
				break;
				case 'v':
				return (version(), EXIT_SUCCESS);
				case 'h':
				return (help(argv[0]), EXIT_SUCCESS);
			}
		}
		// Checks for standalone options
		if (ping->hostname == NULL)
		{
			ping->hostname = argv[optind];
			optind++;
		}
		else if (ping->hostname != NULL && optind == argc - 1)
		{
			LOG(RED "Error: No hostname provided" RESET);
			return (help(argv[0]), EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}