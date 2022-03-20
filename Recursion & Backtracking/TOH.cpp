public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long func(int n,int A,int C,int B)
    {
        if(n==1)
        {
            cout<<"move disk "<<n<<" from rod "<<A<<" to rod "<<C<<endl;
            return 1;
        }
        long long t1=func(n-1,A,B,C);
        cout<<"move disk "<<n<<" from rod "<<A<<" to rod "<<C<<endl;
        long long t2=func(n-1,B,C,A);
        return 1+t1+t2;
    }
    long long toh(int n, int A, int C, int B) {
        return func(n,A,C,B);
    }
