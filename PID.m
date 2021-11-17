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
% Bpre = [ 0; K_t / R_m; 0; -K_t/R_m];
% Derive correct B-matrix.
B = inv(L) * Bpre;

% C-matrix
C = [0, 0, 1, 0];

% D-matrix.
D = 0;

% Define gains. (Can't be zero for some reason).
K_p = 1;
K_i = 1;
K_d = 1;
T_f = 1; % Derivative filter time constant.

% Add parts into state space form.
G = ss(A,B,C,D);

% Define PID controller.
pid = pid(K_p, K_i, K_d);

% Glue system together.
sys = feedback(G, pid);

% Create a state space model of system.
[sysA, sysB, sysC, sysD] = ssdata(sys);

% Transfer function of system.
[num, den] = ss2tf(sysA, sysB, sysC, sysD);

% State space to pole-zero conversion.
[zeroes, poles, gain] = ss2zp(sysA, sysB, sysC, sysD);
