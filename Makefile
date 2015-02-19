all:
	chmod +x in
	sh in
	gcc shuffle/*.c -O3 -Wall -Wextra -lncurses -lpanel -o game

install:
	sudo cp run /usr/bin/ttyNs
	mkdir ~/.ttyNs
	cp -rf *.* game LICENSE ~/.ttyNs
clean: 
	sudo rm /usr/bin/ttyNs
	rm -rf ~/.ttyNs
	rm -rf *