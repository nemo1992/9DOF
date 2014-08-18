/*
 * File: rt_atan232_snf.c
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

#include "rt_atan232_snf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <math.h>

/*
 * Calls single-precision version of ATAN2, with guard against domain error
 * and guards against non-finites
 */
real32_T rt_atan232_snf(real32_T a, real32_T b)
{
  real32_T retValue;
  if (rtIsNaNF(a) || rtIsNaNF(b)) {
    retValue = (rtNaNF);
  } else {
    if (rtIsInfF(a) && rtIsInfF(b)) {
      if (b > 0.0F) {
        b = 1.0F;
      } else {
        b = -1.0F;
      }

      if (a > 0.0F) {
        a = 1.0F;
      } else {
        a = -1.0F;
      }

      retValue = (real32_T) atan2(a,b);
    } else if (b == 0.0F) {
      if (a > 0.0F) {
        retValue = (((real32_T)RT_PI))/2.0F;
      } else if (a < 0.0F) {
        retValue = -(((real32_T)RT_PI))/2.0F;
      } else {
        retValue = 0.0F;
      }
    } else {
      retValue = (real32_T) atan2(a,b);
    }
  }

  return retValue;
}                                      /* end rt_atan232_snf */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
