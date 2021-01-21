COMPILER=g++

NameGrade: NameGrade.o StudentList.o Student.o stringFunctions.o inputFunctions.o grading.o
	$(COMPILER) NameGrade.o StudentList.o Student.o stringFunctions.o inputFunctions.o grading.o -o NameGrade

NameGrade.o:	NameGrade.cc StudentList.h
	$(COMPILER) -c NameGrade.cc

StudentList.o:	constants.h StudentList.h StudentList.cc stringFunctions.h inputFunctions.h
	$(COMPILER) -c StudentList.cc

Student.o: constants.h Student.h Student.cc stringFunctions.h grading.h
	$(COMPILER) -c Student.cc

stringFunctions.o: constants.h stringFunctions.h stringFunctions.cc
	$(COMPILER) -c stringFunctions.cc

inputFunctions.o: inputFunctions.h inputFunctions.cc constants.h
	$(COMPILER) -c inputFunctions.cc

grading.o: grading.h grading.cc
	$(COMPILER) -c grading.cc
