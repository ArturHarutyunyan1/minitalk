CNAME = client
SNAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_DIR = ft_printf
LIBFT_DIR = libft
SRC_DIR = src

SRCS = $(SRC_DIR)/client.c \
       $(SRC_DIR)/server.c \
       $(PRINTF_DIR)/ft_format_parser.c \
       $(PRINTF_DIR)/ft_print_hex.c \
       $(PRINTF_DIR)/ft_printf.c \
       $(PRINTF_DIR)/ft_printf_utils.c \
       $(LIBFT_DIR)/ft_strlen.c \
       $(LIBFT_DIR)/ft_itoa.c \
       $(LIBFT_DIR)/ft_atoi.c \
       $(LIBFT_DIR)/ft_isdigit.c

OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(CNAME) $(SNAME)

$(CNAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(CNAME) $(SRC_DIR)/client.o $(PRINTF_DIR)/*.o $(LIBFT_DIR)/*.o

$(SNAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(SNAME) $(SRC_DIR)/server.o $(PRINTF_DIR)/*.o $(LIBFT_DIR)/*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(CNAME) $(SNAME)

re: fclean all

.PHONY: all clean fclean re