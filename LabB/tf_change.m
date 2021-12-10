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
%Bpre = [ 
%    0, 0;
%    K_t / R_m, l_w;
%    0, 0;
%    -K_t/R_m, l_b
%    ];

% Beta matrix.
Bpre = [ 0; K_t / R_m; 0; -K_t/R_m];
% Derive correct B-matrix.
B = inv(L) * Bpre;

% C-matrix
C_new = [
    0, 0, 1, 0;
    1, 0, 0, 0
    ];

% Unchanged C-matrix
C_old = [0, 0, 1, 0];

% D-matrix.
D = 0;

% Define gains. (Can't be zero for some reason).
% Kp = 46;
% Ki = 260;
% Kd = 0.2;

% Add parts into state space form.
% G_new = ss(A,B,C_new,D);
% G_old = ss(A,B,C_old,D);

% Define PID controller.
% pid = pidstd(Kp, Ki, Kd);

% Glue system together.
% sys_new = feedback(G_new * pid, -1);
% sys_old = feedback(G_old * pid, -1);

% Create a state space model of system.
% [sysA_new, sysB_new, sysC_new, sysD_new] = ssdata(sys_new);
% [sysA_old, sysB_old, sysC_old, sysD_old] = ssdata(sys_old);

% Transfer function of system.
% [num_new, den_new] = ss2tf(sysA_new, sysB_new, sysC_new, sysD_new);
% [num_old, den_old] = ss2tf(sysA_old, sysB_old, sysC_old, sysD_old);

% State space to pole-zero conversion.
[zeroes_nopid, poles_nopid, gain_nopid] = ss2zp(A, B, C_old, D);
% [zeroes_new, poles_new, gain_new] = ss2zp(sysA_new, sysB_new, sysC_new, sysD_new);
% [zeroes_old, poles_old, gain_old] = ss2zp(sysA_old, sysB_old, sysC_old, sysD_old);


% pole-zero map
% pzmap(poles_nopid, zeroes_nopid)

% Get bode-plot of system.
%bode(sys)

% Get bode-plot of linerized robot
% bode(G);
% bandwidth = bandwidth(G);
% hz_bw = bandwidth/(2*pi);
