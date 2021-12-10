/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LabB_ObserverAndControllerOverRobot_data.c
 *
 * Code generated for Simulink model 'LabB_ObserverAndControllerOverRobot'.
 *
 * Model version                  : 8.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Dec 10 13:57:39 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LabB_ObserverAndControllerOverRobot.h"
#include "LabB_ObserverAndControllerOverRobot_private.h"

/* Block parameters (default storage) */
Parameters_LabB_ObserverAndCont LabB_ObserverAndControllerOve_P = {
  /* Variable: Ad
   * Referenced by: '<S4>/Gain7'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.00477844337F, 0.0838334709F, 0.128632188F,
    4.08114815F, -6.38453203E-5F, 0.0087372819F, 1.02077794F, 1.17174911F,
    0.00061079982F, 0.0191756524F, 0.0315431952F, 0.935073912F },

  /* Variable: Bd
   * Referenced by: '<S4>/Gain8'
   */
  { 0.00138210063F, 0.0433322F, -0.00608395459F, -0.193027273F },

  /* Variable: Cd
   * Referenced by: '<S4>/Gain10'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F },

  /* Variable: Kd
   * Referenced by: '<S1>/controller'
   */
  { -32.016716F, -48.486393F, -69.71241F, -11.2112541F },

  /* Variable: Ld
   * Referenced by: '<S4>/Gain9'
   */
  { 0.566476941F, 0.0244672243F, 0.037761692F, 0.513198853F, 0.0150958207F,
    0.189406723F, 1.14759398F, 9.80976295F },

  /* Variable: Md1
   * Referenced by: '<S4>/Gain'
   */
  { 0.613424599F, 0.0485595912F, 0.0146188084F, 0.0592681915F, 0.290536553F,
    0.0645268634F, 0.0226768125F, 0.0455972701F, 0.421653271F },

  /* Variable: Md2
   * Referenced by: '<S4>/Gain1'
   */
  { -0.0261465572F, 0.103118293F, -1.35478103F },

  /* Variable: Md3
   * Referenced by: '<S4>/Gain2'
   */
  { -14.5160217F, 43.2574081F, -840.571045F },

  /* Variable: Md4
   * Referenced by: '<S4>/Gain3'
   */
  { 0.408280164F, -0.0425840914F, 1.21079683F },

  /* Variable: Md5
   * Referenced by: '<S4>/Gain4'
   */
  { 14.5160217F, -43.2574081F, 840.571045F },

  /* Variable: Md6
   * Referenced by: '<S4>/Gain5'
   */
  { 1.0F, 0.0F, 0.0F, -0.0F },

  /* Variable: Md7
   * Referenced by: '<S4>/Gain6'
   */
  { 0.0F, 0.0F, 1.0F, -0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -0.0F, -0.0F, 0.0F, 1.0F },

  /* Variable: fGyroBias
   * Referenced by: '<S2>/gyro bias'
   */
  -171.210785F,

  /* Variable: fWheelRadius
   * Referenced by: '<S2>/convert to meters'
   */
  0.0216F,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S5>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
   * Referenced by: '<S6>/UD'
   */
  0.0F,

  /* Mask Parameter: M1V4LeftMotorDriverPWM6D8FST_Vs
   * Referenced by: '<S53>/Saturation -Vsupply to Vsupply'
   */
  9.0F,

  /* Expression: 0
   * Referenced by: '<S9>/Serial Transmit'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S54>/Constant'
   */
  0.0F,

  /* Computed Parameter: converttoradians_Gain
   * Referenced by: '<S2>/convert to  radians'
   */
  -0.00872664619F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S5>/TSamp'
   */
  29.4117641F,

  /* Computed Parameter: DiscreteTimeIntegratorconvertfr
   * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   */
  0.034F,

  /* Computed Parameter: DiscreteTimeIntegratorconvert_e
   * Referenced by: '<S2>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   */
  0.0F,

  /* Computed Parameter: TSamp_WtEt_m
   * Referenced by: '<S6>/TSamp'
   */
  29.4117641F,

  /* Computed Parameter: Internal_1_1_A
   * Referenced by: '<S7>/Internal_1_1'
   */
  -0.0F,

  /* Computed Parameter: Internal_1_1_C
   * Referenced by: '<S7>/Internal_1_1'
   */
  1.0F,

  /* Computed Parameter: Internal_1_1_InitialCondition
   * Referenced by: '<S7>/Internal_1_1'
   */
  0.0F,

  /* Computed Parameter: Internal_1_2_InitialCondition
   * Referenced by: '<S7>/Internal_1_2'
   */
  0.0F,

  /* Computed Parameter: Internal_1_3_InitialCondition
   * Referenced by: '<S7>/Internal_1_3'
   */
  0.0F,

  /* Computed Parameter: Internal_1_4_InitialCondition
   * Referenced by: '<S7>/Internal_1_4'
   */
  0.0F,

  /* Computed Parameter: Internal_2_1_InitialCondition
   * Referenced by: '<S7>/Internal_2_1'
   */
  0.0F,

  /* Computed Parameter: Internal_2_2_A
   * Referenced by: '<S7>/Internal_2_2'
   */
  -0.0F,

  /* Computed Parameter: Internal_2_2_C
   * Referenced by: '<S7>/Internal_2_2'
   */
  1.0F,

  /* Computed Parameter: Internal_2_2_InitialCondition
   * Referenced by: '<S7>/Internal_2_2'
   */
  0.0F,

  /* Computed Parameter: Internal_2_3_InitialCondition
   * Referenced by: '<S7>/Internal_2_3'
   */
  0.0F,

  /* Computed Parameter: Internal_2_4_InitialCondition
   * Referenced by: '<S7>/Internal_2_4'
   */
  0.0F,

  /* Computed Parameter: Internal_3_1_InitialCondition
   * Referenced by: '<S7>/Internal_3_1'
   */
  0.0F,

  /* Computed Parameter: Internal_3_2_InitialCondition
   * Referenced by: '<S7>/Internal_3_2'
   */
  0.0F,

  /* Computed Parameter: Internal_3_3_A
   * Referenced by: '<S7>/Internal_3_3'
   */
  -0.0F,

  /* Computed Parameter: Internal_3_3_C
   * Referenced by: '<S7>/Internal_3_3'
   */
  1.0F,

  /* Computed Parameter: Internal_3_3_InitialCondition
   * Referenced by: '<S7>/Internal_3_3'
   */
  0.0F,

  /* Computed Parameter: Internal_3_4_InitialCondition
   * Referenced by: '<S7>/Internal_3_4'
   */
  0.0F,

  /* Computed Parameter: Internal_4_1_InitialCondition
   * Referenced by: '<S7>/Internal_4_1'
   */
  0.0F,

  /* Computed Parameter: Internal_4_2_InitialCondition
   * Referenced by: '<S7>/Internal_4_2'
   */
  0.0F,

  /* Computed Parameter: Internal_4_3_InitialCondition
   * Referenced by: '<S7>/Internal_4_3'
   */
  0.0F,

  /* Computed Parameter: Internal_4_4_A
   * Referenced by: '<S7>/Internal_4_4'
   */
  -0.0F,

  /* Computed Parameter: Internal_4_4_C
   * Referenced by: '<S7>/Internal_4_4'
   */
  1.0F,

  /* Computed Parameter: Internal_4_4_InitialCondition
   * Referenced by: '<S7>/Internal_4_4'
   */
  0.0F,

  /* Computed Parameter: Internal_1_1_A_m
   * Referenced by: '<S8>/Internal_1_1'
   */
  -0.0F,

  /* Computed Parameter: Internal_1_1_C_h
   * Referenced by: '<S8>/Internal_1_1'
   */
  1.0F,

  /* Computed Parameter: Internal_1_1_InitialCondition_e
   * Referenced by: '<S8>/Internal_1_1'
   */
  0.0F,

  /* Computed Parameter: Internal_1_2_InitialCondition_o
   * Referenced by: '<S8>/Internal_1_2'
   */
  0.0F,

  /* Computed Parameter: Internal_1_3_InitialCondition_b
   * Referenced by: '<S8>/Internal_1_3'
   */
  0.0F,

  /* Computed Parameter: Internal_2_1_InitialCondition_e
   * Referenced by: '<S8>/Internal_2_1'
   */
  0.0F,

  /* Computed Parameter: Internal_2_2_A_o
   * Referenced by: '<S8>/Internal_2_2'
   */
  -0.0F,

  /* Computed Parameter: Internal_2_2_C_p
   * Referenced by: '<S8>/Internal_2_2'
   */
  1.0F,

  /* Computed Parameter: Internal_2_2_InitialCondition_b
   * Referenced by: '<S8>/Internal_2_2'
   */
  0.0F,

  /* Computed Parameter: Internal_2_3_InitialCondition_h
   * Referenced by: '<S8>/Internal_2_3'
   */
  0.0F,

  /* Computed Parameter: Internal_3_1_InitialCondition_m
   * Referenced by: '<S8>/Internal_3_1'
   */
  0.0F,

  /* Computed Parameter: Internal_3_2_InitialCondition_k
   * Referenced by: '<S8>/Internal_3_2'
   */
  0.0F,

  /* Computed Parameter: Internal_3_3_A_a
   * Referenced by: '<S8>/Internal_3_3'
   */
  -0.0F,

  /* Computed Parameter: Internal_3_3_C_h
   * Referenced by: '<S8>/Internal_3_3'
   */
  1.0F,

  /* Computed Parameter: Internal_3_3_InitialCondition_d
   * Referenced by: '<S8>/Internal_3_3'
   */
  0.0F,

  /* Computed Parameter: converttoradianssec_Gain
   * Referenced by: '<S2>/convert to radians//sec'
   */
  0.000133158057F,

  /* Computed Parameter: SaturationVsupplytoVsupply_Lowe
   * Referenced by: '<S53>/Saturation -Vsupply to Vsupply'
   */
  -9.0F,

  /* Computed Parameter: conversiontodutycycleconverttou
   * Referenced by: '<S53>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
   */
  28.333334F,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S4>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S4>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S9>/Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
