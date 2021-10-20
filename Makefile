NAME			= libftprintf.a

SOURCES 		= ft_printf.c \
					ft_printf2.c \
					ft_printf_utils.c \

SOURCES_BONUS 	= 

OBJECTS 		= ${SOURCES:.c=.o}

OBJECTS_BONUS 	= ${SOURCES_BONUS:.c=.o}

CFLAGS			= -Wall -Werror -Wextra

RM 				= rm -rf

AR				= ar rcs

${NAME}: 		${OBJECTS}
				${AR} ${NAME} ${OBJECTS}

