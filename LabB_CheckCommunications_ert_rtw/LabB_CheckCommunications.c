/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_CheckCommunications.c
 *
 * Code generated for Simulink model 'LabB_CheckCommunications'.
 *
 * Model version                  : 1.466
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 25 14:21:02 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LabB_CheckCommunications.h"
#include "LabB_CheckCommunications_private.h"

/* Block states (default storage) */
D_Work_LabB_CheckCommunications LabB_CheckCommunications_DWork;

/* Real-time model */
static RT_MODEL_LabB_CheckCommunicatio LabB_CheckCommunications_M_;
RT_MODEL_LabB_CheckCommunicatio *const LabB_CheckCommunications_M =
  &LabB_CheckCommunications_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void LabB_CheckCommunications_step(void)
{
  codertarget_arduinobase_interna *obj;
  real_T rtb_Switch;
  real_T u0;
  int16_T out[3];
  int16_T rtb_Abs;
  uint8_T tmp;

  /* MATLABSystem: '<S1>/M2V3 Left Connector 18, 19' */
  enc_output(1.0);

  /* Sin: '<Root>/Sine Wave' */
  if (LabB_CheckCommunications_DWork.systemEnable != 0L) {
    rtb_Switch = LabB_CheckCommunications_P.SineWave_Freq *
      ((LabB_CheckCommunications_M->Timing.clockTick0) * 0.01);
    LabB_CheckCommunications_DWork.lastSin = sin(rtb_Switch);
    LabB_CheckCommunications_DWork.lastCos = cos(rtb_Switch);
    LabB_CheckCommunications_DWork.systemEnable = 0L;
  }

  /* Gain: '<S1>/conversion to duty cycle (convert to int)' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  u0 = floor((((LabB_CheckCommunications_DWork.lastSin *
                LabB_CheckCommunications_P.SineWave_PCos +
                LabB_CheckCommunications_DWork.lastCos *
                LabB_CheckCommunications_P.SineWave_PSin) *
               LabB_CheckCommunications_P.SineWave_HCos +
               (LabB_CheckCommunications_DWork.lastCos *
                LabB_CheckCommunications_P.SineWave_PCos -
                LabB_CheckCommunications_DWork.lastSin *
                LabB_CheckCommunications_P.SineWave_PSin) *
               LabB_CheckCommunications_P.SineWave_Hsin) *
              LabB_CheckCommunications_P.SineWave_Amp +
              LabB_CheckCommunications_P.SineWave_Bias) *
             LabB_CheckCommunications_P.conversiontodutycycleconverttoi);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 65536.0);
  }

  rtb_Abs = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)(uint16_T)u0;

  /* End of Gain: '<S1>/conversion to duty cycle (convert to int)' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  if (rtb_Abs >= LabB_CheckCommunications_P.Switch_Threshold) {
    rtb_Switch = LabB_CheckCommunications_P.Constant2_Value;
  } else {
    rtb_Switch = LabB_CheckCommunications_P.Constant1_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* MATLABSystem: '<S1>/Digital Output1' */
  u0 = rt_roundd_snf(rtb_Switch);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(6, tmp);

  /* End of MATLABSystem: '<S1>/Digital Output1' */

  /* Abs: '<S1>/Abs' */
  if (rtb_Abs < 0) {
    rtb_Abs = -rtb_Abs;
  }

  /* End of Abs: '<S1>/Abs' */

  /* MATLABSystem: '<S1>/PWM' */
  obj = &LabB_CheckCommunications_DWork.obj;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle
    (LabB_CheckCommunications_DWork.obj.PinPWM);

  /* Sum: '<S1>/Add2' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  u0 = LabB_CheckCommunications_P.Constant3_Value + (real_T)rtb_Abs;

  /* Saturate: '<S1>/Saturation 0 to 255' */
  if (u0 > LabB_CheckCommunications_P.Saturation0to255_UpperSat) {
    u0 = LabB_CheckCommunications_P.Saturation0to255_UpperSat;
  } else {
    if (u0 < LabB_CheckCommunications_P.Saturation0to255_LowerSat) {
      u0 = LabB_CheckCommunications_P.Saturation0to255_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Saturation 0 to 255' */

  /* Abs: '<S1>/Abs3' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Sum: '<S1>/Add1'
   */
  u0 = fabs(LabB_CheckCommunications_P.Gain1_Gain * rtb_Switch - u0);

  /* MATLABSystem: '<S1>/PWM' */
  if (!(u0 < 255.0)) {
    u0 = 255.0;
  }

  MW_PWM_SetDutyCycle(LabB_CheckCommunications_DWork.obj.MW_PWM_HANDLE, u0);

  /* MATLABSystem: '<S1>/Accelerometer' */
  MPU6050Accel_Read(&out[0]);

  /* MATLABSystem: '<S1>/Gyroscope' */
  MPU6050Gyro_Read(&out[0]);

  /* Update for Sin: '<Root>/Sine Wave' */
  rtb_Switch = LabB_CheckCommunications_DWork.lastSin;
  LabB_CheckCommunications_DWork.lastSin =
    LabB_CheckCommunications_DWork.lastSin *
    LabB_CheckCommunications_P.SineWave_HCos +
    LabB_CheckCommunications_DWork.lastCos *
    LabB_CheckCommunications_P.SineWave_Hsin;
  LabB_CheckCommunications_DWork.lastCos =
    LabB_CheckCommunications_DWork.lastCos *
    LabB_CheckCommunications_P.SineWave_HCos - rtb_Switch *
    LabB_CheckCommunications_P.SineWave_Hsin;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  LabB_CheckCommunications_M->Timing.clockTick0++;
}

/* Model initialize function */
void LabB_CheckCommunications_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LabB_CheckCommunications_M, 0,
                sizeof(RT_MODEL_LabB_CheckCommunicatio));

  /* states (dwork) */
  (void) memset((void *)&LabB_CheckCommunications_DWork, 0,
                sizeof(D_Work_LabB_CheckCommunications));

  {
    codertarget_arduinobase_interna *obj;

    /* Start for MATLABSystem: '<S1>/M2V3 Left Connector 18, 19' */
    LabB_CheckCommunications_DWork.obj_c.matlabCodegenIsDeleted = false;
    LabB_CheckCommunications_DWork.obj_c.isInitialized = 1L;
    enc_init(1.0, 19.0, 18.0);
    LabB_CheckCommunications_DWork.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    LabB_CheckCommunications_DWork.obj_l.matlabCodegenIsDeleted = false;
    LabB_CheckCommunications_DWork.obj_l.isInitialized = 1L;
    digitalIOSetup(6, 1);
    LabB_CheckCommunications_DWork.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    LabB_CheckCommunications_DWork.obj.matlabCodegenIsDeleted = true;
    LabB_CheckCommunications_DWork.obj.isInitialized = 0L;
    LabB_CheckCommunications_DWork.obj.matlabCodegenIsDeleted = false;
    LabB_CheckCommunications_DWork.obj.PinPWM = 8UL;
    obj = &LabB_CheckCommunications_DWork.obj;
    LabB_CheckCommunications_DWork.obj.isSetupComplete = false;
    LabB_CheckCommunications_DWork.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(LabB_CheckCommunications_DWork.obj.PinPWM,
      0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (LabB_CheckCommunications_DWork.obj.PinPWM);
    MW_PWM_Start(LabB_CheckCommunications_DWork.obj.MW_PWM_HANDLE);
    LabB_CheckCommunications_DWork.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Accelerometer' */
    LabB_CheckCommunications_DWork.obj_g.matlabCodegenIsDeleted = false;
    LabB_CheckCommunications_DWork.obj_g.isInitialized = 1L;
    MPU6050Accel_Init();
    LabB_CheckCommunications_DWork.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Gyroscope' */
    LabB_CheckCommunications_DWork.obj_p.matlabCodegenIsDeleted = false;
    LabB_CheckCommunications_DWork.obj_p.isInitialized = 1L;
    MPU6050Gyro_Init(0.0);
    LabB_CheckCommunications_DWork.obj_p.isSetupComplete = true;

    /* Enable for Sin: '<Root>/Sine Wave' */
    LabB_CheckCommunications_DWork.systemEnable = 1L;
  }
}

/* Model terminate function */
void LabB_CheckCommunications_terminate(void)
{
  codertarget_arduinobase_interna *obj;

  /* Terminate for MATLABSystem: '<S1>/M2V3 Left Connector 18, 19' */
  if (!LabB_CheckCommunications_DWork.obj_c.matlabCodegenIsDeleted) {
    LabB_CheckCommunications_DWork.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/M2V3 Left Connector 18, 19' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!LabB_CheckCommunications_DWork.obj_l.matlabCodegenIsDeleted) {
    LabB_CheckCommunications_DWork.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &LabB_CheckCommunications_DWork.obj;
  if (!LabB_CheckCommunications_DWork.obj.matlabCodegenIsDeleted) {
    LabB_CheckCommunications_DWork.obj.matlabCodegenIsDeleted = true;
    if ((LabB_CheckCommunications_DWork.obj.isInitialized == 1L) &&
        LabB_CheckCommunications_DWork.obj.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (LabB_CheckCommunications_DWork.obj.PinPWM);
      MW_PWM_SetDutyCycle(LabB_CheckCommunications_DWork.obj.MW_PWM_HANDLE, 0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (LabB_CheckCommunications_DWork.obj.PinPWM);
      MW_PWM_Close(LabB_CheckCommunications_DWork.obj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */

  /* Terminate for MATLABSystem: '<S1>/Accelerometer' */
  if (!LabB_CheckCommunications_DWork.obj_g.matlabCodegenIsDeleted) {
    LabB_CheckCommunications_DWork.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Accelerometer' */

  /* Terminate for MATLABSystem: '<S1>/Gyroscope' */
  if (!LabB_CheckCommunications_DWork.obj_p.matlabCodegenIsDeleted) {
    LabB_CheckCommunications_DWork.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Gyroscope' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
