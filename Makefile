NAME				= ft_ping

CC 				= cc

SRCS 				= 	main.c \
						core/resolve_dns.c \
						parsing/manage_inputs.c \
						print/display_executable.c \
						print/display_structure.c \



OBJS_DIR			= .objs

OBJS				= ${SRCS:%.c=$(OBJS_DIR)/%.o}

DEPS				= ${OBJS:.o=.d}

CFLAGS				= -Wall -Wextra -Werror

$(OBJS_DIR)/%.o: %.c Makefile
			@mkdir -p $(dir $@)
			${CC} ${CFLAGS} -c $< -o $@


${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

-include ${DEPS}

all:		${NAME}

clean:
			rm -rf ${OBJS_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re