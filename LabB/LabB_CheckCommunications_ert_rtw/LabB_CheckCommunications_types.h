/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_CheckCommunications_types.h
 *
 * Code generated for Simulink model 'LabB_CheckCommunications'.
 *
 * Model version                  : 1.466
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov 29 14:58:18 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LabB_CheckCommunications_types_h_
#define RTW_HEADER_LabB_CheckCommunications_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_jmW87ivuiBvGFMMEZDviKC
#define struct_tag_jmW87ivuiBvGFMMEZDviKC

struct tag_jmW87ivuiBvGFMMEZDviKC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_jmW87ivuiBvGFMMEZDviKC*/

#ifndef typedef_soMPU6050Accel_LabB_CheckCommun
#define typedef_soMPU6050Accel_LabB_CheckCommun

typedef struct tag_jmW87ivuiBvGFMMEZDviKC soMPU6050Accel_LabB_CheckCommun;

#endif                               /*typedef_soMPU6050Accel_LabB_CheckCommun*/

#ifndef struct_tag_E7ZjpEHEQzzHgi4oOkm0RC
#define struct_tag_E7ZjpEHEQzzHgi4oOkm0RC

struct tag_E7ZjpEHEQzzHgi4oOkm0RC
{
  int16_T __dummy;
};

#endif                                 /*struct_tag_E7ZjpEHEQzzHgi4oOkm0RC*/

#ifndef typedef_b_arduinodriver_ArduinoDigitalI
#define typedef_b_arduinodriver_ArduinoDigitalI

typedef struct tag_E7ZjpEHEQzzHgi4oOkm0RC b_arduinodriver_ArduinoDigitalI;

#endif                               /*typedef_b_arduinodriver_ArduinoDigitalI*/

#ifndef struct_tag_KPrkuOK6ssObybfxqijZPC
#define struct_tag_KPrkuOK6ssObybfxqijZPC

struct tag_KPrkuOK6ssObybfxqijZPC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigitalI DigitalIODriverObj;
};

#endif                                 /*struct_tag_KPrkuOK6ssObybfxqijZPC*/

#ifndef typedef_codertarget_arduinobase_blocks_
#define typedef_codertarget_arduinobase_blocks_

typedef struct tag_KPrkuOK6ssObybfxqijZPC codertarget_arduinobase_blocks_;

#endif                               /*typedef_codertarget_arduinobase_blocks_*/

#ifndef struct_tag_kwccTvFMMbYBwUySNkudLG
#define struct_tag_kwccTvFMMbYBwUySNkudLG

struct tag_kwccTvFMMbYBwUySNkudLG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_kwccTvFMMbYBwUySNkudLG*/

#ifndef typedef_soMPU6050Gyro_LabB_CheckCommuni
#define typedef_soMPU6050Gyro_LabB_CheckCommuni

typedef struct tag_kwccTvFMMbYBwUySNkudLG soMPU6050Gyro_LabB_CheckCommuni;

#endif                               /*typedef_soMPU6050Gyro_LabB_CheckCommuni*/

#ifndef struct_tag_Autt3LIKmDdtX0LpW6qYZF
#define struct_tag_Autt3LIKmDdtX0LpW6qYZF

struct tag_Autt3LIKmDdtX0LpW6qYZF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_Autt3LIKmDdtX0LpW6qYZF*/

#ifndef typedef_Encoder_arduino_LabB_CheckCommu
#define typedef_Encoder_arduino_LabB_CheckCommu

typedef struct tag_Autt3LIKmDdtX0LpW6qYZF Encoder_arduino_LabB_CheckCommu;

#endif                               /*typedef_Encoder_arduino_LabB_CheckCommu*/

/* Custom Type definition for MATLABSystem: '<S1>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_lMInmD9zWRzKpUCrv0OfsC
#define struct_tag_lMInmD9zWRzKpUCrv0OfsC

struct tag_lMInmD9zWRzKpUCrv0OfsC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
  uint32_T PinPWM;
};

#endif                                 /*struct_tag_lMInmD9zWRzKpUCrv0OfsC*/

#ifndef typedef_codertarget_arduinobase_interna
#define typedef_codertarget_arduinobase_interna

typedef struct tag_lMInmD9zWRzKpUCrv0OfsC codertarget_arduinobase_interna;

#endif                               /*typedef_codertarget_arduinobase_interna*/

/* Parameters (default storage) */
typedef struct Parameters_LabB_CheckCommunicat_ Parameters_LabB_CheckCommunicat;

/* Forward declaration for rtModel */
typedef struct tag_RTM_LabB_CheckCommunication RT_MODEL_LabB_CheckCommunicatio;

#endif                        /* RTW_HEADER_LabB_CheckCommunications_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
