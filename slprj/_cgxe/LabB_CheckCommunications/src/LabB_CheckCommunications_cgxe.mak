# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL  = LabB_CheckCommunications
TARGET = cgxe
MODULE_SRCS 	= m_79H60AoriwQj1LzelpYjTG.c
MODEL_SRC	= LabB_CheckCommunications_cgxe.c
MODEL_REG = LabB_CheckCommunications_cgxe_registry.c
MAKEFILE    = LabB_CheckCommunications_cgxe.mak
MATLAB_ROOT	= E:\MATLAB
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------


USER_INCLUDES   =  /I "E:\zaches bibliotek\r7003e - automatic control\labs\R7003E\slprj\_cgxe\labb_checkcommunications\src" /I "E:\zaches bibliotek\r7003e - automatic control\labs\R7003E" /I "E:\zaches bibliotek\r7003e - automatic control\labs\R7003E\LabB\matlabandsimulink" /I "E:\Zaches Bibliotek\R7003E - Automatic Control\labs\R7003E\slprj\_cprj"

MLSL_INCLUDES     = \
    /I "E:\MATLAB\extern\include" \
    /I "E:\MATLAB\simulink\include" \
    /I "E:\MATLAB\rtw\c\src"
COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   =  /I "E:\Zaches Bibliotek\R7003E - Automatic Control\labs\R7003E\slprj\_cgxe\LabB_CheckCommunications\src" /I "E:\Zaches Bibliotek\R7003E - Automatic Control\labs\R7003E"
INCLUDE_PATH = $(MLSL_INCLUDES) $(USER_INCLUDES) $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"
CFLAGS = /c /Zp8 /GR /w /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_MEXCMD_RELEASE=R2018a /DMATLAB_MEX_FILE /nologo /MD   
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion  
#----------------------------- Source Files -----------------------------------

USER_OBJS =

AUX_SRCS = E:\MATLAB\extern\version\c_mexapi_version.c  

REQ_SRCS  = $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS) $(AUX_SRCS)
REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = LabB_CheckCommunications_cgxe.mol
TMWLIB = "E:\MATLAB\extern\lib\win64\microsoft\libmx.lib" "E:\MATLAB\extern\lib\win64\microsoft\libmex.lib" "E:\MATLAB\extern\lib\win64\microsoft\libmat.lib" "E:\MATLAB\extern\lib\win64\microsoft\libfixedpoint.lib" "E:\MATLAB\extern\lib\win64\microsoft\libut.lib" "E:\MATLAB\extern\lib\win64\microsoft\libmwmathutil.lib" "E:\MATLAB\extern\lib\win64\microsoft\libemlrt.lib" "E:\MATLAB\extern\lib\win64\microsoft\libmwcgxert.lib" "E:\MATLAB\extern\lib\win64\microsoft\libmwslexec_simbridge.lib" "E:\MATLAB\extern\lib\win64\microsoft\libmwslccrt.lib" "E:\MATLAB\lib\win64\libmwipp.lib" "E:\MATLAB\extern\lib\win64\microsoft\libcovrt.lib" "E:\MATLAB\extern\lib\win64\microsoft\libmwsl_sfcn_cov_bridge.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
all : $(MEX_FILE_NAME) 


$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(TMWLIB) $(THIRD_PARTY_LIBS) @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

