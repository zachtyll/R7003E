clear all;
close all;
clc;

% DO NOT MODIFY THIS!
iNumberOfEncoderSteps	= 720;
fGyroConversionFactor	= -1/131;
fWheelRadius			= 0.0216; % [m]
load('GyroBias.mat');

% if you want, modify this
fSamplingPeriod			= 0.005; % note: 0.005 is the fastest sampling time with the default mpu5060 library settings

% load the PID values
% Minst 4 räknade sekunder bästa
% kP = -100;
% kI = -300;
% kD = -1.2;
% Minst 13 räknade sekunder bästa.
kP = -146;
kI = -360;
kD = -0.22;