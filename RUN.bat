tcc src/main.c -Iinclude -L. -lraylib && (main.exe) || (
    echo Compilation failed. Please check for errors.
    pause
)