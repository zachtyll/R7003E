% select the sampling time
fSamplingPeriod = 0.005;

% DO NOT MODIFY THIS!
iNumberOfEncoderSteps	= 720;
fGyroConversionFactor	= 250/32768;%-1/131;
fWheelRadius			= 0.0216; % [m]
load('GyroBias.mat');

%%
% Constants and system definition.

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
alfa = [ 0, 1, 0, 0;
    0, a22, 0, a24;
    0, 0, 0, 1;
    0, a42, a43, a44];

% Derive correct A-matrix.
A = inv(gamma) * alfa;


% Beta matrix.
beta = [ 0; K_t / R_m; 0; -K_t/R_m];


% Derive correct B-matrix.
B = inv(gamma) * beta;

% D-Matrix
D = 0;

% C-matrix
C = [1, 0, 0, 0;
    0, 0, 1, 0];

%%

% LQR priority weigths.
C_prio = [20, .1, 5, .2];

% State space to zero-pole conversion via LQR.
R = 1;
rho = 4;
Q = rho*C_prio'*C_prio;
[K, S, c_poles] = lqr(A,B,Q,R);

% Convert continuous system into discrete.
descrete_sys = c2d(ss(A, B, C, D), fSamplingPeriod);

% Create state-space equation of discrete matrixes.
[Ad, Bd, Cd, Dd] = ssdata(descrete_sys);

% Convert the poles to z-space.
zeds = exp(c_poles .* fSamplingPeriod);

% Get control law gain for discrete poles.
Kd = place(Ad, Bd, zeds);

% Define discrete observer poles.
c_oPoles = [-20, -20, -40, -500];
zeds_o = exp(c_oPoles .* fSamplingPeriod);

%%
% Full Observer
Lt = place(Ad', Cd', zeds_o);
Ld = Lt';

%%
% Partial observer

% change of basis
TInv = [
    1, 0, 0, 0;
    0, 0, 1, 0;
    0, 1, 0, 0;
    0, 0, 0, 1
    ];

T = inv(TInv);

% Define new system.
Ad_tilde = TInv * Ad * T;
Bd_tilde = TInv * Bd;
Cd_tilde = Cd * T;

% Used for completing C.
V = [0, 1, 0, 0;
    0, 0, 0, 1];

% Partition A.
Ayy = Ad_tilde(1, 1);
Ayx = Ad_tilde(1, [2, 3, 4]);
Axy = Ad_tilde([2, 3, 4], 1);
Axx = Ad_tilde([2, 3, 4], [2, 3, 4]);

% Partition B.
By = Bd_tilde(1);
Bx = Bd_tilde(2:4);

% Partition C.
Cy = Cd_tilde([1, 2], 1);
Cx = Cd_tilde([1, 2], [2, 3, 4]);

CC = [Ayx; Cx];

% Get observer gain.
Lt_p = place(Axx', ([Ayx; Cx])', zeds_o([1, 2, 4]));
L_p = Lt_p';

L_p_acc = L_p(1:3, 1);
L_p_nacc = L_p(1:3, [2, 3]);

% Observer gain matrixes.
Md1 = (Axx - L_p_acc * Ayx - L_p_nacc * Cx);
Md2 = (Bx - L_p_acc * By);
Md3 = (Axy - L_p_acc * Ayy - L_p_nacc * Cy);
Md4 = L_p_nacc(1:3,2);
Md5 = L_p_acc;
Md6 = T(1:4, 1);
Md7 = T(1:4, 2:4);