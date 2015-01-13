################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cell.cpp \
../src/GUI.cpp \
../src/Minefield.cpp \
../src/Minesweeper.cpp \
../src/Texture.cpp \
../src/lodepng.cpp 

OBJS += \
./src/Cell.o \
./src/GUI.o \
./src/Minefield.o \
./src/Minesweeper.o \
./src/Texture.o \
./src/lodepng.o 

CPP_DEPS += \
./src/Cell.d \
./src/GUI.d \
./src/Minefield.d \
./src/Minesweeper.d \
./src/Texture.d \
./src/lodepng.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


