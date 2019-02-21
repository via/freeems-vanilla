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
 * @ingroup measurementsAndCalculations
 *
 * @brief Generate the derived variables.
 *
 * Second level variables are derived from the core variables and generated here.
 */


#define DERIVEDVARSGENERATOR_C
#include "inc/freeEMS.h"
#include "inc/commsCore.h"
#include "inc/tableLookup.h"
#include "inc/derivedVarsGenerator.h"
#include "inc/locationIDs.h"
#include "inc/decoderInterface.h"


/**
 * Use core variables to lookup and calculate the derived variables. This
 * function uses the core variables to lookup and calculate further second
 * order variables such as load, VE, Lamdda, Transient fuel correction, engine
 * temperature enrichment, Injector dead time, etc.
 */
void generateDerivedVars(){
	/* Determine load based on options */
	if(!(fixedConfigs2.algorithmSettings.loadType)){ /* Use MAP as load */
		DerivedVars->LoadMain = CoreVars->MAP;
	}else if(fixedConfigs2.algorithmSettings.loadType == LOAD_TPS){ /* Use TPS as load */
		DerivedVars->LoadMain = CoreVars->TPS;
	}else if(fixedConfigs2.algorithmSettings.loadType == LOAD_AAP){ /* Use AAP corrected MAP as load */
		DerivedVars->LoadMain = ((unsigned long)CoreVars->MAP * CoreVars->AAP) / KPA(100);
		// TODO add maf calc load option here
	}else{ /* Default to MAP, but throw error */
		DerivedVars->LoadMain = CoreVars->MAP;
	}


	/* Look up target Lambda with RPM and Load */
	DerivedVars->Lambda = lookupMainTable(CoreVars->RPM, DerivedVars->LoadMain, LambdaTableLocationID);


	/* Look up injector dead time with battery voltage */
	DerivedVars->IDT = lookupTwoDTableUS((twoDTableUS*)&TablesA.SmallTablesA.injectorDeadTimeTable, CoreVars->BRV);

	if(!(fixedConfigs2.algorithmSettings.dwellType)){
		DerivedVars->Dwell = lookupTwoDTableUS((twoDTableUS*)&TablesA.SmallTablesA.dwellDesiredVersusVoltageTable, CoreVars->BRV);
	}else if(fixedConfigs2.algorithmSettings.dwellType == DWELL_RPM){
		DerivedVars->Dwell = lookupTwoDTableUS((twoDTableUS*)&TablesA.SmallTablesA.dwellVersusRPMTable, CoreVars->RPM);
	}else if(fixedConfigs2.algorithmSettings.dwellType == DWELL_FIXED){
		DerivedVars->Dwell = fixedConfigs2.algorithmSettings.dwellFixedPeriod;
	}else{
		DerivedVars->Dwell = 0;
	}

	unsigned long tempAdvance = ANGLE_FACTOR * (unsigned long)lookupMainTable(CoreVars->RPM, DerivedVars->LoadMain, IgnitionAdvanceTableMainLocationID);
	DerivedVars->Advance = (unsigned short)(tempAdvance / 1024); // This calculation will change when the timing tables get shrunk to a more reasonable 8 bit size with appropriate scaling
	// Move this magic number to an appropriate place and/or refactor timing calcs/values/etc

/// @todo TODO make generic!!!!
// to go generic we need:
// angle between ignition events (if have tpd) (or total angle and number of events)
// max % dwell
// minimum spark time
// a setting to choose which behaviour (don't limit/% dwell limit/min spark time/other?)
#if CONFIG == HOTEL_ID
	/// @bug hack for hyundai! 135 = 3/4 of 180 = one cycle...
	unsigned long threeQuartersOfAvailableTime = ((unsigned long)CoreVars->DRPM * 135 * ANGLE_FACTOR) / ticks_per_degree_multiplier;
	if(DerivedVars->Dwell > threeQuartersOfAvailableTime){
		DerivedVars->Dwell = threeQuartersOfAvailableTime;
	}
#endif

	/* Look up the engine temperature enrichment percentage with temperature */
	DerivedVars->ETE = lookupTwoDTableUS((twoDTableUS*)&TablesA.SmallTablesA.engineTempEnrichmentTablePercent, CoreVars->CHT);
	/* TODO The above needs some careful thought put into it around different loads and correction effects. */

	if (CoreVars->DTPS > 0) {
		/* Map 0-5% throttle rate to 0-4 ms, cap after */
		if (CoreVars->DTPS < 1638) {
			DerivedVars->TFCTotal = CoreVars->DTPS * 3; /* At most about 4 mS compensation */
		} else {
			DerivedVars->TFCTotal = 4914;
		}
	} else {
		DerivedVars->TFCTotal = 0;
	}

}
