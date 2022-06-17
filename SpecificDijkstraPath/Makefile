# Name of the binary
BINARY = prototyp
# Object files
#hier alle .cpp-Files einfügen, aber mit Endung .o
OBJS   = main.o extendedGraph.o edge.o
# Compiler flags
CFLAGS = -Werror -Wall -std=c++17
# Linker flags
LFLAGS =


# all target: builds all important targets
all: ${BINARY}


# Links the binary
${BINARY} : ${OBJS}
	g++ ${LFLAGS} -o ${BINARY} ${OBJS}


# Compiles a source-file (any file with file extension .c) into an object-file
#
# "%" is a wildcard which matches every file-name (similar to * in regular expressions)
# Such a rule is called a pattern rule (because it matches a pattern, see https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html),
# which are a form of so called implicit rules (see https://www.gnu.org/software/make/manual/html_node/Implicit-Rules.html)
# "$@" and "$<" are so called automatic variables (see https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)
%.o : %.cpp
	g++ -c ${CFLAGS} -o $@ $<


# Rules can not only be used for compiling a program but also for executing a program
run: ${BINARY}
	./${BINARY}


# Delete all build artifacts
clean :
	rm -rf ${BINARY} ${OBJS}


# all  and clean are a "phony" targets, meaning they are no files
.PHONY : all clean