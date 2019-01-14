@echo off

REM Create an EPICS style layout
mkdir bin\%EPICS_HOST_ARCH%
mkdir lib\%EPICS_HOST_ARCH%

if /I "%EPICS_HOST_ARCH%" == "windows-x64-debug" (
    set BUILD_DIR=x64\Debug
    call msbuild.exe /p:Configuration=Debug;Platform=x64 AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "windows-x64" (
    set BUILD_DIR=x64\Release
    call msbuild.exe /p:Configuration=Release;Platform=x64 AstriumChopper.sln
)
    
if /I "%EPICS_HOST_ARCH%" == "windows-x64-static-debug" (
    set BUILD_DIR=x64\Debug
    call msbuild.exe /p:Configuration=Debug;Platform=x64 AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "windows-x64-static" (
    set BUILD_DIR=x64\Release
    call msbuild.exe /p:Configuration=Release;Platform=x64 AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "windows-x64-static_md-debug" (
    set BUILD_DIR=x64\Debug
    call msbuild.exe /p:Configuration=Debug;Platform=x64 AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "windows-x64-static_md" (
    set BUILD_DIR=x64\Release
    call msbuild.exe /p:Configuration=Release;Platform=x64 AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "win32-x86-debug" (
    set BUILD_DIR=Debug
    call msbuild.exe /p:Configuration=Debug;Platform=x86 AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "win32-x86" (
    set BUILD_DIR=Release
    call msbuild.exe /p:Configuration=Release;Platform=x86 AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "win32-x86-static-debug" (
    set BUILD_DIR=Debug
    call msbuild.exe /p:Configuration=Debug;Platform=x86 AstriumChopper.sln
)

if /I "%EPICS_HOST_ARCH%" == "win32-x86-static" (
    set BUILD_DIR=Release
    call msbuild.exe /p:Configuration=Release;Platform=x86 AstriumChopper.sln
)

if %ERRORLEVEL% neq 0 goto PROBLEM

copy %BUILD_DIR%\*.lib lib\%EPICS_HOST_ARCH%
copy %BUILD_DIR%\*.dll bin\%EPICS_HOST_ARCH%

GOTO :EOF

:PROBLEM

@echo astrium chopper Build Failed
exit /b 1
