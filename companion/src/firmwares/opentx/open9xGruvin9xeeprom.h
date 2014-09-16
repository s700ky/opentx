/*
 * Author - Bertrand Songis <bsongis@gmail.com>
 *
 * Based on th9x -> http://code.google.com/p/th9x/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef open9xGruvin9xeeprom_h
#define open9xGruvin9xeeprom_h

#define O9X_V4_MAX_CSFUNCOLD 13
#define O9X_V4_MAX_CSFUNC 15

#include "open9xStockeeprom.h"

PACK(typedef struct t_Open9xGruvin9xFlightModeData_v207 {
  int8_t trim[4];     // -500..500 => trim value, 501 => use trim of phase 0, 502, 503, 504 => use trim of phases 1|2|3|4 instead
  int8_t trim_ext:8;  // 2 less significant extra bits per trim (10bits trims)
  int8_t swtch;       // swtch of phase[0] is not used
  char name[6];
  uint8_t fadeIn:4;
  uint8_t fadeOut:4;
  int16_t rotaryEncoders[2];
  operator FlightModeData();
  t_Open9xGruvin9xFlightModeData_v207() { memset(this, 0, sizeof(t_Open9xGruvin9xFlightModeData_v207)); }
}) Open9xGruvin9xFlightModeData_v207;

PACK(typedef struct t_Open9xGruvin9xFlightModeData_v208 {
  int16_t trim[4];     // -500..500 => trim value, 501 => use trim of phase 0, 502, 503, 504 => use trim of phases 1|2|3|4 instead
  int8_t swtch;       // swtch of phase[0] is not used
  char name[6];
  uint8_t fadeIn:4;
  uint8_t fadeOut:4;
  int16_t rotaryEncoders[2];
  operator FlightModeData();
  t_Open9xGruvin9xFlightModeData_v208() { memset(this, 0, sizeof(t_Open9xGruvin9xFlightModeData_v208)); }
}) Open9xGruvin9xFlightModeData_v208;

PACK(typedef struct t_Open9xGruvin9xMixData_v207 {
  uint8_t destCh:4;          // 0, 1..C9X_NUM_CHNOUT
  int8_t  phase:4;           // -5=!FP4, 0=normal, 5=FP4
  int8_t  weight;
  int8_t  swtch:6;
  uint8_t mltpx:2;           // multiplex method: 0 means +=, 1 means *=, 2 means :=
  int8_t  curve:6;
  uint8_t mixWarn:2;         // mixer warning
  uint8_t delayUp:4;
  uint8_t delayDown:4;
  uint8_t speedUp:4;         // Servogeschwindigkeit aus Tabelle (10ms Cycle)
  uint8_t speedDown:4;       // 0 nichts
  uint16_t srcRaw:7;         //
  uint16_t differential:7;
  uint16_t carryTrim:2;
  int8_t  sOffset;

 operator MixData();
  t_Open9xGruvin9xMixData_v207() { memset(this, 0, sizeof(t_Open9xGruvin9xMixData_v207)); }
}) Open9xGruvin9xMixData_v207;

PACK(typedef struct t_Open9xGruvin9xMixData_v209 {
  uint8_t destCh:4;          // 0, 1..C9X_NUM_CHNOUT
  int8_t  phase:4;           // -5=!FP4, 0=normal, 5=FP4
  int8_t  weight;
  int8_t  swtch:6;
  uint8_t mltpx:2;           // multiplex method: 0 means +=, 1 means *=, 2 means :=
  int8_t  curve:6;
  uint8_t mixWarn:2;         // mixer warning
  uint8_t delayUp:4;
  uint8_t delayDown:4;
  uint8_t speedUp:4;         // Servogeschwindigkeit aus Tabelle (10ms Cycle)
  uint8_t speedDown:4;       // 0 nichts
  uint16_t srcRaw:6;         //
  int16_t differential:7;
  int16_t carryTrim:3;
  int8_t  sOffset;

 operator MixData();
  t_Open9xGruvin9xMixData_v209() { memset(this, 0, sizeof(t_Open9xGruvin9xMixData_v209)); }
}) Open9xGruvin9xMixData_v209;

PACK(typedef struct t_Open9xGruvin9xMixData_v211 {
  uint8_t destCh:4;          // 0, 1..C9X_NUM_CHNOUT
  uint8_t curveMode:1;       // O=curve, 1=differential
  uint8_t noExpo:1;
  uint8_t spare:2;
  int8_t  weight;
  int8_t  swtch:6;
  uint8_t mltpx:2;           // multiplex method: 0 means +=, 1 means *=, 2 means :=
  uint8_t phases:5;
  int8_t  carryTrim:3;
  uint8_t srcRaw:6;
  uint8_t mixWarn:2;         // mixer warning
  uint8_t delayUp:4;
  uint8_t delayDown:4;
  uint8_t speedUp:4;
  uint8_t speedDown:4;
  int8_t  curveParam;
  int8_t  sOffset;

 operator MixData();
  t_Open9xGruvin9xMixData_v211() { memset(this, 0, sizeof(t_Open9xGruvin9xMixData_v211)); }
}) Open9xGruvin9xMixData_v211;

PACK(typedef struct t_Open9xGruvin9xLogicalSwitchData_v207 { // Custom Switches data
  int8_t  v1; //input
  int8_t  v2; //offset
  uint8_t func;

  operator LogicalSwitchData();
  t_Open9xGruvin9xLogicalSwitchData_v207() { memset(this, 0, sizeof(t_Open9xGruvin9xLogicalSwitchData_v207)); }
  int8_t fromSource(RawSource source);
  RawSource toSource(int8_t value);
}) Open9xGruvin9xLogicalSwitchData_v207;

PACK(typedef struct t_Open9xGruvin9xLogicalSwitchData_v209 { // Custom Switches data
  int8_t  v1; //input
  int8_t  v2; //offset
  uint8_t func;

  operator LogicalSwitchData();
  t_Open9xGruvin9xLogicalSwitchData_v209() { memset(this, 0, sizeof(t_Open9xGruvin9xLogicalSwitchData_v209)); }
  int8_t fromSource(RawSource source);
  RawSource toSource(int8_t value);
}) Open9xGruvin9xLogicalSwitchData_v209;

PACK(typedef struct t_Open9xGruvin9xCustomFunctionData_v203 { // Function Switches data
  int8_t  swtch; // input
  uint8_t func;
  uint8_t param;

  operator CustomFunctionData();
  t_Open9xGruvin9xCustomFunctionData_v203() { memset(this, 0, sizeof(t_Open9xGruvin9xCustomFunctionData_v203)); }
}) Open9xGruvin9xCustomFunctionData_v203;

PACK(typedef struct t_Open9xGruvin9xCustomFunctionData_v210 { // Function Switches data
  int8_t  swtch; // input
  uint8_t func:5;
  uint8_t delay:3;
  uint8_t param;

  operator CustomFunctionData();
  t_Open9xGruvin9xCustomFunctionData_v210() { memset(this, 0, sizeof(t_Open9xGruvin9xCustomFunctionData_v210)); }
}) Open9xGruvin9xCustomFunctionData_v210;

PACK(typedef struct t_Open9xGruvin9xSwashRingData_v208 { // Swash Ring data
  uint8_t   invertELE:1;
  uint8_t   invertAIL:1;
  uint8_t   invertCOL:1;
  uint8_t   type:5;
  uint8_t   collectiveSource;
  uint8_t   value;

  operator SwashRingData();
  t_Open9xGruvin9xSwashRingData_v208() { memset(this, 0, sizeof(t_Open9xGruvin9xSwashRingData_v208)); }
}) Open9xGruvin9xSwashRingData_v208;

PACK(typedef struct t_Open9xGruvin9xSwashRingData_v209 { // Swash Ring data
  uint8_t   invertELE:1;
  uint8_t   invertAIL:1;
  uint8_t   invertCOL:1;
  uint8_t   type:5;
  uint8_t   collectiveSource;
  uint8_t   value;

  operator SwashRingData();
  t_Open9xGruvin9xSwashRingData_v209() { memset(this, 0, sizeof(t_Open9xGruvin9xSwashRingData_v209)); }
}) Open9xGruvin9xSwashRingData_v209;

PACK(typedef struct t_Open9xGruvin9xModelData_v207 {
  char      name[10];             // 10 must be first for eeLoadModelName
  Open9xTimerData_v202 timers[2];
  uint8_t   protocol:3;
  uint8_t   thrTrim:1;            // Enable Throttle Trim
  int8_t    ppmNCH:4;
  uint8_t   trimInc:3;            // Trim Increments
  uint8_t   spare1:1;
  uint8_t   pulsePol:1;
  uint8_t   extendedLimits:1;
  uint8_t   extendedTrims:1;
  uint8_t   spare2:1;
  int8_t    ppmDelay;
  uint16_t  beepANACenter;        // 1<<0->A1.. 1<<6->A7
  Open9xGruvin9xMixData_v207 mixData[32];
  Open9xLimitData_v201 limitData[16];
  Open9xExpoData_v201  expoData[14];
  int8_t    curves5[8][5];
  int8_t    curves9[8][9];
  Open9xGruvin9xLogicalSwitchData_v207  logicalSw[12];
  Open9xCustomFunctionData_v203 customFn[16];
  Open9xGruvin9xSwashRingData_v208 swashR;
  Open9xGruvin9xFlightModeData_v207 flightModeData[5];
  Open9xFrSkyData_v205 frsky;
  int8_t    ppmFrameLength;       // 0=22.5ms  (10ms-30ms) 0.5msec increments
  uint8_t   thrTraceSrc;
  uint8_t   modelId;
  uint8_t   frskyLines[4];
  uint16_t  frskyLinesXtra;

  operator ModelData();
  t_Open9xGruvin9xModelData_v207() { memset(this, 0, sizeof(t_Open9xGruvin9xModelData_v207)); }
}) Open9xGruvin9xModelData_v207;

PACK(typedef struct t_Open9xGruvin9xModelData_v208 {
  char      name[10];             // 10 must be first for eeLoadModelName
  Open9xTimerData_v202 timers[2];
  uint8_t   protocol:3;
  uint8_t   thrTrim:1;            // Enable Throttle Trim
  int8_t    ppmNCH:4;
  uint8_t   trimInc:3;            // Trim Increments
  uint8_t   disableThrottleWarning:1;
  uint8_t   pulsePol:1;
  uint8_t   extendedLimits:1;
  uint8_t   extendedTrims:1;
  uint8_t   spare2:1;
  int8_t    ppmDelay;
  uint16_t  beepANACenter;        // 1<<0->A1.. 1<<6->A7
  Open9xGruvin9xMixData_v207 mixData[32];
  Open9xLimitData_v201 limitData[16];
  Open9xExpoData_v201  expoData[14];
  int8_t    curves5[8][5];
  int8_t    curves9[8][9];
  Open9xGruvin9xLogicalSwitchData_v207  logicalSw[12];
  Open9xGruvin9xCustomFunctionData_v203 customFn[16];
  Open9xGruvin9xSwashRingData_v208 swashR;
  Open9xGruvin9xFlightModeData_v208 flightModeData[5];
  Open9xFrSkyData_v208 frsky;
  int8_t    ppmFrameLength;       // 0=22.5ms  (10ms-30ms) 0.5msec increments
  uint8_t   thrTraceSrc;
  uint8_t   modelId;
  uint8_t   frskyLines[4];
  uint16_t  frskyLinesXtra;
  int8_t    servoCenter[16];

  uint8_t varioSource:3;
  uint8_t varioSpeedUpMin:5;    // if increment in 0.2m/s = 3.0m/s max
  uint8_t varioSpeedDownMin;

  operator ModelData();
  t_Open9xGruvin9xModelData_v208() { memset(this, 0, sizeof(t_Open9xGruvin9xModelData_v208)); }
}) Open9xGruvin9xModelData_v208;

PACK(typedef struct t_Open9xGruvin9xModelData_v209 {
  char      name[10];             // 10 must be first for eeLoadModelName
  Open9xTimerData_v202 timers[2];
  uint8_t   protocol:3;
  uint8_t   thrTrim:1;            // Enable Throttle Trim
  int8_t    ppmNCH:4;
  uint8_t   trimInc:3;            // Trim Increments
  uint8_t   disableThrottleWarning:1;
  uint8_t   pulsePol:1;
  uint8_t   extendedLimits:1;
  uint8_t   extendedTrims:1;
  uint8_t   spare2:1;
  int8_t    ppmDelay;
  uint16_t  beepANACenter;        // 1<<0->A1.. 1<<6->A7
  Open9xGruvin9xMixData_v209 mixData[32];
  Open9xLimitData_v201 limitData[16];
  Open9xExpoData_v201  expoData[14];
  int8_t    curves5[8][5];
  int8_t    curves9[8][9];
  Open9xGruvin9xLogicalSwitchData_v209  logicalSw[12];
  Open9xGruvin9xCustomFunctionData_v203 customFn[16];
  Open9xGruvin9xSwashRingData_v209 swashR;
  Open9xGruvin9xFlightModeData_v208 flightModeData[5];
  Open9xFrSkyData_v208 frsky;
  int8_t    ppmFrameLength;       // 0=22.5ms  (10ms-30ms) 0.5msec increments
  uint8_t   thrTraceSrc;
  uint8_t   modelId;
  uint8_t   frskyLines[4];
  uint16_t  frskyLinesXtra;
  int8_t    servoCenter[16];

  uint8_t varioSource:3;
  uint8_t varioSpeedUpMin:5;    // if increment in 0.2m/s = 3.0m/s max
  uint8_t varioSpeedDownMin;
  uint8_t switchWarningStates;

  operator ModelData();
  t_Open9xGruvin9xModelData_v209() { memset(this, 0, sizeof(t_Open9xGruvin9xModelData_v209)); }
}) Open9xGruvin9xModelData_v209;

PACK(typedef struct t_Open9xGruvin9xModelData_v210 {
  char      name[10];             // 10 must be first for eeLoadModelName
  Open9xTimerData_v202 timers[2];
  uint8_t   protocol:3;
  uint8_t   thrTrim:1;            // Enable Throttle Trim
  int8_t    ppmNCH:4;
  uint8_t   trimInc:3;            // Trim Increments
  uint8_t   disableThrottleWarning:1;
  uint8_t   pulsePol:1;
  uint8_t   extendedLimits:1;
  uint8_t   extendedTrims:1;
  uint8_t   spare2:1;
  int8_t    ppmDelay;
  uint16_t  beepANACenter;        // 1<<0->A1.. 1<<6->A7
  Open9xGruvin9xMixData_v209 mixData[32];
  Open9xLimitData_v201 limitData[16];
  Open9xExpoData_v201  expoData[14];
  int8_t    curves[8];
  int8_t    points[112-8];
  Open9xGruvin9xLogicalSwitchData_v209  logicalSw[12];
  Open9xGruvin9xCustomFunctionData_v210 customFn[16];
  Open9xGruvin9xSwashRingData_v209 swashR;
  Open9xGruvin9xFlightModeData_v208 flightModeData[5];

  int8_t    ppmFrameLength;       // 0=22.5ms  (10ms-30ms) 0.5msec increments
  uint8_t   thrTraceSrc;
  uint8_t   modelId;

  int8_t    servoCenter[16];

  uint8_t switchWarningStates;

  Open9xFrSkyData_v210 frsky;

  operator ModelData();
  t_Open9xGruvin9xModelData_v210() { memset(this, 0, sizeof(t_Open9xGruvin9xModelData_v210)); }
}) Open9xGruvin9xModelData_v210;

PACK(typedef struct t_Open9xGruvin9xModelData_v211 {
  char      name[10];             // 10 must be first for eeLoadModelName
  Open9xTimerData_v202 timers[2];
  uint8_t   protocol:3;
  uint8_t   thrTrim:1;            // Enable Throttle Trim
  int8_t    ppmNCH:4;
  uint8_t   trimInc:3;            // Trim Increments
  uint8_t   disableThrottleWarning:1;
  uint8_t   pulsePol:1;
  uint8_t   extendedLimits:1;
  uint8_t   extendedTrims:1;
  uint8_t   spare1:1;
  int8_t    ppmDelay;
  uint16_t  beepANACenter;        // 1<<0->A1.. 1<<6->A7
  Open9xGruvin9xMixData_v211 mixData[32];
  Open9xLimitData_v211 limitData[16];
  Open9xExpoData_v211  expoData[14];
  int8_t    curves[8];
  int8_t    points[112-8];
  Open9xGruvin9xLogicalSwitchData_v209  logicalSw[12];
  Open9xGruvin9xCustomFunctionData_v210 customFn[16];
  Open9xGruvin9xSwashRingData_v209 swashR;
  Open9xGruvin9xFlightModeData_v208 flightModeData[5];

  int8_t    ppmFrameLength;       // 0=22.5ms  (10ms-30ms) 0.5msec increments
  uint8_t   thrTraceSrc;
  uint8_t   modelId;
  uint8_t switchWarningStates;

  Open9xFrSkyData_v210 frsky;
  Open9xTimerDataExtra timersXtra[2];

  operator ModelData();
  t_Open9xGruvin9xModelData_v211() { memset(this, 0, sizeof(t_Open9xGruvin9xModelData_v211)); }
}) Open9xGruvin9xModelData_v211;

#endif
