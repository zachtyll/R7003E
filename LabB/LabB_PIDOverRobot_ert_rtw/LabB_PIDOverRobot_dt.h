/*
 * LabB_PIDOverRobot_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LabB_PIDOverRobot".
 *
 * Model version              : 1.560
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Nov 29 17:10:22 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(uint8_T),
  sizeof(codertarget_arduinobase_inter_n),
  sizeof(Encoder_arduino_LabB_PIDOverRob),
  sizeof(soMPU6050Gyro_LabB_PIDOverRobot),
  sizeof(codertarget_arduinobase_blocks_),
  sizeof(codertarget_arduinobase_interna)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "uint8_T",
  "codertarget_arduinobase_inter_n",
  "Encoder_arduino_LabB_PIDOverRob",
  "soMPU6050Gyro_LabB_PIDOverRobot",
  "codertarget_arduinobase_blocks_",
  "codertarget_arduinobase_interna"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&LabB_PIDOverRobot_B.DiscreteTimeIntegratorconvertfr), 1, 0, 3 }
  ,

  { (char_T *)(&LabB_PIDOverRobot_DWork.obj), 15, 0, 1 },

  { (char_T *)(&LabB_PIDOverRobot_DWork.obj_a), 19, 0, 1 },

  { (char_T *)(&LabB_PIDOverRobot_DWork.obj_l), 16, 0, 1 },

  { (char_T *)(&LabB_PIDOverRobot_DWork.obj_ls), 17, 0, 1 },

  { (char_T *)(&LabB_PIDOverRobot_DWork.obj_i), 18, 0, 1 },

  { (char_T *)(&LabB_PIDOverRobot_DWork.Scope_PWORK.LoggedData[0]), 11, 0, 3 },

  { (char_T *)(&LabB_PIDOverRobot_DWork.DiscreteTimeIntegratorconvertfr), 1, 0,
    3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&LabB_PIDOverRobot_P.fGyroBias), 1, 0, 12 },

  { (char_T *)(&LabB_PIDOverRobot_P.SerialTransmit_Protocol), 0, 0, 1 },

  { (char_T *)(&LabB_PIDOverRobot_P.Constant_Value), 1, 0, 9 },

  { (char_T *)(&LabB_PIDOverRobot_P.Constant_Value_p), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] LabB_PIDOverRobot_dt.h */
