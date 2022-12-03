.SILENT:
all:
	make --no-print-directory -C mandatory

clean:
	make clean --no-print-directory -C mandatory

fclean:
	make fclean --no-print-directory -C mandatory
	rm -rf objs

re:
	make re --no-print-directory -C mandatory

run:
	make run --no-print-directory -C mandatory

valgrind:
	make valgrind --no-print-directory -C mandatory

bonus:
	make --no-print-directory -C bonus

clean_bonus:
	make clean --no-print-directory -C bonus

fclean_bonus:
	make fclean --no-print-directory -C bonus
	rm -rf objs

re_bonus:
	make re --no-print-directory -C bonus

run_bonus:
	make run --no-print-directory -C bonus

valgrind_bonus:
	make valgrind --no-print-directory -C bonus

fclean_all: fclean fclean_bonus
	rm -rf objs

.PHONY: all clean fclean re run valgrind bonus clean_bonus fclean_bonus re_bonus run_bonus valgrind_bonus fclean_all
