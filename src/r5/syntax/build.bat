@set PATH=%PATH%;D:\MinGW\msys\1.0\bin

flex -o %~dp0lexer.yy.cpp %~dp0lexer.l

bison --defines=%~dp0parser.yy.h -o %~dp0parser.yy.cpp -v --report-file=%~dp0parser.txt %~dp0parser.y

@echo.
@echo.
@pause
