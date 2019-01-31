all:
	@gcc -o picmaker picmaker.c
	@./picmaker

clean:
	@rm *.o picmaker *.png *.ppm
