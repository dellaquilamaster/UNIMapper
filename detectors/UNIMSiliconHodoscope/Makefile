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
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMSiliconPad
INCLUDES  += -I$(UNIMapperSrc)detectors/UNIMSiliconHodoscope
INCLUDES  += -I$(UNIMapperSrc)UNIMRunInfo
INCLUDES  += -I$(UNIMapperSrc)UNIMExperimentalSetup
INCLUDES  += -I$(UNIMapperSrc)UNIMDetectorMap
INCLUDES  += -I$(UNIMapperSrc)UNIMCalibration
INCLUDES  += -I$(UNIMapperSrc)UNIMShared

RLIBS     := -L$(UNIMapperSrc)lib -lUNIMDetector -lUNIMCalibration

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall -Wpedantic

UNIMSILICONHODOSCOPE_LIB := libUNIMSiliconHodoscope.$(DllSuf)
SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

UNIMSILICONHODOSCOPE_DICT  := UNIMSiliconHodoscopeDict.$(SrcSuf)
UNIMSILICONHODOSCOPE_DICTH := $(UNIMSILICONHODOSCOPE_DICT:.$(SrcSuf)=.h)
UNIMSILICONHODOSCOPE_DICTO := $(UNIMSILICONHODOSCOPE_DICT:.$(SrcSuf)=.$(ObjSuf))
UNIMSILICONHODOSCOPE_PCM   := UNIMSiliconHodoscopeDict$(PcmSuf)

UNIMSILICONHODOSCOPE_HDRS  := $(wildcard UNIM*.$(SrcSuf))
UNIMSILICONHODOSCOPE_HDRS  := $(UNIMSILICONHODOSCOPE_HDRS:.$(SrcSuf)=.h) UNIMSiliconHodoscopeLinkDef.h
UNIMSILICONHODOSCOPE_HDRS  := $(filter-out $(UNIMSILICONHODOSCOPE_DICTH),$(UNIMSILICONHODOSCOPE_HDRS))

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

all: $(UNIMSILICONHODOSCOPE_LIB)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf) .$(PcmSuf)

$(UNIMSILICONHODOSCOPE_DICT): $(UNIMSILICONHODOSCOPE_HDRS)
	@echo "Generating dictionary $@..."
	rootcling -f $@ -p $(INCLUDES) $^

$(UNIMSILICONHODOSCOPE_LIB): $(OBJS) $(UNIMSILICONHODOSCOPE_DICTO)
	@$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)
	@echo "$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)"

install:
	@echo "cp $(UNIMSILICONHODOSCOPE_LIB) $(UNIMSILICONHODOSCOPE_PCM) $(UNIMapperSrc)lib/."
	@cp $(UNIMSILICONHODOSCOPE_LIB) $(UNIMSILICONHODOSCOPE_PCM) $(UNIMapperSrc)lib/.

.PHONY: distclean
distclean:
	@rm -f $(UNIMSILICONHODOSCOPE_LIB) $(UNIMSILICONHODOSCOPE_DICT) $(UNIMSILICONHODOSCOPE_DICTH) $(UNIMSILICONHODOSCOPE_PCM) $(OBJS)
	@rm -f $(UNIMapperSrc)lib/$(UNIMSILICONHODOSCOPE_LIB) $(UNIMapperSrc)lib/$(UNIMSILICONHODOSCOPE_PCM) $(OBJS)

.PHONY: clean
clean:
	@$(RM) -f $(UNIMSILICONHODOSCOPE_LIB) $(UNIMSILICONHODOSCOPE_DICT) $(UNIMSILICONHODOSCOPE_DICTH) $(UNIMSILICONHODOSCOPE_PCM) $(OBJS)
	@$(RM) -f *.expand

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)
