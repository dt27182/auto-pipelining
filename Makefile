run:
	sbt "project cpu" "run -ctest --autoPipe --targetDir /home/cc/cs250/fa13/class/cs250-ao/auto-pipelining/emulator"
build:
	sbt "project cpu" "run -vbuild --autoPipe --targetDir /home/cc/cs250/fa13/class/cs250-ao/auto-pipelining/vlsi/build/generated-src"
clean:
	sbt "project chisel" clean
	sbt "project cpu" clean
	rm -f emulator/*.cpp
	rm -f emulator/*.h
	rm -f emulator/*.o
	rm -rf target
	rm -f emulator/Hello
	rm *.vpd
	rm *.vcd
