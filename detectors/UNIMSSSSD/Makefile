CFLAGS    :=`root-config --cflags --libs`

DllSuf    := so
SrcSuf    := cpp
ObjSuf    := o
PcmSuf    := _rdict.pcm

INCLUDES  := -I$(UNIMapperSrc)
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

RLIBS     := -L$(UNIMapperSrc)lib -lUNIMDetector -lUNIMDSSSD -lUNIMCalibration

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall -Wpedantic

UNIMSSSSD_LIB := libUNIMSSSSD.$(DllSuf)
SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

UNIMSSSSD_DICT  := UNIMSSSSDDict.$(SrcSuf)
UNIMSSSSD_DICTH := $(UNIMSSSSD_DICT:.$(SrcSuf)=.h)
UNIMSSSSD_DICTO := $(UNIMSSSSD_DICT:.$(SrcSuf)=.$(ObjSuf))
UNIMSSSSD_PCM   := UNIMSSSSDDict$(PcmSuf)

UNIMSSSSD_HDRS  := $(wildcard UNIM*.$(SrcSuf))
UNIMSSSSD_HDRS  := $(UNIMSSSSD_HDRS:.$(SrcSuf)=.h) UNIMSSSSDLinkDef.h
UNIMSSSSD_HDRS  := $(filter-out $(UNIMSSSSD_DICTH),$(UNIMSSSSD_HDRS))

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

all: $(UNIMSSSSD_LIB)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf) .$(PcmSuf)

$(UNIMSSSSD_DICT): $(UNIMSSSSD_HDRS)
	@echo "Generating dictionary $@..."
	rootcling -f $@ -p $(INCLUDES) $^

$(UNIMSSSSD_LIB): $(OBJS) $(UNIMSSSSD_DICTO)
	@$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)
	@echo "$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)"

install:
	@echo "cp $(UNIMSSSSD_LIB) $(UNIMSSSSD_PCM) $(UNIMapperSrc)lib/."
	@cp $(UNIMSSSSD_LIB) $(UNIMSSSSD_PCM) $(UNIMapperSrc)lib/.

.PHONY: distclean
distclean:
	@rm -f $(UNIMSSSSD_LIB) $(UNIMSSSSD_DICT) $(UNIMSSSSD_DICTH) $(UNIMSSSSD_PCM) $(OBJS)
	@rm -f $(UNIMapperSrc)lib/$(UNIMSSSSD_LIB) $(UNIMapperSrc)lib/$(UNIMSSSSD_PCM) $(OBJS)

.PHONY: clean
clean:
	@$(RM) -f $(UNIMSSSSD_LIB) $(UNIMSSSSD_DICT) $(UNIMSSSSD_DICTH) $(UNIMSSSSD_PCM) $(OBJS)
	@$(RM) -f *.expand

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)
