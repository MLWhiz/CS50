#
# Makefile
#
# David J. Malan
# malan@harvard.edu
#

all: bounce button checkbox click cursor label slider text window

bounce: bounce.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o bounce bounce.c -lcs -lm

button: button.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o button button.c -lcs -lm

checkbox: checkbox.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o checkbox checkbox.c -lcs -lm

click: click.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o click click.c -lcs -lm

cursor: cursor.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o cursor cursor.c -lcs -lm

label: label.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o label label.c -lcs -lm

slider: slider.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o slider slider.c -lcs -lm

text: text.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o text text.c -lcs -lm

window: window.c Makefile
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o window window.c -lcs -lm

clean:
	rm -f *.o core bounce button checkbox click cursor label slider text window
