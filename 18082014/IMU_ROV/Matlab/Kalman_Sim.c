/*
* File: Kalman_Sim.c
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

/* Exported block signals */
real32_T fgyro[3];                     /* '<Root>/Gyro  Sensor' */
real32_T facc[3];                      /* '<Root>/Acc  Sensor' */
real32_T fmag[3];                      /* '<Root>/Mag  Sensor' */
real_T Out2;                           /* '<Root>/Pulse Generator' */
real32_T Out1[3];                      /* '<Root>/Gain2' */
int8_T eml_p[6];
real32_T eml_b_x[36];
int8_T eml_ipiv[6];
int32_T eml_jBcol;
int32_T eml_kAcol;
int32_T eml_k;
int32_T eml_i;
int32_T eml_loop_ub;
int32_T eml_b_k;
int32_T eml_mmj;
int32_T eml_jp1j;
int32_T eml_j;
int32_T eml_jA;
real32_T eml_smax;
real32_T eml_c_x;
real32_T eml_y;
real32_T eml_scale;
boolean_T eml_firstNonZero;
real32_T eml_xk;
real32_T eml_t;
real32_T eml_y;
real32_T eml_scale;
boolean_T eml_firstNonZero;
real32_T eml_xk;
real32_T eml_t;
int8_T eml_p[6];
real32_T eml_b_x[36];
int8_T eml_ipiv[6];
int32_T eml_jBcol;
int32_T eml_kAcol;
int32_T eml_k;
int32_T eml_i;
int32_T eml_loop_ub;
int32_T eml_b_k;
int32_T eml_mmj;
int32_T eml_jp1j;
int32_T eml_j;
int32_T eml_jA;
real32_T eml_smax;
real32_T eml_c_x;
real32_T eml_y;
real32_T eml_scale;
boolean_T eml_firstNonZero;
real32_T eml_xk;
real32_T eml_t;
real32_T eml_C;
real32_T eml_C_0[9];
real32_T eml_Phik[36];
real32_T eml_x[6];
real32_T eml_P[36];
real32_T eml_Kk[36];
int8_T eml_I[36];
int8_T eml_b_I[9];
int8_T eml_c_I[9];
real_T eml_d[9];
real_T eml_b_d[9];
int32_T eml_j;
real32_T eml_cos_theta;
real32_T eml_sin_phi;
real32_T eml_cos_phi;
real32_T eml_x_0[6];
real32_T eml_P_0[36];
int8_T eml_I_0[36];
real32_T rtb_TmpSignalConversionAtSFunct[6];
real32_T rtb_x_h[6];
real32_T rtb_theta;
real32_T rtb_x_0[3];
real32_T tmp[36];
real32_T eml_Xh[2];
real32_T rtb_x_h_0[3];
real32_T tmp_0[36];
real32_T eml_Phik_0[36];
real32_T tmp_1[9];
real32_T tmp_2[9];
real32_T tmp_3[36];
real32_T rtb_TmpSignalConversionAtSFun_0[6];
int32_T tmp_4;
int32_T tmp_5;
real32_T rtb_Gain1_idx;
real32_T rtb_Gain1_idx_0;
real32_T rtb_x_h_idx;
real32_T rtb_x_h_idx_0;
static real32_T tmp_6[9] = { 9.999999776E-003F, 0.0F, 0.0F, 0.0F,
9.999999776E-003F, 0.0F, 0.0F, 0.0F, 9.999999776E-003F };

static int8_T tmp_7[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

static real32_T tmp_8[36] = { 9.999999747E-005F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
0.0F, 9.999999747E-005F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
9.999999747E-005F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 9.999999776E-003F,
0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 9.999999776E-003F, 0.0F, 0.0F, 0.0F,
0.0F, 0.0F, 0.0F, 9.999999776E-003F };

/* Block states (auto storage) */
D_Work_Kalman_Sim Kalman_Sim_DWork;

/* Real-time model */
RT_MODEL_Kalman_Sim Kalman_Sim_M_;
RT_MODEL_Kalman_Sim *Kalman_Sim_M = &Kalman_Sim_M_;

/* Forward declaration for local functions */
static void Kalman_Sim_inv(const real32_T eml_x[36], real32_T eml_y[36]);
static real32_T Kalman_Sim_norm(const real32_T eml_x[3]);
static real32_T Kalman_Sim_norm_a(const real32_T eml_x[2]);
static void Kalman_Sim_inv_i(const real32_T eml_x[36], real32_T eml_y[36]);
static real32_T Kalman_Sim_norm_i(const real32_T eml_x[3]);

/* Function for Embedded MATLAB: '<S4>/Embedded MATLAB Function' */
static void Kalman_Sim_inv(const real32_T eml_x[36], real32_T eml_y[36])
{
  
  for (eml_j = 0; eml_j < 36; eml_j++) {
    eml_y[eml_j] = 0.0F;
    eml_b_x[eml_j] = eml_x[eml_j];
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_ipiv[eml_j] = (int8_T)(1 + eml_j);
  }
  
  for (eml_j = 0; eml_j < 5; eml_j++) {
    eml_mmj = 5 - eml_j;
    eml_loop_ub = eml_j * 7 + 1;
    eml_jp1j = eml_loop_ub + 1;
    eml_b_k = eml_mmj + 1;
    eml_jBcol = 1;
    eml_k = eml_loop_ub;
    eml_smax = (real32_T)fabs(eml_b_x[eml_loop_ub - 1]);
    for (eml_kAcol = 2; eml_kAcol <= eml_b_k; eml_kAcol++) {
      eml_k++;
      eml_c_x = (real32_T)fabs(eml_b_x[eml_k - 1]);
      if (eml_c_x > eml_smax) {
        eml_jBcol = eml_kAcol;
        eml_smax = eml_c_x;
      }
    }
    
    eml_b_k = eml_jBcol - 1;
    if ((real_T)eml_b_x[(eml_loop_ub + eml_b_k) - 1] != 0.0) {
      if (eml_b_k != 0) {
        eml_ipiv[eml_j] = (int8_T)((eml_j + 1) + eml_b_k);
        eml_k = 1 + eml_j;
        eml_b_k += eml_k;
        for (eml_jBcol = 0; eml_jBcol < 6; eml_jBcol++) {
          eml_c_x = eml_b_x[eml_k - 1];
          eml_b_x[eml_k - 1] = eml_b_x[eml_b_k - 1];
          eml_b_x[eml_b_k - 1] = eml_c_x;
          eml_k += 6;
          eml_b_k += 6;
        }
      }
      
      eml_b_k = (eml_mmj - 1) + eml_jp1j;
      for (eml_jBcol = eml_jp1j; eml_jBcol <= eml_b_k; eml_jBcol++) {
        eml_b_x[eml_jBcol - 1] /= eml_b_x[eml_loop_ub - 1];
      }
    }
    
    eml_i = 5 - eml_j;
    eml_jA = eml_loop_ub + 6;
    eml_b_k = eml_loop_ub + 6;
    for (eml_jBcol = 1; eml_jBcol <= eml_i; eml_jBcol++) {
      eml_c_x = eml_b_x[eml_b_k - 1];
      if ((real_T)eml_c_x != 0.0) {
        eml_c_x = -eml_c_x;
        eml_k = eml_jp1j;
        eml_kAcol = eml_mmj + eml_jA;
        for (eml_loop_ub = 1 + eml_jA; eml_loop_ub <= eml_kAcol; eml_loop_ub++)
        {
          eml_b_x[eml_loop_ub - 1] += eml_b_x[eml_k - 1] * eml_c_x;
          eml_k++;
        }
      }
      
      eml_b_k += 6;
      eml_jA += 6;
    }
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_p[eml_j] = (int8_T)(1 + eml_j);
  }
  
  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = (int32_T)eml_ipiv[eml_b_k];
    if (eml_jBcol > eml_b_k + 1) {
      eml_k = (int32_T)eml_p[eml_jBcol - 1];
      eml_p[eml_jBcol - 1] = eml_p[eml_b_k];
      eml_p[eml_b_k] = (int8_T)eml_k;
    }
  }
  
  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = (int32_T)eml_p[eml_b_k];
    eml_y[eml_b_k + 6 * (eml_jBcol - 1)] = 1.0F;
    for (eml_k = eml_b_k + 1; eml_k < 7; eml_k++) {
      if ((real_T)eml_y[(eml_jBcol - 1) * 6 + (eml_k - 1)] != 0.0) {
        for (eml_kAcol = eml_k + 1; eml_kAcol < 7; eml_kAcol++) {
          eml_y[(eml_kAcol - 1) + 6 * (eml_jBcol - 1)] = eml_y[(eml_jBcol - 1) *
            6 + (eml_kAcol - 1)] - eml_y[(eml_jBcol - 1) * 6 + (eml_k - 1)] *
              eml_b_x[(eml_k - 1) * 6 + (eml_kAcol - 1)];
        }
      }
    }
  }
  
  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = eml_b_k * 6;
    for (eml_k = 6; eml_k > 0; eml_k += -1) {
      eml_kAcol = (eml_k - 1) * 6;
      if ((real_T)eml_y[(eml_k + eml_jBcol) - 1] != 0.0) {
        eml_y[(eml_k + eml_jBcol) - 1] /= eml_b_x[(eml_k + eml_kAcol) - 1];
        eml_loop_ub = eml_k - 1;
        for (eml_i = 1; eml_i <= eml_loop_ub; eml_i++) {
          eml_y[(eml_i + eml_jBcol) - 1] -= eml_y[(eml_k + eml_jBcol) - 1] *
            eml_b_x[(eml_i + eml_kAcol) - 1];
        }
      }
    }
  }
}

