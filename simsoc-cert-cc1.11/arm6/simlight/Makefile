# SimSoC-Cert, a toolkit for generating certified processor simulators
# See the COPYRIGHTS and LICENSE files.

DIR := ../..

COQ_INCLUDES := -I $(DIR)/coq

include $(DIR)/Makefile.common

default: simlight

######################################################################
# compilation of simlight

CPPFLAGS := #-I$(DIR)/tools/bin2elf
#CFLAGS := -Wall -Wextra -Wno-unused -Werror -g
#CC := ccomp -fstruct-assign -fno-longlong

SOURCES_MO := common.c elf_loader.c arm_mmu.c arm_system_coproc.c slv6_math.c \
	slv6_mode.c slv6_status_register.c slv6_processor.c slv6_condition.c \
	arm_not_implemented.c

SOURCES := $(SOURCES_MO) slv6_iss.c

OBJECTS := $(SOURCES:%.c=%.o) simlight.o

HEADERS := $(DIR)/tools/bin2elf/elf.h \
	int64_init.h int64_config.h int64_native.h int64_emul.h \
	$(SOURCES_MO:%.c=%.h) \
	slv6_iss_c_prelude.h slv6_iss_h_prelude.h \
	slv6_iss.h

simlight: $(OBJECTS)
	$(CC) $^ -o simlight

%.o: %.c $(HEADERS)
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

slv6_iss.h slv6_iss.c: $(SIMGEN) ../arm6.pc ../arm6.dec
	$(SIMGEN) -ocxx slv6_iss -ipc ../arm6.pc -idec ../arm6.dec

../arm6.pc ../arm6.dec: FORCE
	$(MAKE) -C .. $(@:../%=%)

simlight.opt: FORCE
	gcc simlight.c $(SOURCES:%=--include %) -g -DNDEBUG -O3 -I../elf -o $@

clean::
	rm -f $(OBJECTS) slv6_iss.[ch] simlight simlight.opt

######################################################################
# representation of simlight in Coq

.PHONY: proof

proof: libcoq all.vo

all.vo: $(DIR)/coq/Cnotations.vo

.PRECIOUS: all.v

all.c: $(HEADERS) $(SOURCES) simlight.c
	cat $+ | sed -e 's|#include "\(.*\)|//#include "\1|' -e 's|#include <elf.h>|//#include <elf.h>|' > $@

clean::
	rm -f all.c all.v all.glob all.vo

######################################################################
# extraction

ocaml: extraction-libcoq extraction
	$(SHOW) ocamlbuild arm6/simlight/extraction/all.cmo
	$(HIDE) $(OCAMLBUILD) arm6/simlight/extraction/all.cmo

extraction.v: all.vo

######################################################################
# dependency graph

simlight.dep: FORCE
	grep '#include ' $(HEADERS) $(SOURCES) simlight.c | sed -e 's|#include||' -e 's|["<>]||g' -e 's|\([^/]*\)/||g' > $@

clean::
	rm -f simlight.dep

.PHONY: depend

depend: simlight.ps
	gv $< &
