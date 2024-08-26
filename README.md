# RT_equation_solver
-----------

### How to use
Run via console
Enter ```compile.bat``` and ```quad_solver.exe```
```shell
compile.bat
quad_solver.exe
```

If you want, you can add flags to the line above, which will be discussed below.
Enter three numbers, separated by spaces.
These three numbers are the coefficients of the quadratic equation, starting with the highest coefficient.
Get the correct answer and realize that real men solve the square not by Vieta, but by `RT_equation_solver`

### Flags
`--help` or `-h` prints information how to use falgs.
Example of displaying information in the console

<img width="530" alt="--help" src="https://github.com/user-attachments/assets/34d9fbbb-5b30-4fe9-b353-edf52ee5dc8f">

--do_test or -d turns on testing of the program with results output.
An example of displaying successful test execution in the console

<img width="530" alt="success" src="https://github.com/user-attachments/assets/5d518d6f-65b2-441d-8a89-f8f7d7ad39af">

An example of displaying failed tests in the console

<img width="530" alt="error" src="https://github.com/user-attachments/assets/f5d2cffc-5dd3-4743-abe8-f189aba206ec">

--only_test or -o disables solving equations with input coefficients, disables input of coefficients
An example of how this flag works

<img width="530" alt="error" src="https://github.com/user-attachments/assets/d6446f1b-3444-400b-a3c7-73a2ff0a66f5">

### Features
- Custom assert (quad_assert)
- Tests of solving the equation
- Flags