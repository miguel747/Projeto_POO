#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=MinGW_1-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/arqtexto.o \
	${OBJECTDIR}/Persistencia.o \
	${OBJECTDIR}/ErroSave.o \
	${OBJECTDIR}/Tabuleiro.o \
	${OBJECTDIR}/Peca.o \
	${OBJECTDIR}/Casa.o \
	${OBJECTDIR}/jogo.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto_poo.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto_poo.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto_poo ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/arqtexto.o: arqtexto.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/arqtexto.o arqtexto.cpp

${OBJECTDIR}/Persistencia.o: Persistencia.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Persistencia.o Persistencia.cpp

${OBJECTDIR}/ErroSave.o: ErroSave.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ErroSave.o ErroSave.cpp

${OBJECTDIR}/Tabuleiro.o: Tabuleiro.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tabuleiro.o Tabuleiro.cpp

${OBJECTDIR}/Peca.o: Peca.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Peca.o Peca.cpp

${OBJECTDIR}/Casa.o: Casa.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Casa.o Casa.cpp

${OBJECTDIR}/jogo.o: jogo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/jogo.o jogo.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/RunnerTestArqTexto.o ${TESTDIR}/RunnerTestTabuleiro.o ${TESTDIR}/testClassArqTexto.o ${TESTDIR}/testClassTabuleiro.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} ../../trabalho/save/cppunit-1.12.1/lib/libcppunit.a -lcppunit ../../../Unb/POO/trabalho/save/cppunit-1.12.1/lib/libcppunit.a 


${TESTDIR}/RunnerTestArqTexto.o: RunnerTestArqTexto.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../Unb/POO/trabalho/save/cppunit-1.12.1/include -I../../trabalho/save/cppunit-1.12.1/include -MMD -MP -MF $@.d -o ${TESTDIR}/RunnerTestArqTexto.o RunnerTestArqTexto.cpp


${TESTDIR}/RunnerTestTabuleiro.o: RunnerTestTabuleiro.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../Unb/POO/trabalho/save/cppunit-1.12.1/include -I../../trabalho/save/cppunit-1.12.1/include -MMD -MP -MF $@.d -o ${TESTDIR}/RunnerTestTabuleiro.o RunnerTestTabuleiro.cpp


${TESTDIR}/testClassArqTexto.o: testClassArqTexto.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../Unb/POO/trabalho/save/cppunit-1.12.1/include -I../../trabalho/save/cppunit-1.12.1/include -MMD -MP -MF $@.d -o ${TESTDIR}/testClassArqTexto.o testClassArqTexto.cpp


${TESTDIR}/testClassTabuleiro.o: testClassTabuleiro.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../Unb/POO/trabalho/save/cppunit-1.12.1/include -I../../trabalho/save/cppunit-1.12.1/include -MMD -MP -MF $@.d -o ${TESTDIR}/testClassTabuleiro.o testClassTabuleiro.cpp


${OBJECTDIR}/arqtexto_nomain.o: ${OBJECTDIR}/arqtexto.o arqtexto.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/arqtexto.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/arqtexto_nomain.o arqtexto.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/arqtexto.o ${OBJECTDIR}/arqtexto_nomain.o;\
	fi

${OBJECTDIR}/Persistencia_nomain.o: ${OBJECTDIR}/Persistencia.o Persistencia.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Persistencia.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Persistencia_nomain.o Persistencia.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Persistencia.o ${OBJECTDIR}/Persistencia_nomain.o;\
	fi

${OBJECTDIR}/ErroSave_nomain.o: ${OBJECTDIR}/ErroSave.o ErroSave.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ErroSave.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/ErroSave_nomain.o ErroSave.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ErroSave.o ${OBJECTDIR}/ErroSave_nomain.o;\
	fi

${OBJECTDIR}/Tabuleiro_nomain.o: ${OBJECTDIR}/Tabuleiro.o Tabuleiro.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Tabuleiro.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tabuleiro_nomain.o Tabuleiro.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Tabuleiro.o ${OBJECTDIR}/Tabuleiro_nomain.o;\
	fi

${OBJECTDIR}/Peca_nomain.o: ${OBJECTDIR}/Peca.o Peca.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Peca.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Peca_nomain.o Peca.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Peca.o ${OBJECTDIR}/Peca_nomain.o;\
	fi

${OBJECTDIR}/Casa_nomain.o: ${OBJECTDIR}/Casa.o Casa.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Casa.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Casa_nomain.o Casa.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Casa.o ${OBJECTDIR}/Casa_nomain.o;\
	fi

${OBJECTDIR}/jogo_nomain.o: ${OBJECTDIR}/jogo.o jogo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/jogo.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/jogo_nomain.o jogo.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/jogo.o ${OBJECTDIR}/jogo_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projeto_poo.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
