/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_CheckCommunications.h
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

#ifndef RTW_HEADER_LabB_CheckCommunications_h_
#define RTW_HEADER_LabB_CheckCommunications_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef LabB_CheckCommunications_COMMON_INCLUDES_
#define LabB_CheckCommunications_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MPU6050wrapper.h"
#include "MW_arduino_digitalio.h"
#include "encoder_arduino.h"
#include "MW_PWM.h"
#endif                           /* LabB_CheckCommunications_COMMON_INCLUDES_ */

#include "LabB_CheckCommunications_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_interna obj; /* '<S1>/PWM' */
  soMPU6050Accel_LabB_CheckCommun obj_g;/* '<S1>/Accelerometer' */
  codertarget_arduinobase_blocks_ obj_l;/* '<S1>/Digital Output1' */
  soMPU6050Gyro_LabB_CheckCommuni obj_p;/* '<S1>/Gyroscope' */
  Encoder_arduino_LabB_CheckCommu obj_c;/* '<S1>/M2V3 Left Connector 18, 19' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
} D_Work_LabB_CheckCommunications;

/* Parameters (default storage) */
struct Parameters_LabB_CheckCommunicat_ {
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T conversiontodutycycleconverttoi;/* Expression: 255/5
                                          * Referenced by: '<S1>/conversion to duty cycle (convert to int)'
                                          */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Saturation0to255_UpperSat;    /* Expression: 255
                                        * Referenced by: '<S1>/Saturation 0 to 255'
                                        */
  real_T Saturation0to255_LowerSat;    /* Expression: 0
                                        * Referenced by: '<S1>/Saturation 0 to 255'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255
                                        * Referenced by: '<S1>/Gain1'
                                        */
  int16_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S1>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LabB_CheckCommunication {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_LabB_CheckCommunicat LabB_CheckCommunications_P;

/* Block states (default storage) */
extern D_Work_LabB_CheckCommunications LabB_CheckCommunications_DWork;

/* Model entry point functions */
extern void LabB_CheckCommunications_initialize(void);
extern void LabB_CheckCommunications_step(void);
extern void LabB_CheckCommunications_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LabB_CheckCommunicatio *const LabB_CheckCommunications_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Unused code path elimination
 * Block '<S1>/Data Type Conversion1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion2' : Unused code path elimination
 * Block '<S4>/Gain1' : Unused code path elimination
 * Block '<S1>/Sum' : Unused code path elimination
 * Block '<S1>/Sum1' : Unused code path elimination
 * Block '<S1>/Sum2' : Unused code path elimination
 * Block '<S1>/Sum3' : Unused code path elimination
 * Block '<S1>/Sum4' : Unused code path elimination
 * Block '<S1>/accelerometer angle bias' : Unused code path elimination
 * Block '<S1>/angle offset' : Unused code path elimination
 * Block '<S1>/angular velocity to angle' : Unused code path elimination
 * Block '<S1>/g_y and g_z to angle in radians' : Unused code path elimination
 * Block '<S1>/gyro velocity bias' : Unused code path elimination
 * Block '<S1>/raw x velocity to deg. // sec.' : Unused code path elimination
 * Block '<S1>/raw y acceleration to g_y' : Unused code path elimination
 * Block '<S1>/raw z acceleration to g_z' : Unused code path elimination
 * Block '<S2>/Gain' : Unused code path elimination
 * Block '<S3>/Gain' : Unused code path elimination
 * Block '<Root>/accelerometer' : Unused code path elimination
 * Block '<Root>/encoder' : Unused code path elimination
 * Block '<Root>/gyro' : Unused code path elimination
 * Block '<Root>/motor' : Unused code path elimination
 */

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
 * '<Root>' : 'LabB_CheckCommunications'
 * '<S1>'   : 'LabB_CheckCommunications/Balancing Robot'
 * '<S2>'   : 'LabB_CheckCommunications/Radians to Degrees'
 * '<S3>'   : 'LabB_CheckCommunications/Radians to Degrees1'
 * '<S4>'   : 'LabB_CheckCommunications/Balancing Robot/Degrees to Radians'
 */
#endif                              /* RTW_HEADER_LabB_CheckCommunications_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
