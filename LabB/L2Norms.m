%% Load files and set parameters.
info33 = readmatrix('Info33.csv')';
info53 = readmatrix('Info53.csv')';
info73 = readmatrix('Info73.csv')';
info113 = readmatrix('Info113.csv')';
info133 = readmatrix('Info133.csv')';
info153 = readmatrix('Info153.csv')';
info173 = readmatrix('Info173.csv')';
info193 = readmatrix('Info193.csv')';
info200 = readmatrix('Info200.csv')';

% Number of seconds to skip into experiment.
skip_sec = 4;

% Euclidian/L2 norm is used.
euclidian = 2;

%% Start computing.

% Cut away skip_sec of seconds from experiment data.
% Take only samples on each second of the experiment.
% Compute L2 norms.
norm33_xw = norm(info33(skip_sec*33:33:end,2), euclidian);
norm53_xw = norm(info53(skip_sec*53:53:end,2), euclidian);
norm73_xw = norm(info73(skip_sec*73:73:end,2), euclidian);
norm93_xw = norm(info93(skip_sec*93:93:end,2), euclidian);
norm113_xw = norm(info113(skip_sec*113:113:end,2), euclidian);
norm133_xw = norm(info133(skip_sec*133:133:end,2), euclidian);
norm153_xw = norm(info153(skip_sec*153:153:end,2), euclidian);
norm173_xw = norm(info173(skip_sec*173:173:end,2), euclidian);
norm193_xw = norm(info193(skip_sec*193:193:end,2), euclidian);
norm200_xw = norm(info200(skip_sec*200:200:end,2), euclidian);

% Get the L2 norm of theta for each set.
norm33_theta = norm(info33(skip_sec*33:33:end,3), euclidian);
norm53_theta = norm(info53(skip_sec*53:53:end,3), euclidian);
norm73_theta = norm(info73(skip_sec*73:73:end,3), euclidian);
norm93_theta = norm(info93(skip_sec*93:93:end,3), euclidian);
norm113_theta = norm(info113(skip_sec*113:113:end,3), euclidian);
norm133_theta = norm(info133(skip_sec*133:133:end,3), euclidian);
norm153_theta = norm(info153(skip_sec*153:153:end,3), euclidian);
norm173_theta = norm(info173(skip_sec*173:173:end,3), euclidian);
norm193_theta = norm(info193(skip_sec*193:193:end,3), euclidian);
norm200_theta = norm(info200(skip_sec*200:200:end,3), euclidian);

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
