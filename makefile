all:
	@gcc -o picmaker picmaker.c
	@./picmaker

clean:
	@rm picmaker *.ppm
