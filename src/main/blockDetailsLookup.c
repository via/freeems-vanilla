/* FreeEMS - the open source engine management system
 *
 * Copyright 2008-2013 Fred Cooke
 *
 * This file is part of the FreeEMS project.
 *
 * FreeEMS software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FreeEMS software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with any FreeEMS software.  If not, see http://www.gnu.org/licenses/
 *
 * We ask that if you make any changes to this file you email them upstream to
 * us at admin(at)diyefi(dot)org or, even better, fork the code on github.com!
 *
 * Thank you for choosing FreeEMS to run your engine!
 */


/** @file
 *
 * @ingroup communicationsFiles
 *
 * @brief Memory block details lookup
 *
 * This file holds the single function lookupBlockDetails() which
 * functions as a sort of address book for logical blocks of memory.
 */


#define BLOCK_DETAILS_LOOKUP_C
#include "inc/freeEMS.h"
#include "inc/interrupts.h"
#include "inc/locationIDs.h"
#include "inc/pagedLocationBuffers.h"
#include "inc/blockDetailsLookup.h"


/** @brief Lookup memory block details.
 *
 * Flash only blocks leave the RAM address and page values
 * set to zero. ID's that don't exist return an error code.
 *
 * @note This function is an exception to the style rule switch statement
 * blocks of using a {} pair for each case statement. Readability is better
 * without them in this case.
 *
 * @param locationID is the ID of the memory location for which details are required.
 * @param details is a pointer to the blockDetails struct to populate with the details.
 *
 * @return An error code. Zero means success, anything else is a failure.
 */
