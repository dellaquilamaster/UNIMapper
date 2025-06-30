CXXFLAGS = -g

all:
	$(MAKE) root
	$(MAKE) -C main  ;			$(MAKE) -C main install

root:
	$(MAKE) -C UNIMShared ;				$(MAKE) -C UNIMShared install
	$(MAKE) -C UNIMRunInfo ;			$(MAKE) -C UNIMRunInfo install
	$(MAKE) -C UNIMCalibration ;			$(MAKE) -C UNIMCalibration install
	$(MAKE) -C detectors/UNIMDetector ;		$(MAKE) -C detectors/UNIMDetector install
	$(MAKE) -C detectors/UNIMDSSSD ;		$(MAKE) -C detectors/UNIMDSSSD install
	$(MAKE) -C detectors/UNIMSSSSD ;		$(MAKE) -C detectors/UNIMSSSSD install
	$(MAKE) -C detectors/UNIMLampWedge ;		$(MAKE) -C detectors/UNIMLampWedge install
	$(MAKE) -C detectors/UNIMSiliconPad ;		$(MAKE) -C detectors/UNIMSiliconPad install
	$(MAKE) -C detectors/UNIMSiliconHodoscope ;	$(MAKE) -C detectors/UNIMSiliconHodoscope install
	$(MAKE) -C detectors/UNIMSpare ;		$(MAKE) -C detectors/UNIMSpare install
	$(MAKE) -C UNIMExperimentalSetup ;		$(MAKE) -C UNIMExperimentalSetup install
	$(MAKE) -C UNIMDetectorMap ;			$(MAKE) -C UNIMDetectorMap install
	$(MAKE) -C UNIMMapper ;				$(MAKE) -C UNIMMapper install
	$(MAKE) -C UNIMRawDataReader ;			$(MAKE) -C UNIMRawDataReader install

install:
	$(MAKE) -C UNIMShared install
	$(MAKE) -C UNIMRunInfo install
	$(MAKE) -C UNIMMapper install
	$(MAKE) -C UNIMRawDataReader install
	$(MAKE) -C UNIMCalibration install
	$(MAKE) -C detectors/UNIMDetector install
	$(MAKE) -C detectors/UNIMDSSSD install
	$(MAKE) -C detectors/UNIMSSSSD install
	$(MAKE) -C detectors/UNIMLampWedge install
	$(MAKE) -C detectors/UNIMSiliconPad install
	$(MAKE) -C detectors/UNIMSiliconHodoscope install
	$(MAKE) -C detectors/UNIMSpare install
	$(MAKE) -C UNIMExperimentalSetup install
	$(MAKE) -C UNIMDetectorMap install

distclean:
	$(MAKE) -C UNIMShared distclean
	$(MAKE) -C UNIMRunInfo distclean
	$(MAKE) -C UNIMMapper distclean
	$(MAKE) -C UNIMRawDataReader distclean
	$(MAKE) -C UNIMCalibration distclean
	$(MAKE) -C detectors/UNIMDetector distclean
	$(MAKE) -C detectors/UNIMDSSSD distclean
	$(MAKE) -C detectors/UNIMSSSSD distclean
	$(MAKE) -C detectors/UNIMLampWedge distclean
	$(MAKE) -C detectors/UNIMSiliconPad distclean
	$(MAKE) -C detectors/UNIMSiliconHodoscope distclean
	$(MAKE) -C detectors/UNIMSpare distclean
	$(MAKE) -C UNIMExperimentalSetup distclean
	$(MAKE) -C UNIMDetectorMap distclean
	
	$(MAKE) -C main distclean

clean:
	$(MAKE) -C UNIMShared clean
	$(MAKE) -C UNIMRunInfo clean
	$(MAKE) -C UNIMRawDataReader clean
	$(MAKE) -C detectors/UNIMDetector clean
	$(MAKE) -C detectors/UNIMDSSSD clean
	$(MAKE) -C detectors/UNIMSSSSD clean
	$(MAKE) -C detectors/UNIMLampWedge clean
	$(MAKE) -C detectors/UNIMSiliconPad clean
	$(MAKE) -C detectors/UNIMSiliconHodoscope clean
	$(MAKE) -C detectors/UNIMSpare clean
	$(MAKE) -C UNIMExperimentalSetup clean
	$(MAKE) -C UNIMDetectorMap clean
	$(MAKE) -C UNIMCalibration clean

	$(MAKE) -C main clean
