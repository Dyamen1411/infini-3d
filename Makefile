#!/usr/bin/make -f
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#
# Author : Alan "Lailouezzz" Le Bouder <alan.le-bouder@univ-rouen.fr>
#
# Description of source tree :
# └── include
#     └── <header>.h
# └── src
#     └── <compilunit>.c
#
# After compilation :
# - $(OBJDIR) contain all object files and gcc generated dependencies
# - $(OUTDIR) contain the executable
#
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# ---
# General targets
# ---

# Build everything

all: _all

# Include vars and msg module

include Makefile.vars Makefile.msg

_all: $(OUTDIR)/$(BIN)

# Mostly clean (clean everything but the end result)

clean: 
	$(call rmsg,Removing the object folder ($(OBJDIR)))
	$(call qcmd,$(RM) -rf $(OBJDIR))

mclean: clean

# Clean everything

fclean: clean 
	$(call rmsg,Removing the output binary folder ($(OUTDIR)))
	$(call qcmd,$(RM) -rf $(OUTDIR))

# Clean libs

cleanlibs: $(LIBS_CLEAN_RULE)
	$(call rmsg,Clean libs ($(LIBS)))

# Fclean libs

fcleanlibs: cleanlibs $(LIBS_FCLEAN_RULE)
	$(call rmsg,Fclean libs ($(LIBS)))

# To original state

mrproper: fclean fcleanlibs
	$(call rmsg,Removing the configuration file (Makefile.cfg))
	$(call qcmd,$(RM) -rf Makefile.cfg)

# Remake everything

re: fclean all

# Make the doxygen documentation

doc: doc/Doxyfile
	$(call bcmd,doxygen,$<,doxygen $<)

# Clean the doxygen documentation

cleandoc:
	$(call rmsg,Removing the documentation (doc/html doc/man))
	$(call qcmd,$(RM) -rf doc/html doc/man)

.PHONY: _all all clean mclean fclean cleanlibs fcleanlibs mrproper re doc cleandoc

# ---
# Check configuration
# ---

Makefile.cfg:
	$(call emsg,Makefile.cfg missing did you "./configure")
	@exit 1

# ---
# Folders targets
# ---

# Make the binary

$(OUTDIR)/$(BIN): $(LIBS_MAKE_RULE) $(OBJS)
	$(call qcmd,$(MKDIR) -p $(@D))
	$(call bcmd,ld,$(OBJS),$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LD_LIBS))

# Make objects

$(OBJDIR)/%.o: $(SRCDIR)/%
	$(call qcmd,$(MKDIR) -p $(@D))
	$(call bcmd,cc,$<,$(CC) -c $(CFLAGS) -o $@ $<)

# Include generated dep by cc

-include $(DEP)
