/*
 * File: Kalman_Sim.h
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

#ifndef RTW_HEADER_Kalman_Sim_h_
#define RTW_HEADER_Kalman_Sim_h_
#ifndef Kalman_Sim_COMMON_INCLUDES_
# define Kalman_Sim_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_atan232_snf.h"
#endif                                 /* Kalman_Sim_COMMON_INCLUDES_ */

#include "Kalman_Sim_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE[6];        /* '<S1>/Unit Delay' */
  real32_T UnitDelay1_DSTATE[36];      /* '<S1>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE[6];       /* '<S1>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE[36];      /* '<S1>/Unit Delay3' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} D_Work_Kalman_Sim;

/* Parameters (auto storage) */
struct Parameters_Kalman_Sim_ {
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real32_T UnitDelay_X0[6];            /* Computed Parameter: UnitDelay_X0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  real32_T UnitDelay1_X0[36];          /* Computed Parameter: UnitDelay1_X0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real32_T UnitDelay2_X0[6];           /* Computed Parameter: UnitDelay2_X0
                                        * Referenced by: '<S1>/Unit Delay2'
                                        */
  real32_T UnitDelay3_X0[36];          /* Computed Parameter: UnitDelay3_X0
                                        * Referenced by: '<S1>/Unit Delay3'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_Kalman_Sim {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_Kalman_Sim Kalman_Sim_P;

/* Block states (auto storage) */
extern D_Work_Kalman_Sim Kalman_Sim_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern real32_T fgyro[3];              /* '<Root>/Gyro  Sensor' */
extern real32_T facc[3];               /* '<Root>/Acc  Sensor' */
extern real32_T fmag[3];               /* '<Root>/Mag  Sensor' */
extern real_T Out2;                    /* '<Root>/Pulse Generator' */
extern real32_T Out1[3];               /* '<Root>/Gain2' */

/* Model entry point functions */
extern void Kalman_Sim_initialize(void);
extern void Kalman_Sim_step(void);
extern void Kalman_Sim_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Kalman_Sim *Kalman_Sim_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : Kalman_Sim
 * '<S1>'   : Kalman_Sim/DCM Filter
 * '<S2>'   : Kalman_Sim/DCM Filter/Compute psi
 * '<S3>'   : Kalman_Sim/DCM Filter/Compute z2
 * '<S4>'   : Kalman_Sim/DCM Filter/KF1 estimates phi & theta
 * '<S5>'   : Kalman_Sim/DCM Filter/KF2 estimates psi
 * '<S6>'   : Kalman_Sim/DCM Filter/KF1 estimates phi & theta/Embedded MATLAB Function
 * '<S7>'   : Kalman_Sim/DCM Filter/KF2 estimates psi/Embedded MATLAB Function
 */
#endif                                 /* RTW_HEADER_Kalman_Sim_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
