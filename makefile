all:
	@echo Compiling bootloader...
	@as86 boot.s -o boot.o
	@ld86 -d boot.o -o boot
	@rm boot.o

	@echo Compiling kernel...
	@g++ -c -nostdlib kernel.cpp -o kernel.o
	@g++ -c -nostdlib io.cpp -o io.o
	@g++ -c -nostdlib string.cpp -o string.o
	@g++ -c -nostdlib kernelStart.s -o kernelStart.o
	@ld kernel.o string.o io.o kernelStart.o -o kernel --oformat=binary
	@rm kernel.o kernelStart.o

	@echo Writing to iso...
	@./write
	@rm kernel
	@rm boot
	@echo All done!
