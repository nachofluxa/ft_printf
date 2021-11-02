NAME			= libftprintf.a

SOURCES 		= ft_printf.c \
					ft_printf2.c \
					ft_printf_utils.c \

OBJECTS 		= ${SOURCES:.c=.o}

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra

RM 				= rm -rf

AR				= ar rcs

all:			${NAME}

${NAME}: 		${OBJECTS}
				${AR} ${NAME} ${OBJECTS}

clean:			
				${RM} ${OBJECTS}

fclean: 		clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re bonus	
