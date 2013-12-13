run: build
	sbt "project cpu" "run -backannotation --autoPipe --targetDir generated"
build:
	sbt "project cpu" "run -vbuild --targetDir generated"
dc:
	mkdir -p generated/dc-syn
	cd generated/dc-syn; dc_shell -64bit -f gentcl.tcl
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
