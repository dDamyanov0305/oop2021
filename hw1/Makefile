mystring: MyString.o MyString_tests.o catch2.o
	g++ -o mystring MyString.o MyString_tests.o catch2.o

MyString.o: MyString.cpp
	g++ -c MyString.cpp

MyString_tests.o: MyString_tests.cpp
	g++ -c MyString_tests.cpp

catch2.o:
	g++ -c catch2.cpp

vehicle: Vehicle.o Vehicle_tests.o MyString.o
	g++ -o vehicle Vehicle.o MyString.o Vehicle_tests.o catch2.o

Vehicle.o: Vehicle.cpp
	g++ -c Vehicle.cpp

Vehicle_tests.o: Vehicle_tests.cpp
	g++ -c Vehicle_tests.cpp

garage: Garage.o Garage_tests.o Vehicle.o MyString.o
	g++ -o garage Garage.o Garage_tests.o Vehicle.o MyString.o catch2.o

Garage.o: Garage.cpp
	g++ -c Garage.cpp

Garage_tests.o: Garage_tests.cpp
	g++ -c Garage_tests.cpp

clean:
	$(RM) MyString.o MyString_tests.o mystring_main

clean_catch2:
	$(RM) catch2.o