/* Function for Embedded MATLAB: '<S4>/Embedded MATLAB Function' */
static real32_T Kalman_Sim_norm(const real32_T eml_x[3])
{
  
  eml_y = 0.0F;
  eml_scale = 0.0F;
  eml_firstNonZero = true;
  if (eml_x[0] != 0.0F) {
    eml_scale = (real32_T)fabs(eml_x[0]);
    eml_y = 1.0F;
    eml_firstNonZero = false;
  }
  
  if (eml_x[1] != 0.0F) {
    eml_xk = (real32_T)fabs(eml_x[1]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0F;
      eml_firstNonZero = false;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0F;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }
  
  if (eml_x[2] != 0.0F) {
    eml_xk = (real32_T)fabs(eml_x[2]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0F;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0F;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }
  
  return eml_scale * (real32_T)sqrt(eml_y);
}

/* Function for Embedded MATLAB: '<S1>/Compute z2' */
static real32_T Kalman_Sim_norm_a(const real32_T eml_x[2])
{
  
  eml_y = 0.0F;
  eml_scale = 0.0F;
  eml_firstNonZero = true;
  if (eml_x[0] != 0.0F) {
    eml_scale = (real32_T)fabs(eml_x[0]);
    eml_y = 1.0F;
    eml_firstNonZero = false;
  }
  
  if (eml_x[1] != 0.0F) {
    eml_xk = (real32_T)fabs(eml_x[1]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0F;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0F;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }
  
  return eml_scale * (real32_T)sqrt(eml_y);
}

/* Function for Embedded MATLAB: '<S5>/Embedded MATLAB Function' */
static void Kalman_Sim_inv_i(const real32_T eml_x[36], real32_T eml_y[36])
{
  
  for (eml_j = 0; eml_j < 36; eml_j++) {
    eml_y[eml_j] = 0.0F;
    eml_b_x[eml_j] = eml_x[eml_j];
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_ipiv[eml_j] = (int8_T)(1 + eml_j);
  }
  
  for (eml_j = 0; eml_j < 5; eml_j++) {
    eml_mmj = 5 - eml_j;
    eml_loop_ub = eml_j * 7 + 1;
    eml_jp1j = eml_loop_ub + 1;
    eml_b_k = eml_mmj + 1;
    eml_jBcol = 1;
    eml_k = eml_loop_ub;
    eml_smax = (real32_T)fabs(eml_b_x[eml_loop_ub - 1]);
    for (eml_kAcol = 2; eml_kAcol <= eml_b_k; eml_kAcol++) {
      eml_k++;
      eml_c_x = (real32_T)fabs(eml_b_x[eml_k - 1]);
      if (eml_c_x > eml_smax) {
        eml_jBcol = eml_kAcol;
        eml_smax = eml_c_x;
      }
    }
    
    eml_b_k = eml_jBcol - 1;
    if ((real_T)eml_b_x[(eml_loop_ub + eml_b_k) - 1] != 0.0) {
      if (eml_b_k != 0) {
        eml_ipiv[eml_j] = (int8_T)((eml_j + 1) + eml_b_k);
        eml_k = 1 + eml_j;
        eml_b_k += eml_k;
        for (eml_jBcol = 0; eml_jBcol < 6; eml_jBcol++) {
          eml_c_x = eml_b_x[eml_k - 1];
          eml_b_x[eml_k - 1] = eml_b_x[eml_b_k - 1];
          eml_b_x[eml_b_k - 1] = eml_c_x;
          eml_k += 6;
          eml_b_k += 6;
        }
      }
      
      eml_b_k = (eml_mmj - 1) + eml_jp1j;
      for (eml_jBcol = eml_jp1j; eml_jBcol <= eml_b_k; eml_jBcol++) {
        eml_b_x[eml_jBcol - 1] /= eml_b_x[eml_loop_ub - 1];
      }
    }
    
    eml_i = 5 - eml_j;
    eml_jA = eml_loop_ub + 6;
    eml_b_k = eml_loop_ub + 6;
    for (eml_jBcol = 1; eml_jBcol <= eml_i; eml_jBcol++) {
      eml_c_x = eml_b_x[eml_b_k - 1];
      if ((real_T)eml_c_x != 0.0) {
        eml_c_x = -eml_c_x;
        eml_k = eml_jp1j;
        eml_kAcol = eml_mmj + eml_jA;
        for (eml_loop_ub = 1 + eml_jA; eml_loop_ub <= eml_kAcol; eml_loop_ub++)
        {
          eml_b_x[eml_loop_ub - 1] += eml_b_x[eml_k - 1] * eml_c_x;
          eml_k++;
        }
      }
      
      eml_b_k += 6;
      eml_jA += 6;
    }
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_p[eml_j] = (int8_T)(1 + eml_j);
  }
  
  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = (int32_T)eml_ipiv[eml_b_k];
    if (eml_jBcol > eml_b_k + 1) {
      eml_k = (int32_T)eml_p[eml_jBcol - 1];
      eml_p[eml_jBcol - 1] = eml_p[eml_b_k];
      eml_p[eml_b_k] = (int8_T)eml_k;
    }
  }
  
  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = (int32_T)eml_p[eml_b_k];
    eml_y[eml_b_k + 6 * (eml_jBcol - 1)] = 1.0F;
    for (eml_k = eml_b_k + 1; eml_k < 7; eml_k++) {
      if ((real_T)eml_y[(eml_jBcol - 1) * 6 + (eml_k - 1)] != 0.0) {
        for (eml_kAcol = eml_k + 1; eml_kAcol < 7; eml_kAcol++) {
          eml_y[(eml_kAcol - 1) + 6 * (eml_jBcol - 1)] = eml_y[(eml_jBcol - 1) *
            6 + (eml_kAcol - 1)] - eml_y[(eml_jBcol - 1) * 6 + (eml_k - 1)] *
              eml_b_x[(eml_k - 1) * 6 + (eml_kAcol - 1)];
        }
      }
    }
  }
  
  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = eml_b_k * 6;
    for (eml_k = 6; eml_k > 0; eml_k += -1) {
      eml_kAcol = (eml_k - 1) * 6;
      if ((real_T)eml_y[(eml_k + eml_jBcol) - 1] != 0.0) {
        eml_y[(eml_k + eml_jBcol) - 1] /= eml_b_x[(eml_k + eml_kAcol) - 1];
        eml_loop_ub = eml_k - 1;
        for (eml_i = 1; eml_i <= eml_loop_ub; eml_i++) {
          eml_y[(eml_i + eml_jBcol) - 1] -= eml_y[(eml_k + eml_jBcol) - 1] *
            eml_b_x[(eml_i + eml_kAcol) - 1];
        }
      }
    }
  }
}

