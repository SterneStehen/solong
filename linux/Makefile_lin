NAME := so_long

CC := gcc

# Указываем папку header для поиска заголовочных файлов
CFLAGS := -Wall -Wextra -Werror -Iheader/ -Iminilibx_linux

# Добавляем все .c файлы из указанных папок
SOURCE := game/*.c
GETNEXTLINE := get_next/*.c

# Пути и флаги для подключения библиотек
LIBRARY := -Lminilibx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Путь к minilibx
MINILIBX := minilibx_linux/

all: $(NAME)

$(NAME):
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:
	make clean -C $(MINILIBX)

fclean: clean
	rm -rf $(NAME)

re: fclean all
