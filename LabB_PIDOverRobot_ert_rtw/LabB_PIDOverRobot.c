/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_PIDOverRobot.c
 *
 * Code generated for Simulink model 'LabB_PIDOverRobot'.
 *
 * Model version                  : 8.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Nov 30 14:18:53 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LabB_PIDOverRobot.h"
#include "LabB_PIDOverRobot_private.h"

/* Block states (default storage) */
D_Work_LabB_PIDOverRobot LabB_PIDOverRobot_DWork;

/* Real-time model */
static RT_MODEL_LabB_PIDOverRobot LabB_PIDOverRobot_M_;
RT_MODEL_LabB_PIDOverRobot *const LabB_PIDOverRobot_M = &LabB_PIDOverRobot_M_;
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
void LabB_PIDOverRobot_step(void)
{
  codertarget_arduinobase_interna *obj;
  int32_T rtb_Encoder_0;
  real32_T rtb_FilterCoefficient;
  real32_T rtb_IntegralGain;
  real32_T rtb_SaturationVsupplytoVsupply;
  real32_T rtb_Sum_c;
  real32_T tmp;
  int16_T out[3];
  uint16_T rtb_DataTypeConversion6;
  uint8_T dataIn[15];

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  DiscreteIntegrator: '<S32>/Filter'
   *  Gain: '<S31>/Derivative Gain'
   *  Sum: '<S32>/SumD'
   */
  rtb_FilterCoefficient = (LabB_PIDOverRobot_P.PIDController_D *
    LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr -
    LabB_PIDOverRobot_DWork.Filter_DSTATE) * LabB_PIDOverRobot_P.PIDController_N;

  /* Sum: '<S46>/Sum' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Gain: '<S42>/Proportional Gain'
   */
  rtb_Sum_c = (LabB_PIDOverRobot_P.PIDController_P *
               LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr +
               LabB_PIDOverRobot_DWork.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<S44>/Saturation' */
  if (rtb_Sum_c > LabB_PIDOverRobot_P.PIDController_UpperSaturationLi) {
    rtb_SaturationVsupplytoVsupply =
      LabB_PIDOverRobot_P.PIDController_UpperSaturationLi;
  } else if (rtb_Sum_c < LabB_PIDOverRobot_P.PIDController_LowerSaturationLi) {
    rtb_SaturationVsupplytoVsupply =
      LabB_PIDOverRobot_P.PIDController_LowerSaturationLi;
  } else {
    rtb_SaturationVsupplytoVsupply = rtb_Sum_c;
  }

  /* End of Saturate: '<S44>/Saturation' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Fcn: '<S5>/Fcn'
   */
  tmp = (real32_T)floor((rtb_SaturationVsupplytoVsupply + 10.0F) * 3276.8F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion6 = tmp < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-tmp :
    (uint16_T)tmp;

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* MATLABSystem: '<S5>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S54>/Extract Desired Bits'
   *  DataTypeConversion: '<S55>/Extract Desired Bits'
   */
  dataIn[1] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  dataIn[2] = (uint8_T)rtb_DataTypeConversion6;

  /* MATLABSystem: '<S3>/Encoder' */
  rtb_Encoder_0 = enc_output(1.0);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type  Conversion2'
   *  Fcn: '<S5>/Fcn1'
   *  Gain: '<S2>/convert to  radians'
   *  Gain: '<S2>/convert to meters'
   *  MATLABSystem: '<S3>/Encoder'
   */
  tmp = (real32_T)floor((LabB_PIDOverRobot_P.converttoradians_Gain * (real32_T)
    rtb_Encoder_0 * LabB_PIDOverRobot_P.fWheelRadius + 10.0F) * 3276.8F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion6 = tmp < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-tmp :
    (uint16_T)tmp;

  /* End of DataTypeConversion: '<S5>/Data Type Conversion1' */

  /* MATLABSystem: '<S5>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S60>/Extract Desired Bits'
   *  DataTypeConversion: '<S61>/Extract Desired Bits'
   */
  dataIn[3] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  dataIn[4] = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S5>/Data Type Conversion2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S5>/Fcn2'
   */
  tmp = (real32_T)floor((LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr
    + 10.0F) * 3276.8F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion6 = tmp < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-tmp :
    (uint16_T)tmp;

  /* End of DataTypeConversion: '<S5>/Data Type Conversion2' */

  /* MATLABSystem: '<S5>/Serial Transmit' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataTypeConversion: '<S58>/Extract Desired Bits'
   *  DataTypeConversion: '<S59>/Extract Desired Bits'
   *  DataTypeConversion: '<S62>/Extract Desired Bits'
   *  DataTypeConversion: '<S63>/Extract Desired Bits'
   *  SignalConversion generated from: '<S5>/Serial Transmit'
   */
  if (LabB_PIDOverRobot_DWork.obj.Protocol !=
      LabB_PIDOverRobot_P.SerialTransmit_Protocol) {
    LabB_PIDOverRobot_DWork.obj.Protocol =
      LabB_PIDOverRobot_P.SerialTransmit_Protocol;
  }

  dataIn[0] = LabB_PIDOverRobot_P.Constant_Value_p;
  dataIn[5] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  dataIn[6] = (uint8_T)rtb_DataTypeConversion6;
  dataIn[7] = 128U;
  dataIn[8] = 0U;
  dataIn[9] = 128U;
  dataIn[10] = 0U;
  dataIn[11] = 128U;
  dataIn[12] = 0U;
  dataIn[13] = 128U;
  dataIn[14] = 0U;
  MW_Serial_write(LabB_PIDOverRobot_DWork.obj.port, &dataIn[0], 15.0,
                  LabB_PIDOverRobot_DWork.obj.dataSizeInBytes,
                  LabB_PIDOverRobot_DWork.obj.sendModeEnum,
                  LabB_PIDOverRobot_DWork.obj.dataType,
                  LabB_PIDOverRobot_DWork.obj.sendFormatEnum, 2.0, '\x00');

  /* Gain: '<S30>/Kb' incorporates:
   *  Sum: '<S30>/SumI2'
   */
  rtb_Sum_c = (rtb_SaturationVsupplytoVsupply - rtb_Sum_c) *
    LabB_PIDOverRobot_P.PIDController_Kb;

  /* Gain: '<S34>/Integral Gain' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   */
  rtb_IntegralGain = LabB_PIDOverRobot_P.PIDController_I *
    LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr;

  /* Product: '<S1>/Product1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S1>/turn off the motor if the measured angle is greater than X degrees'
   */
  rtb_SaturationVsupplytoVsupply *= (real32_T)((real32_T)fabs
    (LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr) < 0.75F);

  /* MATLABSystem: '<S3>/Gyroscope' */
  MPU6050Gyro_Read(&out[0]);

  /* MATLABSystem: '<S68>/Digital Output1' incorporates:
   *  Constant: '<S69>/Constant'
   *  RelationalOperator: '<S69>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(rtb_SaturationVsupplytoVsupply <
    LabB_PIDOverRobot_P.Constant_Value));

  /* Saturate: '<S68>/Saturation -Vsupply to Vsupply' */
  if (rtb_SaturationVsupplytoVsupply >
      LabB_PIDOverRobot_P.M1V4LeftMotorDriverPWM6D8FST_Vs) {
    rtb_SaturationVsupplytoVsupply =
      LabB_PIDOverRobot_P.M1V4LeftMotorDriverPWM6D8FST_Vs;
  } else {
    if (rtb_SaturationVsupplytoVsupply <
        LabB_PIDOverRobot_P.SaturationVsupplytoVsupply_Lowe) {
      rtb_SaturationVsupplytoVsupply =
        LabB_PIDOverRobot_P.SaturationVsupplytoVsupply_Lowe;
    }
  }

  /* End of Saturate: '<S68>/Saturation -Vsupply to Vsupply' */

  /* MATLABSystem: '<S68>/PWM' */
  obj = &LabB_PIDOverRobot_DWork.obj_a;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(LabB_PIDOverRobot_DWork.obj_a.PinPWM);

  /* Gain: '<S68>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)' */
  tmp = (real32_T)floor(LabB_PIDOverRobot_P.conversiontodutycycleconverttou *
                        rtb_SaturationVsupplytoVsupply);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<S68>/PWM' incorporates:
   *  Gain: '<S68>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
   */
  MW_PWM_SetDutyCycle(LabB_PIDOverRobot_DWork.obj_a.MW_PWM_HANDLE, (real_T)(tmp <
    0.0F ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-tmp : (int16_T)(uint8_T)tmp));

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' incorporates:
   *  Constant: '<S2>/gyro bias'
   *  DataTypeConversion: '<S3>/Data Type  Conversion1'
   *  Gain: '<S2>/convert to radians//sec'
   *  MATLABSystem: '<S3>/Gyroscope'
   *  Sum: '<S2>/Sum'
   */
  LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr += ((real32_T)out[0] -
    LabB_PIDOverRobot_P.fGyroBias) *
    LabB_PIDOverRobot_P.converttoradianssec_Gain *
    LabB_PIDOverRobot_P.DiscreteTimeIntegratorconvertfr;

  /* Update for DiscreteIntegrator: '<S37>/Integrator' incorporates:
   *  Sum: '<S30>/SumI4'
   */
  LabB_PIDOverRobot_DWork.Integrator_DSTATE += (rtb_Sum_c + rtb_IntegralGain) *
    LabB_PIDOverRobot_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S32>/Filter' */
  LabB_PIDOverRobot_DWork.Filter_DSTATE += LabB_PIDOverRobot_P.Filter_gainval *
    rtb_FilterCoefficient;
}

/* Model initialize function */
void LabB_PIDOverRobot_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(LabB_PIDOverRobot_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&LabB_PIDOverRobot_DWork, 0,
                sizeof(D_Work_LabB_PIDOverRobot));

  {
    codertarget_arduinobase_interna *obj;
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<S3>/Encoder' */
    LabB_PIDOverRobot_DWork.obj_l.matlabCodegenIsDeleted = false;
    LabB_PIDOverRobot_DWork.obj_l.isInitialized = 1L;
    enc_init(1.0, 19.0, 18.0);
    LabB_PIDOverRobot_DWork.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Serial Transmit' */
    LabB_PIDOverRobot_DWork.obj.matlabCodegenIsDeleted = false;
    LabB_PIDOverRobot_DWork.obj.Protocol =
      LabB_PIDOverRobot_P.SerialTransmit_Protocol;
    LabB_PIDOverRobot_DWork.obj.isInitialized = 1L;
    LabB_PIDOverRobot_DWork.obj.port = 0.0;
    LabB_PIDOverRobot_DWork.obj.dataSizeInBytes = 1.0;
    LabB_PIDOverRobot_DWork.obj.dataType = 0.0;
    LabB_PIDOverRobot_DWork.obj.sendModeEnum = 0.0;
    LabB_PIDOverRobot_DWork.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(LabB_PIDOverRobot_DWork.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    LabB_PIDOverRobot_DWork.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/Serial Transmit' */

    /* Start for MATLABSystem: '<S3>/Gyroscope' */
    LabB_PIDOverRobot_DWork.obj_ls.matlabCodegenIsDeleted = false;
    LabB_PIDOverRobot_DWork.obj_ls.isInitialized = 1L;
    MPU6050Gyro_Init(0.0);
    LabB_PIDOverRobot_DWork.obj_ls.isSetupComplete = true;

    /* Start for MATLABSystem: '<S68>/Digital Output1' */
    LabB_PIDOverRobot_DWork.obj_i.matlabCodegenIsDeleted = false;
    LabB_PIDOverRobot_DWork.obj_i.isInitialized = 1L;
    digitalIOSetup(8, 1);
    LabB_PIDOverRobot_DWork.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S68>/PWM' */
    LabB_PIDOverRobot_DWork.obj_a.matlabCodegenIsDeleted = true;
    LabB_PIDOverRobot_DWork.obj_a.isInitialized = 0L;
    LabB_PIDOverRobot_DWork.obj_a.matlabCodegenIsDeleted = false;
    LabB_PIDOverRobot_DWork.obj_a.PinPWM = 6UL;
    obj = &LabB_PIDOverRobot_DWork.obj_a;
    LabB_PIDOverRobot_DWork.obj_a.isSetupComplete = false;
    LabB_PIDOverRobot_DWork.obj_a.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(LabB_PIDOverRobot_DWork.obj_a.PinPWM, 0.0,
      0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(LabB_PIDOverRobot_DWork.obj_a.PinPWM);
    MW_PWM_Start(LabB_PIDOverRobot_DWork.obj_a.MW_PWM_HANDLE);
    LabB_PIDOverRobot_DWork.obj_a.isSetupComplete = true;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
    LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr =
      LabB_PIDOverRobot_P.DiscreteTimeIntegratorconvert_o;

    /* InitializeConditions for DiscreteIntegrator: '<S37>/Integrator' */
    LabB_PIDOverRobot_DWork.Integrator_DSTATE =
      LabB_PIDOverRobot_P.PIDController_InitialConditio_n;

    /* InitializeConditions for DiscreteIntegrator: '<S32>/Filter' */
    LabB_PIDOverRobot_DWork.Filter_DSTATE =
      LabB_PIDOverRobot_P.PIDController_InitialConditionF;
  }
}

/* Model terminate function */
void LabB_PIDOverRobot_terminate(void)
{
  codertarget_arduinobase_interna *obj;

  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!LabB_PIDOverRobot_DWork.obj_l.matlabCodegenIsDeleted) {
    LabB_PIDOverRobot_DWork.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S5>/Serial Transmit' */
  if (!LabB_PIDOverRobot_DWork.obj.matlabCodegenIsDeleted) {
    LabB_PIDOverRobot_DWork.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Serial Transmit' */

  /* Terminate for MATLABSystem: '<S3>/Gyroscope' */
  if (!LabB_PIDOverRobot_DWork.obj_ls.matlabCodegenIsDeleted) {
    LabB_PIDOverRobot_DWork.obj_ls.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Gyroscope' */

  /* Terminate for MATLABSystem: '<S68>/Digital Output1' */
  if (!LabB_PIDOverRobot_DWork.obj_i.matlabCodegenIsDeleted) {
    LabB_PIDOverRobot_DWork.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S68>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S68>/PWM' */
  obj = &LabB_PIDOverRobot_DWork.obj_a;
  if (!LabB_PIDOverRobot_DWork.obj_a.matlabCodegenIsDeleted) {
    LabB_PIDOverRobot_DWork.obj_a.matlabCodegenIsDeleted = true;
    if ((LabB_PIDOverRobot_DWork.obj_a.isInitialized == 1L) &&
        LabB_PIDOverRobot_DWork.obj_a.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(LabB_PIDOverRobot_DWork.obj_a.PinPWM);
      MW_PWM_SetDutyCycle(LabB_PIDOverRobot_DWork.obj_a.MW_PWM_HANDLE, 0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(LabB_PIDOverRobot_DWork.obj_a.PinPWM);
      MW_PWM_Close(LabB_PIDOverRobot_DWork.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S68>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
