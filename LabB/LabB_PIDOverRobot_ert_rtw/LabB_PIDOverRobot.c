/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_PIDOverRobot.c
 *
 * Code generated for Simulink model 'LabB_PIDOverRobot'.
 *
 * Model version                  : 1.560
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov 29 17:10:22 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LabB_PIDOverRobot.h"
#include "LabB_PIDOverRobot_private.h"
#include "LabB_PIDOverRobot_dt.h"

/* Block signals (default storage) */
BlockIO_LabB_PIDOverRobot LabB_PIDOverRobot_B;

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
  real32_T rtb_Saturation;
  real32_T rtb_Sum_c;
  real32_T tmp;
  int16_T out[3];
  uint16_T rtb_DataTypeConversion6;
  uint8_T dataIn[15];

  /* DiscreteIntegrator: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  LabB_PIDOverRobot_B.DiscreteTimeIntegratorconvertfr =
    LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr;

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S32>/Filter'
   *  Gain: '<S31>/Derivative Gain'
   *  Sum: '<S32>/SumD'
   */
  rtb_FilterCoefficient = (LabB_PIDOverRobot_P.PIDController_D *
    LabB_PIDOverRobot_B.DiscreteTimeIntegratorconvertfr -
    LabB_PIDOverRobot_DWork.Filter_DSTATE) * LabB_PIDOverRobot_P.PIDController_N;

  /* Sum: '<S46>/Sum' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Gain: '<S42>/Proportional Gain'
   */
  rtb_Sum_c = (LabB_PIDOverRobot_P.PIDController_P *
               LabB_PIDOverRobot_B.DiscreteTimeIntegratorconvertfr +
               LabB_PIDOverRobot_DWork.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<S44>/Saturation' */
  if (rtb_Sum_c > LabB_PIDOverRobot_P.PIDController_UpperSaturationLi) {
    rtb_Saturation = LabB_PIDOverRobot_P.PIDController_UpperSaturationLi;
  } else if (rtb_Sum_c < LabB_PIDOverRobot_P.PIDController_LowerSaturationLi) {
    rtb_Saturation = LabB_PIDOverRobot_P.PIDController_LowerSaturationLi;
  } else {
    rtb_Saturation = rtb_Sum_c;
  }

  /* End of Saturate: '<S44>/Saturation' */

  /* Product: '<S1>/Product1' incorporates:
   *  Fcn: '<S1>/turn off the motor if the measured angle is greater than X degrees'
   */
  LabB_PIDOverRobot_B.Product1 = (real32_T)((real32_T)fabs
    (LabB_PIDOverRobot_B.DiscreteTimeIntegratorconvertfr) < 0.75F) *
    rtb_Saturation;

  /* MATLABSystem: '<S3>/Gyroscope' */
  MPU6050Gyro_Read(&out[0]);

  /* DataTypeConversion: '<S3>/Data Type  Conversion1' incorporates:
   *  MATLABSystem: '<S3>/Gyroscope'
   */
  LabB_PIDOverRobot_B.DataTypeConversion1 = out[0];

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Fcn: '<S5>/Fcn'
   */
  tmp = (real32_T)floor((rtb_Saturation + 10.0F) * 3276.8F);
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
   *  Fcn: '<S5>/Fcn2'
   */
  tmp = (real32_T)floor((LabB_PIDOverRobot_B.DiscreteTimeIntegratorconvertfr +
    10.0F) * 3276.8F);
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

  /* MATLABSystem: '<S68>/Digital Output1' incorporates:
   *  Constant: '<S69>/Constant'
   *  RelationalOperator: '<S69>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(LabB_PIDOverRobot_B.Product1 <
    LabB_PIDOverRobot_P.Constant_Value));

  /* MATLABSystem: '<S68>/PWM' */
  obj = &LabB_PIDOverRobot_DWork.obj_a;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(LabB_PIDOverRobot_DWork.obj_a.PinPWM);

  /* Saturate: '<S68>/Saturation -Vsupply to Vsupply' */
  if (LabB_PIDOverRobot_B.Product1 >
      LabB_PIDOverRobot_P.M1V4LeftMotorDriverPWM6D8FST_Vs) {
    tmp = LabB_PIDOverRobot_P.M1V4LeftMotorDriverPWM6D8FST_Vs;
  } else if (LabB_PIDOverRobot_B.Product1 <
             LabB_PIDOverRobot_P.SaturationVsupplytoVsupply_Lowe) {
    tmp = LabB_PIDOverRobot_P.SaturationVsupplytoVsupply_Lowe;
  } else {
    tmp = LabB_PIDOverRobot_B.Product1;
  }

  /* End of Saturate: '<S68>/Saturation -Vsupply to Vsupply' */

  /* Gain: '<S68>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)' */
  tmp = (real32_T)floor(LabB_PIDOverRobot_P.conversiontodutycycleconverttou *
                        tmp);
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
   *  Gain: '<S2>/convert to radians//sec'
   *  Sum: '<S2>/Sum'
   */
  LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr +=
    (LabB_PIDOverRobot_B.DataTypeConversion1 - LabB_PIDOverRobot_P.fGyroBias) *
    LabB_PIDOverRobot_P.converttoradianssec_Gain *
    LabB_PIDOverRobot_P.DiscreteTimeIntegratorconvertfr;

  /* Update for DiscreteIntegrator: '<S37>/Integrator' incorporates:
   *  Gain: '<S30>/Kb'
   *  Gain: '<S34>/Integral Gain'
   *  Sum: '<S30>/SumI2'
   *  Sum: '<S30>/SumI4'
   */
  LabB_PIDOverRobot_DWork.Integrator_DSTATE += ((rtb_Saturation - rtb_Sum_c) *
    LabB_PIDOverRobot_P.PIDController_Kb + LabB_PIDOverRobot_P.PIDController_I *
    LabB_PIDOverRobot_B.DiscreteTimeIntegratorconvertfr) *
    LabB_PIDOverRobot_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S32>/Filter' */
  LabB_PIDOverRobot_DWork.Filter_DSTATE += LabB_PIDOverRobot_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.005s, 0.0s] */
    rtExtModeUpload(0, (real_T)LabB_PIDOverRobot_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(LabB_PIDOverRobot_M)!=-1) &&
        !((rtmGetTFinal(LabB_PIDOverRobot_M)-
           LabB_PIDOverRobot_M->Timing.taskTime0) >
          LabB_PIDOverRobot_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(LabB_PIDOverRobot_M, "Simulation finished");
    }

    if (rtmGetStopRequested(LabB_PIDOverRobot_M)) {
      rtmSetErrorStatus(LabB_PIDOverRobot_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  LabB_PIDOverRobot_M->Timing.taskTime0 =
    ((time_T)(++LabB_PIDOverRobot_M->Timing.clockTick0)) *
    LabB_PIDOverRobot_M->Timing.stepSize0;
}

/* Model initialize function */
void LabB_PIDOverRobot_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LabB_PIDOverRobot_M, 0,
                sizeof(RT_MODEL_LabB_PIDOverRobot));
  rtmSetTFinal(LabB_PIDOverRobot_M, -1);
  LabB_PIDOverRobot_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  LabB_PIDOverRobot_M->Sizes.checksums[0] = (3374721303U);
  LabB_PIDOverRobot_M->Sizes.checksums[1] = (2414234328U);
  LabB_PIDOverRobot_M->Sizes.checksums[2] = (867387550U);
  LabB_PIDOverRobot_M->Sizes.checksums[3] = (2414289126U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    LabB_PIDOverRobot_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LabB_PIDOverRobot_M->extModeInfo,
      &LabB_PIDOverRobot_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LabB_PIDOverRobot_M->extModeInfo,
                        LabB_PIDOverRobot_M->Sizes.checksums);
    rteiSetTPtr(LabB_PIDOverRobot_M->extModeInfo, rtmGetTPtr(LabB_PIDOverRobot_M));
  }

  /* block I/O */
  (void) memset(((void *) &LabB_PIDOverRobot_B), 0,
                sizeof(BlockIO_LabB_PIDOverRobot));

  /* states (dwork) */
  (void) memset((void *)&LabB_PIDOverRobot_DWork, 0,
                sizeof(D_Work_LabB_PIDOverRobot));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LabB_PIDOverRobot_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_interna *obj;
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<S3>/Gyroscope' */
    LabB_PIDOverRobot_DWork.obj_ls.matlabCodegenIsDeleted = false;
    LabB_PIDOverRobot_DWork.obj_ls.isInitialized = 1L;
    MPU6050Gyro_Init(0.0);
    LabB_PIDOverRobot_DWork.obj_ls.isSetupComplete = true;

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
    LabB_PIDOverRobot_DWork.obj.port = 1.0;
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

  /* Terminate for MATLABSystem: '<S3>/Gyroscope' */
  if (!LabB_PIDOverRobot_DWork.obj_ls.matlabCodegenIsDeleted) {
    LabB_PIDOverRobot_DWork.obj_ls.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Gyroscope' */

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