unsigned short lookupBlockDetails(unsigned short locationID, blockDetails* details){
	/* Initialise the four values needed for operations on memory at 0 for error checking */
	details->RAMPage = 0;
	details->FlashPage = 0;
	details->RAMAddress = 0;
	details->FlashAddress = 0;

	/* Initialise the block size to 1024 to save code space and increase readability */
	details->size = sizeof(mainTable);

	// No need to set parent value to zero as ignored unless flag set, done for clarity in hex stream.
	details->parent = 0;

	/* Look up the locations and set non default sizes */
	switch (locationID) {
	/* flash only fixed conf full blocks */
	case FixedConfig1LocationID:
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&fixedConfigs1;
		break;
	case FixedConfig2LocationID:
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&fixedConfigs2;
		break;

	/* lookup tables */
	case IATTransferTableLocationID:
		details->size = sizeof(IATTransferTable);
		details->FlashPage = LOOKUP_PPAGE;
		details->FlashAddress = IATTransferTableLocation;
		break;
	case CHTTransferTableLocationID:
		details->size = sizeof(CHTTransferTable);
		details->FlashPage = LOOKUP_PPAGE;
		details->FlashAddress = CHTTransferTableLocation;
		break;
#ifdef ALL_CONFIG
	case MAFTransferTableLocationID:
		details->size = sizeof(MAFTransferTable);
		details->FlashPage = LOOKUP_PPAGE;
		details->FlashAddress = MAFTransferTableLocation;
		break;
	case TestTransferTableLocationID:
		details->size = sizeof(TestTransferTable);
		details->FlashPage = LOOKUP_PPAGE;
		details->FlashAddress = TestTransferTableLocation;
		break;
#endif
	/* fuel tables */
	case VETableMainLocationID:
		details->RAMPage = RPAGE_FUEL_ONE;
		details->FlashPage = FUELTABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA;
		details->FlashAddress = VETableMainFlashLocation;
		break;
#ifdef ALL_CONFIG
	case VETableSecondaryLocationID:
		details->RAMPage = RPAGE_FUEL_ONE;
		details->FlashPage = FUELTABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB;
		details->FlashAddress = VETableSecondaryFlashLocation;
		break;
#endif
	case AirflowTableLocationID:
		details->RAMPage = RPAGE_FUEL_ONE;
		details->FlashPage = FUELTABLES_PPAGE;
		details->RAMAddress = (void*)&TablesC;
		details->FlashAddress = AirflowTableFlashLocation;
		break;
	case LambdaTableLocationID:
		details->RAMPage = RPAGE_FUEL_ONE;
		details->FlashPage = FUELTABLES_PPAGE;
		details->RAMAddress = (void*)&TablesD;
		details->FlashAddress = LambdaTableFlashLocation;
		break;
#ifdef ALL_CONFIG
	case VETableMain2LocationID:
		details->RAMPage = RPAGE_FUEL_TWO;
		details->FlashPage = FUELTABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA;
		details->FlashAddress = VETableMainFlash2Location;
		break;
	case VETableSecondary2LocationID:
		details->RAMPage = RPAGE_FUEL_TWO;
		details->FlashPage = FUELTABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB;
		details->FlashAddress = VETableSecondaryFlash2Location;
		break;
	case AirflowTable2LocationID:
		details->RAMPage = RPAGE_FUEL_TWO;
		details->FlashPage = FUELTABLES_PPAGE;
		details->RAMAddress = (void*)&TablesC;
		details->FlashAddress = AirflowTableFlash2Location;
		break;
	case LambdaTable2LocationID:
		details->RAMPage = RPAGE_FUEL_TWO;
		details->FlashPage = FUELTABLES_PPAGE;
		details->RAMAddress = (void*)&TablesD;
		details->FlashAddress = LambdaTableFlash2Location;
		break;
#endif

	/* timing tables */
	case IgnitionAdvanceTableMainLocationID:
		details->RAMPage = RPAGE_TIME_ONE;
		details->FlashPage = TIMETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA;
		details->FlashAddress = IgnitionAdvanceTableMainFlashLocation;
		break;
#ifdef ALL_CONFIG
	case IgnitionAdvanceTableSecondaryLocationID:
		details->RAMPage = RPAGE_TIME_ONE;
		details->FlashPage = TIMETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB;
		details->FlashAddress = IgnitionAdvanceTableSecondaryFlashLocation;
		break;
	case InjectionAdvanceTableMainLocationID:
		details->RAMPage = RPAGE_TIME_ONE;
		details->FlashPage = TIMETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesC;
		details->FlashAddress = InjectionAdvanceTableMainFlashLocation;
		break;
	case InjectionAdvanceTableSecondaryLocationID:
		details->RAMPage = RPAGE_TIME_ONE;
		details->FlashPage = TIMETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesD;
		details->FlashAddress = InjectionAdvanceTableSecondaryFlashLocation;
		break;
	case IgnitionAdvanceTableMain2LocationID:
		details->RAMPage = RPAGE_TIME_TWO;
		details->FlashPage = TIMETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA;
		details->FlashAddress = IgnitionAdvanceTableMainFlash2Location;
		break;
	case IgnitionAdvanceTableSecondary2LocationID:
		details->RAMPage = RPAGE_TIME_TWO;
		details->FlashPage = TIMETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB;
		details->FlashAddress = IgnitionAdvanceTableSecondaryFlash2Location;
		break;
	case InjectionAdvanceTableMain2LocationID:
		details->RAMPage = RPAGE_TIME_TWO;
		details->FlashPage = TIMETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesC;
		details->FlashAddress = InjectionAdvanceTableMainFlash2Location;
		break;
	case InjectionAdvanceTableSecondary2LocationID:
		details->RAMPage = RPAGE_TIME_TWO;
		details->FlashPage = TIMETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesD;
		details->FlashAddress = InjectionAdvanceTableSecondaryFlash2Location;
		break;
#endif

	/* small table full blocks */
	case SmallTablesALocationID:
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA;
		details->FlashAddress = SmallTablesAFlashLocation;
		break;
	case SmallTablesBLocationID:
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB;
		details->FlashAddress = SmallTablesBFlashLocation;
		break;
#ifdef ALL_CONFIG
	case SmallTablesCLocationID:
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesC;
		details->FlashAddress = SmallTablesCFlashLocation;
		break;
	case SmallTablesDLocationID:
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesD;
		details->FlashAddress = SmallTablesDFlashLocation;
		break;
	case SmallTablesA2LocationID:
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA;
		details->FlashAddress = SmallTablesAFlash2Location;
		break;
	case SmallTablesB2LocationID:
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB;
		details->FlashAddress = SmallTablesBFlash2Location;
		break;
	case SmallTablesC2LocationID:
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesC;
		details->FlashAddress = SmallTablesCFlash2Location;
		break;
	case SmallTablesD2LocationID:
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesD;
		details->FlashAddress = SmallTablesDFlash2Location;
		break;
#endif

	/* TablesA small tables */
	case dwellDesiredVersusVoltageTableLocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.dwellDesiredVersusVoltageTable;
		details->FlashAddress = dwellDesiredVersusVoltageTableLocation;
		details->parent = SmallTablesALocationID;
		break;
	case injectorDeadTimeTableLocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.injectorDeadTimeTable;
		details->FlashAddress = injectorDeadTimeTableLocation;
		details->parent = SmallTablesALocationID;
		break;
#ifdef ALL_CONFIG
	case postStartEnrichmentTableLocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.postStartEnrichmentTable;
		details->FlashAddress = postStartEnrichmentTableLocation;
		details->parent = SmallTablesALocationID;
		break;
	case engineTempEnrichmentTableFixedLocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.engineTempEnrichmentTableFixed;
		details->FlashAddress = engineTempEnrichmentTableFixedLocation;
		details->parent = SmallTablesALocationID;
		break;
#endif
	case primingVolumeTableLocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.primingVolumeTable;
		details->FlashAddress = primingVolumeTableLocation;
		details->parent = SmallTablesALocationID;
		break;
	case engineTempEnrichmentTablePercentLocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.engineTempEnrichmentTablePercent;
		details->FlashAddress = engineTempEnrichmentTablePercentLocation;
		details->parent = SmallTablesALocationID;
		break;
	case dwellVersusRPMTableLocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.dwellVersusRPMTable;
		details->FlashAddress = dwellVersusRPMTableLocation;
		details->parent = SmallTablesALocationID;
		break;
	case blendVersusRPMTableLocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.blendVersusRPMTable;
		details->FlashAddress = blendVersusRPMTableLocation;
		details->parent = SmallTablesALocationID;
		break;

#ifdef ALL_CONFIG
	case dwellDesiredVersusVoltageTable2LocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.dwellDesiredVersusVoltageTable;
		details->FlashAddress = dwellDesiredVersusVoltageTable2Location;
		details->parent = SmallTablesA2LocationID;
		break;
	case injectorDeadTimeTable2LocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.injectorDeadTimeTable;
		details->FlashAddress = injectorDeadTimeTable2Location;
		details->parent = SmallTablesA2LocationID;
		break;
	case postStartEnrichmentTable2LocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.postStartEnrichmentTable;
		details->FlashAddress = postStartEnrichmentTable2Location;
		details->parent = SmallTablesA2LocationID;
		break;
	case engineTempEnrichmentTableFixed2LocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.engineTempEnrichmentTableFixed;
		details->FlashAddress = engineTempEnrichmentTableFixed2Location;
		details->parent = SmallTablesA2LocationID;
		break;
	case primingVolumeTable2LocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.primingVolumeTable;
		details->FlashAddress = primingVolumeTable2Location;
		details->parent = SmallTablesA2LocationID;
		break;
	case engineTempEnrichmentTablePercent2LocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.engineTempEnrichmentTablePercent;
		details->FlashAddress = engineTempEnrichmentTablePercent2Location;
		details->parent = SmallTablesA2LocationID;
		break;
	case dwellVersusRPMTable2LocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.dwellVersusRPMTable;
		details->FlashAddress = dwellVersusRPMTable2Location;
		details->parent = SmallTablesA2LocationID;
		break;
	case blendVersusRPMTable2LocationID:
		details->size = sizeof(twoDTableUS);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.blendVersusRPMTable;
		details->FlashAddress = blendVersusRPMTable2Location;
		details->parent = SmallTablesA2LocationID;
		break;
#endif
	/* TablesB small tables */
	case loggingSettingsLocationID:
		details->size = sizeof(loggingSetting);
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB.SmallTablesB.loggingSettings;
		details->FlashAddress = loggingSettingsLocation;
		details->parent = SmallTablesBLocationID;
		break;
#ifdef ALL_CONFIG
	case loggingSettings2LocationID:
		details->size = sizeof(loggingSetting);
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB.SmallTablesB.loggingSettings;
		details->FlashAddress = loggingSettings2Location;
		details->parent = SmallTablesB2LocationID;
		break;
#endif

	/* TablesC small tables */
		// TODO add data chunks from TablesC when some are put in

	/* TablesD small tables */
		// TODO add data chunks from TablesD when some are put in

#ifdef ALL_CONFIG
	/* filler block entries */
	case fillerALocationID:
		details->size = SMALL_TABLES_1_FILLER_SIZE;
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.filler;
		details->FlashAddress = fillerALocation;
		details->parent = SmallTablesALocationID;
		break;
	case fillerA2LocationID:
		details->size = SMALL_TABLES_1_FILLER_SIZE;
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesA.SmallTablesA.filler;
		details->FlashAddress = fillerA2Location;
		details->parent = SmallTablesA2LocationID;
		break;
	case fillerBLocationID:
		details->size = SMALL_TABLES_2_FILLER_SIZE;
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB.SmallTablesB.filler;
		details->FlashAddress = fillerBLocation;
		details->parent = SmallTablesBLocationID;
		break;
	case fillerB2LocationID:
		details->size = SMALL_TABLES_2_FILLER_SIZE;
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesB.SmallTablesB.filler;
		details->FlashAddress = fillerB2Location;
		details->parent = SmallTablesB2LocationID;
		break;
	case fillerCLocationID:
		details->size = SMALL_TABLES_3_FILLER_SIZE;
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesC.SmallTablesC.filler;
		details->FlashAddress = fillerCLocation;
		details->parent = SmallTablesCLocationID;
		break;
	case fillerC2LocationID:
		details->size = SMALL_TABLES_3_FILLER_SIZE;
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesC.SmallTablesC.filler;
		details->FlashAddress = fillerC2Location;
		details->parent = SmallTablesC2LocationID;
		break;
	case fillerDLocationID:
		details->size = SMALL_TABLES_4_FILLER_SIZE;
		details->RAMPage = RPAGE_TUNE_ONE;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesD.SmallTablesD.filler;
		details->FlashAddress = fillerDLocation;
		details->parent = SmallTablesDLocationID;
		break;
	case fillerD2LocationID:
		details->size = SMALL_TABLES_4_FILLER_SIZE;
		details->RAMPage = RPAGE_TUNE_TWO;
		details->FlashPage = TUNETABLES_PPAGE;
		details->RAMAddress = (void*)&TablesD.SmallTablesD.filler;
		details->FlashAddress = fillerD2Location;
		details->parent = SmallTablesD2LocationID;
		break;
#endif

	/* Fixed conf 1 small chunks */
	case engineSettingsLocationID:
		details->size = sizeof(engineSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs1.engineSettings);
		details->parent = FixedConfig1LocationID;
		break;
	case serialSettingsLocationID:
		details->size = sizeof(serialSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs1.serialSettings);
		details->parent = FixedConfig1LocationID;
		break;
	case coarseBBSettingsLocationID:
		details->size = sizeof(coarseBitBangSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs1.coarseBitBangSettings);
		details->parent = FixedConfig1LocationID;
		break;
	case schedulingSettingsLocationID:
		details->size = sizeof(schedulingSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs1.schedulingSettings);
		details->parent = FixedConfig1LocationID;
		break;
	case cutAndLimiterSettingsLocationID:
		details->size = sizeof(cutAndLimiterSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs1.cutAndLimiterSettings);
		details->parent = FixedConfig1LocationID;
		break;
	case simpleGPIOSettingsLocationID:
		details->size = sizeof(simpleGPIOSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs1.simpleGPIOSettings);
		details->parent = FixedConfig1LocationID;
		break;
	case userTextFieldLocationID:
		details->size = userTextFieldArrayLength1;
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs1.userTextField);
		details->parent = FixedConfig1LocationID;
		break;

	/* Fixed conf 2 small chunks */
	case sensorSourcesLocationID:
		details->size = sizeof(sensorSource);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs2.sensorSources);
		details->parent = FixedConfig2LocationID;
		break;
	case sensorPresetsLocationID:
		details->size = sizeof(sensorPreset);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs2.sensorPresets);
		details->parent = FixedConfig2LocationID;
		break;
	case sensorRangesLocationID:
		details->size = sizeof(sensorRange);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs2.sensorRanges);
		details->parent = FixedConfig2LocationID;
		break;
	case sensorSettingsLocationID:
		details->size = sizeof(sensorSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs2.sensorSettings);
		details->parent = FixedConfig2LocationID;
		break;
	case algorithmSettingsLocationID:
		details->size = sizeof(algorithmSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs2.algorithmSettings);
		details->parent = FixedConfig2LocationID;
		break;
	case inputOutputSettingsLocationID:
		details->size = sizeof(inputOutputSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs2.inputOutputSettings);
		details->parent = FixedConfig2LocationID;
		break;
	case decoderSettingsLocationID:
		details->size = sizeof(decoderSetting);
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs2.decoderSettings);
		details->parent = FixedConfig2LocationID;
		break;
	case userTextField2LocationID:
		details->size = userTextFieldArrayLength2;
		details->FlashPage = PPAGE;
		details->FlashAddress = (void*)&(fixedConfigs2.userTextField2);
		details->parent = FixedConfig2LocationID;
		break;

