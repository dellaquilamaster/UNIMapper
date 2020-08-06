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

RLIBS     := -L$(UNIMapperSrc)lib -lUNIMDetector -lUNIMSiliconPad

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall -Wpedantic

UNIMSILICONPAD_LIB := libUNIMSiliconHodoscope.$(DllSuf)
SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

UNIMSILICONPAD_DICT  := UNIMSiliconHodoscopeDict.$(SrcSuf)
UNIMSILICONPAD_DICTH := $(UNIMSILICONPAD_DICT:.$(SrcSuf)=.h)
UNIMSILICONPAD_DICTO := $(UNIMSILICONPAD_DICT:.$(SrcSuf)=.$(ObjSuf))
UNIMSILICONPAD_PCM   := UNIMSiliconHodoscopeDict$(PcmSuf)

UNIMSILICONPAD_HDRS  := $(wildcard UNIM*.$(SrcSuf))
UNIMSILICONPAD_HDRS  := $(UNIMSILICONPAD_HDRS:.$(SrcSuf)=.h) UNIMSiliconHodoscopeLinkDef.h
UNIMSILICONPAD_HDRS  := $(filter-out $(UNIMSILICONPAD_DICTH),$(UNIMSILICONPAD_HDRS))

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

all: $(UNIMSILICONPAD_LIB)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf) .$(PcmSuf)

$(UNIMSILICONPAD_DICT): $(UNIMSILICONPAD_HDRS)
	@echo "Generating dictionary $@..."
	rootcling -f $@ -p $(INCLUDES) $^

$(UNIMSILICONPAD_LIB): $(OBJS) $(UNIMSILICONPAD_DICTO)
	@$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)
	@echo "$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)"

install:
	@echo "cp $(UNIMSILICONPAD_LIB) $(UNIMSILICONPAD_PCM) $(UNIMapperSrc)lib/."
	@cp $(UNIMSILICONPAD_LIB) $(UNIMSILICONPAD_PCM) $(UNIMapperSrc)lib/.

.PHONY: distclean
distclean:
	@rm -f $(UNIMSILICONPAD_LIB) $(UNIMSILICONPAD_DICT) $(UNIMSILICONPAD_DICTH) $(UNIMSILICONPAD_PCM) $(OBJS)
	@rm -f $(UNIMapperSrc)lib/$(UNIMSILICONPAD_LIB) $(UNIMapperSrc)lib/$(UNIMSILICONPAD_PCM) $(OBJS)

.PHONY: clean
clean:
	@$(RM) -f $(UNIMSILICONPAD_LIB) $(UNIMSILICONPAD_DICT) $(UNIMSILICONPAD_DICTH) $(UNIMSILICONPAD_PCM) $(OBJS)
	@$(RM) -f *.expand

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)
