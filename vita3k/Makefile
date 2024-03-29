.SUFFIXES:

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/ds_rules

#---------------------------------------------------------------------------------
# TARGET is the name of the output
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
#---------------------------------------------------------------------------------
TARGET       := $(shell basename $(CURDIR))
BUILD        := build
SOURCES      := . compat lang ime util nitro nitro/fs

VERSION      := 0.0.0
GAME_TITLE   := Vita3K
GAME_SUBTITLE1 := PS Vita emulator
GAME_SUBTITLE2 := v$(VERSION) - CoffeeBrewer64

#---------------------------------------------------------------------------------
# GAME_ICON := $(TOPDIR)/ICONAMEHERE.bmp
#---------------------------------------------------------------------------------

ARCH         := -mthumb -mthumb-interwork -march=armv5te -mtune=arm946e-s

CFLAGS       := -g -Wall -O2 -fomit-frame-pointer -ffast-math $(ARCH)
CFLAGS       += $(INCLUDE) -DARM9 -DNEDIT_VERSION=\"$(VERSION)\"
CXXFLAGS     := $(CFLAGS) -fno-rtti -fno-exceptions -std=gnu++17
ASFLAGS      := -g $(ARCH)
LDFLAGS      := -specs=ds_arm9.specs -g $(ARCH) -Wl,-Map,$(notdir $*.map) -Wl,-wrap,malloc -Wl,-wrap,free -Wl,-wrap,abort

#---------------------------------------------------------------------------------
# any extra libraries we wish to link with the project (order is important)
#---------------------------------------------------------------------------------
LIBS         := -lfat -lnds9
 
#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
LIBDIRS      := $(LIBNDS)
 
#---------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------
export TOPDIR := $(CURDIR)

export OUTPUT := $(CURDIR)/$(TARGET)

export VPATH  := $(CURDIR)

export DEPSDIR := $(CURDIR)/$(BUILD)

CFILES        := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.c))
CPPFILES      := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.cpp))
SFILES        := $(foreach dir,$(SOURCES),$(wildcard $(dir)/*.s))
BINFILES      := $(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))
 
#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#---------------------------------------------------------------------------------
export LD := $(CC)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
export LD := $(CXX)
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

export OFILES := $(addsuffix .o,$(BINFILES)) \
            $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
 
export INCLUDE := -I$(CURDIR) \
            $(foreach dir,$(SOURCES),-I$(dir)) \
            $(foreach dir,$(LIBDIRS),-I$(dir)/include) \
            -I$(CURDIR)/$(BUILD)
 
export LIBPATHS := $(foreach dir,$(LIBDIRS),-L$(dir)/lib)
 
.PHONY: $(BUILD) clean
 
#---------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@$(foreach dir,$(SOURCES),mkdir -p $(BUILD)/$(dir);)
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(BUILD) $(TARGET).elf $(TARGET).nds

#---------------------------------------------------------------------------------
else
 
#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
$(OUTPUT).nds: $(OUTPUT).elf
$(OUTPUT).nds: $(shell find $(TOPDIR)/$(NITRODATA))
$(OUTPUT).elf: $(OFILES)
 
#---------------------------------------------------------------------------------
%.bin.o: %.bin
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	$(bin2o)
 
-include $(DEPSDIR)/*.d
endif

