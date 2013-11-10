run:
	sbt "project cpu" "run --targetDir /home/eecs/wenyu/auto-pipelining/fsm-test/emulator"

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
