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

RLIBS     := -L$(UNIMapperSrc)lib -lUNIMDetector

CXXFLAGS  += $(INCLUDES) -std=c++11 -fPIC -O3 -Wall -Wpedantic

UNIMLAMPWEDGE_LIB := libUNIMLampWedge.$(DllSuf)
SRCS = $(wildcard *.$(SrcSuf))
OBJS = $(patsubst %.$(SrcSuf), %.$(ObjSuf), $(SRCS))

UNIMLAMPWEDGE_DICT  := UNIMLampWedgeDict.$(SrcSuf)
UNIMLAMPWEDGE_DICTH := $(UNIMLAMPWEDGE_DICT:.$(SrcSuf)=.h)
UNIMLAMPWEDGE_DICTO := $(UNIMLAMPWEDGE_DICT:.$(SrcSuf)=.$(ObjSuf))
UNIMLAMPWEDGE_PCM   := UNIMLampWedgeDict$(PcmSuf)

UNIMLAMPWEDGE_HDRS  := $(wildcard UNIM*.$(SrcSuf))
UNIMLAMPWEDGE_HDRS  := $(UNIMLAMPWEDGE_HDRS:.$(SrcSuf)=.h) UNIMLampWedgeLinkDef.h
UNIMLAMPWEDGE_HDRS  := $(filter-out $(UNIMLAMPWEDGE_DICTH),$(UNIMLAMPWEDGE_HDRS))

.$(SrcSuf).$(ObjSuf):
	@$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)
	@echo "$(CXX) $(CXXFLAGS) -c $< $(SYSLIB) $(CFLAGS)"

all: $(UNIMLAMPWEDGE_LIB)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf) .$(PcmSuf)

$(UNIMLAMPWEDGE_DICT): $(UNIMLAMPWEDGE_HDRS)
	@echo "Generating dictionary $@..."
	rootcling -f $@ -p $(INCLUDES) $^

$(UNIMLAMPWEDGE_LIB): $(OBJS) $(UNIMLAMPWEDGE_DICTO)
	@$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)
	@echo "$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(CFLAGS) $(RLIBS)"

install:
	@echo "cp $(UNIMLAMPWEDGE_LIB) $(UNIMLAMPWEDGE_PCM) $(UNIMapperSrc)lib/."
	@cp $(UNIMLAMPWEDGE_LIB) $(UNIMLAMPWEDGE_PCM) $(UNIMapperSrc)lib/.

.PHONY: distclean
distclean:
	@rm -f $(UNIMLAMPWEDGE_LIB) $(UNIMLAMPWEDGE_DICT) $(UNIMLAMPWEDGE_DICTH) $(UNIMLAMPWEDGE_PCM) $(OBJS)
	@rm -f $(UNIMapperSrc)lib/$(UNIMLAMPWEDGE_LIB) $(UNIMapperSrc)lib/$(UNIMLAMPWEDGE_PCM) $(OBJS)

.PHONY: clean
clean:
	@$(RM) -f $(UNIMLAMPWEDGE_LIB) $(UNIMLAMPWEDGE_DICT) $(UNIMLAMPWEDGE_DICTH) $(UNIMLAMPWEDGE_PCM) $(OBJS)
	@$(RM) -f *.expand

.PHONY: lint
lint:
	$(LINT) $(INC_SRCH_PATH) $(SRCS)
