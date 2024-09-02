for /F "tokens=1,2,3 delims=. " %%a in ("%VSCMD_VER%") do (
   set VS_MAJOR=%%a
   set VS_MINOR=%%b
   set VS_SU=%%c
)

if "%VS_MAJOR%" == "17" (
    REM VS2022
    set PLATFORM_TOOLSET=v143
    set TARGET_FRAMEWORK_VERSION=v4.7.2
) else (
    REM VS2019
    set PLATFORM_TOOLSET=v142
    set TARGET_FRAMEWORK_VERSION=v4.0
)
