ROOT=..
MODULE=modulename
HOME=$(ROOT)/$(MODULE)

#----------------------------------------------------------
# Path for project directories
#----------------------------------------------------------
SDIR=$(HOME)/src
IDIR=$(HOME)/include
ODIR=$(HOME)/obj
LDIR=$(HOME)/lib

#----------------------------------------------------------
# Compiler and it option
#----------------------------------------------------------
CC=gcc
CFLAGS= -Wall -c
LFLAGS=
LDIR=
LIBS=

#----------------------------------------------------------
# Source files
#----------------------------------------------------------
OUT=$(ODIR)/$(MODULE).out
CSRCS= $(wildcard $(SDIR)/*.c)
OBJS=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(CSRCS))

#----------------------------------------------------------
# Pattern rules
#----------------------------------------------------------
$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	$(CC) $(CFLAGS) $^ -o $@

#----------------------------------------------------------
# Rules
#----------------------------------------------------------
all: $(OUT)

$(OUT): $(OBJS)
	@echo "Generating output file..."
	$(CC) $(LFLAGS) $(LDIR) $(LIBS) $(OBJS) -o $@
	@echo "Performing clean up..."
	@rm $(OBJS)

$(ODIR):
	@mkdir -p $@
	@echo "Object directory created...!!"

clean:
	@rm -rf $(ODIR)

print-%  : ; @echo $* = $($*)

.phony: all clean
