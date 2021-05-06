@echo off
:start
cls
timeout /t 1
tasklist /fi "imagename eq ShaderCompileWorker.exe" | find /i "ShaderCompileWorker.exe" > nul
if not errorlevel 1 ("Equide">%cd%\Equide.txt) else (del "%cd%\Equide.txt")
tasklist /fi "imagename eq Boost.exe" | find /i "Boost.exe" > nul
if not errorlevel 1 (goto start) else (exit)