/* Function for Embedded MATLAB: '<S5>/Embedded MATLAB Function' */
static real32_T Kalman_Sim_norm_i(const real32_T eml_x[3])
{
  
  eml_y = 0.0F;
  eml_scale = 0.0F;
  eml_firstNonZero = true;
  if (eml_x[0] != 0.0F) {
    eml_scale = (real32_T)fabs(eml_x[0]);
    eml_y = 1.0F;
    eml_firstNonZero = false;
  }
  
  if (eml_x[1] != 0.0F) {
    eml_xk = (real32_T)fabs(eml_x[1]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0F;
      eml_firstNonZero = false;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0F;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }
  
  if (eml_x[2] != 0.0F) {
    eml_xk = (real32_T)fabs(eml_x[2]);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0F;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0F;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }
  
  return eml_scale * (real32_T)sqrt(eml_y);
}

/* Model step function */
void Kalman_Sim_step(void)
{
  
  
  /* Gain: '<Root>/Gain1' incorporates:
  *  Inport: '<Root>/Mag  Sensor'
  */
  rtb_Gain1_idx = Kalman_Sim_P.Gain1_Gain * fmag[1];
  rtb_Gain1_idx_0 = Kalman_Sim_P.Gain1_Gain * fmag[2];
  
  /* SignalConversion: '<S6>/TmpSignal ConversionAt SFunction Inport3' incorporates:
  *  Inport: '<Root>/Acc  Sensor'
  *  Inport: '<Root>/Gyro  Sensor'
  */
  rtb_TmpSignalConversionAtSFunct[0] = Kalman_Sim_P.Gain1_Gain * facc[0];
  rtb_TmpSignalConversionAtSFunct[1] = Kalman_Sim_P.Gain1_Gain * facc[1];
  rtb_TmpSignalConversionAtSFunct[2] = Kalman_Sim_P.Gain1_Gain * facc[2];
  rtb_TmpSignalConversionAtSFunct[3] = Kalman_Sim_P.Gain1_Gain * fgyro[0];
  rtb_TmpSignalConversionAtSFunct[4] = Kalman_Sim_P.Gain1_Gain * fgyro[1];
  rtb_TmpSignalConversionAtSFunct[5] = Kalman_Sim_P.Gain1_Gain * fgyro[2];
  
  /* Embedded MATLAB: '<S4>/Embedded MATLAB Function' incorporates:
  *  UnitDelay: '<S1>/Unit Delay'
  *  UnitDelay: '<S1>/Unit Delay1'
  */
  /* Embedded MATLAB Function 'DCM Filter/KF1 estimates phi & theta/Embedded MATLAB Function': '<S6>:1' */
  /*  x_1: (6x1) previous estimate value [C31;C32;C33;gx;gy;gz] */
  /*  P_1: (6x6) previous error covariance */
  /*  z  : (6x1) observer value [ax;ay;az;gx;gy;gz] */
  /*  x  : (6x1) estimation value at this time  */
  /*  P  : (6x6) error covariance */
  /* % Init Kalman */
  /*  q = 1; */
  /*  a = 100; %0.4 */
  /*  ra0 = r; */
  /*  rg0 = 1/a; */
  /*  R = [ra0/a*eye(3,3), zeros(3,3); */
  /*        zeros(3,3),a*rg0*eye(3,3)]; */
  /* 5e-4; % q decrease -> overshoot, */
  /* [0.002; 8.26e-4; 0.0104]/100; */
  /* [4.86e-5; 3.98e-5; 1.54e-5]*10; */
  /*  ra0 = [1e-4; 1e-4 ; 1e-4]; */
  /*  rw0 = [1;1;1]; */
  /*  z(1:3) = z(1:3)/norm(z(1:3)); */
  /* '<S6>:1:28' */
  if ((real_T)rtb_TmpSignalConversionAtSFunct[0] > 2.0) {
    /* '<S6>:1:29' */
    /* '<S6>:1:30' */
    rtb_TmpSignalConversionAtSFunct[0] = 2.0F;
  }
  
  if ((real_T)rtb_TmpSignalConversionAtSFunct[1] > 2.0) {
    /* '<S6>:1:32' */
    /* '<S6>:1:33' */
    rtb_TmpSignalConversionAtSFunct[1] = 2.0F;
  }
  
  if ((real_T)rtb_TmpSignalConversionAtSFunct[2] > 2.0) {
    /* '<S6>:1:35' */
    /* '<S6>:1:36' */
    rtb_TmpSignalConversionAtSFunct[2] = 2.0F;
  }
  
  /* q = 1e-2; */
  /*  ra0 = [1e-4; 1e-4 ; 1e-4]; */
  /*  rw0 = [1e-2; 1e-2; 1e-2]; */
  /* '<S6>:1:44' */
  for (eml_j = 0; eml_j < 9; eml_j++) {
    eml_d[eml_j] = 0.0;
    eml_b_d[eml_j] = 0.0;
    eml_b_I[eml_j] = 0;
    eml_c_I[eml_j] = 0;
  }
  
  eml_d[0] = 4.8600000000000006E-003;
  eml_d[4] = 0.00398;
  eml_d[8] = 1.5400000000000001E-003;
  eml_b_d[0] = 0.00002;
  eml_b_d[4] = 8.26E-006;
  eml_b_d[8] = 0.000104;
  
  /*  Note: a is divided by 'g' --> H = I; */
  /* % Discrete model */
  /* '<S6>:1:49' */
  /* '<S6>:1:50' */
  /* '<S6>:1:51' */
  /* '<S6>:1:52' */
  eml_C_0[0] = 0.0F;
  eml_C_0[3] = -Kalman_Sim_DWork.UnitDelay_DSTATE[2];
  eml_C_0[6] = Kalman_Sim_DWork.UnitDelay_DSTATE[1];
  eml_C_0[1] = Kalman_Sim_DWork.UnitDelay_DSTATE[2];
  eml_C_0[4] = 0.0F;
  eml_C_0[7] = -Kalman_Sim_DWork.UnitDelay_DSTATE[0];
  eml_C_0[2] = -Kalman_Sim_DWork.UnitDelay_DSTATE[1];
  eml_C_0[5] = Kalman_Sim_DWork.UnitDelay_DSTATE[0];
  eml_C_0[8] = 0.0F;
  
  /* '<S6>:1:53' */
  eml_b_I[0] = 1;
  eml_b_I[4] = 1;
  eml_b_I[8] = 1;
  eml_c_I[0] = 1;
  eml_c_I[4] = 1;
  eml_c_I[8] = 1;
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik[6 * eml_j] = (real32_T)eml_c_I[3 * eml_j];
    eml_Phik[1 + 6 * eml_j] = (real32_T)eml_c_I[3 * eml_j + 1];
    eml_Phik[2 + 6 * eml_j] = (real32_T)eml_c_I[3 * eml_j + 2];
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik[6 * (eml_j + 3)] = eml_C_0[3 * eml_j] * 9.999999776E-003F;
    eml_Phik[1 + 6 * (eml_j + 3)] = eml_C_0[3 * eml_j + 1] * 9.999999776E-003F;
    eml_Phik[2 + 6 * (eml_j + 3)] = eml_C_0[3 * eml_j + 2] * 9.999999776E-003F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik[3 + 6 * eml_j] = 0.0F;
    eml_Phik[4 + 6 * eml_j] = 0.0F;
    eml_Phik[5 + 6 * eml_j] = 0.0F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik[3 + 6 * (eml_j + 3)] = (real32_T)eml_b_I[3 * eml_j];
    eml_Phik[4 + 6 * (eml_j + 3)] = (real32_T)eml_b_I[3 * eml_j + 1];
    eml_Phik[5 + 6 * (eml_j + 3)] = (real32_T)eml_b_I[3 * eml_j + 2];
  }
  
  /*  Phik = I + Phi(kT) * T */
  /* '<S6>:1:54' */
  /* % Time update */
  /*  State */
  /* '<S6>:1:58' */
  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_x[eml_j] = 0.0F;
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_x[eml_j] += eml_Phik[6 * tmp_4 + eml_j] *
        Kalman_Sim_DWork.UnitDelay_DSTATE[tmp_4];
    }
  }
  
  /*  Error covariance */
  /* '<S6>:1:60' */
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_Phik_0[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        eml_Phik_0[eml_j + 6 * tmp_4] = eml_Phik[6 * tmp_5 + eml_j] *
          Kalman_Sim_DWork.UnitDelay1_DSTATE[6 * tmp_4 + tmp_5] + eml_Phik_0[6 *
            tmp_4 + eml_j];
      }
    }
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_1[3 * eml_j] = eml_C_0[3 * eml_j] * 9.999999975E-007F;
    tmp_1[1 + 3 * eml_j] = eml_C_0[3 * eml_j + 1] * 9.999999975E-007F;
    tmp_1[2 + 3 * eml_j] = eml_C_0[3 * eml_j + 2] * 9.999999975E-007F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 3; tmp_4++) {
      tmp_2[eml_j + 3 * tmp_4] = 0.0F;
      tmp_2[eml_j + 3 * tmp_4] = tmp_2[3 * tmp_4 + eml_j] + tmp_1[eml_j] *
        eml_C_0[tmp_4];
      tmp_2[eml_j + 3 * tmp_4] = tmp_2[3 * tmp_4 + eml_j] + tmp_1[eml_j + 3] *
        eml_C_0[tmp_4 + 3];
      tmp_2[eml_j + 3 * tmp_4] = tmp_2[3 * tmp_4 + eml_j] + tmp_1[eml_j + 6] *
        eml_C_0[tmp_4 + 6];
    }
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_3[6 * eml_j] = tmp_2[3 * eml_j];
    tmp_3[1 + 6 * eml_j] = tmp_2[3 * eml_j + 1];
    tmp_3[2 + 6 * eml_j] = tmp_2[3 * eml_j + 2];
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_3[6 * (eml_j + 3)] = eml_C_0[3 * eml_j] * 9.999999747E-005F;
    tmp_3[1 + 6 * (eml_j + 3)] = eml_C_0[3 * eml_j + 1] * 9.999999747E-005F;
    tmp_3[2 + 6 * (eml_j + 3)] = eml_C_0[3 * eml_j + 2] * 9.999999747E-005F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_3[3 + 6 * eml_j] = 9.999999747E-005F * eml_C_0[eml_j];
    tmp_3[4 + 6 * eml_j] = eml_C_0[eml_j + 3] * 9.999999747E-005F;
    tmp_3[5 + 6 * eml_j] = eml_C_0[eml_j + 6] * 9.999999747E-005F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_3[3 + 6 * (eml_j + 3)] = tmp_6[3 * eml_j];
    tmp_3[4 + 6 * (eml_j + 3)] = tmp_6[3 * eml_j + 1];
    tmp_3[5 + 6 * (eml_j + 3)] = tmp_6[3 * eml_j + 2];
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      rtb_x_h_idx = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        rtb_x_h_idx += eml_Phik_0[6 * tmp_5 + eml_j] * eml_Phik[6 * tmp_5 +
          tmp_4];
      }
      
      eml_P[eml_j + 6 * tmp_4] = tmp_3[6 * tmp_4 + eml_j] * 8.999999613E-003F +
        rtb_x_h_idx;
    }
  }
  
  /* % Measurement update */
  /*  Compute Kalman gain */
  /* '<S6>:1:64' */
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_Phik_0[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        eml_Phik_0[eml_j + 6 * tmp_4] = (real32_T)tmp_7[6 * tmp_5 + eml_j] *
          eml_P[6 * tmp_4 + tmp_5] + eml_Phik_0[6 * tmp_4 + eml_j];
      }
    }
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      tmp_3[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        tmp_3[eml_j + 6 * tmp_4] = eml_Phik_0[6 * tmp_5 + eml_j] * (real32_T)
          tmp_7[6 * tmp_4 + tmp_5] + tmp_3[6 * tmp_4 + eml_j];
      }
    }
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik_0[6 * eml_j] = (real32_T)eml_b_d[3 * eml_j];
    eml_Phik_0[1 + 6 * eml_j] = (real32_T)eml_b_d[3 * eml_j + 1];
    eml_Phik_0[2 + 6 * eml_j] = (real32_T)eml_b_d[3 * eml_j + 2];
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik_0[6 * (eml_j + 3)] = 0.0F;
    eml_Phik_0[1 + 6 * (eml_j + 3)] = 0.0F;
    eml_Phik_0[2 + 6 * (eml_j + 3)] = 0.0F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik_0[3 + 6 * eml_j] = 0.0F;
    eml_Phik_0[4 + 6 * eml_j] = 0.0F;
    eml_Phik_0[5 + 6 * eml_j] = 0.0F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik_0[3 + 6 * (eml_j + 3)] = (real32_T)eml_d[3 * eml_j];
    eml_Phik_0[4 + 6 * (eml_j + 3)] = (real32_T)eml_d[3 * eml_j + 1];
    eml_Phik_0[5 + 6 * (eml_j + 3)] = (real32_T)eml_d[3 * eml_j + 2];
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      tmp_0[tmp_4 + 6 * eml_j] = tmp_3[6 * eml_j + tmp_4] + eml_Phik_0[6 * eml_j
        + tmp_4];
    }
  }
  
  Kalman_Sim_inv(tmp_0, tmp_3);
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_Phik_0[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        eml_Phik_0[eml_j + 6 * tmp_4] = eml_P[6 * tmp_5 + eml_j] * (real32_T)
          tmp_7[6 * tmp_4 + tmp_5] + eml_Phik_0[6 * tmp_4 + eml_j];
      }
    }
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_Kk[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        eml_Kk[eml_j + 6 * tmp_4] = eml_Phik_0[6 * tmp_5 + eml_j] * tmp_3[6 *
          tmp_4 + tmp_5] + eml_Kk[6 * tmp_4 + eml_j];
      }
    }
  }
  
  /*  Update estimate with measurement z */
  /* '<S6>:1:66' */
  for (eml_j = 0; eml_j < 6; eml_j++) {
    rtb_x_h_idx = 0.0F;
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      rtb_x_h_idx += (real32_T)tmp_7[6 * tmp_4 + eml_j] * eml_x[tmp_4];
    }
    
    rtb_TmpSignalConversionAtSFun_0[eml_j] =
      rtb_TmpSignalConversionAtSFunct[eml_j] - rtb_x_h_idx;
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    rtb_x_h_idx = 0.0F;
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      rtb_x_h_idx += eml_Kk[6 * tmp_4 + eml_j] *
        rtb_TmpSignalConversionAtSFun_0[tmp_4];
    }
    
    rtb_x_h[eml_j] = eml_x[eml_j] + rtb_x_h_idx;
  }
  
  /*  Normalization DCM(1:3) */
  /* '<S6>:1:68' */
  rtb_x_h_0[0] = rtb_x_h[0];
  rtb_x_h_0[1] = rtb_x_h[1];
  rtb_x_h_0[2] = rtb_x_h[2];
  eml_C = Kalman_Sim_norm(rtb_x_h_0);
  rtb_x_h_idx = rtb_x_h[1] / eml_C;
  rtb_x_h_idx_0 = rtb_x_h[2] / eml_C;
  rtb_x_h[0] /= eml_C;
  rtb_x_h[1] = rtb_x_h_idx;
  rtb_x_h[2] = rtb_x_h_idx_0;
  
  /*  Update the error covariance */
  /* '<S6>:1:70' */
  for (eml_j = 0; eml_j < 36; eml_j++) {
    eml_I[eml_j] = 0;
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_I[eml_j + 6 * eml_j] = 1;
  }
  
  /* Embedded MATLAB: '<S1>/Compute z2' incorporates:
  *  Inport: '<Root>/Mag  Sensor'
  */
  /* Embedded MATLAB Function 'DCM Filter/Compute z2': '<S3>:1' */
  /*  x_kf1 = [C31;C32;C33;gx;gy;gz]; */
  /*  m = [mx;my;mz]; */
  /*  Get measurement data: Magnetometer, phi & theta from above result */
  /* '<S3>:1:6' */
  eml_C = -rtb_x_h[0];
  
  /* '<S3>:1:7' */
  rtb_theta = (real32_T)asin(eml_C);
  
  /* '<S3>:1:8' */
  eml_cos_theta = (real32_T)cos(rtb_theta);
  
  /* '<S3>:1:10' */
  /* '<S3>:1:11' */
  eml_sin_phi = rtb_x_h[1] / eml_cos_theta;
  
  /*  reduce computation */
  /* '<S3>:1:12' */
  eml_cos_phi = rtb_x_h[2] / eml_cos_theta;
  
  /* '<S3>:1:14' */
  /* '<S3>:1:15' */
  rtb_x_h_idx = (Kalman_Sim_P.Gain1_Gain * fmag[0] * eml_cos_theta +
                 rtb_Gain1_idx * eml_C * eml_sin_phi) + rtb_Gain1_idx_0 * eml_C *
    eml_cos_phi;
  
  /* '<S3>:1:16' */
  rtb_x_h_idx_0 = rtb_Gain1_idx * eml_cos_phi - rtb_Gain1_idx_0 * eml_sin_phi;
  
  /* '<S3>:1:17' */
  eml_Xh[0] = rtb_x_h_idx;
  eml_Xh[1] = rtb_x_h_idx_0;
  rtb_Gain1_idx = (-rtb_x_h_idx_0) / Kalman_Sim_norm_a(eml_Xh);
  
  /* '<S3>:1:18' */
  eml_Xh[0] = rtb_x_h_idx;
  eml_Xh[1] = rtb_x_h_idx_0;
  rtb_x_h_idx_0 = rtb_x_h_idx / Kalman_Sim_norm_a(eml_Xh);
  
  /* '<S3>:1:20' */
  
  /* Embedded MATLAB: '<S5>/Embedded MATLAB Function' incorporates:
  *  UnitDelay: '<S1>/Unit Delay2'
  *  UnitDelay: '<S1>/Unit Delay3'
  */
  /* Embedded MATLAB Function 'DCM Filter/KF2 estimates psi/Embedded MATLAB Function': '<S7>:1' */
  /*  x_1: (6x1) previous estimate value [C21;C22;C23;gx;gy;gz] */
  /*  P_1: (6x6) previous error covariance */
  /*  z  : (6x1) observer value [mx;my;mz;gx;gy;gz] */
  /*  x  : (6x1) estimation value at this time */
  /*  P  : (6x6) error covariance */
  /* % Init Kalman */
  /*  q = 1; */
  /*  rm0 = 0.01; */
  /*  rg0 = 1; */
  /* '<S7>:1:18' */
  /* % Discrete model */
  /* '<S7>:1:23' */
  /* '<S7>:1:24' */
  /* '<S7>:1:25' */
  /* '<S7>:1:26' */
  eml_C_0[0] = 0.0F;
  eml_C_0[3] = -Kalman_Sim_DWork.UnitDelay2_DSTATE[2];
  eml_C_0[6] = Kalman_Sim_DWork.UnitDelay2_DSTATE[1];
  eml_C_0[1] = Kalman_Sim_DWork.UnitDelay2_DSTATE[2];
  eml_C_0[4] = 0.0F;
  eml_C_0[7] = -Kalman_Sim_DWork.UnitDelay2_DSTATE[0];
  eml_C_0[2] = -Kalman_Sim_DWork.UnitDelay2_DSTATE[1];
  eml_C_0[5] = Kalman_Sim_DWork.UnitDelay2_DSTATE[0];
  eml_C_0[8] = 0.0F;
  
  /* '<S7>:1:27' */
  for (eml_j = 0; eml_j < 9; eml_j++) {
    eml_b_I[eml_j] = 0;
    eml_c_I[eml_j] = 0;
  }
  
  eml_b_I[0] = 1;
  eml_b_I[4] = 1;
  eml_b_I[8] = 1;
  eml_c_I[0] = 1;
  eml_c_I[4] = 1;
  eml_c_I[8] = 1;
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik[6 * eml_j] = (real32_T)eml_c_I[3 * eml_j];
    eml_Phik[1 + 6 * eml_j] = (real32_T)eml_c_I[3 * eml_j + 1];
    eml_Phik[2 + 6 * eml_j] = (real32_T)eml_c_I[3 * eml_j + 2];
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik[6 * (eml_j + 3)] = eml_C_0[3 * eml_j] * 9.999999776E-003F;
    eml_Phik[1 + 6 * (eml_j + 3)] = eml_C_0[3 * eml_j + 1] * 9.999999776E-003F;
    eml_Phik[2 + 6 * (eml_j + 3)] = eml_C_0[3 * eml_j + 2] * 9.999999776E-003F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik[3 + 6 * eml_j] = 0.0F;
    eml_Phik[4 + 6 * eml_j] = 0.0F;
    eml_Phik[5 + 6 * eml_j] = 0.0F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    eml_Phik[3 + 6 * (eml_j + 3)] = (real32_T)eml_b_I[3 * eml_j];
    eml_Phik[4 + 6 * (eml_j + 3)] = (real32_T)eml_b_I[3 * eml_j + 1];
    eml_Phik[5 + 6 * (eml_j + 3)] = (real32_T)eml_b_I[3 * eml_j + 2];
  }
  
  /*  Phik = I + Phi(kT) * T */
  /* '<S7>:1:28' */
  /* % Time update */
  /*  State */
  /* '<S7>:1:32' */
  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_x_0[eml_j] = 0.0F;
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_x_0[eml_j] += eml_Phik[6 * tmp_4 + eml_j] *
        Kalman_Sim_DWork.UnitDelay2_DSTATE[tmp_4];
    }
  }
  
  /*  Error covariance */
  /* '<S7>:1:34' */
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_Phik_0[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        eml_Phik_0[eml_j + 6 * tmp_4] = eml_Phik[6 * tmp_5 + eml_j] *
          Kalman_Sim_DWork.UnitDelay3_DSTATE[6 * tmp_4 + tmp_5] + eml_Phik_0[6 *
            tmp_4 + eml_j];
      }
    }
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_1[3 * eml_j] = eml_C_0[3 * eml_j] * 9.999999975E-007F;
    tmp_1[1 + 3 * eml_j] = eml_C_0[3 * eml_j + 1] * 9.999999975E-007F;
    tmp_1[2 + 3 * eml_j] = eml_C_0[3 * eml_j + 2] * 9.999999975E-007F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 3; tmp_4++) {
      tmp_2[eml_j + 3 * tmp_4] = 0.0F;
      tmp_2[eml_j + 3 * tmp_4] = tmp_2[3 * tmp_4 + eml_j] + tmp_1[eml_j] *
        eml_C_0[tmp_4];
      tmp_2[eml_j + 3 * tmp_4] = tmp_2[3 * tmp_4 + eml_j] + tmp_1[eml_j + 3] *
        eml_C_0[tmp_4 + 3];
      tmp_2[eml_j + 3 * tmp_4] = tmp_2[3 * tmp_4 + eml_j] + tmp_1[eml_j + 6] *
        eml_C_0[tmp_4 + 6];
    }
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_3[6 * eml_j] = tmp_2[3 * eml_j];
    tmp_3[1 + 6 * eml_j] = tmp_2[3 * eml_j + 1];
    tmp_3[2 + 6 * eml_j] = tmp_2[3 * eml_j + 2];
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_3[6 * (eml_j + 3)] = eml_C_0[3 * eml_j] * 9.999999747E-005F;
    tmp_3[1 + 6 * (eml_j + 3)] = eml_C_0[3 * eml_j + 1] * 9.999999747E-005F;
    tmp_3[2 + 6 * (eml_j + 3)] = eml_C_0[3 * eml_j + 2] * 9.999999747E-005F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_3[3 + 6 * eml_j] = 9.999999747E-005F * eml_C_0[eml_j];
    tmp_3[4 + 6 * eml_j] = eml_C_0[eml_j + 3] * 9.999999747E-005F;
    tmp_3[5 + 6 * eml_j] = eml_C_0[eml_j + 6] * 9.999999747E-005F;
  }
  
  for (eml_j = 0; eml_j < 3; eml_j++) {
    tmp_3[3 + 6 * (eml_j + 3)] = tmp_6[3 * eml_j];
    tmp_3[4 + 6 * (eml_j + 3)] = tmp_6[3 * eml_j + 1];
    tmp_3[5 + 6 * (eml_j + 3)] = tmp_6[3 * eml_j + 2];
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      rtb_x_h_idx = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        rtb_x_h_idx += eml_Phik_0[6 * tmp_5 + eml_j] * eml_Phik[6 * tmp_5 +
          tmp_4];
      }
      
      eml_P_0[eml_j + 6 * tmp_4] = tmp_3[6 * tmp_4 + eml_j] * 8.999999613E-003F
        + rtb_x_h_idx;
    }
  }
  
  /* % Measurement update */
  /*  Compute Kalman gain */
  /* '<S7>:1:38' */
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_Phik_0[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        eml_Phik_0[eml_j + 6 * tmp_4] = (real32_T)tmp_7[6 * tmp_5 + eml_j] *
          eml_P_0[6 * tmp_4 + tmp_5] + eml_Phik_0[6 * tmp_4 + eml_j];
      }
    }
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      rtb_x_h_idx = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        rtb_x_h_idx += eml_Phik_0[6 * tmp_5 + eml_j] * (real32_T)tmp_7[6 * tmp_4
          + tmp_5];
      }
      
      tmp[eml_j + 6 * tmp_4] = tmp_8[6 * tmp_4 + eml_j] + rtb_x_h_idx;
    }
  }
  
  Kalman_Sim_inv_i(tmp, tmp_3);
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_Phik_0[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        eml_Phik_0[eml_j + 6 * tmp_4] = eml_P_0[6 * tmp_5 + eml_j] * (real32_T)
          tmp_7[6 * tmp_4 + tmp_5] + eml_Phik_0[6 * tmp_4 + eml_j];
      }
    }
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      eml_Phik[eml_j + 6 * tmp_4] = 0.0F;
      for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
        eml_Phik[eml_j + 6 * tmp_4] = eml_Phik_0[6 * tmp_5 + eml_j] * tmp_3[6 *
          tmp_4 + tmp_5] + eml_Phik[6 * tmp_4 + eml_j];
      }
    }
  }
  
  /*  Update estimate with measurement z */
  /* '<S7>:1:40' */
  rtb_TmpSignalConversionAtSFunct[0] = eml_cos_theta * rtb_Gain1_idx;
  rtb_TmpSignalConversionAtSFunct[1] = eml_sin_phi * eml_C * rtb_Gain1_idx +
    eml_cos_phi * rtb_x_h_idx_0;
  rtb_TmpSignalConversionAtSFunct[2] = eml_cos_phi * eml_C * rtb_Gain1_idx +
    (-eml_sin_phi) * rtb_x_h_idx_0;
  rtb_TmpSignalConversionAtSFunct[3] = rtb_x_h[3];
  rtb_TmpSignalConversionAtSFunct[4] = rtb_x_h[4];
  rtb_TmpSignalConversionAtSFunct[5] = rtb_x_h[5];
  for (eml_j = 0; eml_j < 6; eml_j++) {
    rtb_x_h_idx = 0.0F;
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      rtb_x_h_idx += (real32_T)tmp_7[6 * tmp_4 + eml_j] * eml_x_0[tmp_4];
    }
    
    rtb_TmpSignalConversionAtSFun_0[eml_j] =
      rtb_TmpSignalConversionAtSFunct[eml_j] - rtb_x_h_idx;
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    rtb_x_h_idx = 0.0F;
    for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
      rtb_x_h_idx += eml_Phik[6 * tmp_4 + eml_j] *
        rtb_TmpSignalConversionAtSFun_0[tmp_4];
    }
    
    rtb_TmpSignalConversionAtSFunct[eml_j] = eml_x_0[eml_j] + rtb_x_h_idx;
  }
  
  /*  Normalization DCM(1:3) */
  /* '<S7>:1:42' */
  rtb_x_0[0] = rtb_TmpSignalConversionAtSFunct[0];
  rtb_x_0[1] = rtb_TmpSignalConversionAtSFunct[1];
  rtb_x_0[2] = rtb_TmpSignalConversionAtSFunct[2];
  eml_C = Kalman_Sim_norm_i(rtb_x_0);
  rtb_x_h_idx = rtb_TmpSignalConversionAtSFunct[1] / eml_C;
  rtb_x_h_idx_0 = rtb_TmpSignalConversionAtSFunct[2] / eml_C;
  rtb_TmpSignalConversionAtSFunct[0] /= eml_C;
  rtb_TmpSignalConversionAtSFunct[1] = rtb_x_h_idx;
  rtb_TmpSignalConversionAtSFunct[2] = rtb_x_h_idx_0;
  
  /*  Update the error covariance */
  /* '<S7>:1:44' */
  for (eml_j = 0; eml_j < 36; eml_j++) {
    eml_I_0[eml_j] = 0;
  }
  
  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_I_0[eml_j + 6 * eml_j] = 1;
  }
  
  /* Embedded MATLAB: '<S1>/Compute psi' */
  /* Embedded MATLAB Function 'DCM Filter/Compute psi': '<S2>:1' */
  /*  x1: [C31,C32,C33,gx,gy,gz] */
  /*  x2: [C21 C22 C23 gx gy gz] */
  /* '<S2>:1:7' */
  /* '<S2>:1:8' */
  /* '<S2>:1:9' */
  /* '<S2>:1:10' */
  /* '<S2>:1:11' */
  /* '<S2>:1:12' */
  /* '<S2>:1:14' */
  /* '<S2>:1:15' */
  eml_C = rtb_TmpSignalConversionAtSFunct[2] * rtb_x_h[0] -
    rtb_TmpSignalConversionAtSFunct[0] * rtb_x_h[2];
  
  /* '<S2>:1:16' */
  eml_cos_theta = rtb_TmpSignalConversionAtSFunct[0] * rtb_x_h[1] -
    rtb_TmpSignalConversionAtSFunct[1] * rtb_x_h[0];
  
  /* '<S2>:1:17' */
  /* '<S2>:1:19' */
  /* '<S2>:1:20' */
  eml_sin_phi = (real32_T)cos(-((real32_T)asin(rtb_x_h[0])));
  if ((real_T)rtb_x_h[0] == 1.0) {
    /* '<S2>:1:22' */
    /* theta = pi/2; */
    /* '<S2>:1:24' */
    /* '<S2>:1:25' */
    eml_C = rt_atan232_snf(eml_C, eml_cos_theta);
  } else if ((real_T)rtb_x_h[0] == -1.0) {
    /* '<S2>:1:26' */
    /* theta = -pi/2; */
    /* '<S2>:1:28' */
    /*  anything */
    /* '<S2>:1:29' */
    eml_C = rt_atan232_snf(-eml_C, -eml_cos_theta);
  } else {
    /* phi = atan2(C32/cos_theta , C33/cos_theta); */
    /* '<S2>:1:32' */
    eml_C = rt_atan232_snf(rtb_TmpSignalConversionAtSFunct[0] / eml_sin_phi,
                           (rtb_TmpSignalConversionAtSFunct[1] * rtb_x_h[2] -
                            rtb_TmpSignalConversionAtSFunct[2] * rtb_x_h[1]) / eml_sin_phi);
  }
  
  /* Gain: '<Root>/Gain2' */
  Out1[0] = Kalman_Sim_P.Gain2_Gain * rt_atan232_snf(rtb_x_h[1], rtb_x_h[2]);
  Out1[1] = Kalman_Sim_P.Gain2_Gain * rtb_theta;
  Out1[2] = Kalman_Sim_P.Gain2_Gain * eml_C;
  
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  Out2 = ((real_T)Kalman_Sim_DWork.clockTickCounter <
          Kalman_Sim_P.PulseGenerator_Duty) &&
    (Kalman_Sim_DWork.clockTickCounter >= 0) ? Kalman_Sim_P.PulseGenerator_Amp :
    0.0;
    if ((real_T)Kalman_Sim_DWork.clockTickCounter >=
        Kalman_Sim_P.PulseGenerator_Period - 1.0) {
          Kalman_Sim_DWork.clockTickCounter = 0;
        } else {
          Kalman_Sim_DWork.clockTickCounter = Kalman_Sim_DWork.clockTickCounter + 1;
        }
    
    /* Update for UnitDelay: '<S1>/Unit Delay' */
    for (eml_j = 0; eml_j < 6; eml_j++) {
      Kalman_Sim_DWork.UnitDelay_DSTATE[eml_j] = rtb_x_h[eml_j];
    }
    
    /* Update for UnitDelay: '<S1>/Unit Delay1' */
    for (eml_j = 0; eml_j < 6; eml_j++) {
      for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
        rtb_x_h_idx = 0.0F;
        for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
          rtb_x_h_idx += eml_Kk[6 * tmp_5 + eml_j] * (real32_T)tmp_7[6 * tmp_4 +
            tmp_5];
        }
        
        eml_Phik_0[eml_j + 6 * tmp_4] = (real32_T)eml_I[6 * tmp_4 + eml_j] -
          rtb_x_h_idx;
      }
    }
    
    for (eml_j = 0; eml_j < 6; eml_j++) {
      for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
        Kalman_Sim_DWork.UnitDelay1_DSTATE[eml_j + 6 * tmp_4] = 0.0F;
        for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
          Kalman_Sim_DWork.UnitDelay1_DSTATE[eml_j + 6 * tmp_4] = eml_Phik_0[6 *
            tmp_5 + eml_j] * eml_P[6 * tmp_4 + tmp_5] +
              Kalman_Sim_DWork.UnitDelay1_DSTATE[6 * tmp_4 + eml_j];
        }
      }
    }
    
    /* Update for UnitDelay: '<S1>/Unit Delay2' */
    for (eml_j = 0; eml_j < 6; eml_j++) {
      Kalman_Sim_DWork.UnitDelay2_DSTATE[eml_j] =
        rtb_TmpSignalConversionAtSFunct[eml_j];
    }
    
    /* Update for UnitDelay: '<S1>/Unit Delay3' */
    for (eml_j = 0; eml_j < 6; eml_j++) {
      for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
        rtb_x_h_idx = 0.0F;
        for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
          rtb_x_h_idx += eml_Phik[6 * tmp_5 + eml_j] * (real32_T)tmp_7[6 * tmp_4 +
            tmp_5];
        }
        
        eml_Phik_0[eml_j + 6 * tmp_4] = (real32_T)eml_I_0[6 * tmp_4 + eml_j] -
          rtb_x_h_idx;
      }
    }
    
    for (eml_j = 0; eml_j < 6; eml_j++) {
      for (tmp_4 = 0; tmp_4 < 6; tmp_4++) {
        Kalman_Sim_DWork.UnitDelay3_DSTATE[eml_j + 6 * tmp_4] = 0.0F;
        for (tmp_5 = 0; tmp_5 < 6; tmp_5++) {
          Kalman_Sim_DWork.UnitDelay3_DSTATE[eml_j + 6 * tmp_4] = eml_Phik_0[6 *
            tmp_5 + eml_j] * eml_P_0[6 * tmp_4 + tmp_5] +
              Kalman_Sim_DWork.UnitDelay3_DSTATE[6 * tmp_4 + eml_j];
        }
      }
    }
}

