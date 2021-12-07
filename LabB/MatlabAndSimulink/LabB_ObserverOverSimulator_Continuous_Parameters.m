close all;
clear all;
clc;
%%
% Define constants.
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
L = [
    1, 0, 0, 0;
    0, L22, 0, L24;
    0, 0, 1, 0;
    0, L42, 0, L44
    ];

% Alfa matrix coeff.
a22 = -(K_e * K_t) / (R_m * l_w);
a24 = (K_e *K_t) / R_m;
a42 = - a22;
a43 = m_b * l_b * g;
a44 = - a24;

% Alfa matrix.
Apre = [
    0, 1, 0, 0;
    0, a22, 0, a24;
    0, 0, 0, 1;
    0, a42, a43, a44
    ];

% Derive correct A-matrix.
A = inv(L) * Apre;

% Beta matrix.
BpreAlt = [ 0; K_t / R_m; 0; -K_t/R_m];

% Derive correct B-matrix.
B = inv(L) * BpreAlt;

% C-matrix
C = [1, 0, 0, 0;
    0, 0, 1, 0];

% LQR weighting values.
C_line = [20, .1, 5, .2];

% D-matrix.
D = 0;

%%
% Full order observer with LQR and place.
% State space to zero-pole conversion.
%[zeroes, poles, gain] = ss2zp(A, B, C, DAlt, 1);
R = 1;
rho = 6;
Q = rho*C_line'*C_line;
[K, S, e] = lqr(A,B,Q,R);

% Controller poles.
pc = e;

% Observer poles.
pe = e*6;

% Get full order observer gains.
Lt = place(A', C', pe);
L = Lt';

%%
% Partial observer

% Change of basis.
TInv = [
    1, 0, 0, 0;
    0, 0, 1, 0;
    0, 1, 0, 0;
    0, 0, 0, 1
    ];

T = inv(TInv);

% Define the new system variables.
A_tilde = TInv * A * T;
B_tilde = TInv * B;
C_tilde = C * T;

% Basis completion for C.
V = [0, 1, 0, 0;
    0, 0, 0, 1];

% Partition A.
Ayy = A_tilde(1, 1);
Ayx = A_tilde(1, [2, 3, 4]);
Axy = A_tilde([2, 3, 4], 1);
Axx = A_tilde([2, 3, 4], [2, 3, 4]);

% Partition B.
By = B_tilde(1);
Bx = B_tilde(2:4);

% Partition C.
Cy = C_tilde([1, 2], 1);
Cx = C_tilde([1, 2], [2, 3, 4]);

CC = [Ayx; Cx];

% Get gain L_p.
Lt_p = place(Axx', ([Ayx; Cx])', pe([1, 2, 4]));
L_p = Lt_p';
%L_p = (place(Axx', Cx', pe([1, 2, 4])))';
%L_p = (place(Axx', Cx', pe))';

% Get L_p for accurate readings.
L_p_acc = L_p(1:3, 1);

% Get L_p for non-accurate readings.
L_p_nacc = L_p(1:3, [2, 3]);

% Set observer matrixes.
M1 = (Axx - L_p_acc * Ayx - L_p_nacc * Cx);
M2 = (Bx - L_p_acc * By);
M3 = (Axy - L_p_acc * Ayy - L_p_nacc * Cy);
M4 = L_p_nacc(1:3,2);
M5 = L_p_acc;
M6 = T(1:4, 1);
M7 = T(1:4, 2:4);


% Partial observer
% M1 = 1.0e+03 * [
%    -0.4358   -0.0072    0.0091
%    -0.0011   -0.0340    0.0010
%     1.8717   -0.0165   -0.0400
% ]
%  
% M2 = [
%    20.6000
%          0
%   -90.0000
% ]
% 
% M3 = [
%      0
%      0
%      0
% ]
% 
% M4 = [
%     1.1459
%    33.9942
%    78.4584
% ]
% 
% M5 = [
%     0.7598
%     1.1459
%    31.6987
% ]
% 
% M6 = [
%      1
%      0
%      0
%      0
% ]
% 
% M7 = [
%      0     0     0
%      1     0     0
%      0     1     0
%      0     0     1
% ]
% 
% L = [
%    15.0196    0.5900
%    -2.7287   18.9345
%     0.6038   44.9804
%    22.1715  435.4379
% ]
% 
% A = 1.0e+03 * [
%          0    0.0010         0         0
%          0   -0.4350   -0.0061    0.0091
%          0         0         0    0.0010
%          0    1.9034    0.0620   -0.0400
% ]
% 
% B = [
%          0
%    20.6000
%          0
%   -90.0000
% ]
% 
% C = [
%      1     0     0     0
%      0     0     1     0
% ]
% 
% D = [
%      0
% ]
% 
