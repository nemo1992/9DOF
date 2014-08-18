/*
 * File: Kalman_Sim_data.c
 *
 * Real-Time Workshop code generated for Simulink model Kalman_Sim.
 *
 * Model version                        : 1.84
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Fri Dec 14 00:30:17 2012
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Fri Dec 14 00:30:20 2012
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Kalman_Sim.h"
#include "Kalman_Sim_private.h"

/* Block parameters (auto storage) */
Parameters_Kalman_Sim Kalman_Sim_P = {
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  200.0,                               /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  100.0,                               /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */

  /*  Computed Parameter: UnitDelay_X0
   * Referenced by: '<S1>/Unit Delay'
   */
  { -3.000000142E-004F, -1.300000004E-003F, 1.0F, 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: UnitDelay1_X0
   * Referenced by: '<S1>/Unit Delay1'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F },
  1.0F,                                /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1.0F,                                /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S1>/Constant1'
                                        */

  /*  Computed Parameter: UnitDelay2_X0
   * Referenced by: '<S1>/Unit Delay2'
   */
  { 5.099999905E-001F, 8.600000143E-001F, 1.200000057E-003F, 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: UnitDelay3_X0
   * Referenced by: '<S1>/Unit Delay3'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F },
  5.729578247E+002F                    /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
