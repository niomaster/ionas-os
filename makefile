all:
	as86 boot.s -o boot.o
	ld86 -d boot.o -o boot
	rm boot.o
	g++ -c kernel.cpp -o kernel.o
	ld -static kernel.o -o kernel -lcrt0 --oformat=binary
	rm kernel.o
	./write
