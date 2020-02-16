CFLAGS    :=`root-config --cflags --libs`

DllSuf    := so
SrcSuf    := cpp
ObjSuf    := o
PcmSuf    := _rdict.pcm

INCLUDES  := -I$(UNIMapperSrc)
INCLUDES  += -I$(UNIMapperSrc)UNIMRawDataReader
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMDetector
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMDSSSD
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMLampWedge
INCLUDES  += -I$(UNIMapperSrc)UNIMRunInfo
INCLUDES  += -I$(UNIMapperSrc)UNIMExperimentalSetup
INCLUDES  += -I$(UNIMapperSrc)UNIMDetectorMap
INCLUDES  += -I$(UNIMapperSrc)UNIMCalibration
INCLUDES  += -I$(UNIMapperSrc)UNIMShared

RLIBS     := -L$(UNIMapperSrc)lib -lUNIMDetector

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall -Wpedantic

UNIMDSSSD_LIB := libUNIMDSSSD.$(DllSuf)
SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

UNIMDSSSD_DICT  := UNIMDSSSDDict.$(SrcSuf)
UNIMDSSSD_DICTH := $(UNIMDSSSD_DICT:.$(SrcSuf)=.h)
UNIMDSSSD_DICTO := $(UNIMDSSSD_DICT:.$(SrcSuf)=.$(ObjSuf))
UNIMDSSSD_PCM   := UNIMDSSSDDict$(PcmSuf)

UNIMDSSSD_HDRS  := $(wildcard UNIM*.$(SrcSuf))
UNIMDSSSD_HDRS  := $(UNIMDSSSD_HDRS:.$(SrcSuf)=.h) UNIMDSSSDLinkDef.h
UNIMDSSSD_HDRS  := $(filter-out $(UNIMDSSSD_DICTH),$(UNIMDSSSD_HDRS))

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

all: $(UNIMDSSSD_LIB)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf) .$(PcmSuf)

$(UNIMDSSSD_DICT): $(UNIMDSSSD_HDRS)
	@echo "Generating dictionary $@..."
	rootcling -f $@ -p $(INCLUDES) $^

$(UNIMDSSSD_LIB): $(OBJS) $(UNIMDSSSD_DICTO)
	@$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)
	@echo "$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)"

install:
	@echo "cp $(UNIMDSSSD_LIB) $(UNIMDSSSD_PCM) $(UNIMapperSrc)lib/."
	@cp $(UNIMDSSSD_LIB) $(UNIMDSSSD_PCM) $(UNIMapperSrc)lib/.

.PHONY: distclean
distclean:
	@rm -f $(UNIMDSSSD_LIB) $(UNIMDSSSD_DICT) $(UNIMDSSSD_DICTH) $(UNIMDSSSD_PCM) $(OBJS)
	@rm -f $(UNIMapperSrc)lib/$(UNIMDSSSD_LIB) $(UNIMapperSrc)lib/$(UNIMDSSSD_PCM) $(OBJS)

.PHONY: clean
clean:
	@$(RM) -f $(UNIMDSSSD_LIB) $(UNIMDSSSD_DICT) $(UNIMDSSSD_DICTH) $(UNIMDSSSD_PCM) $(OBJS)
	@$(RM) -f *.expand

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)
