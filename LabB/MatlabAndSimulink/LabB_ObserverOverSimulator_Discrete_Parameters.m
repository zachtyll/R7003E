close all;
clear all;
clc;

% select the sampling time
fSamplingPeriod = 0.005;

% load the PID
kP = -46.6;
kI = -260;
kD = -0.1;
% Define constants.
g = 9.8;
b_f = 0;
m_b = 0.381;
l_b = 0.112;
I_b = 0.00616;
m_w = 0.036;
l_w = 0.021;
I_w = 0.00000746;
R_m = 4.4;
L_m = 0;
b_m = 0;
K_e = 0.444;
K_t = 0.470;

% Gamma matrix coeff.
L22 = I_w/l_w + l_w * m_w + l_w * m_b;
L24 = l_w * m_b * l_b;
L42 = m_b * l_b;
L44 = I_b + m_b * l_b^(2);

% Gamma matrix.
L = [1, 0, 0, 0;
    0, L22, 0, L24;
    0, 0, 1, 0;
    0, L42, 0, L44];

% Alfa matrix coeff.
a22 = -(K_e * K_t) / (R_m * l_w);
a24 = (K_e *K_t) / R_m;
a42 = - a22;
a43 = m_b * l_b * g;
a44 = - a24;

% Alfa matrix.
Apre = [ 0, 1, 0, 0;
    0, a22, 0, a24;
    0, 0, 0, 1;
    0, a42, a43, a44];

% Derive correct A-matrix.
A = inv(L) * Apre;


% Beta matrix.
BpreAlt = [ 0; K_t / R_m; 0; -K_t/R_m];


% Derive correct B-matrix.
B = inv(L) * BpreAlt;

% C-matrix
C = [1, 0, 0, 0;
    0, 0, 1, 0];
C_line = [20, .1, 5, .2];

% D-matrix.
D = 0;

% State space to zero-pole conversion.
%[zeroes, poles, gain] = ss2zp(A, B, C, DAlt, 1);
R = 1;
rho = 6;
Q = rho*C_line'*C_line;
[K, S, e] = lqr(A,B,Q,R);

pc = [-20, -20, -40, -2860];
pe = pc;

descrete_sys = c2d(ss(A, B, C, D), fSamplingPeriod);
[Ad, Bd, Cd, Dd] = ssdata(descrete_sys);


% map the poles
zeds = exp(pc .* fSamplingPeriod);


% Full Observer
Lt = place(Ad', Cd', zeds);
Ld = Lt';

% Partial observer
% change of base
TInv = [1, 0, 0, 0;
    0, 0, 1, 0;
    0, 1, 0, 0;
    0, 0, 0, 1]

T = inv(TInv);

Ad_tilde = TInv * Ad * T;
Bd_tilde = TInv * Bd;
Cd_tilde = Cd * T;

V = [0, 1, 0, 0;
    0, 0, 0, 1];

Ayy = Ad_tilde(1, 1);
Ayx = Ad_tilde(1, [2, 3, 4]);
Axy = Ad_tilde([2, 3, 4], 1);
Axx = Ad_tilde([2, 3, 4], [2, 3, 4]);

By = Bd_tilde(1);
Bx = Bd_tilde(2:4);

Cy = Cd_tilde([1, 2], 1);
Cx = Cd_tilde([1, 2], [2, 3, 4]);

CC = [Ayx; Cx];

Lt_p = place(Axx', ([Ayx; Cx])', zeds([1, 2, 4]));
L_p = Lt_p';
%L_p = (place(Axx', Cx', pe([1, 2, 4])))';
%L_p = (place(Axx', Cx', pe))';

L_p_acc = L_p([1:3], 1);
%L_p_nacc = L_p([1:3], [1, 2]);
L_p_nacc = L_p([1:3], [2, 3]);

Md1 = (Axx - L_p_acc * Ayx - L_p_nacc * Cx)
Md2 = (Bx - L_p_acc * By)
Md3 = (Axy - L_p_acc * Ayy - L_p_nacc * Cy)
Md4 = L_p_nacc([1:3],2)
%M4 = L_p_nacc;
Md5 = L_p_acc
Md6 = T([1:4], 1)
Md7 = T([1:4], [2:4])





% Ld = [
% 	0.0723    0.0028
%     0.0015    0.0464
%     0.0030    0.2118
%     0.0399    2.1508
% ]
% 
% 
% Md1 = [
%     0.1066   -0.0417    0.0156
%    -0.0561    0.9865    0.0029
%     0.5176    0.0215    0.8387
% ]
% 
% Md2 = [
%     0.0355
%    -0.0048
%    -0.3641
% ]
% 
% Md3 = 1.0e+03 * [
%    -0.0288
%    -0.0316
%    -1.4370
% ]
% 
% Md4 = [
%     0.0331
%     0.0152
%     0.2480
% ]
% 
% Md5 = 1.0e+03 * [
%     0.0288
%     0.0316
%     1.4370
% ]
% 
% Md6 = [
%      1
%      0
%      0
%      0
% ]
% 
% Md7 = [
%      0     0     0
%      1     0     0
%      0     1     0
%      0     0     1
% ]
% 
% Ad = [ 
%     1.0000    0.0022   -0.0000    0.0001
%          0    0.1691   -0.0096    0.0173
%          0    0.0124    1.0006    0.0047
%          0    3.6345    0.2183    0.9237
% ]
% 
% Bd = [ 
%     0.0001
%     0.0394
%    -0.0006
%    -0.1715
% ]
% 
% Cd = [ 
%      1     0     0     0
%      0     0     1     0
% ]
% 
% Dd = [
%      0
%      0
% ]

