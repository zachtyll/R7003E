@echo off

cd .

chcp 1252

if "%1"=="" ("E:\MATLAB\bin\win64\gmake"  -f wrapper.mk all) else ("E:\MATLAB\bin\win64\gmake"  -f wrapper.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1