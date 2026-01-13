/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:27:26 by ldalmass          #+#    #+#             */
/*   Updated: 2026/01/13 11:39:56 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
#define FT_PING_H

# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <arpa/inet.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <signal.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# include "log.h"
# include "colors.h"

#define unused __attribute__((unused))

typedef struct s_ping
{
	bool	is_bonus;
	bool	is_root;
	char	*program_name;
	char	*hostname;
	int		count;
	int		interval;
	int		sockfd;
	struct	addrinfo *addr_info;
}	t_ping;

int		parse_args(int argc, char **argv, t_ping *ping);
void	help(char *elf_name);
void	init_ping_struct(t_ping *ping, char **argv);
void	print_ping_struct(t_ping *ping);

int		create_icmp_socket(t_ping *ping);
int		resolve_hostname(t_ping *ping);
void	print_addr_info(t_ping *ping);
void	print_sockaddr(struct sockaddr *addr);

#endif