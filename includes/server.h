/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:18:32 by smostefa          #+#    #+#             */
/*   Updated: 2022/04/26 17:55:18 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../libft/libft.h"

# define ANSI_COLOR_BLUE	"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE	"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED	"\x1b[91m"
# define ANSI_COLOR_RESET	"\x1b[0m"

# define BUFFER_SIZE 4

# define SLEEP_TIME 0

# define L1 " .              +   .                .   . .     .  .   .. . +  .\n"
# define L2 "                   .                    .       .    * .. .    + \n"
# define L3 "  .       *                        . . . .  .   .  + . ..   .    \n"
# define L4 "                                        .  .  +  . . ..  *       \n"
# define L5 ".        WELCOME TO MINITALK     .  .   .    .    . . .   .      \n"
# define L6 "                             .     .     . +.    +  . .          \n"
# define L7 "                             .       .   . .                   . \n"
# define L8 "        . .                .    * . . .  .  +   .    *           \n"
# define L9 "           +      .           .   .      +                  .+   \n"
# define L10 "                            .       . +  .+. .               .  \n"
# define L11 "  .                      .     . + .  . .     .      .          \n"
# define L12 "           .      .    .     . .   . . .        ! /             \n"
# define L13 "      *             .    . .  +    .  .       - O -             \n"
# define L14 "          .     .    .  +   . .  *  .       . / |         .     \n"
# define L15 "               . + .  .  .  .. +  .                          .. \n"
# define L16 ".      .  .  .  *   .  *  . +..  .            *          +      \n"
# define L17 " .      .   . .   .   .   . .  +   .    .            +          \n"

# define HI "You can send messages across the universe by using this PID : "
# define LISTEN "[Listening...]\n\n"
# define SIGACTION_ERROR "\nSorry, we could not set up sigaction.\n\n"
# define KILL_ERROR "\nWe could not to reach the server, did you close it ?\n\n"
# define SERVER_ERROR "\nWhoops, the server has just crashed... \n\n"
# define PARAMETER_ERROR "\nTry again with no parameter.\n\n"
# define MALLOC "\nA malloc error occurred and we had to stop the process.\n\n"
# define SERVER_CLOSE "\nThe following client was closed during transmission : "
# define SERVER_CLOSE_2 "\nDon't close client before the end of the delivery. \n\n"

//server.c
int		receive_len(int signum, int pid);
int		receive_mssg(int signum, int pid);
void	print_message(int pid);
int		main(int argc, char **argv);

//server_utils.c
void	handle_signal(int signum, siginfo_t *info, void *context);
int		set_sigaction(void);
void	say_hello(void);
void	ft_putstr_fd_color(char *str, int fd, char *color);

#endif
