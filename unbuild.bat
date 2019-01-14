@echo off

if /I "%EPICS_HOST_ARCH%" == "windows-x64-debug" (
    call msbuild.exe /p:Configuration=Debug;Platform=x64 /t:clean AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "windows-x64" (
    call msbuild.exe /p:Configuration=Release;Platform=x64 /t:clean AstriumChopper.sln
)
    
if /I "%EPICS_HOST_ARCH%" == "win32-x86-debug" (
    call msbuild.exe /p:Configuration=Debug;Platform=x86 /t:clean AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "win32-x86" (
    call msbuild.exe /p:Configuration=Release;Platform=x86 /t:clean AstriumChopper.sln
)

if %ERRORLEVEL% neq 0 goto PROBLEM

rmdir /S /Q bin\%EPICS_HOST_ARCH%
rmdir /S /Q lib\%EPICS_HOST_ARCH%

GOTO :EOF

:PROBLEM

@echo astriumchopper Clean Failed
exit /b 1
