close all;
clear all;
clc;


%K = [ -10.0000  -57.4908 -105.0371  -19.5009 ]


% Magical stuff that might make it work?
clear all
clc

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

% Beta matrix for simulation.
Bpre = [ 
    0, 0;
    K_t / R_m, l_w;
    0, 0;
    -K_t/R_m, l_b
    ];

% Beta matrix.
BpreAlt = [ 0; K_t / R_m; 0; -K_t/R_m];


% Derive correct B-matrix.
B = inv(L) * BpreAlt;

% C-matrix
C = [20, .1, 5, .2];


% D-matrix.
DAlt = [0, 0];
D = 0;

% Get transfer function.
[num, den] = ss2tf(A, B, C, D, 1);

s = tf('s');
G1 = (s^4*num(1) + s^3*num(2) + s^2*num(3) + s*num(4) + num(5))/(s^4*den(1) + s^3*den(2) + s^2*den(3) + s*den(4) + den(5));
G2 = (s^4*num(1) - s^3*num(2) + s^2*num(3) - s*num(4) + num(5))/(s^4*den(1) - s^3*den(2) + s^2*den(3) - s*den(4) + den(5));
%G1 = -(s+2)/(s^2-1);
%G2 = -(-s + 2) / (s^2-1);


rlocus(G1 * G2)

% State space to zero-pole conversion.
%[zeroes, poles, gain] = ss2zp(A, B, C, DAlt, 1);

R = 1;
rho = 6;
Q = rho*C'*C;
K = lqr(A,B,Q,R);
