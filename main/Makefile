CFLAGS    :=`root-config --cflags --libs`

PROG      :=exec_UNIMMapper.exe

DllSuf    := so
SrcSuf    := cpp
ObjSuf    := o

INCLUDES  := -I$(UNIMapperSrc)
INCLUDES  += -I$(UNIMapperSrc)main
INCLUDES  += -I$(UNIMapperSrc)UNIMRawDataReader
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMDetector
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMDSSSD
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMSSSSD
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMLampWedge
INCLUDES  += -I$(UNIMapperSrc)UNIMRunInfo
INCLUDES  += -I$(UNIMapperSrc)UNIMExperimentalSetup
INCLUDES  += -I$(UNIMapperSrc)UNIMDetectorMap
INCLUDES  += -I$(UNIMapperSrc)UNIMCalibration
INCLUDES  += -I$(UNIMapperSrc)UNIMShared

RLIBS     := -L$(UNIMapperSrc)lib -lUNIMRawDataReader -lUNIMDetector -lUNIMDSSSD -lUNIMRunInfo -lUNIMDetectorMap -lUNIMExperimentalSetup -lUNIMShared

SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall -Wpedantic

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

.PHONEY : all build
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)

all : build

build : $(PROG)

$(PROG) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(CFLAGS) $(RLIBS)

install:
	@cp $(PROG) $(UNIMapperSrc)/$(PROG)

.PHONY: clean
clean :
	rm -f $(OBJS) $(PROG)

.PHONY: distclean
distclean: clean
	@rm -f $(UNIMapperSrc)/$(PROG)

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)