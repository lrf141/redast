REDAST_SERVER_NAME=redast
REDAST_SERVER_OBJ=main.o opt.o

CCCOLOR="\033[34m"
LINKCOLOR="\033[34;1m"
ENDCOLOR="\033[0m"
SRCCOLOR="\033[33m"
BINCOLOR="\033[37;1m"
QUIET_CC = @printf '    %b %b\n' $(CCCOLOR)CC$(ENDCOLOR) $(SRCCOLOR)$@$(ENDCOLOR) 1>&2;
QUIET_LINK = @printf '    %b %b\n' $(LINKCOLOR)LINK$(ENDCOLOR) $(BINCOLOR)$@$(ENDCOLOR) 1>&2;

STD=-std=c11
ifneq (,$(findstring clang,$(CC)))
  STD+=-Wno-c11-extensions
endif
WARN=-Wall -W -Wno-missing-field-initializers
OPT=-O2
DEBUG=-g -ggdb
FINAL_CFLAGS=$(STD) $(WARN) $(OPT) $(DEBUG)
NODEPS=clean

FINAL_LIBS=-lm
REDAST_CC=$(QUIET_CC)$(CC) $(FINAL_CFLAGS)
REDAST_LD=$(QUIET_LINK)$(CC) $(FINAL_LDFLAGS)

Makefile.dep:
	-$(REDAST_CC) -MM *.c > Makefile.dep 2> /dev/null || true

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
-include Makefile.dep
endif

all: $(REDAST_SERVER_NAME)
	@echo ""
	@echo "Build Success :)"
	@echo ""

$(REDAST_SERVER_NAME): $(REDAST_SERVER_OBJ)
	$(REDAST_LD) -o $@ $^ $(FINAL_LIBS)

clean:
	rm -rf src/*.o
	rm -rf Makefile.dep
	rm -rf $(REDAST_SERVER_NAME)