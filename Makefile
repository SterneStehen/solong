NAME := so_long

CC := clang

# Флаги компиляции с указанием папок для заголовочных файлов
CFLAGS := -Wall -Wextra -Werror -Iheader/ -Iminilibx

# Исходные файлы проекта
SOURCE := $(wildcard game/*.c)
GETNEXTLINE := $(wildcard get_next/*.c)
PRINTF := $(wildcard printf/*.c)

# Объектные файлы, созданные из исходных файлов
OBJ := $(SOURCE:.c=.o) $(GETNEXTLINE:.c=.o) $(PRINTF:.c=.o)

# Путь к папке MiniLibX
MLX_PATH = ./minilibx

# Флаги для библиотеки MiniLibX и дополнительных фреймворков macOS
MLX_FLAGS := -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