// Internal blocks of variables that are sometimes useful to read out
	case ADCRegistersLocationID:
		details->size = sizeof(ADCBuffer);
		details->RAMPage = RPAGE_LINEAR;
		details->RAMAddress = &ADCBuffers;
		break;
	case coreVarsLocationID:
		details->size = sizeof(CoreVar);
		details->RAMPage = RPAGE_LINEAR;
		details->RAMAddress = (void*)CoreVars;
		break;
	case DerivedVarsLocationID:
		details->size = sizeof(DerivedVar);
		details->RAMPage = RPAGE_LINEAR;
		details->RAMAddress = (void*)DerivedVars;
		break;
	case KeyUserDebugLocationID:
		details->size = sizeof(KeyUserDebug);
		details->RAMPage = RPAGE_LINEAR;
		details->RAMAddress = &KeyUserDebugs;
		break;
	case CountersLocationID:
		details->size = sizeof(Counter);
		details->RAMPage = RPAGE_LINEAR;
		details->RAMAddress = &Counters;
		break;
	case ClocksLocationID:
		details->size = sizeof(Clock);
		details->RAMPage = RPAGE_LINEAR;
		details->RAMAddress = &Clocks;
		break;
	case FlaggablesLocationID:
		details->size = sizeof(Flaggable);
		details->RAMPage = RPAGE_LINEAR;
		details->RAMAddress = &Flaggables;
		break;
	case Flaggables2LocationID:
		details->size = sizeof(Flaggable2);
		details->RAMPage = RPAGE_LINEAR;
		details->RAMAddress = &Flaggables2;
		break;

	default:
		/* Return early if locationID is not valid. */
		return locationIDNotFound;
	}


	// Setup all of the flags for various groups here
	// Setting flags above is wrong, keep it all in one place, here!

	// Initialise the flags to having flash, everything does at the moment, and indexable, most is, negate at end for those that don't.
	details->flags = block_is_in_flash | block_is_indexable;

	if(locationID < MainTable_TwoDTableUS_Border){
		details->flags |= block_is_main_table | block_is_in_ram | block_gets_verified | block_for_backup_restore;
	}else if(locationID < TwoDTableUS_SmallTableFullBlocks_Border){
		details->flags |= block_is_2dus_table | block_is_in_ram | block_has_parent | block_gets_verified;
	}else if(locationID < SmallTableFullBlocks_SmallTableFillers_Border){
		details->flags |= block_is_in_ram | block_for_backup_restore;
		details->flags &= ~block_is_indexable;
	}else if(locationID < SmallTableFillers_FlashLookupTables_Border){
		details->flags |= block_has_parent | block_is_in_ram;
		details->flags &= ~block_is_indexable;
	}else if(locationID < FlashLookupTables_SmallTableConfigs_Border){
		details->flags |= block_is_lookup_data | block_for_backup_restore;
		details->flags &= ~block_is_indexable;
	}else if(locationID < SmallTableConfigs_FixedConfigBlocks_Border){
		details->flags |= block_has_parent | block_is_in_ram | block_is_configuration;
	}else if(locationID < FixedConfigBlocks_FixedConfigSubBlocks_Border){
		details->flags |= block_for_backup_restore;
	}else if(locationID < FixedConfigSubBlocks_Border_ReadOnlyVarBlocks){
		details->flags |= block_has_parent | block_is_configuration;
	}else{ // RO variable blocks exposed polling and streaming
		details->flags |= block_is_read_only | block_is_in_ram;
		details->flags &= ~block_is_in_flash;
	}

/* Fall through to not return error */
	return 0;
}
