    double pw(double x, int n) {
        if (n == 0) return 1.0;
        double result = pw(x, n/2);
        result *= result;
        if (n%2 == 1) result *= x;
        return result;
    }

    double myPow(double x, int n) {
        if (x == 1.0 || x == 0) return x;
        else if (x == -1.0) return (n%2 == 1) ? -1 : 1;
        if (n < 0) {
            if (n == INT_MIN) return 0;
            else return 1.0/pw(x,-n);
        }
        else return pw(x,n);
    }
