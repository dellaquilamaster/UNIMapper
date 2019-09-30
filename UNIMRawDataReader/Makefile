CFLAGS    :=`root-config --cflags --libs`

DllSuf    := so
SrcSuf    := cpp
ObjSuf    := o
PcmSuf    := _rdict.pcm

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

RLIBS     := -L$(UNIMapperSrc)lib

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall -Wpedantic

UNIMRAWDATAREADER_LIB := libUNIMRawDataReader.$(DllSuf)
SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

M2RMIDASROOTEVENT_DICT  := M2RMidasRootEventDict.$(SrcSuf)
M2RMIDASROOTEVENT_DICTH := $(M2RMIDASROOTEVENT_DICT:.$(SrcSuf)=.h)
M2RMIDASROOTEVENT_DICTO := $(M2RMIDASROOTEVENT_DICT:.$(SrcSuf)=.$(ObjSuf))
M2RMIDASROOTEVENT_PCM   := M2RMidasRootEventDict$(PcmSuf)

M2RMIDASROOTEVENT_HDRS  := $(wildcard M2R*.$(SrcSuf))
M2RMIDASROOTEVENT_HDRS  := $(M2RMIDASROOTEVENT_HDRS:.$(SrcSuf)=.h) M2RMidasRootEventLinkDef.h
M2RMIDASROOTEVENT_HDRS  := $(filter-out $(M2RMIDASROOTEVENT_DICTH),$(M2RMIDASROOTEVENT_HDRS))

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

all: $(UNIMRAWDATAREADER_LIB)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf) .$(PcmSuf)

$(M2RMIDASROOTEVENT_DICT): $(M2RMIDASROOTEVENT_HDRS)
	@echo "Generating dictionary $@..."
	rootcling -f $@ -p $(INCLUDES) $^

$(UNIMRAWDATAREADER_LIB): $(OBJS) $(M2RMIDASROOTEVENT_DICTO)
	@$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)
	@echo "$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)"

install:
	@echo "cp $(UNIMRAWDATAREADER_LIB) $(M2RMIDASROOTEVENT_PCM) $(UNIMapperSrc)lib/."
	@cp $(UNIMRAWDATAREADER_LIB) $(M2RMIDASROOTEVENT_PCM) $(UNIMapperSrc)lib/.

.PHONY: distclean
distclean:
	@rm -f $(UNIMRAWDATAREADER_LIB) $(M2RMIDASROOTEVENT_DICT) $(M2RMIDASROOTEVENT_DICTH) $(M2RMIDASROOTEVENT_PCM) $(OBJS)
	@rm -f $(UNIMapperSrc)lib/$(UNIMRAWDATAREADER_LIB) $(UNIMapperSrc)lib/$(M2RMIDASROOTEVENT_PCM) $(OBJS)

.PHONY: clean
clean:
	@$(RM) -f $(UNIMRAWDATAREADER_LIB) $(M2RMIDASROOTEVENT_DICT) $(M2RMIDASROOTEVENT_DICTH) $(M2RMIDASROOTEVENT_PCM) $(OBJS)
	@$(RM) -f *.expand

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)
