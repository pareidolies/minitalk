#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"

# define ANSI_COLOR_BLUE		"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_LIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_RESET		"\x1b[0m"

# define BUFFER_SIZE 4

# define SLEEP_TIME 0

# define L1 " .              +   .                .   . .     .  .   .. . + . .  .  .\n"
# define L2 "                   .                    .       .    * .. .   . +  +  . \n"
# define L3 "  .       *                        . . . .  .   .  + . ..   .  . .      \n"
# define L4 "                                        .  .  +  . . ..  *         .    \n"
# define L5 ".        WELCOME TO MINITALK     .  .   .    .    . . .   .      .      \n"
# define L6 "                             .     .     . +.    +  . .                 \n"
# define L7 "                             .       .   . .                    .    *  \n"
# define L8 "        . .                .    * . . .  .  +   .    *            *     \n"
# define L9 "           +      .           .   .      +                  .+          \n"
# define L10 "                            .       . +  .+. .               +.         \n"
# define L11 "  .                      .     . + .  . .     .      .             ..   \n"
# define L12 "           .      .    .     . .   . . .        ! /                     \n"
# define L13 "      *             .    . .  +    .  .       - O -                     \n"
# define L14 "          .     .    .  +   . .  *  .       . / |         .             \n"
# define L15 "               . + .  .  .  .. +  .                           ..        \n"
# define L16 ".      .  .  .  *   .  *  . +..  .            *          +              \n"
# define L17 " .      .   . .   .   .   . .  +   .    .            +      *         . \n"

# define WELCOME_MSSG "You can send messages across the universe by using this PID : "
# define LISTEN "[Listening...]\n\n"
# define SIGUSR_ERROR "\nError : Unfortunately, a SIGUSR error stopped the process.\n\n"
# define SIGACTION_ERROR "\nError : Sorry, we could not set up sigaction.\n\n"
# define KILL_ERROR "\nError : We did not manage to reach the server, did you close it ?\n\n"
# define SERVER_ERROR "\nError : Whoops, the server has just crashed... Maybe you can try again !\n\n"
# define PARAMETER_ERROR "\nError : Try again with no parameter.\n\n"
# define MALLOC "\nError : A malloc error occurred and we had to stop the process.\n\n"

//server.c
int	receive_len(int signum, int pid);
int	receive_mssg(int signum, int pid);
int	main(int argc, char **argv);

//server_utils.c
void	handle_signal(int signum, siginfo_t *info, void *context);
int	set_sigaction();
void	say_hello();
void	ft_putstr_fd_color(char *str, int fd, char *color);

#endif
