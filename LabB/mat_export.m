%% Turn serial data into variables and compose into .mat format.

% Load .mat files containing experiment data.
exp_1 = load('E:\MATLAB-Projects\R7003E\LabB\experiment_1.mat');
exp_2 = load('E:\MATLAB-Projects\R7003E\LabB\experiment_2.mat');

% Load times.
group_12_experiment_1_times = exp_1.afTimes';
group_12_experiment_2_times = exp_2.afTimes';

% Load encoders.
group_12_experiment_1_encoder = exp_1.aafProcessedInformation(2, 1:end)';
group_12_experiment_2_encoder = exp_2.aafProcessedInformation(2, 1:end)';

% Load angles.
group_12_experiment_1_angle = exp_1.aafProcessedInformation(3, 1:end)';
group_12_experiment_2_angle = exp_2.aafProcessedInformation(3, 1:end)';

% Load actuation.
group_12_experiment_1_actuation = exp_1.aafProcessedInformation(1, 1:end)';
group_12_experiment_2_actuation = exp_2.aafProcessedInformation(1, 1:end)';

% Define velocity as scalar (Calculated analytically).
group_12_r_max = 0.2;

% Save as .mat file.
save group_12_results.mat ...
    group_12_experiment_1_times group_12_experiment_1_encoder ...
    group_12_experiment_1_angle group_12_experiment_1_actuation ...
    group_12_experiment_2_times group_12_experiment_2_encoder ...
    group_12_experiment_2_angle group_12_experiment_2_actuation ...
    group_12_r_max