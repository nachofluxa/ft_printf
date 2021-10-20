NAME			= libftprintf.a

SOURCES 		= ft_printf.c \
					ft_printf2.c \
					ft_printf_utils.c \

SOURCES_BONUS 	= 

OBJECTS 		= ${SOURCES:.c=.o}

OBJECTS_BONUS 	= ${SOURCES_BONUS:.c=.o}

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra

RM 				= rm -rf

AR				= ar rcs

all:			${NAME}

${NAME}: 		${OBJECTS}
				${AR} ${NAME} ${OBJECTS}

%.o: %.c 		${CC} ${CFLAGS} -c $< -o $@ 

clean:			
				${RM} ${OBJECTS}

fclean: 		clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re bonus	
