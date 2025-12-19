NAME				= 	ft_ping

CC 					= 	cc

PRINT_DIR			=	print/display_executable.c \
						print/display_structure.c \

CORE_DIR			=	core/create_socket.c \

PARSING_DIR			=	parsing/manage_inputs.c \
						parsing/check_ipv4.c \
						parsing/resolve_dns.c \

SRCS 				= 	main.c \
						${CORE_DIR} \
						${PARSING_DIR} \
						${PRINT_DIR} \



OBJS_DIR			= 	.objs

OBJS				=	${SRCS:%.c=$(OBJS_DIR)/%.o}

DEPS				= 	${OBJS:.o=.d}

CFLAGS				= 	-Wall -Wextra -Werror

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