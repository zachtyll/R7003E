%% Load files.
info33 = readmatrix('Info33.csv')';
info53 = readmatrix('Info53.csv')';
info73 = readmatrix('Info73.csv')';
info113 = readmatrix('Info113.csv')';
info133 = readmatrix('Info133.csv')';
info153 = readmatrix('Info153.csv')';
info173 = readmatrix('Info173.csv')';
info193 = readmatrix('Info193.csv')';
info200 = readmatrix('Info200.csv')';

%% Start computing.

% Create ratios for number of samples compared to lowest sample size.
smallest = size(info33,1);

ratio33 = floor(size(info33,1)/smallest);
ratio53 = floor(size(info53,1)/smallest);
ratio73 = floor(size(info73,1)/smallest);
ratio93 = floor(size(info93,1)/smallest);
ratio113 = floor(size(info113,1)/smallest);
ratio133 = floor(size(info133,1)/smallest);
ratio153 = floor(size(info153,1)/smallest);
ratio173 = floor(size(info173,1)/smallest);
ratio193 = floor(size(info193,1)/smallest);
ratio200 = floor(size(info200,1)/smallest);

% Get the L2 norm of xw for each set.
% NOTE: 4 seconds removed from info200 due to experimental error.


% Adjust for error in each set. (Move 4 seconds forward).

% Experiment duration
exp_dur = 30;

samples2second33 = floor(size(info33,1) / exp_dur);
samples2second53 = floor(size(info53,1) / exp_dur);
samples2second73 = floor(size(info73,1) / exp_dur);
samples2second93 = floor(size(info93,1) / exp_dur);
samples2second113 = floor(size(info113,1) / exp_dur);
samples2second133 = floor(size(info133,1) / exp_dur);
samples2second153 = floor(size(info153,1) / exp_dur);
samples2second173 = floor(size(info173,1) / exp_dur);
samples2second193 = floor(size(info193,1) / exp_dur);
samples2second200 = floor(size(info200,1) / exp_dur);

% Number of seconds to skip into experiment.
skip_sec = 4;


% Euclidian norm is used.
euclidian = 2;

% Cut away skip_sec of seconds from experiment data.
norm33_xw = norm(info33(skip_sec*samples2second33:ratio33:end,2), euclidian);
norm53_xw = norm(info53(skip_sec*samples2second53:ratio53:end,2), euclidian);
norm73_xw = norm(info73(skip_sec*samples2second73:ratio73:end,2), euclidian);
norm93_xw = norm(info93(skip_sec*samples2second93:ratio93:end,2), euclidian);
norm113_xw = norm(info113(skip_sec*samples2second113:ratio113:end,2), euclidian);
norm133_xw = norm(info133(skip_sec*samples2second133:ratio133:end,2), euclidian);
norm153_xw = norm(info153(skip_sec*samples2second153:ratio153:end,2), euclidian);
norm173_xw = norm(info173(skip_sec*samples2second173:ratio173:end,2), euclidian);
norm193_xw = norm(info193(skip_sec*samples2second193:ratio193:end,2), euclidian);
norm200_xw = norm(info200(skip_sec*samples2second200:ratio200:end,2), euclidian);

% Get the L2 norm of theta for each set.
norm33_theta = norm(info33(skip_sec*samples2second33:ratio33:end,3), euclidian);
norm53_theta = norm(info53(skip_sec*samples2second53:ratio53:end,3), euclidian);
norm73_theta = norm(info73(skip_sec*samples2second73:ratio73:end,3), euclidian);
norm93_theta = norm(info93(skip_sec*samples2second93:ratio93:end,3), euclidian);
norm113_theta = norm(info113(skip_sec*samples2second113:ratio113:end,3), euclidian);
norm133_theta = norm(info133(skip_sec*samples2second133:ratio133:end,3), euclidian);
norm153_theta = norm(info153(skip_sec*samples2second153:ratio153:end,3), euclidian);
norm173_theta = norm(info173(skip_sec*samples2second173:ratio173:end,3), euclidian);
norm193_theta = norm(info193(skip_sec*samples2second193:ratio193:end,3), euclidian);
norm200_theta = norm(info200(skip_sec*samples2second200:ratio200:end,2), euclidian);

%% Compile and write data to file.

% Compile data array for xw.
L2_xw = [
    norm33_xw, norm53_xw, norm73_xw, norm93_xw, norm113_xw, norm133_xw,...
    norm153_xw, norm173_xw, norm193_xw, norm200_xw
    ];

L2_theta = [
    norm33_theta, norm53_theta, norm73_theta, norm93_theta, norm113_theta,...
    norm133_theta, norm153_theta, norm173_theta, norm193_theta, norm200_theta
    ];

% Write to file.
writematrix(info_L2_x_w', 'L2Norms_x_w.csv')
writematrix(info_L2_theta', 'L2Norms_theta.csv')
