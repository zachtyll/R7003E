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
gamma = [1, 0, 0, 0;
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
alpha = [ 0, 1, 0, 0;
    0, a22, 0, a24;
    0, 0, 0, 1;
    0, a42, a43, a44];

% Derive correct A-matrix.
A = inv(gamma) * alpha;

% Beta matrix.
beta = [ 0; K_t / R_m; 0; -K_t/R_m];
% Derive correct B-matrix.
B = inv(gamma) * beta;

% C-matrix.
C = [
    1, 0, 0, 0;
    0, 0, 1, 0
];

% D-matrix.
D = 0;

% Run LQR_placement to get poles.
% run('LQR_placement')

% Set weights.
C_prio = [20, 0.1, 5, 0.2];

% Set R.
R = 1;

% Set rho.
rho = 6;

% Compute Q.
Q = rho*C_prio'*C_prio;

% Compute LQR-algo.
[K,S,lqr_poles] = lqr(A,B,Q,R);

% Desired poles by ratio multiplication.
pe = lqr_poles * 5;

% Get L-gains.
Lt = place(A', C', pe);
L = Lt';