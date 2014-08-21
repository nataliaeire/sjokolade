// Comment line!
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int oppg22();

int main()
{
// Guessing char* argv[] means I'm getting the.. pointer? To.. what?

// We're converting the text argv[1] to double using atof:

    double r;

    cout << "Hello, O fair one! What's your favourite number? ";
    // Note that you can also end the previous line by adding << endl before ;.
    // Then, the input from cin will appear on it's own line.
    cin >> r;
    double s = sin(r);
    cout << "All right! Guess what, the sine of "<< r << " is " << s << "!" << endl << endl;
    cout << "How you doin'." << endl << endl;
    return 0;
}


int oppg22()
{

}