/* Model initialize function */
void Kalman_Sim_initialize(void)
{
  /* Registration code */
  
  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  
  /* initialize error status */
  rtmSetErrorStatus(Kalman_Sim_M, (NULL));
  
  /* block I/O */
  
  /* exported global signals */
  Out2 = 0.0;
  Out1[0] = 0.0F;
  Out1[1] = 0.0F;
  Out1[2] = 0.0F;
  
  /* states (dwork) */
  (void) memset((void *)&Kalman_Sim_DWork, 0,
                sizeof(D_Work_Kalman_Sim));
   
   /* external inputs */
   (void) memset(fgyro,0,
                 3*sizeof(real32_T));
    (void) memset(facc,0,
                  3*sizeof(real32_T));
     (void) memset(fmag,0,
                   3*sizeof(real32_T));
      
      /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
      Kalman_Sim_DWork.clockTickCounter = 0;
      
      {
        int32_T i;
        
        /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
        for (i = 0; i < 6; i++) {
          Kalman_Sim_DWork.UnitDelay_DSTATE[i] = Kalman_Sim_P.UnitDelay_X0[i];
        }
        
        /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
        memcpy((void *)(&Kalman_Sim_DWork.UnitDelay1_DSTATE[0]), (void *)
               (&Kalman_Sim_P.UnitDelay1_X0[0]), 36U * sizeof(real32_T));
        
        /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
        for (i = 0; i < 6; i++) {
          Kalman_Sim_DWork.UnitDelay2_DSTATE[i] = Kalman_Sim_P.UnitDelay2_X0[i];
        }
        
        /* InitializeConditions for UnitDelay: '<S1>/Unit Delay3' */
        memcpy((void *)(&Kalman_Sim_DWork.UnitDelay3_DSTATE[0]), (void *)
               (&Kalman_Sim_P.UnitDelay3_X0[0]), 36U * sizeof(real32_T));
      }

}

/* Model terminate function */
void Kalman_Sim_terminate(void)
{
  /* (no terminate code required) */
}

/*
* File trailer for Real-Time Workshop generated code.
*
* [EOF]
*/
