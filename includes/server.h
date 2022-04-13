#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

# define ANSI_COLOR_BLUE		"\x1b[94m"
# define ANSI_COLOR_LIGHT_WHITE		"\x1b[97m"
# define ANSI_COLOR_RESET		"\x1b[0m"

# define BUFFER_SIZE 4

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
# define SIGUSR_ERROR "SIGUSR error.\n"
# define PARAMETER_ERROR "Try again without adding any parameter.\n"

typedef struct s_server {
	pid_t	pid;
	int	bits;
	char	character;
	char	*message;

}	t_server;

void    ft_putstr_fd_color(char *str, int fd, char *color);

#endif
