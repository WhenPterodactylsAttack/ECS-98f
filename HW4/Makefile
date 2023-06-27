all: translator_unittests report.html

translator_unittests: translator_unittests.c translator_tools.c translator_tools.h
	gcc --coverage -g -O0 translator_unittests.c translator_tools.c -lcunit -o translator_unittests
	./translator_unittests

report.html: translator_unittests translator_unittests.gcda translator_unittests.gcno translator_tools.gcda translator_tools.gcno
	gcovr --html-details -o report.html

.PHONY: clean
clean:
	rm -rf *.o *.exe translator_unittests *.gcno *.gcda
