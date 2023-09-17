################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../children_math_game.c \
../DIO_DRIVER.c \
../EEPROM_DRIVER.c \
../functions.c \
../KEY_PAD_DRIVER.c \
../LCD_DRIVER.c \
../LED_DRIVER.c \
../PUSH_BUTTON.c \
../TIMER_DRIVER.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
children_math_game.o \
DIO_DRIVER.o \
EEPROM_DRIVER.o \
functions.o \
KEY_PAD_DRIVER.o \
LCD_DRIVER.o \
LED_DRIVER.o \
PUSH_BUTTON.o \
TIMER_DRIVER.o


OBJS_AS_ARGS +=  \
children_math_game.o \
DIO_DRIVER.o \
EEPROM_DRIVER.o \
functions.o \
KEY_PAD_DRIVER.o \
LCD_DRIVER.o \
LED_DRIVER.o \
PUSH_BUTTON.o \
TIMER_DRIVER.o


C_DEPS +=  \
children_math_game.d \
DIO_DRIVER.d \
EEPROM_DRIVER.d \
functions.d \
KEY_PAD_DRIVER.d \
LCD_DRIVER.d \
LED_DRIVER.d \
PUSH_BUTTON.d \
TIMER_DRIVER.d


C_DEPS_AS_ARGS +=  \
children_math_game.d \
DIO_DRIVER.d \
EEPROM_DRIVER.d \
functions.d \
KEY_PAD_DRIVER.d \
LCD_DRIVER.d \
LED_DRIVER.d \
PUSH_BUTTON.d \
TIMER_DRIVER.d


OUTPUT_FILE_PATH +=children_math_game.elf

OUTPUT_FILE_PATH_AS_ARGS +=children_math_game.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR32/GNU C Compiler



















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -O1 -fpack-struct -fshort-enums -g2 -Wall -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega32   -o"$@" "$<" 
	@echo Finished building: $<



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="children_math_game.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group  -mmcu=atmega32  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "children_math_game.elf" "children_math_game.hex"
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "children_math_game.elf" "children_math_game.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objdump.exe" -h -S "children_math_game.elf" > "children_math_game.lss"
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "children_math_game.elf" "children_math_game.srec"
	"C:\Program Files (x86)\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-size.exe" "children_math_game.elf"
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "children_math_game.elf" "children_math_game.a" "children_math_game.hex" "children_math_game.lss" "children_math_game.eep" "children_math_game.map" "children_math_game.srec"
	