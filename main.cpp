// Comment line!
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int oppg22(int N, ofstream* file);
float oppg31_stepSize(float topValue, int steps);

int main()
{
    // Starting out - a.k.a a Hello World script.



    // Guessing char* argv[] means I'm getting the.. pointer? To.. what?

    // We're converting the text argv[1] to double using atof:

    double r;

    cout << "Hello, O fair one! What's your favourite number? ";
    /* Note that you can also end the previous line by adding << endl before ;.
    Then, the input from cin will appear on it's own line. */
    cin >> r;
    double s = sin(r);
    cout << "All right! Guess what, the sine of "<< r << " is " << s << "!" << endl << endl;
    cout << "How you doin'." << endl << endl;



    // Starting problem 2.2

    int yesno, i, N;

    cout << "Would you like a single series (0) or a for-loop (1)?" << endl << endl;
    cin >> yesno;

    ofstream myfile;
    myfile.open("tekstfil.dat");

    if(yesno == 0){
        cout << "Summing 1/n. Choose N: " << endl;
        cin >> N;
        oppg22(N, &myfile);
    }else{

        for(i=1; i < 11; i++){
            N = pow(10,i);//10^i;
            oppg22(N,&myfile);
        } // end for loop
    } // end if


    // Second of the recommended questions; problem 3.1
    int topValue, steps, stepSize;
    float derPoint;

    cout << "Choose number of steps: " << endl;
    cin >> steps;
    topValue = 3;
    derPoint = sqrt(2);

    stepSize = oppg31_stepSize(topValue, steps);

    x = linspace();
    double* result = new double(N);

    for (int i=0; i<N; i++) {
        result[i] = 0;
    }

    ddx(int N, double h, double* x, double* result);




    void oppg31_stepSize();
    void oppg31_allXValues();



    return 0;
} // ending main()


// First of the recommended questions; problem 2.2

int oppg22(int N, ofstream* file)
{
    /* Make a program which sums sup = sum(1/n) n=1 to n=N and sdown = sum(1/n) n=N to n=1.
The program should read N from screen and write the final output to screen.

Compare sup og sdown for different N using both single and double precision
for N up to N = 10^10. Which of the above formula is the most realiable one?
Try to give an explanation of possible differences. One possibility for guiding
the eye is for example to make a log-log-plot of the relative difference as a
function of N in steps of 10^n with n=1,2,...,10. This means you need to compute
log_10(|(sup(N)−sdown(N))/sdown(N)|) as function of log_10(N). */


    int n;
    float s_up, s_down, term_up, term_down, error;

    s_up = 0.0;
    s_down = 0.0;
    n = 1;

    // while(n <= N){
    for(n = 1; n<= N ; n++){
        term_up = 1./n;
        term_down = 1./(N-n+1);
        //n++;

        s_up += term_up;
        s_down += term_down;

        error = log10(fabs((s_up-s_down)/s_down));
    } // end while loop

    *file << setiosflags(ios::showpoint | ios:: uppercase);
    *file << setw(20) << setprecision(15) << N << " " << s_up << " " << s_down << " " << error << endl;

    return 0;
} // ending oppg. 2.2




void oppg31()
{
    float h, der2atanX, der3atanX, derPoint;
    int i, steps;

    cout << "Choose number of steps: " << endl;
    cin >> steps;
    derPoint = sqrt(2);

    float x[steps];
    x[0] = 0.;
    h = 3./steps;

    // Defining valid x values for which we can find a derivative
    for(i=0; i<steps; i++){
        x[i] += h;
    }

    // Computing derivatives
    der2atanX = (atan(derPoint+h)-atan(derPoint))/h;
    der3atanX = (atan(derPoint+h)-atan(derPoint-h))/(2.*h);

    return;
}

float oppg31_stepSize(float topValue, int steps){
    float h
    h = topValue./steps;
    return 0;
}

float oppg31_allXValues(int steps, float h)
{
    float x[steps];
    int i;
    x[0] = 0.;
    for(i = 1; i < steps; i++){
        x[i] = x[i-1] + h;
    }
    return 0;
}


void ddx(int N, double h, double* x, double* result) {

    // x = 0, 1,2,3,4..,x_max

    for (i ... N) {
        der2atanX = (atan(x[i]+h)-atan(x[i])) / h;
        result[i] = der2atanX;
    }
}




/*          ANSWERS
FLOAT:

Summing 1/n. Choose N:
10000
Sum of 1/n from n=1 to n=10000 is equal to 9.78761292
Sum of 1/n from n=10000 to n=1 is equal to 9.78760433


DOUBLE:

Summing 1/n. Choose N:
10000
Sum of 1/n from n=1 to n=10000 is equal to 9.78760604
Sum of 1/n from n=10000 to n=1 is equal to 9.78760604

When starting from a large number (starting from n=1), the new numbers will be
small in comparison, and only a small part of them will actually contribute to the
sum. As the terms grow smaller and smaller in size, the new ones will fall beneath
the precision of the existing sum.
So..
The one starting at n=N is the most reliable one?



BUT





According to the answers I'm getting, the series starting at 1 is actually the largest. Though
only for numbers up to 10⁵. From 10⁶, the series starting at N is the largest one. Tutors
weren't sure why.
*/
