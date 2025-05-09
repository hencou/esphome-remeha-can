#pragma once
#include "esphome/core/defines.h"
#include "remeha-can-od-types.h"

namespace remeha_can_lib {

const RemehaObjectDictionary ObjectDictionary = {
#ifdef rem_parHeGasTypeSelector
{ 0x222c00, new Enum("parHeGasTypeSelector", "GP043", false, -1, 0.0 , { { 0, "No gas type selected" }, { 1, "Natural gas" }, { 2, "Liquid Petrol Gas" }, { 3, "Air Propane" } }) },
#endif
#ifdef rem_parChMaxPowerCorrection
{ 0x223000, new I8("parChMaxPowerCorrection", "GP088", false, -1, 1 ) },
#endif
#ifdef rem_parGvcIgnitionPower
{ 0x226800, new U16("parGvcIgnitionPower", "GP066", false, -1, 0.01 ) },
#endif
#ifdef rem_parHeMinimumPower
{ 0x226900, new U16("parHeMinimumPower", "GP067", false, -1, 0.01 ) },
#endif
#ifdef rem_parGvcMaxPowerCorrection
{ 0x226b00, new I8("parGvcMaxPowerCorrection", "GP068", false, -1, 1 ) },
#endif
#ifdef rem_parHpOutdoorBivalentTemperature
{ 0x230000, new I16("parHpOutdoorBivalentTemperature", "HP000", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpMessFlowmeter
{ 0x230b00, new U16("parHpMessFlowmeter", "HP011", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpBackupType
{ 0x231d00, new Enum("parHpBackupType", "HP029", false, -1, 0.0 , { { 0, "No Backup" }, { 1, "1-stage electrical backup" }, { 2, "2-stage electrical backup" }, { 3, "Boiler Backup" } }) },
#endif
#ifdef rem_parHpDelayGeneratorStart
{ 0x231e00, new U16("parHpDelayGeneratorStart", "HP030", false, -1, 1 ) },
#endif
#ifdef rem_parHpDelayGeneratorStop
{ 0x231f00, new U16("parHpDelayGeneratorStop", "HP031", false, -1, 1 ) },
#endif
#ifdef rem_parHpElectricPulseValency
{ 0x232100, new U16("parHpElectricPulseValency", "HP033", false, -1, 1 ) },
#endif
#ifdef rem_parHpTimeLowOutsideTemp
{ 0x232f00, new U8("parHpTimeLowOutsideTemp", "HP047", false, -1, 1 ) },
#endif
#ifdef rem_parHpTimeHighOutsideTemp
{ 0x233000, new U8("parHpTimeHighOutsideTemp", "HP048", false, -1, 1 ) },
#endif
#ifdef rem_parHpLowOutsideTempValue
{ 0x233100, new I16("parHpLowOutsideTempValue", "HP049", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpHighOutsideTempValue
{ 0x233200, new I16("parHpHighOutsideTempValue", "HP050", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpMinimumOutsideTemperatureHP
{ 0x233300, new I16("parHpMinimumOutsideTemperatureHP", "HP051", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpCOPThreshold
{ 0x233600, new U16("parHpCOPThreshold", "HP054", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpSilentMode
{ 0x233a00, new Enum("parHpSilentMode", "HP058", false, -1, 0.0 , { { 0, "No silent mode" }, { 1, "Silent mode level 1" }, { 2, "Silent mode level 2" }, { 3, "Silent mode level 3" }, { 4, "Silent mode level 4" }, { 5, "Silent mode level 5" } }) },
#endif
#ifdef rem_parHpHybrid
{ 0x233d00, new Enum("parHpHybrid", "HP061", false, -1, 0.0 , { { 0, "No Hybrid" }, { 1, "Hybrid Cost" }, { 2, "Hybrid Primary Energy" }, { 3, "Hybrid CO2" } }) },
#endif
#ifdef rem_parHpHybridCoefEmCO2ElecCH
{ 0x234100, new U8("parHpHybridCoefEmCO2ElecCH", "HP065", false, -1, 1 ) },
#endif
#ifdef rem_parHpHybridCoefEmCO2ElecDHW
{ 0x234200, new U8("parHpHybridCoefEmCO2ElecDHW", "HP066", false, -1, 1 ) },
#endif
#ifdef rem_parHpHybridCoefEmCO2GasOil
{ 0x234300, new U8("parHpHybridCoefEmCO2GasOil", "HP067", false, -1, 1 ) },
#endif
#ifdef rem_parHpHybridBoilerEfficiency
{ 0x234400, new U8("parHpHybridBoilerEfficiency", "HP068", false, -1, 1 ) },
#endif
#ifdef rem_parHpBufferTankEnabled
{ 0x235600, new Enum("parHpBufferTankEnabled", "HP086", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_parHpBufferTankHysterisis
{ 0x235700, new U16("parHpBufferTankHysterisis", "HP087", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpOffsetChPhotovoltaic
{ 0x235b00, new U16("parHpOffsetChPhotovoltaic", "HP091", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpOffsetDhwPhotovoltaic
{ 0x235c00, new U16("parHpOffsetDhwPhotovoltaic", "HP092", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpStartTimeLowNoise
{ 0x235e00, new U8("parHpStartTimeLowNoise", "HP094", false, -1, 1 ) },
#endif
#ifdef rem_parHpStopTimeLowNoise
{ 0x235f00, new U8("parHpStopTimeLowNoise", "HP095", false, -1, 1 ) },
#endif
#ifdef rem_parHpTempoBetweenStagesCh
{ 0x236c00, new U8("parHpTempoBetweenStagesCh", "HP108", false, -1, 1 ) },
#endif
#ifdef rem_parHpPipingSelection
{ 0x239f00, new Enum("parHpPipingSelection", "HP159", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_parHpEnergyConsumption
{ 0x23a000, new Enum("parHpEnergyConsumption", "HP157", false, -1, 0.0 , { { 0, "An internal software estimation method is used for the assessment of the variable/signal." }, { 1, "An external measurement device is used for the assessment  of the variable/signal." } }) },
#endif
#ifdef rem_parHpAntiCycleTime
{ 0x23a600, new U8("parHpAntiCycleTime", "HP155", false, -1, 1 ) },
#endif
#ifdef rem_parHpHybridElectricalCostTariff1Accurate
{ 0x23bb00, new U16("parHpHybridElectricalCostTariff1Accurate", "HP062", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpHybridElectricalCostTariff2Accurate
{ 0x23be00, new U16("parHpHybridElectricalCostTariff2Accurate", "HP063", false, -1, 0.01 ) },
#endif
#ifdef rem_parHpHybridGasOilCostAccurate
{ 0x23bf00, new U16("parHpHybridGasOilCostAccurate", "HP064", false, -1, 0.01 ) },
#endif
#ifdef rem_parApBlockingFunction
{ 0x300100, new Enum("parApBlockingFunction", "AP001", false, -1, 0.0 , { { 0, "Not used" }, { 1, "Full blocking" }, { 2, "Partial blocking" }, { 3, "User reset locking" }, { 4, "Backup Relieved" }, { 5, "Generator relieved" }, { 6, "Generator and backup relieved" }, { 7, "High Tariff Low Tariff" }, { 8, "Photovoltaic Heat Pump Only" }, { 9, "Photovoltaic Heat Pump And backup" }, { 10, "Smart Grid ready" }, { 11, "Heating Cooling" }, { 12, "Central heating blocking" } }) },
#endif
#ifdef rem_parApEnableManualHeatDemand
{ 0x300200, new Enum("parApEnableManualHeatDemand", "AP002", false, -1, 0.0 , { { 0, "Off" }, { 1, "With setpoint" }, { 2, "OTC" } }) },
#endif
#ifdef rem_parApMinWaterPress
{ 0x300600, new U8("parApMinWaterPress", "AP006", false, -1, 0.1 ) },
#endif
#ifdef rem_parApReleaseWaitTime
{ 0x300800, new U8("parApReleaseWaitTime", "AP008", false, -1, 1 ) },
#endif
#ifdef rem_parApServiceBurnHours
{ 0x300900, new U16("parApServiceBurnHours", "AP009", false, -1, 2 ) },
#endif
#ifdef rem_parApServiceNotification
{ 0x300a00, new Enum("parApServiceNotification", "AP010", false, -1, 0.0 , { { 0, "No service notification" }, { 1, "Custom service notification" }, { 2, "ABC service notification" }, { 3, "Service notification based on ABC conditions and condensing burning hours" } }) },
#endif
#ifdef rem_parApServiceOperationTime
{ 0x300b00, new U16("parApServiceOperationTime", "AP011", false, -1, 2 ) },
#endif
#ifdef rem_parApCoolingForced
{ 0x301100, new Enum("parApCoolingForced", "AP015", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_parApChEnabled
{ 0x301200, new Enum("parApChEnabled", "AP016", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_parApDhwEnabled
{ 0x301300, new Enum("parApDhwEnabled", "AP017", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_parApHeatDemandFlowTemperatureSetpoint
{ 0x301c00, new U16("parApHeatDemandFlowTemperatureSetpoint", "AP026", false, -1, 0.01 ) },
#endif
#ifdef rem_parApCooling
{ 0x301e00, new Enum("parApCooling", "AP028", false, -1, 0.0 , { { 0, "Cooling off" }, { 1, "Active cooling on" }, { 2, "Free cooling on" } }) },
#endif
#ifdef rem_parApCoolingPermission
{ 0x301f00, new Enum("parApCoolingPermission", "AP029", false, -1, 0.0 , { { 0, "Cooling not allowed" }, { 1, "Cooling allowed" } }) },
#endif
#ifdef rem_parApOutsideSensorType
{ 0x302900, new Enum("parApOutsideSensorType", "AP056", false, -1, 0.0 , { { 0, "No outside sensor" }, { 1, "AF60" }, { 2, "QAC34" } }) },
#endif
#ifdef rem_parApMessMinWaterPressure
{ 0x302b00, new U8("parApMessMinWaterPressure", "AP058", false, -1, 0.1 ) },
#endif
#ifdef rem_parApMaxTemperatureSetpoint
{ 0x303000, new U16("parApMaxTemperatureSetpoint", "AP063", false, -1, 0.01 ) },
#endif
#ifdef rem_parApReleaseInputFunction
{ 0x303700, new Enum("parApReleaseInputFunction", "AP013", false, -1, 0.0 , { { 0, "The release input is disabled, the status contact is ignored.\nrelease CH or release full" }, { 1, "All heat demands are blocked with no exceptions." }, { 2, "Central heat demands are blocked with the exception of anti-frost." } }) },
#endif
#ifdef rem_parApReleaseInputLogicLevel
{ 0x303800, new Enum("parApReleaseInputLogicLevel", "AP018", false, -1, 0.0 , { { 0, "Contact is normally opened" }, { 1, "Contact is normally closed" } }) },
#endif
#ifdef rem_parApSummerWinter
{ 0x303a00, new U16("parApSummerWinter", "AP073", false, -1, 0.01 ) },
#endif
#ifdef rem_parApForceSummerMode
{ 0x303b00, new Enum("parApForceSummerMode", "AP074", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_parApNeutralBandSummerWinter
{ 0x303c00, new U16("parApNeutralBandSummerWinter", "AP075", false, -1, 0.01 ) },
#endif
#ifdef rem_parBuildingInertia
{ 0x304000, new U8("parBuildingInertia", "AP079", false, -1, 1 ) },
#endif
#ifdef rem_parApFrostMinToutside
{ 0x304100, new I16("parApFrostMinToutside", "AP080", false, -1, 0.01 ) },
#endif
#ifdef rem_parApOperationalWaterPressure
{ 0x304c00, new U8("parApOperationalWaterPressure", "AP070", false, -1, 0.1 ) },
#endif
#ifdef rem_parApAutoFilling
{ 0x304d00, new Enum("parApAutoFilling", "AP014", false, -1, 0.0 , { { 0, "Auto filling disabled" }, { 1, "Auto filling manual" }, { 2, "Auto filling auto" } }) },
#endif
#ifdef rem_parApBlocking1ContactLogic
{ 0x305300, new Enum("parApBlocking1ContactLogic", "AP098", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_parApBlocking2ContactLogic
{ 0x305400, new Enum("parApBlocking2ContactLogic", "AP099", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_parApBlockingFunction2
{ 0x305500, new Enum("parApBlockingFunction2", "AP100", false, -1, 0.0 , { { 0, "Not used" }, { 1, "Full blocking" }, { 2, "Partial blocking" }, { 3, "User reset locking" }, { 4, "Backup Relieved" }, { 5, "Generator relieved" }, { 6, "Generator and backup relieved" }, { 7, "High Tariff Low Tariff" }, { 8, "Photovoltaic Heat Pump Only" }, { 9, "Photovoltaic Heat Pump And backup" }, { 10, "Smart Grid ready" }, { 11, "Heating Cooling" }, { 12, "Central heating blocking" } }) },
#endif
#ifdef rem_parApDeairationCycle
{ 0x305600, new Enum("parApDeairationCycle", "AP101", false, -1, 0.0 , { { 0, "No deair at power up" }, { 1, "Always deair at power up" }, { 2, "Deair only at first power up" } }) },
#endif
#ifdef rem_parApPumpZoneDedicated
{ 0x305700, new Enum("parApPumpZoneDedicated", "AP102", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_parApToutsideTypeSensorConnectionToUse
{ 0x306800, new Enum("parApToutsideTypeSensorConnectionToUse", "AP091", false, -1, 0.0 , { { 0, "Sensor type used is based on priority. The following list in reducing priority : wired , wireless, internet" }, { 1, "Wired sensor is to be used" }, { 2, "Wireless sensor is to be used" }, { 3, "Internet measured temperature is used." }, { 4, "No sensor is used or connected" } }) },
#endif
#ifdef rem_parSystemSensorPITemperatureRange
{ 0x30ac00, new U16("parSystemSensorPITemperatureRange", "AP061", false, -1, 0.01 ) },
#endif
#ifdef rem_parSystemSensorPFactorTemperature
{ 0x30ad00, new U8("parSystemSensorPFactorTemperature", "AP062", false, -1, 0.1 ) },
#endif
#ifdef rem_parChPumpPostRun
{ 0x320f00, new U8("parChPumpPostRun", "PP015", false, -1, 1 ) },
#endif
#ifdef rem_parChPumpSpeedMax
{ 0x321000, new U8("parChPumpSpeedMax", "PP016", false, -1, 1 ) },
#endif
#ifdef rem_parChPumpSpeedMin
{ 0x321200, new U8("parChPumpSpeedMin", "PP018", false, -1, 1 ) },
#endif
#ifdef rem_parChHysteresis
{ 0x321700, new U16("parChHysteresis", "PP023", false, -1, 0.01 ) },
#endif
#ifdef rem_parZoneTFlowSetpointMax
{ 0x340100, new U16("parZoneTFlowSetpointMax", "CP000", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneTFlowSetpoint
{ 0x340200, new U16("parZoneTFlowSetpoint", "CP010", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneFunction
{ 0x340400, new Enum("parZoneFunction", "CP020", false, 10, 0.0 , { { 0, "Disable" }, { 1, "Direct" }, { 2, "Mixing Circuit" }, { 3, "Swimming pool" }, { 4, "High Temperature" }, { 5, "Fan Convector" }, { 6, "DHW tank" }, { 7, "Electrical DHW" }, { 8, "Time Program" }, { 9, "ProcessHeat" }, { 10, "DHW Layered" }, { 11, "DHW BIC" }, { 12, "DHW Commercial Tank" }, { 13, "Domestic Hot Water - Fresh Water Station settings" }, { 14, "Gas process heat" }, { 31, "DHW external fresh water station" }, { 200, "BSB" }, { 254, "\"Occupied\" is used for a BSB zone to indicate that the a room unit is connected to that zone." } }) },
#endif
#ifdef rem_parZoneMixingValveBandwith
{ 0x340500, new U16("parZoneMixingValveBandwith", "CP030", false, 10, 0.01 ) },
#endif
#ifdef rem_parZonePumpPostRun
{ 0x340800, new U8("parZonePumpPostRun", "CP040", false, 10, 1 ) },
#endif
#ifdef rem_parZoneMixingValveShift
{ 0x340900, new U16("parZoneMixingValveShift", "CP050", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneAmbiantNightSetpoint
{ 0x340b00, new U16("parZoneAmbiantNightSetpoint", "CP070", false, 10, 0.1 ) },
#endif
#ifdef rem_parZoneRoomUserActivitySetpoint
{ 0x340c00, new U16("parZoneRoomUserActivitySetpoint", "CP080", false, 50, 0.1 ) },
#endif
#ifdef rem_parZoneRoomCoolingSetpoint
{ 0x341200, new U16("parZoneRoomCoolingSetpoint", "CP140", false, 50, 0.1 ) },
#endif
#ifdef rem_parZoneRoomManualSetpoint
{ 0x341300, new U16("parZoneRoomManualSetpoint", "CP200", false, 10, 0.1 ) },
#endif
#ifdef rem_parZoneHCZPD
{ 0x341400, new U16("parZoneHCZPD", "CP210", false, 10, 0.1 ) },
#endif
#ifdef rem_parZoneHCZPN
{ 0x341500, new U16("parZoneHCZPN", "CP220", false, 10, 0.1 ) },
#endif
#ifdef rem_parZoneSlope
{ 0x341600, new U8("parZoneSlope", "CP230", false, 10, 0.1 ) },
#endif
#ifdef rem_parZoneTFlowCoolingMixingSetpoint
{ 0x341a00, new U16("parZoneTFlowCoolingMixingSetpoint", "CP270", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneTFlowCoolingFanSetpoint
{ 0x341b00, new U16("parZoneTFlowCoolingFanSetpoint", "CP280", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneMode
{ 0x341f00, new Enum("parZoneMode", "CP320", false, 10, 0.0 , { { 0, "Scheduling" }, { 1, "Manual" }, { 2, "Antifrost" }, { 3, "Temporary" } }) },
#endif
#ifdef rem_parZoneReducedNightMode
{ 0x342400, new Enum("parZoneReducedNightMode", "CP340", false, 10, 0.0 , { { 0, "Stop heat demand" }, { 1, "Continue heat demand" } }) },
#endif
#ifdef rem_parZoneDhwComfortSetpoint
{ 0x342500, new U16("parZoneDhwComfortSetpoint", "CP350", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDhwReducedSetpoint
{ 0x342600, new U16("parZoneDhwReducedSetpoint", "CP360", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDhwHolidaySetpoint
{ 0x342700, new U16("parZoneDhwHolidaySetpoint", "CP370", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDhwAntilegionelSetpoint
{ 0x342800, new U16("parZoneDhwAntilegionelSetpoint", "CP380", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDhwHysterisis
{ 0x342c00, new U16("parZoneDhwHysterisis", "CP420", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneTemporaryRoomSetpoint
{ 0x345100, new U16("parZoneTemporaryRoomSetpoint", "CP510", false, 10, 0.1 ) },
#endif
#ifdef rem_parZoneSwimmingPoolSetpoint
{ 0x345400, new U16("parZoneSwimmingPoolSetpoint", "CP540", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneTimeProgramSelected
{ 0x345800, new Enum("parZoneTimeProgramSelected", "CP570", false, 10, 0.0 , { { 0, "Schedule 1" }, { 1, "Schedule 2" }, { 2, "Schedule 3" }, { 3, "Cooling" } }) },
#endif
#ifdef rem_parZoneProcessHeatSetpoint
{ 0x345b00, new U16("parZoneProcessHeatSetpoint", "CP600", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneOthLogicLevelContact
{ 0x345f00, new Enum("parZoneOthLogicLevelContact", "CP640", false, 10, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_parZoneAmbiantCoolingNightSetpoint
{ 0x346000, new U16("parZoneAmbiantCoolingNightSetpoint", "CP650", false, 10, 0.1 ) },
#endif
#ifdef rem_parZoneIconType
{ 0x346300, new Enum("parZoneIconType", "CP660", false, 10, 0.0 , { { 0, "None" }, { 1, "All" }, { 2, "Bedroom" }, { 3, "Livingroom" }, { 4, "Study" }, { 5, "Outdoor" }, { 6, "Kitchen" }, { 7, "Basement" }, { 8, "Swimming Pool" }, { 9, "icone for domestical hot water Tank" }, { 10, "icone for domestical hot waterElectrical Tank" }, { 11, "icone for domestical hot water Layered Tank" }, { 12, "Domestic Hot Water Boiler Internal tank" }, { 13, "Time Program" } }) },
#endif
#ifdef rem_parZoneRoomUnitBusChannel
{ 0x346500, new U8("parZoneRoomUnitBusChannel", "CP680", false, 10, 1 ) },
#endif
#ifdef rem_parZoneOthContactReversedForCooling
{ 0x346600, new Enum("parZoneOthContactReversedForCooling", "CP690", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_parZoneDhwCalorifierOffset
{ 0x346700, new U16("parZoneDhwCalorifierOffset", "CP700", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDhwCalorifierSetpointRaise
{ 0x346800, new U16("parZoneDhwCalorifierSetpointRaise", "CP710", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneProcessHeatCalorifierSetpointRaise
{ 0x346900, new U16("parZoneProcessHeatCalorifierSetpointRaise", "CP720", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneMaxPreHeatTime
{ 0x346c00, new U16("parZoneMaxPreHeatTime", "CP750", false, 10, 1 ) },
#endif
#ifdef rem_parZoneBuffered
{ 0x347000, new Enum("parZoneBuffered", "CP770", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_parZoneHeatingControlStrategy
{ 0x347100, new Enum("parZoneHeatingControlStrategy", "CP780", false, 10, 0.0 , { { 0, "Automatic Mode" }, { 1, "Room Temperature Control" }, { 2, "Outside Temperature Control" }, { 3, "Oustide and Room temperature Control" } }) },
#endif
#ifdef rem_parZoneScreedDryingDuration1
{ 0x348300, new U8("parZoneScreedDryingDuration1", "ZP000", false, 10, 1 ) },
#endif
#ifdef rem_parZoneScreedDryingStartTemp1
{ 0x348400, new I16("parZoneScreedDryingStartTemp1", "ZP010", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneScreedDryingEndTemp1
{ 0x348500, new I16("parZoneScreedDryingEndTemp1", "ZP020", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneScreedDryingDuration2
{ 0x348600, new U8("parZoneScreedDryingDuration2", "ZP030", false, 10, 1 ) },
#endif
#ifdef rem_parZoneScreedDryingStartTemp2
{ 0x348700, new I16("parZoneScreedDryingStartTemp2", "ZP040", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneScreedDryingEndTemp2
{ 0x348800, new I16("parZoneScreedDryingEndTemp2", "ZP050", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneScreedDryingDuration3
{ 0x348900, new U8("parZoneScreedDryingDuration3", "ZP060", false, 10, 1 ) },
#endif
#ifdef rem_parZoneScreedDryingStartTemp3
{ 0x348a00, new I16("parZoneScreedDryingStartTemp3", "ZP070", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneScreedDryingEndTemp3
{ 0x348b00, new I16("parZoneScreedDryingEndTemp3", "ZP080", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneScreedDryingEnable
{ 0x348c00, new Enum("parZoneScreedDryingEnable", "ZP090", false, 10, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_parBufferControlStrategy
{ 0x350200, new Enum("parBufferControlStrategy", "BP002", false, -1, 0.0 , { { 0, "Fixed setpoint" }, { 1, "Calculated setpoint" }, { 2, "Dedicated slope" } }) },
#endif
#ifdef rem_parBufferHeatingForcedSetpoint
{ 0x350300, new I16("parBufferHeatingForcedSetpoint", "BP003", false, -1, 0.01 ) },
#endif
#ifdef rem_parBufferCoolingForcedSetpoint
{ 0x350400, new I16("parBufferCoolingForcedSetpoint", "BP004", false, -1, 0.01 ) },
#endif
#ifdef rem_parBufferSlope
{ 0x350500, new U8("parBufferSlope", "BP005", false, -1, 0.1 ) },
#endif
#ifdef rem_parBufferHysteresis
{ 0x350e00, new I16("parBufferHysteresis", "BP014", false, -1, 0.01 ) },
#endif
#ifdef rem_parBufferHysteresisStopLoading
{ 0x351300, new I16("parBufferHysteresisStopLoading", "BP019", false, -1, 0.01 ) },
#endif
#ifdef rem_parDhwCalorifierSetpointRaise
{ 0x360500, new U16("parDhwCalorifierSetpointRaise", "DP005", false, -1, 0.01 ) },
#endif
#ifdef rem_parDhwCalorifierHysteresis
{ 0x360600, new U16("parDhwCalorifierHysteresis", "DP006", false, -1, 0.01 ) },
#endif
#ifdef rem_parDhw3wvStandby
{ 0x360700, new Enum("parDhw3wvStandby", "DP007", false, -1, 0.0 , { { 0, "CH position" }, { 1, "DHW position" } }) },
#endif
#ifdef rem_parDhwPumpPostRun
{ 0x361400, new U8("parDhwPumpPostRun", "DP020", false, -1, 1 ) },
#endif
#ifdef rem_parDhwCalorifierOffset
{ 0x362200, new U16("parDhwCalorifierOffset", "DP034", false, -1, 0.01 ) },
#endif
#ifdef rem_parDhwMaxTemp
{ 0x362f00, new U16("parDhwMaxTemp", "DP046", false, -1, 0.01 ) },
#endif
#ifdef rem_parZoneDHWPrimaryTimeProgramSelected
{ 0x365300, new Enum("parZoneDHWPrimaryTimeProgramSelected", "DP060", false, 10, 0.0 , { { 0, "Schedule 1" }, { 1, "Schedule 2" }, { 2, "Schedule 3" }, { 3, "Cooling" } }) },
#endif
#ifdef rem_parZoneDhwPrimaryComfortSetpoint
{ 0x365400, new U16("parZoneDhwPrimaryComfortSetpoint", "DP070", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDHWPrimaryReducedSetpoint
{ 0x365500, new U16("parZoneDHWPrimaryReducedSetpoint", "DP080", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDHWPrimaryHysteresis
{ 0x365900, new U16("parZoneDHWPrimaryHysteresis", "DP120", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDHWPrimaryLoadType
{ 0x365b00, new Enum("parZoneDHWPrimaryLoadType", "DP140", false, 10, 0.0 , { { 0, "Combi" }, { 1, "Solo" }, { 2, "Layered cylinder" }, { 3, "Process heat" }, { 4, "The consumer for primary Dhw is external only" }, { 5, "Integrated DHW tank 'BIC' solution." } }) },
#endif
#ifdef rem_parZoneDHWPrimaryBoilerSwitch
{ 0x365c00, new Enum("parZoneDHWPrimaryBoilerSwitch", "DP150", false, 10, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_parZoneDHWprimaryAntiLegionellaSetpoint
{ 0x365d00, new U16("parZoneDHWprimaryAntiLegionellaSetpoint", "DP160", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDHWPrimaryMode
{ 0x366100, new Enum("parZoneDHWPrimaryMode", "DP200", false, 10, 0.0 , { { 0, "Scheduling" }, { 1, "Manual" }, { 2, "Antifrost" }, { 3, "Temporary" } }) },
#endif
#ifdef rem_parZoneDhwPrimaryHolidaySetpoint
{ 0x367500, new U16("parZoneDhwPrimaryHolidaySetpoint", "DP337", false, 10, 0.01 ) },
#endif
#ifdef rem_parZoneDhwPrimaryShowerTimerTime
{ 0x367700, new U8("parZoneDhwPrimaryShowerTimerTime", "DP357", false, 10, 1 ) },
#endif
#ifdef rem_parZoneDhwPrimaryShowerTimerAction
{ 0x367800, new Enum("parZoneDhwPrimaryShowerTimerAction", "DP367", false, 10, 0.0 , { { 0, "Off" }, { 1, "Warning" }, { 2, "Reduced mode DHW set point" } }) },
#endif
#ifdef rem_parZoneDhwPrimaryShowerTimerTemperatureReduced
{ 0x367900, new U16("parZoneDhwPrimaryShowerTimerTemperatureReduced", "DP377", false, 10, 0.01 ) },
#endif
#ifdef rem_parCascadePermutation
{ 0x370500, new U8("parCascadePermutation", "NP005", false, -1, 1 ) },
#endif
#ifdef rem_parCascadeType
{ 0x370600, new Enum("parCascadeType", "NP006", false, -1, 0.0 , { { 0, "Traditional" }, { 1, "Parallel" } }) },
#endif
#ifdef rem_parCascadeParallelHeatingOutsideTemperatureTrigger
{ 0x370700, new I16("parCascadeParallelHeatingOutsideTemperatureTrigger", "NP007", false, -1, 0.01 ) },
#endif
#ifdef rem_parCascadeInterStageTime
{ 0x370900, new U8("parCascadeInterStageTime", "NP009", false, -1, 1 ) },
#endif
#ifdef rem_parCascadeMode
{ 0x370e00, new Enum("parCascadeMode", "NP014", false, -1, 0.0 , { { 0, "Automatic" }, { 1, "Heating" }, { 2, "Cooling" } }) },
#endif
#ifdef rem_parSmsStatusContacts
{ 0x380600, new Enum("parSmsStatusContacts", "EP018", false, 4, 0.0 , { { 0, "No Action" }, { 1, "Alarm" }, { 2, "Alarm Inverted (fails safe)" }, { 3, "Burning" }, { 4, "Not burning" }, { 5, "Reserved" }, { 6, "Reserved" }, { 7, "Service request" }, { 8, "Boiler on CH" }, { 9, "Boiler on DHW" }, { 10, "CH pump on" }, { 11, "Locking or Blocking" }, { 12, "Cooling mode" } }) },
#endif
#ifdef rem_varHeBurnerSwitchTemperatureConditions
{ 0x420000, new I16("varHeBurnerSwitchTemperatureConditions", "GM000", false, -1, 0.01 ) },
#endif
#ifdef rem_varHeUncorrectedTreturn
{ 0x420100, new I16("varHeUncorrectedTreturn", "GM014", false, -1, 0.01 ) },
#endif
#ifdef rem_varHeCtrFailedBurnerStarts
{ 0x420700, new U16("varHeCtrFailedBurnerStarts", "GC007", false, -1, 1 ) },
#endif
#ifdef rem_varHeFanRpm
{ 0x420b00, new U16("varHeFanRpm", "GM001", false, -1, 1 ) },
#endif
#ifdef rem_varHeFanRpmSetpoint
{ 0x420c00, new U16("varHeFanRpmSetpoint", "GM002", false, -1, 1 ) },
#endif
#ifdef rem_varHeFlameDetect
{ 0x420d00, new Enum("varHeFlameDetect", "GM003", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varHeGasValve1
{ 0x420e00, new Enum("varHeGasValve1", "GM004", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varHeGasValve2
{ 0x420f00, new Enum("varHeGasValve2", "GM005", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varHeGpsSwitch
{ 0x421000, new Enum("varHeGpsSwitch", "GM006", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varHeIgnition
{ 0x421100, new Enum("varHeIgnition", "GM007", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varHeIonisationCurrent
{ 0x421200, new U8("varHeIonisationCurrent", "GM008", false, -1, 0.1 ) },
#endif
#ifdef rem_varHePowerAvailable
{ 0x421400, new U16("varHePowerAvailable", "GM010", false, -1, 0.01 ) },
#endif
#ifdef rem_varHePowerSetpoint
{ 0x421500, new U16("varHePowerSetpoint", "GM011", false, -1, 0.01 ) },
#endif
#ifdef rem_varHeReleaseInput
{ 0x421600, new Enum("varHeReleaseInput", "GM012", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varHeShutdownInput
{ 0x421700, new Enum("varHeShutdownInput", "GM013", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varHeVpsSwitch
{ 0x421900, new Enum("varHeVpsSwitch", "GM015", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varHeSafetyTemperature1
{ 0x421f00, new I16("varHeSafetyTemperature1", "GM020", false, -1, 1 ) },
#endif
#ifdef rem_varHeSafetyTemperature2
{ 0x422000, new I16("varHeSafetyTemperature2", "GM021", false, -1, 1 ) },
#endif
#ifdef rem_varHeBurnerCommand
{ 0x422100, new U8("varHeBurnerCommand", "GM022", false, -1, 1 ) },
#endif
#ifdef rem_varHeStbStatus
{ 0x422400, new Enum("varHeStbStatus", "GM025", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varHeFlameTestActive
{ 0x422600, new Enum("varHeFlameTestActive", "GM027", false, -1, 0.0 , { { 0, "Inactive" }, { 1, "Active" } }) },
#endif
#ifdef rem_varHeGvcMode
{ 0x422700, new Enum("varHeGvcMode", "GM028", false, -1, 0.0 , { { 0, "Normal mode" }, { 1, "Write mode" }, { 2, "Gas band detection mode" }, { 3, "Calibration mode" }, { 4, "Factory test mode" }, { 5, "Combustion correction" }, { 6, "Gas valve modulator offset correction in progress" }, { 7, "Combustion correction for low load to calibration load" }, { 8, "Safety parameter table data processing." }, { 9, "Calibration pre-ignition" }, { 10, "Stable at maximum capacity" }, { 11, "Stable at medium capacity" }, { 12, "Stable at minimum capacity" }, { 13, "Calibrating at maximum capacity" }, { 14, "Calibrating at medium capacity" }, { 15, "Calibrating at minimum capacity" }, { 16, "ADA supervision testing drift on calibration point" }, { 17, "Fast up-modulation of fan enabled to prevent another flame loss" } }) },
#endif
#ifdef rem_varHeGvcInput
{ 0x422800, new Enum("varHeGvcInput", "GM029", false, -1, 0.0 , { { 0, "Normal mode" }, { 1, "Write mode" }, { 2, "Gas band detection mode" }, { 3, "Calibration mode" }, { 4, "Factory test mode" }, { 5, "Combustion correction" }, { 6, "Gas valve modulator offset correction in progress" }, { 7, "Combustion correction for low load to calibration load" }, { 8, "Safety parameter table data processing." }, { 9, "Calibration pre-ignition" }, { 10, "Stable at maximum capacity" }, { 11, "Stable at medium capacity" }, { 12, "Stable at minimum capacity" }, { 13, "Calibrating at maximum capacity" }, { 14, "Calibrating at medium capacity" }, { 15, "Calibrating at minimum capacity" }, { 16, "ADA supervision testing drift on calibration point" }, { 17, "Fast up-modulation of fan enabled to prevent another flame loss" } }) },
#endif
#ifdef rem_varHeGvcOutput
{ 0x422900, new U8("varHeGvcOutput", "GM030", false, -1, 1 ) },
#endif
#ifdef rem_varHeGvcState
{ 0x422a00, new Enum("varHeGvcState", "GM031", false, -1, 0.0 , { { 0, "Standby" }, { 1, "Pre-purge stage of burner cycle" }, { 2, "Pre-ignition stage of burner cycle" }, { 3, "Ignition stage of burner cycle" }, { 4, "Flame check stage of burner cycle" }, { 5, "Burning stage of burner cycle" }, { 6, "Reserved due to legacy" }, { 7, "Reserved due to legacy" }, { 8, "Valve proving system test active" }, { 9, "Interpurge stage between burner cycles" }, { 10, "Post-purge stage at the end of the burner cycle" }, { 11, "Fan running for EOL test or development" }, { 12, "Error with blocking severity" }, { 13, "Error with locking severity" }, { 14, "Maximum amount of locking resets exceeded. Power cycle required." }, { 15, "Hydrogen error with blocking severity" }, { 16, "Hydrogen error with locking severity" }, { 17, "Hydrogen error with locking severity, Safety unit out of resets" }, { 254, "Preparing to go through reset." } }) },
#endif
#ifdef rem_varHeGvcSubState
{ 0x422b00, new Enum("varHeGvcSubState", "GM032", false, -1, 0.0 , { { 0, "Standby" }, { 1, "Waiting for the flame current to stabilize" }, { 2, "Gas valve stepper has reached maximum value, unable to increase power output further." }, { 3, "Gas valve stepper has reached minimum value, unable to decrease power output further." }, { 4, "Not_Used" }, { 5, "Not_Used" }, { 6, "Not_Used" }, { 7, "not used" }, { 8, "Gas valve modulation offset correction in progress" }, { 9, "Not_Used" }, { 10, "Going through self-reset. Communication errors temporarily suppressed." }, { 11, "Burner calibration active" } }) },
#endif
#ifdef rem_varHeGvcLockingCode
{ 0x422c00, new U8("varHeGvcLockingCode", "GM033", false, -1, 1 ) },
#endif
#ifdef rem_varHeGvcBlockingCode
{ 0x422d00, new U8("varHeGvcBlockingCode", "GM034", false, -1, 1 ) },
#endif
#ifdef rem_varHeGvcPowerOutput
{ 0x422e00, new U16("varHeGvcPowerOutput", "GM035", false, -1, 0.01 ) },
#endif
#ifdef rem_varHeGvcPowerSetpoint
{ 0x422f00, new U16("varHeGvcPowerSetpoint", "GM036", false, -1, 0.01 ) },
#endif
#ifdef rem_varHeFanPwm
{ 0x423300, new U8("varHeFanPwm", "GM040", false, -1, 1 ) },
#endif
#ifdef rem_varHeTFlow2
{ 0x423500, new I16("varHeTFlow2", "GM042", false, -1, 0.01 ) },
#endif
#ifdef rem_varHeSafetyTemperature3
{ 0x423600, new I16("varHeSafetyTemperature3", "GM043", false, -1, 0.1 ) },
#endif
#ifdef rem_varHeControlledStopReason
{ 0x423700, new Enum("varHeControlledStopReason", "GM044", false, -1, 0.0 , { { 0, "None" }, { 1, "CH blocking" }, { 2, "DHW blocking" }, { 3, "Wait for burner start" }, { 4, "Flow temperature above absolute max" }, { 5, "Flow temperature above start temperature" }, { 6, "Heatexchanger temperature above start temperature" }, { 7, "Average flow temperature above start temperature" }, { 8, "Flow temperature above max setpoint" }, { 9, "Delta T too high" }, { 10, "Flow temperature above stop temperature" }, { 11, "Anti cycle on off heat demand." }, { 12, "Poor combustion" }, { 13, "Solar temperature above stop temperature" } }) },
#endif
#ifdef rem_varGvcGasValveModulatorPower
{ 0x423a00, new U8("varGvcGasValveModulatorPower", "GM048", false, -1, 1 ) },
#endif
#ifdef rem_varGvcCtrCalibrations
{ 0x423e00, new U16("varGvcCtrCalibrations", "GC001", false, -1, 10 ) },
#endif
#ifdef rem_varHpHeatPumpTF
{ 0x430100, new I16("varHpHeatPumpTF", "HM001", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpHeatPumpTR
{ 0x430200, new I16("varHpHeatPumpTR", "HM002", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpHeatPumpSetpoint
{ 0x430300, new I16("varHpHeatPumpSetpoint", "HM003", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpBlockingInput1
{ 0x430400, new Enum("varHpBlockingInput1", "HM004", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varHpBlockingInput2
{ 0x430500, new Enum("varHpBlockingInput2", "HM005", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varHpUnitFailure
{ 0x430700, new Enum("varHpUnitFailure", "HM007", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varHpCompressorState
{ 0x430800, new Enum("varHpCompressorState", "HM008", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varHpDefrost
{ 0x430900, new Enum("varHpDefrost", "HM009", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varHpBackUp1State
{ 0x430c00, new Enum("varHpBackUp1State", "HM012", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varHpHeatPumpFlowTempAveraged
{ 0x431400, new I16("varHpHeatPumpFlowTempAveraged", "HM020", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpOutdoorUnitErrorRate
{ 0x431800, new U16("varHpOutdoorUnitErrorRate", "HM024", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpCompDemand
{ 0x431e00, new Enum("varHpCompDemand", "HM030", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varHpCOPCalculated
{ 0x431f00, new U16("varHpCOPCalculated", "HM031", false, -1, 0.001 ) },
#endif
#ifdef rem_varHpCOPThreshold
{ 0x432000, new U16("varHpCOPThreshold", "HM032", false, -1, 0.001 ) },
#endif
#ifdef rem_varHpCoolingSetpoint
{ 0x432100, new U16("varHpCoolingSetpoint", "HM033", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpTempoBetweenStageCalculated
{ 0x433800, new U16("varHpTempoBetweenStageCalculated", "HM056", false, -1, 1 ) },
#endif
#ifdef rem_varHpCompressorCurrent
{ 0x434000, new U16("varHpCompressorCurrent", "HM062", false, -1, 0.1 ) },
#endif
#ifdef rem_varHpCondenserRefrigerantGasTemperature
{ 0x437500, new I16("varHpCondenserRefrigerantGasTemperature", "HM087", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpOutdoorUnitPumpDown
{ 0x437600, new Enum("varHpOutdoorUnitPumpDown", "HM088", false, -1, 0.0 , { { 0, "Inactive" }, { 1, "Active" } }) },
#endif
#ifdef rem_varHpOutdoorUnitOutsideTemperature
{ 0x437700, new I16("varHpOutdoorUnitOutsideTemperature", "HM098", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpCondenserRefrigerantPressure
{ 0x437800, new U16("varHpCondenserRefrigerantPressure", "HM097", false, -1, 0.1 ) },
#endif
#ifdef rem_varHpOutdoorUnitVoltage
{ 0x437900, new U16("varHpOutdoorUnitVoltage", "HM096", false, -1, 1 ) },
#endif
#ifdef rem_varHpModel
{ 0x437d00, new U8("varHpModel", "HM091", false, -1, 1 ) },
#endif
#ifdef rem_varOduStatus
{ 0x437e00, new U8("varOduStatus", "HM092", false, -1, 1 ) },
#endif
#ifdef rem_varHpOutdoorUnitSoftwareVersion
{ 0x437f00, new U8("varHpOutdoorUnitSoftwareVersion", "HM093", false, -1, 1 ) },
#endif
#ifdef rem_varHpIpmTemperature
{ 0x438000, new I16("varHpIpmTemperature", "HM094", false, -1, 0.01 ) },
#endif
#ifdef rem_varHpOffPeriod
{ 0x438100, new Enum("varHpOffPeriod", "HM095", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varApCtrHoursTotal
{ 0x500000, new U32("varApCtrHoursTotal", "AC001", false, -1, 1 ) },
#endif
#ifdef rem_varApDhwActive
{ 0x500100, new Enum("varApDhwActive", "AM001", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varApLowNoise
{ 0x500200, new Enum("varApLowNoise", "AM002", false, -1, 0.0 , { { 0, "No silent mode" }, { 1, "Silent mode level 1" }, { 2, "Silent mode level 2" }, { 3, "Silent mode level 3" }, { 4, "Silent mode level 4" }, { 5, "Silent mode level 5" } }) },
#endif
#ifdef rem_varApErrorStatusBlocking
{ 0x500400, new U8("varApErrorStatusBlocking", "AM004", false, -1, 1 ) },
#endif
#ifdef rem_varApErrorStatusLocking
{ 0x500500, new U8("varApErrorStatusLocking", "AM005", false, -1, 1 ) },
#endif
#ifdef rem_varApOutsideSensorConnected
{ 0x500700, new Enum("varApOutsideSensorConnected", "AP078", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varApPumpSpeed
{ 0x500c00, new U16("varApPumpSpeed", "AM010", false, -1, 0.1 ) },
#endif
#ifdef rem_varApForceDeair
{ 0x500d00, new Enum("varApForceDeair", "BM013", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varApServiceRequired
{ 0x500e00, new Enum("varApServiceRequired", "AM011", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varApStatus
{ 0x500f00, new Enum("varApStatus", "AM012", false, -1, 0.0 , { { 0, "The device is in standby" }, { 1, "A heat demand is pending" }, { 2, "The producer is starting the burner" }, { 3, "The producer is burning for ch heat demand" }, { 4, "The producer is burning for Dhw" }, { 5, "the producer is stopping the burner" }, { 6, "A heat demand has ended the pump is post running" }, { 7, "The producer is running for cooling" }, { 8, "The burner will not be started because the burner start conditions are not met. This can be time and temperature" }, { 9, "A blocking is active" }, { 10, "A locking is active" }, { 11, "Commisioning mode, low load" }, { 12, "Commissioning mode maximal Ch power" }, { 13, "Commissioning mode maximal Dhw power" }, { 14, "Commissioning mode custom power" }, { 15, "Manual heat demand on Ch is active" }, { 16, "The temperatures are too low, the boiler frost protection is running" }, { 17, "The boiler is running the de air program" }, { 18, "The fan is running to cool down the inside of the boiler" }, { 19, "A reset has been received the device is resetting. This state is valid until the device goes through reset not after the reset." }, { 20, "The device is filling adding water to the installation" }, { 21, "The device is in halt state, all processes are stopped. Power cycle the device to start opertion" }, { 22, "Forced Calibration" }, { 23, "To reflect that factory mode is active." }, { 24, "Hydraulic balancing mode is active." }, { 200, "All functions are stopped, the service tool interface is controlling the device functions" }, { 254, "The state of the device is undefined" } }) },
#endif
#ifdef rem_varApSubStatus
{ 0x501100, new Enum("varApSubStatus", "AM014", false, -1, 0.0 , { { 0, "The sub process is in standby. When the device status in not standby the device is waiting on a process or action to continue" }, { 1, "The device is waiting, to restart. Too many heat demands in a predefined time window or too the min heater off time is not respected." }, { 2, "external hydraulic valve is opened, when this option is configured in the device. External option boards must be connected to drive the valve" }, { 3, "The device starts the pump" }, { 4, "The system temperatures do not meet the burner start requirements. The burner is waiting for the temperature to meet the start conditions" }, { 10, "external gasvalve valve is opened, when this option is connectedto the system. External option boards must be connected to drive the valve" }, { 11, "Before the burner starts the fan goes to an increased rpm before the flue gas valve is opened." }, { 12, "Opening of the flue gas valve" }, { 13, "Increase the fan speed to prepurge RPM" }, { 14, "Wait a time defined by a parameter, for the release input to close before the burner can start" }, { 15, "Send a burner start command to the safety core" }, { 16, "Valve proving test is running" }, { 17, "Start the ignitor before the gas valve is opened" }, { 18, "Ignition of the burner" }, { 19, "Check the pressence of the flame directly after the ignition" }, { 20, "Purge the heat exchanger after a failed ignition" }, { 21, "Wait for the burner to be active." }, { 22, "Waiting for Boiler Room Ventilation Fan to start" }, { 30, "The boiler is burning for the requested setpoint" }, { 31, "The boiler is burning for a reduced internal setpoint due to temperature limitations" }, { 32, "The boiler is burning on the requested power, the boiler is burning on power control" }, { 33, "the heat exchanger temperature is rising faster than gradient level 1, the modulation is stopped" }, { 34, "the heat exchanger temperature is rising faster than gradient level 2, the modulation is set to low load" }, { 35, "the heat exchanger temperature is rising faster than gradient level 1, the boiler is in blocking" }, { 36, "The ionization signal is too low the burner power is increased to increase the ionization signal. Prevent the burner to switch off" }, { 37, "Stabilization time, during this time the temperatures should stabilize. The temperature protections are swichted off" }, { 38, "To prevent noise due to a cold burner the burner runs at start load for 30 seconds" }, { 39, "Central heating was interruppted by Dhw and now resumes at the power level where it was running on" }, { 40, "Remove the burner demand from the safety core" }, { 41, "Purge the heat exchanger after a burner demand" }, { 42, "Close the external gas valve" }, { 43, "Set the fan speed to close the flue gas valve" }, { 44, "Stop the fan" }, { 45, "The flue gas temperature is to high, parameter setting, the burner power is decreased to lower the flue gas temperature" }, { 46, "The auto filling is filling the installation, the installation was empty." }, { 47, "The auto filling is topping up the installation. The water pressure in the installation was low." }, { 48, "The flow temperature set point is reduced to protect the heat exchanger against thermal stress when the maximum set point has been set higher than the maximum value (parHeReducedFlowTempMaxAtMaxDt)" }, { 49, "Gas valve modulator offset correction in progress" }, { 60, "The pump is running after a heat demand. The remaining heat is put to the connected hydraulic system" }, { 61, "Remove the power from the pump" }, { 62, "Close the external hydraulic valve" }, { 63, "SetBoilerAntiCycleTimer" }, { 65, "HeatPumpReleivedAndBackupOn" }, { 66, "HeatPumpFlowOverMaxFlowTempAndBackupON" }, { 67, "HeatPumpOffDuToExternalConditionAndBackupOn" }, { 68, "HeatPumpOffDuToHybridAndBackupOn" }, { 69, "DefrostingWithHeatPumpOnly" }, { 70, "DefrostingWithBackupOnly" }, { 71, "DefrostingWithHeatPumpAndBackup" }, { 72, "PumpSourcePostRunAndBackupRun" }, { 73, "HeatPumpFlowOverMaxTemperature" }, { 74, "SourcePumpPostRun" }, { 75, "HeatPumpOffDuToHumiditySensor" }, { 76, "HeatPumpOffDuToWaterFlow" }, { 78, "SetpointLimitedDuToHumiditySensor" }, { 79, "HeatPumpAndBackupReleivedForHeatingAndDhw" }, { 80, "HeatPumpReleveidForCooling" }, { 81, "HeatPumpOffDuToOutsideTemperature" }, { 82, "HeatPumpOffUnderrun" }, { 83, "DeAirPumpOnAndValveCH" }, { 84, "DeAirPumpOnAndValveDhw" }, { 85, "DeAirPumpOffAndValveCH" }, { 86, "DeAirPumpOffAndValveDhw" }, { 88, "BLInputBackupLimited" }, { 89, "BLInputHeatPumpLimited" }, { 90, "BLInputBackupandHeatPumpLimited" }, { 91, "BLInputLowTariff" }, { 92, "BLInputPhotovoltaicWithHeatPumpOnly" }, { 93, "BLInputPhotovoltaicWithHeatPumpAndBackup" }, { 94, "BLInputSmartGrid" }, { 95, "The boiler is in wait state until the water pressure is sufficient. De-air will not start" }, { 96, "No producer available in the appliance or the system" }, { 97, "The minimum power is increased for 1 hour. Modulation range is limted." }, { 98, "The maximum power is decreased as long as gas valve modulator is at the maximum limit. Modulation range is limted." }, { 102, "HeatPumpFreeCoolingModeChPumpInactive" }, { 103, "HeatPumpFreeCoolingModeChPumpActive" }, { 104, "SourcePumpPreRunning" }, { 105, "The electronic combustion of the gas air is calibrating the combustion" }, { 106, "Blocking input function is active" }, { 107, "Compressor is in warmup time (ON, but not allowed to go OFF), that means compressor minimum on time" }, { 108, "Evaporator defrost protection active in curative mode, that means: remove ice from evaporator" }, { 109, "Evaporator defrost protection active in preventive mode, that means:  prevent ice formation" }, { 200, "Initialising Done" }, { 201, "Initialising Csu, device data storage" }, { 202, "Initialising Identifiers" }, { 203, "Initialising Blocking Parameters" }, { 204, "Initialising Safety Unit" }, { 205, "Initialising Blocking" }, { 254, "The sub state of the boiler is undefined" }, { 255, "The safety core has been reset too many times in a row. Wait 1 hour or power cycle the device before a next reset can be given." } }) },
#endif
#ifdef rem_varApSystemPumpRunning
{ 0x501200, new Enum("varApSystemPumpRunning", "AM015", false, -1, 0.0 , { { 0, "Inactive" }, { 1, "Active" } }) },
#endif
#ifdef rem_varApTflow
{ 0x501300, new I16("varApTflow", "AM016", false, -1, 0.01 ) },
#endif
#ifdef rem_varApTheatExchanger
{ 0x501400, new I16("varApTheatExchanger", "AM017", false, -1, 0.01 ) },
#endif
#ifdef rem_varApTreturn
{ 0x501500, new I16("varApTreturn", "AM018", false, -1, 0.01 ) },
#endif
#ifdef rem_varApWaterPressure
{ 0x501600, new U8("varApWaterPressure", "AM019", false, -1, 0.1 ) },
#endif
#ifdef rem_varApHdOnOffDemand
{ 0x501900, new Enum("varApHdOnOffDemand", "AM022", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varApDhwTemperature
{ 0x501a00, new I16("varApDhwTemperature", "BM000", false, -1, 0.01 ) },
#endif
#ifdef rem_varApPowerActual
{ 0x501b00, new U16("varApPowerActual", "AM024", false, -1, 0.01 ) },
#endif
#ifdef rem_varApTOutside
{ 0x501e00, new I16("varApTOutside", "AM027", false, -1, 0.01 ) },
#endif
#ifdef rem_varAp0to10Vinput
{ 0x501f00, new U8("varAp0to10Vinput", "AM028", false, -1, 0.1 ) },
#endif
#ifdef rem_varApStatusContactPosition
{ 0x502100, new Enum("varApStatusContactPosition", "AM200", false, 10, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varApNextServiceIndication
{ 0x502400, new Enum("varApNextServiceIndication", "AM033", false, -1, 0.0 , { { 0, "Next service notification: A" }, { 1, "Next service notification: B" }, { 2, "Next service notification: A" }, { 3, "Next service notification: C" } }) },
#endif
#ifdef rem_varApFlueGasTemperature
{ 0x502700, new I16("varApFlueGasTemperature", "AM036", false, -1, 0.1 ) },
#endif
#ifdef rem_varAp3wayValveStatus
{ 0x502800, new Enum("varAp3wayValveStatus", "AM037", false, -1, 0.0 , { { 0, "CH" }, { 1, "DHW" } }) },
#endif
#ifdef rem_varApControlTemp
{ 0x503100, new I16("varApControlTemp", "AM040", false, -1, 0.01 ) },
#endif
#ifdef rem_varApPowerDownResetNeeded
{ 0x503800, new Enum("varApPowerDownResetNeeded", "AM043", false, -1, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varApCtrServiceBurningHours
{ 0x504000, new U16("varApCtrServiceBurningHours", "AC002", false, -1, 2 ) },
#endif
#ifdef rem_varApCtrServiceOperatingHours
{ 0x504100, new U16("varApCtrServiceOperatingHours", "AC003", false, -1, 2 ) },
#endif
#ifdef rem_varApCtrServiceBurnerStarts
{ 0x504200, new U32("varApCtrServiceBurnerStarts", "AC004", false, -1, 1 ) },
#endif
#ifdef rem_varApChEnergyConsumption
{ 0x504400, new U32("varApChEnergyConsumption", "AC005", false, -1, 1 ) },
#endif
#ifdef rem_varApDhwEnergyConsumption
{ 0x504500, new U32("varApDhwEnergyConsumption", "AC006", false, -1, 1 ) },
#endif
#ifdef rem_varApCoolingEnergyConsumption
{ 0x504600, new U32("varApCoolingEnergyConsumption", "AC007", false, -1, 1 ) },
#endif
#ifdef rem_varApToutsideInternetTemperature
{ 0x504e00, new I16("varApToutsideInternetTemperature", "AM046", false, -1, 0.01 ) },
#endif
#ifdef rem_varApActualProducerPower
{ 0x505b00, new U32("varApActualProducerPower", "AM047", false, -1, 0.001 ) },
#endif
#ifdef rem_varApFlueGasTemperature2
{ 0x507100, new I16("varApFlueGasTemperature2", "AM055", false, -1, 0.1 ) },
#endif
#ifdef rem_varApFlowmeter
{ 0x508300, new U16("varApFlowmeter", "AM056", false, -1, 0.01 ) },
#endif
#ifdef rem_varApChEnergyDelivery
{ 0x508500, new U32("varApChEnergyDelivery", "AC008", false, -1, 1 ) },
#endif
#ifdef rem_varApDhwEnergyDelivery
{ 0x508600, new U32("varApDhwEnergyDelivery", "AC009", false, -1, 1 ) },
#endif
#ifdef rem_varApCoolingEnergyDelivery
{ 0x508700, new U32("varApCoolingEnergyDelivery", "AC010", false, -1, 1 ) },
#endif
#ifdef rem_varApSeasonalPerformanceFactor
{ 0x508a00, new U8("varApSeasonalPerformanceFactor", "AC013", false, -1, 0.1 ) },
#endif
#ifdef rem_varApSeasonMode
{ 0x50a700, new Enum("varApSeasonMode", "AM091", false, -1, 0.0 , { { 0, "Winter" }, { 1, "Winter system frost protection acitve" }, { 2, "Summer neutral band" }, { 3, "Summer" } }) },
#endif
#ifdef rem_varApInternalSetpoint
{ 0x50a900, new U16("varApInternalSetpoint", "AM101", false, -1, 0.01 ) },
#endif
#ifdef rem_varApCtrPumpRunHours
{ 0x50ad00, new U32("varApCtrPumpRunHours", "AC026", false, -1, 1 ) },
#endif
#ifdef rem_varApCtrPumpStarts
{ 0x50ae00, new U32("varApCtrPumpStarts", "AC027", false, -1, 1 ) },
#endif
#ifdef rem_varApCtrBackup1Starts
{ 0x50b100, new U32("varApCtrBackup1Starts", "AC030", false, -1, 1 ) },
#endif
#ifdef rem_varChCtrHeatingBurnHours
{ 0x530000, new U32("varChCtrHeatingBurnHours", "PC000", false, -1, 1 ) },
#endif
#ifdef rem_varChSetpoint
{ 0x530200, new U16("varChSetpoint", "PM002", false, -1, 0.01 ) },
#endif
#ifdef rem_varChTflowAverage
{ 0x530300, new I16("varChTflowAverage", "PM003", false, -1, 0.01 ) },
#endif
#ifdef rem_varChCtrBurnerStarts
{ 0x530b00, new U32("varChCtrBurnerStarts", "PC002", false, -1, 1 ) },
#endif
#ifdef rem_varChCtrBurnHours
{ 0x530c00, new U32("varChCtrBurnHours", "PC003", false, -1, 1 ) },
#endif
#ifdef rem_varChCtrFlameLoss
{ 0x530d00, new U16("varChCtrFlameLoss", "PC004", false, -1, 1 ) },
#endif
#ifdef rem_varChCtrCoolingBurnHours
{ 0x530f00, new U32("varChCtrCoolingBurnHours", "PC005", false, -1, 1 ) },
#endif
#ifdef rem_varZoneProducerPowerEngineStatus
{ 0x540100, new Enum("varZoneProducerPowerEngineStatus", "CM001", false, 9, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varZoneMvdClosing
{ 0x540200, new Enum("varZoneMvdClosing", "CM010", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZoneMvdOpening
{ 0x540300, new Enum("varZoneMvdOpening", "CM020", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZoneTRoom
{ 0x540400, new I16("varZoneTRoom", "CM030", false, 10, 0.1 ) },
#endif
#ifdef rem_varZoneTflow
{ 0x540500, new I16("varZoneTflow", "CM040", false, 10, 0.01 ) },
#endif
#ifdef rem_varZonePumpRunning
{ 0x540600, new Enum("varZonePumpRunning", "CM050", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZonePumpSpeed
{ 0x540700, new U16("varZonePumpSpeed", "CM060", false, 10, 0.1 ) },
#endif
#ifdef rem_varZoneTemperatureSetpoint
{ 0x540800, new U16("varZoneTemperatureSetpoint", "CM070", false, 10, 0.01 ) },
#endif
#ifdef rem_varZoneModulationSetpoint
{ 0x540900, new U8("varZoneModulationSetpoint", "CM080", false, 10, 1 ) },
#endif
#ifdef rem_varZoneTroomTemporarySetpoint
{ 0x540f00, new I16("varZoneTroomTemporarySetpoint", "CM110", false, 10, 0.1 ) },
#endif
#ifdef rem_varZoneCurrentMode
{ 0x541000, new Enum("varZoneCurrentMode", "CM120", false, 10, 0.0 , { { 0, "Scheduling" }, { 1, "Manual" }, { 2, "Antifrost" }, { 3, "Temporary" } }) },
#endif
#ifdef rem_varZoneCurrentActivities
{ 0x541300, new Enum("varZoneCurrentActivities", "CM130", false, 10, 0.0 , { { 0, "Anti frost" }, { 1, "Reduced" }, { 2, "Comfort" }, { 3, "Anti legionella" } }) },
#endif
#ifdef rem_varZoneOtPresent
{ 0x541400, new Enum("varZoneOtPresent", "CM140", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZoneHdOnOffDemand
{ 0x541500, new Enum("varZoneHdOnOffDemand", "CM150", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZoneModulatedHeatDemandPresent
{ 0x541600, new Enum("varZoneModulatedHeatDemandPresent", "CM160", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZoneOtSmartPowerAvailable
{ 0x541700, new Enum("varZoneOtSmartPowerAvailable", "CM170", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZoneRuPresent
{ 0x541800, new Enum("varZoneRuPresent", "CM180", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZoneTRoomSetpoint
{ 0x541900, new I16("varZoneTRoomSetpoint", "CM190", false, 10, 0.1 ) },
#endif
#ifdef rem_varZoneCurrentHeatingMode
{ 0x541d00, new Enum("varZoneCurrentHeatingMode", "CM200", false, 10, 0.0 , { { 0, "No heat demand." }, { 1, "Heating mode is active" }, { 2, "Cooling mode is active" } }) },
#endif
#ifdef rem_varZoneTOutside
{ 0x542e00, new I16("varZoneTOutside", "CM210", false, 10, 0.01 ) },
#endif
#ifdef rem_varZoneToutsideAverageShortWindon
{ 0x542f00, new I16("varZoneToutsideAverageShortWindon", "CM220", false, 10, 0.01 ) },
#endif
#ifdef rem_varZoneToutsideAverageLongWindow
{ 0x543000, new I16("varZoneToutsideAverageLongWindow", "CM230", false, 10, 0.01 ) },
#endif
#ifdef rem_varZoneToutsideConnected
{ 0x543100, new Enum("varZoneToutsideConnected", "CM240", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varZoneTDhwTopTemperature
{ 0x543300, new I16("varZoneTDhwTopTemperature", "CM250", false, 10, 0.01 ) },
#endif
#ifdef rem_varZoneRoomTemperatureMeasured
{ 0x543400, new I16("varZoneRoomTemperatureMeasured", "CM260", false, 10, 0.01 ) },
#endif
#ifdef rem_varZoneCalculatedRoomTemperatureSetpoint
{ 0x543600, new I16("varZoneCalculatedRoomTemperatureSetpoint", "CM280", false, 10, 0.01 ) },
#endif
#ifdef rem_varZoneSecondarySwimmingPoolpumpStatus
{ 0x543700, new Enum("varZoneSecondarySwimmingPoolpumpStatus", "CM290", false, 10, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varZoneElectricalBackupOutputStatus
{ 0x543800, new Enum("varZoneElectricalBackupOutputStatus", "CM300", false, 10, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varZoneOffActivityReason
{ 0x544400, new Enum("varZoneOffActivityReason", "CM390", false, 10, 0.0 , { { 0, "The zone is not disabled." }, { 1, "Zone activity is Off / antifrost because zone mode is holiday" }, { 2, "Zone activity is Off / antifrost because the zone On/Off contact forces it" }, { 3, "Zone activity is Off / antifrost because the zone hydraulic balancing mode is on" } }) },
#endif
#ifdef rem_varZoneScreedDryingCurrentSetpoint
{ 0x544700, new I16("varZoneScreedDryingCurrentSetpoint", "ZM000", false, 10, 0.01 ) },
#endif
#ifdef rem_varZoneCtrScreedDryingRemainingTime
{ 0x544a00, new U8("varZoneCtrScreedDryingRemainingTime", "ZC000", false, 10, 1 ) },
#endif
#ifdef rem_varBufferTankTemperature
{ 0x550100, new I16("varBufferTankTemperature", "BM001", false, 10, 0.01 ) },
#endif
#ifdef rem_varBufferTankPumpState
{ 0x550800, new Enum("varBufferTankPumpState", "BM021", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varBufferMode
{ 0x551500, new Enum("varBufferMode", "BM020", false, -1, 0.0 , { { 0, "Decoupling Tank" }, { 1, "Storage Tank" } }) },
#endif
#ifdef rem_varDhwTankTemperature
{ 0x560100, new I16("varDhwTankTemperature", "DM001", false, -1, 0.01 ) },
#endif
#ifdef rem_varDhwFlowSpeed
{ 0x560200, new U16("varDhwFlowSpeed", "DM002", false, -1, 0.1 ) },
#endif
#ifdef rem_varDhwFlowSwitchSignal
{ 0x560300, new Enum("varDhwFlowSwitchSignal", "DM003", false, -1, 0.0 , { { 0, "Open" }, { 1, "Closed" }, { 2, "Off" } }) },
#endif
#ifdef rem_varDhwFlowTempSetpoint
{ 0x560400, new U16("varDhwFlowTempSetpoint", "DM004", false, -1, 0.01 ) },
#endif
#ifdef rem_varDhwSolarTemp
{ 0x560500, new I16("varDhwSolarTemp", "DM005", false, -1, 0.01 ) },
#endif
#ifdef rem_varDhwTankTemperatureTop
{ 0x560600, new I16("varDhwTankTemperatureTop", "DM006", false, -1, 0.01 ) },
#endif
#ifdef rem_varDhwTasStatus
{ 0x560700, new Enum("varDhwTasStatus", "DM007", false, -1, 0.0 , { { 0, "Off" }, { 1, "On" } }) },
#endif
#ifdef rem_varDhwOutTemp
{ 0x560900, new I16("varDhwOutTemp", "DM008", false, -1, 0.01 ) },
#endif
#ifdef rem_varDhwCtr3WayValveCycles
{ 0x560a00, new U32("varDhwCtr3WayValveCycles", "DC002", false, -1, 1 ) },
#endif
#ifdef rem_varDhwCtr3WayValveHours
{ 0x560b00, new U32("varDhwCtr3WayValveHours", "DC003", false, -1, 1 ) },
#endif
#ifdef rem_varDhwCtrBurnerStartsDhw
{ 0x560c00, new U32("varDhwCtrBurnerStartsDhw", "DC004", false, -1, 1 ) },
#endif
#ifdef rem_varDhwCtrBurnHours
{ 0x560d00, new U32("varDhwCtrBurnHours", "DC005", false, -1, 1 ) },
#endif
#ifdef rem_varDhwPrimaryMode
{ 0x560e00, new Enum("varDhwPrimaryMode", "DM009", false, 10, 0.0 , { { 0, "Scheduling" }, { 1, "Manual" }, { 2, "Antifrost" }, { 3, "Temporary" } }) },
#endif
#ifdef rem_varZoneDhwPrimaryCurrentActivities
{ 0x560f00, new Enum("varZoneDhwPrimaryCurrentActivities", "DM019", false, 10, 0.0 , { { 0, "Anti frost" }, { 1, "Reduced" }, { 2, "Comfort" }, { 3, "Anti legionella" } }) },
#endif
#ifdef rem_varDHWTemperatureSetpoint
{ 0x561000, new U16("varDHWTemperatureSetpoint", "DM029", false, -1, 0.01 ) },
#endif
#ifdef rem_varZoneDhwPrimaryShowerTimerElapsed
{ 0x561300, new Enum("varZoneDhwPrimaryShowerTimerElapsed", "DM050", false, 10, 0.0 , { { 0, "No" }, { 1, "Yes" } }) },
#endif
#ifdef rem_varCascadeNumberProducerFirstStart
{ 0x570000, new U8("varCascadeNumberProducerFirstStart", "NM000", false, -1, 1 ) },
#endif
#ifdef rem_varProducerManagerSystemFlowTemperature
{ 0x570100, new I16("varProducerManagerSystemFlowTemperature", "NM001", false, -1, 0.01 ) },
#endif
#ifdef rem_varCascadeNbStageAvailable
{ 0x571600, new U8("varCascadeNbStageAvailable", "NM022", false, -1, 1 ) },
#endif
#ifdef rem_varCascadeNbStageRequired
{ 0x571700, new U8("varCascadeNbStageRequired", "NM023", false, -1, 1 ) },
#endif
#ifdef rem_varCascadeNumberProducersPresent
{ 0x571c00, new U8("varCascadeNumberProducersPresent", "NM028", false, -1, 1 ) },
#endif

};

}; // namespace remeha_can

