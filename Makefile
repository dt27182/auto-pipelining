run:
	cd ../chisel && sbt publish-local
	sbt run

clean:
	rm -f *.cpp
	rm -f *.h
	rm -f *.o
	rm -rf target
	rm Hello
	rm *.vpd
	rm *.vcd
