zlabert_battin.c:134:40: warning: Either the condition 'i<=20' is redundant or the array 'd[21]' is accessed at index 21, which is out of bounds. [arrayIndexOutOfBoundsCond]
        double del_val = 1.0 / (1.0 + d[i+1] * v * delold);
                                       ^
labert_battin.c:133:14: note: Assuming that condition 'i<=20' is not redundant
    while (i <= 20 && fabs(termold) > 1e-6) {
             ^
labert_battin.c:134:40: note: Array index out of bounds
        double del_val = 1.0 / (1.0 + d[i+1] * v * delold);
                                       ^
labert_battin.c:240:14: style: Redundant initialization for 'bete'. The initialized value is overwritten before it is read. [redundantInitialization]
        bete = 2.0 * asin(sinv);
             ^
labert_battin.c:239:21: note: bete is initialized
        double bete = 2.0 * acos(cosv);
                    ^
labert_battin.c:240:14: note: bete is overwritten
        bete = 2.0 * asin(sinv);
             ^
labert_battin.c:182:12: style: The scope of the variable 'x' can be reduced. [variableScope]
    double x = 10.0;
           ^
labert_battin.c:58:12: style: Variable 'c' can be declared as const array [constVariable]
    double c[21] = {
           ^
labert_battin.c:104:12: style: Variable 'd' can be declared as const array [constVariable]
    double d[21] = {
           ^
labert_battin.c:145:51: style: Parameter 'dm' can be declared as pointer to const [constParameterPointer]
int lambert_battin(Vector3D ro, Vector3D r, char* dm, double dtsec, Vector3D* vo, Vector3D* v) {
                                                  ^
labert_battin.c:182:14: style: Variable 'x' is assigned a value that is never used. [unreadVariable]
    double x = 10.0;
             ^
labert_battin.c:49:0: style: The function 'add_vectors' is never used. [unusedFunction]
Vector3D add_vectors(Vector3D a, Vector3D b) {
^
nofile:0:0: information: Active checkers: 106/592 (use --checkers-report=<filename> to see details) [checkersReport]

