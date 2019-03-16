DEPS = main.o chessboard_theme.o file_manager.o plot.o knight.o
EXEC = the-trapped-knight
DATAFILES = $(wildcard *.data)



all: pStart the-trapped-knight execute wclean pEnd


pStart:
	@echo
	@echo

the-trapped-knight: $(DEPS)
	-rm -rf $(EXEC) $(DATAFILES)
	gcc $(DEPS) -o $(EXEC)

execute: the-trapped-knight
	./the-trapped-knight

wclean:
	-rm -rf $(DEPS)


pEnd:
	@echo
	@echo



.PHONY: clean
clean:
	-rm -rf $(DEPS) $(EXEC) $(DATAFILES)
