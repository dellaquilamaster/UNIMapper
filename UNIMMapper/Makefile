CFLAGS    :=`root-config --cflags --libs`

DllSuf    := so
SrcSuf    := cpp
ObjSuf    := o

INCLUDES  := -I$(UNIMapperSrc)
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMDetector
INCLUDES  += -I$(UNIMapperSrc)UNIMRawDataReader
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMDetector
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMDSSSD
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMSSSSD
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMLampWedge
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMSiliconPad
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMSiliconHodoscope
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMSpare
INCLUDES  += -I$(UNIMapperSrc)UNIMRunInfo
INCLUDES  += -I$(UNIMapperSrc)UNIMExperimentalSetup
INCLUDES  += -I$(UNIMapperSrc)UNIMDetectorMap
INCLUDES  += -I$(UNIMapperSrc)UNIMCalibration
INCLUDES  += -I$(UNIMapperSrc)UNIMShared
INCLUDES  += -I$(UNIMapperSrc)UNIMMapper

RLIBS     := -L$(UNIMapperSrc)lib -lUNIMShared -lUNIMRunInfo -lUNIMCalibration -lUNIMDetectorMap -lUNIMExperimentalSetup

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall -Wpedantic

UNIMSHARED_LIB := libUNIMMapper.$(DllSuf)
SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

all: $(UNIMSHARED_LIB)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)

$(UNIMSHARED_LIB): $(OBJS)
	@$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)
	@echo "$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)"

install:
	@echo "cp $(UNIMSHARED_LIB) $(UNIMapperSrc)lib/."
	@cp $(UNIMSHARED_LIB) $(UNIMapperSrc)lib/.

.PHONY: distclean
distclean:
	@rm -f $(UNIMSHARED_LIB) $(OBJS)
	@rm -f $(UNIMapperSrc)lib/$(UNIMSHARED_LIB)

.PHONY: clean
clean:
	@$(RM) -f $(UNIMSHARED_LIB) $(OBJS)
	@$(RM) -f *.expand

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)
